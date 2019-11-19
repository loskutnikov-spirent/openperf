#ifndef _ICP_UTILS_OVERLOADED_VISITOR_H_
#define _ICP_UTILS_OVERLOADED_VISITOR_H_

namespace icp::utils {

/**
 * This struct is magic.  Use templates and parameter packing to provide
 * some syntactic sugar for creating visitor objects for std::visit.
 */
template<typename ...Ts>
struct overloaded_visitor : Ts...
{
    overloaded_visitor(const Ts&... args)
        : Ts(args)...
    {}

    using Ts::operator()...;
};

}

#endif /* _ICP_UTILS_OVERLOADED_VISITOR_H_ */
