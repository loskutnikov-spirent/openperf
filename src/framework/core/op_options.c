#include <assert.h>
#include <errno.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

#include "core/op_common.h"
#include "core/op_log.h"
#include "core/op_options.h"

static SLIST_HEAD(op_options_data_head, op_options_data)
    op_options_data_head = SLIST_HEAD_INITIALIZER(op_options_data_head);

static unsigned _max_option_length()
{
    unsigned max_length = 0;
    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            max_length = op_max(strlen(curr->long_opt), max_length);
        }
    }

    return (max_length);
}

static void __attribute__((noreturn)) _usage(const char* program_name)
{
    FILE* output = stderr;

    unsigned opt_width = _max_option_length() + 4;

    fprintf(output, "Usage: %s\n\n", program_name);
    fprintf(output, "Options:\n");

    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (curr->short_opt == 0) {
                fprintf(output,
                        "      --%-*s%s\n",
                        opt_width,
                        curr->long_opt,
                        curr->description);
            } else {
                fprintf(output,
                        "  -%c, --%-*s%s\n",
                        curr->short_opt,
                        opt_width,
                        curr->long_opt,
                        curr->description);
            }
        }
    }

    exit(EXIT_SUCCESS);
}

int op_options_init()
{
    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        if (opt_data->init) {
            if (opt_data->init() != 0) {
                OP_LOG(OP_LOG_ERROR,
                       "Failed to initialize %s options\n",
                       opt_data->name);
            }
        }
    }

    return (0);
}

static struct op_options_data* _find_options_data(int opt)
{
    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (curr->short_opt == opt) {
                return (opt_data);
            } else if (op_options_hash_long(curr->long_opt) == opt) {
                return (opt_data);
            }
        }
    }
    return (NULL);
}

static const struct op_option* _find_opt_by_long(const char* long_op,
                                                 size_t len)
{
    /* No shenanigans, please. */
    assert(long_op);
    assert(len > 0);

    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (strncmp(long_op, curr->long_opt, len) == 0) { return (curr); }
        }
    }
    return (NULL);
}

static const struct op_option* _find_opt_by_short(int op)
{
    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (curr->short_opt == op) {
                return (curr);
            } else if (op_options_hash_long(curr->long_opt) == op) {
                return (curr);
            }
        }
    }
    return (NULL);
}

int _allocate_optstring(char** optstringp)
{
    /* Figure out necessary string length */
    int length = 1; /* include trailing null */
    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (curr->short_opt) { length += curr->opt_type ? 2 : 1; }
        }
    }

    /* Allocate sufficient length */
    char* optstring = calloc(1, length);
    if (!optstring) { return (-ENOMEM); }

    /* Fill in string */
    unsigned idx = 0;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (curr->short_opt) {
                optstring[idx++] = curr->short_opt;
                if (curr->opt_type) { optstring[idx++] = ':'; }
            }
        }
    }

    *optstringp = optstring;
    return (0);
}

int _allocate_longopts(struct option** longoptsp)
{
    /* Figure out necessary longopts length */
    int nb_opts = 1; /* include null terminated ending */
    struct op_options_data* opt_data = NULL;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            nb_opts++;
        }
    }

    struct option* longopts = calloc(nb_opts, sizeof(*longopts));
    if (!longopts) { return (-ENOMEM); }

    /* Fill in longopts */
    unsigned idx = 0;
    SLIST_FOREACH (opt_data, &op_options_data_head, next) {
        for (const struct op_option* curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            longopts[idx++] = (struct option){
                curr->long_opt,
                curr->opt_type == OP_OPTION_TYPE_NONE ? 0 : 1,
                NULL,
                curr->short_opt ? curr->short_opt
                                : op_options_hash_long(curr->long_opt)};
        }
    }

    *longoptsp = longopts;
    return (0);
}

int op_options_parse(int argc, char* argv[])
{
    optind = 1; /* magic variable for getopt */
    opterr = 1;

    char* optstring = NULL;
    int error = _allocate_optstring(&optstring);
    if (error) { return (error); }

    struct option* longopts = NULL;
    if ((error = _allocate_longopts(&longopts)) != 0) {
        free(optstring);
        return (error);
    }

    for (;;) {
        int option_index = 0;
        int opt = getopt_long(argc, argv, optstring, longopts, &option_index);
        if (opt == -1) { break; }
        if (opt == '?' || opt == 'h') {
            /* unspecified option */
            _usage(argv[0]);
        }
        struct op_options_data* opt_data = _find_options_data(opt);
        assert(opt_data);
        if (opt_data->callback) {
            if (opt_data->callback(opt, optarg) != 0) { _usage(argv[0]); }
        }
    }

    free(optstring);
    free(longopts);
    return (0);
}

/*
 * Hash a long option string to the size of a short one (int).
 * This assumes long_opt points to a NULL-terminated string.
 * Using FNV-1a for simplicity.
 * https://tools.ietf.org/html/draft-eastlake-fnv-03
 */
int op_options_hash_long(const char* long_opt)
{
    /* Initialize hash with the 32-bit offset_basis */
    unsigned int hash = 2166136261;
    static const unsigned int fnv_prime = 16777619;
    const char* val = long_opt;

    while (*val != '\0') {
        hash ^= *val++;
        hash *= fnv_prime;
    }

    return hash;
}

void op_options_register(struct op_options_data* opt_data)
{
    assert(opt_data->name); /* catch init ordering problems */
    SLIST_INSERT_HEAD(&op_options_data_head, opt_data, next);
}

const char* op_options_get_long_opt(int op)
{
    const struct op_option* opt = _find_opt_by_short(op);
    /* All CLI options must have a long-form version. */
    assert(opt);

    return (opt->long_opt);
}

enum op_option_type op_options_get_opt_type_short(int op)
{
    const struct op_option* opt = _find_opt_by_short(op);

    if (opt) { return (opt->opt_type); }

    return (OP_OPTION_TYPE_NONE);
}

enum op_option_type op_options_get_opt_type_long(const char* long_opt,
                                                 size_t len)
{
    const struct op_option* opt = _find_opt_by_long(long_opt, len);
    assert(opt);

    return (opt->opt_type);
}

/*
 * Register the help option.
 * Note: we don't register any callbacks because we can handle them directly.
 * Additionally, there is no mechanism to get argv, which we need for calling
 * usage.
 */
static struct op_options_data help_option = {
    .name = "help",
    .init = NULL,
    .callback = NULL,
    .options = {
        {"Print this message.", "help", 'h', OP_OPTION_TYPE_NONE},
        {0, 0, 0, 0},
    }};

REGISTER_OPTIONS(help_option)
