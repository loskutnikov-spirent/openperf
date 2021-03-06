#ifndef _OP_PACKET_PROTOCOL_TRANSMOGRIFY_IPV4_HPP_
#define _OP_PACKET_PROTOCOL_TRANSMOGRIFY_IPV4_HPP_

/**
 * swagger <-> libpacket transmogrify header for IPv4
 *
 * This file is automatically generated by the transmogrify code generator.
 * Do not edit this file manually.
 **/

#include "packet/protocol/ipv4.hpp"
#include "swagger/v1/model/PacketProtocolIpv4.h"

namespace openperf::packet::protocol::transmogrify {

libpacket::protocol::ipv4 to_protocol(const std::shared_ptr<swagger::v1::model::PacketProtocolIpv4>&);

std::shared_ptr<swagger::v1::model::PacketProtocolIpv4> to_swagger(const libpacket::protocol::ipv4&);

}

#endif /* _OP_PACKET_PROTOCOL_TRANSMOGRIFY_IPV4_HPP_ */
