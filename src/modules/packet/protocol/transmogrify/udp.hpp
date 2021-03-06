#ifndef _OP_PACKET_PROTOCOL_TRANSMOGRIFY_UDP_HPP_
#define _OP_PACKET_PROTOCOL_TRANSMOGRIFY_UDP_HPP_

/**
 * swagger <-> libpacket transmogrify header for udp
 *
 * This file is automatically generated by the transmogrify code generator.
 * Do not edit this file manually.
 **/

#include "packet/protocol/udp.hpp"
#include "swagger/v1/model/PacketProtocolUdp.h"

namespace openperf::packet::protocol::transmogrify {

libpacket::protocol::udp to_protocol(const std::shared_ptr<swagger::v1::model::PacketProtocolUdp>&);

std::shared_ptr<swagger::v1::model::PacketProtocolUdp> to_swagger(const libpacket::protocol::udp&);

}

#endif /* _OP_PACKET_PROTOCOL_TRANSMOGRIFY_UDP_HPP_ */
