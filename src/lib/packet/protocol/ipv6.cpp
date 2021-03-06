/**
 * IPv6 implementation for the packet header C++ Library
 *
 * This file is automatically generated by the library code generator.
 * Do not edit this file manually.
 **/

#include "ipv6.hpp"

namespace libpacket::protocol {

/**
 * IPv6 getter implementations
 **/

uint32_t get_ipv6_version(const ipv6& header) noexcept
{
    auto tmp = header.version_traffic_class_flow_label.load<uint32_t>() & 0xf0000000;
    tmp >>= 28;
    return (tmp);
}

uint32_t get_ipv6_traffic_class(const ipv6& header) noexcept
{
    auto tmp = header.version_traffic_class_flow_label.load<uint32_t>() & 0xff00000;
    tmp >>= 20;
    return (tmp);
}

uint32_t get_ipv6_flow_label(const ipv6& header) noexcept
{
    auto tmp = header.version_traffic_class_flow_label.load<uint32_t>() & 0xfffff;
    return (tmp);
}

uint16_t get_ipv6_payload_length(const ipv6& header) noexcept
{
    return (header.payload_length.load());
}

uint8_t get_ipv6_next_header(const ipv6& header) noexcept
{
    auto tmp = header.next_header.load<uint8_t>();
    return (tmp);
}

uint8_t get_ipv6_hop_limit(const ipv6& header) noexcept
{
    return (header.hop_limit.load());
}

const type::ipv6_address& get_ipv6_source(const ipv6& header) noexcept
{
    return (header.source);
}

const type::ipv6_address& get_ipv6_destination(const ipv6& header) noexcept
{
    return (header.destination);
}

/**
 * IPv6 setter implementations
 **/

void set_ipv6_defaults(ipv6& header) noexcept
{
    set_ipv6_version(header, 6);
    set_ipv6_next_header(header, 59);
    set_ipv6_hop_limit(header, 64);
}

void set_ipv6_version(ipv6& header, uint32_t value) noexcept
{
    value <<= 28;
    header.version_traffic_class_flow_label.store(static_cast<uint32_t>(((value & 0xf0000000) | (header.version_traffic_class_flow_label.load<uint32_t>() & ~0xf0000000))));
}

void set_ipv6_traffic_class(ipv6& header, uint32_t value) noexcept
{
    value <<= 20;
    header.version_traffic_class_flow_label.store(static_cast<uint32_t>(((value & 0xff00000) | (header.version_traffic_class_flow_label.load<uint32_t>() & ~0xff00000))));
}

void set_ipv6_flow_label(ipv6& header, uint32_t value) noexcept
{
    header.version_traffic_class_flow_label.store(static_cast<uint32_t>(((value & 0xfffff) | (header.version_traffic_class_flow_label.load<uint32_t>() & ~0xfffff))));
}

void set_ipv6_payload_length(ipv6& header, uint16_t value) noexcept
{
    header.payload_length = value;
}

void set_ipv6_next_header(ipv6& header, uint8_t value) noexcept
{
    header.next_header.store(value);
}

void set_ipv6_hop_limit(ipv6& header, uint8_t value) noexcept
{
    header.hop_limit = value;
}

void set_ipv6_source(ipv6& header, const type::ipv6_address& value) noexcept
{
    header.source = value;
}

void set_ipv6_source(ipv6& header, type::ipv6_address&& value) noexcept
{
    set_ipv6_source(header, value);
}

void set_ipv6_destination(ipv6& header, const type::ipv6_address& value) noexcept
{
    header.destination = value;
}

void set_ipv6_destination(ipv6& header, type::ipv6_address&& value) noexcept
{
    set_ipv6_destination(header, value);
}

/**
 * IPv6 field translate implementation
 **/

template <typename Key, typename Value, typename... Pairs>
constexpr auto associative_array(Pairs&&... pairs)
    -> std::array<std::pair<Key, Value>, sizeof... (pairs)>
{
    return {{std::forward<Pairs>(pairs)...}};
}

enum ipv6::field_name ipv6::get_field_name(std::string_view name) noexcept
{
    constexpr auto field_names = associative_array<std::string_view, ipv6::field_name>(
        std::pair("version", ipv6::field_name::version),
        std::pair("traffic_class", ipv6::field_name::traffic_class),
        std::pair("flow_label", ipv6::field_name::flow_label),
        std::pair("payload_length", ipv6::field_name::payload_length),
        std::pair("next_header", ipv6::field_name::next_header),
        std::pair("hop_limit", ipv6::field_name::hop_limit),
        std::pair("source", ipv6::field_name::source),
        std::pair("destination", ipv6::field_name::destination));

    auto cursor = std::begin(field_names), end = std::end(field_names);
    while (cursor != end) {
        if (cursor->first == name) return (cursor->second);
        cursor++;
    }

    return (ipv6::field_name::none);
}

const std::type_info& ipv6::get_field_type(ipv6::field_name field) noexcept
{
    switch (field) {
        case ipv6::field_name::version:
            return (typeid(uint32_t));
        case ipv6::field_name::traffic_class:
            return (typeid(uint32_t));
        case ipv6::field_name::flow_label:
            return (typeid(uint32_t));
        case ipv6::field_name::payload_length:
            return (typeid(uint16_t));
        case ipv6::field_name::next_header:
            return (typeid(uint8_t));
        case ipv6::field_name::hop_limit:
            return (typeid(uint8_t));
        case ipv6::field_name::source:
            return (typeid(type::ipv6_address));
        case ipv6::field_name::destination:
            return (typeid(type::ipv6_address));
        default:
            return (typeid(nullptr));
    }
}

}
