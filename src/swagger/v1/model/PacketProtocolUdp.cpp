/**
* OpenPerf API
* REST API interface for OpenPerf
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/


#include "PacketProtocolUdp.h"

namespace swagger {
namespace v1 {
namespace model {

PacketProtocolUdp::PacketProtocolUdp()
{
    m_Checksum = 0;
    m_ChecksumIsSet = false;
    m_Destination = 0;
    m_DestinationIsSet = false;
    m_Length = 0;
    m_LengthIsSet = false;
    m_Source = 0;
    m_SourceIsSet = false;
    
}

PacketProtocolUdp::~PacketProtocolUdp()
{
}

void PacketProtocolUdp::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketProtocolUdp::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_ChecksumIsSet)
    {
        val["checksum"] = m_Checksum;
    }
    if(m_DestinationIsSet)
    {
        val["destination"] = m_Destination;
    }
    if(m_LengthIsSet)
    {
        val["length"] = m_Length;
    }
    if(m_SourceIsSet)
    {
        val["source"] = m_Source;
    }
    

    return val;
}

void PacketProtocolUdp::fromJson(nlohmann::json& val)
{
    if(val.find("checksum") != val.end())
    {
        setChecksum(val.at("checksum"));
    }
    if(val.find("destination") != val.end())
    {
        setDestination(val.at("destination"));
    }
    if(val.find("length") != val.end())
    {
        setLength(val.at("length"));
    }
    if(val.find("source") != val.end())
    {
        setSource(val.at("source"));
    }
    
}


int32_t PacketProtocolUdp::getChecksum() const
{
    return m_Checksum;
}
void PacketProtocolUdp::setChecksum(int32_t value)
{
    m_Checksum = value;
    m_ChecksumIsSet = true;
}
bool PacketProtocolUdp::checksumIsSet() const
{
    return m_ChecksumIsSet;
}
void PacketProtocolUdp::unsetChecksum()
{
    m_ChecksumIsSet = false;
}
int32_t PacketProtocolUdp::getDestination() const
{
    return m_Destination;
}
void PacketProtocolUdp::setDestination(int32_t value)
{
    m_Destination = value;
    m_DestinationIsSet = true;
}
bool PacketProtocolUdp::destinationIsSet() const
{
    return m_DestinationIsSet;
}
void PacketProtocolUdp::unsetDestination()
{
    m_DestinationIsSet = false;
}
int32_t PacketProtocolUdp::getLength() const
{
    return m_Length;
}
void PacketProtocolUdp::setLength(int32_t value)
{
    m_Length = value;
    m_LengthIsSet = true;
}
bool PacketProtocolUdp::lengthIsSet() const
{
    return m_LengthIsSet;
}
void PacketProtocolUdp::unsetLength()
{
    m_LengthIsSet = false;
}
int32_t PacketProtocolUdp::getSource() const
{
    return m_Source;
}
void PacketProtocolUdp::setSource(int32_t value)
{
    m_Source = value;
    m_SourceIsSet = true;
}
bool PacketProtocolUdp::sourceIsSet() const
{
    return m_SourceIsSet;
}
void PacketProtocolUdp::unsetSource()
{
    m_SourceIsSet = false;
}

}
}
}

