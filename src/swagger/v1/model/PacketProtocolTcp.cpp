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


#include "PacketProtocolTcp.h"

namespace swagger {
namespace v1 {
namespace model {

PacketProtocolTcp::PacketProtocolTcp()
{
    m_Ack = 0L;
    m_AckIsSet = false;
    m_Checksum = 0;
    m_ChecksumIsSet = false;
    m_Data_offset = 0;
    m_Data_offsetIsSet = false;
    m_Destination = 0;
    m_DestinationIsSet = false;
    m_FlagsIsSet = false;
    m_Reserved = 0;
    m_ReservedIsSet = false;
    m_Sequence = 0L;
    m_SequenceIsSet = false;
    m_Source = 0;
    m_SourceIsSet = false;
    m_Urgent_pointer = 0;
    m_Urgent_pointerIsSet = false;
    m_Window = 0;
    m_WindowIsSet = false;
    
}

PacketProtocolTcp::~PacketProtocolTcp()
{
}

void PacketProtocolTcp::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketProtocolTcp::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_AckIsSet)
    {
        val["ack"] = m_Ack;
    }
    if(m_ChecksumIsSet)
    {
        val["checksum"] = m_Checksum;
    }
    if(m_Data_offsetIsSet)
    {
        val["data_offset"] = m_Data_offset;
    }
    if(m_DestinationIsSet)
    {
        val["destination"] = m_Destination;
    }
    {
        nlohmann::json jsonArray;
        for( auto& item : m_Flags )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            val["flags"] = jsonArray;
        }
    }
    if(m_ReservedIsSet)
    {
        val["reserved"] = m_Reserved;
    }
    if(m_SequenceIsSet)
    {
        val["sequence"] = m_Sequence;
    }
    if(m_SourceIsSet)
    {
        val["source"] = m_Source;
    }
    if(m_Urgent_pointerIsSet)
    {
        val["urgent_pointer"] = m_Urgent_pointer;
    }
    if(m_WindowIsSet)
    {
        val["window"] = m_Window;
    }
    

    return val;
}

void PacketProtocolTcp::fromJson(nlohmann::json& val)
{
    if(val.find("ack") != val.end())
    {
        setAck(val.at("ack"));
    }
    if(val.find("checksum") != val.end())
    {
        setChecksum(val.at("checksum"));
    }
    if(val.find("data_offset") != val.end())
    {
        setDataOffset(val.at("data_offset"));
    }
    if(val.find("destination") != val.end())
    {
        setDestination(val.at("destination"));
    }
    {
        m_Flags.clear();
        nlohmann::json jsonArray;
        if(val.find("flags") != val.end())
        {
        for( auto& item : val["flags"] )
        {
            m_Flags.push_back(item);
            
        }
        }
    }
    if(val.find("reserved") != val.end())
    {
        setReserved(val.at("reserved"));
    }
    if(val.find("sequence") != val.end())
    {
        setSequence(val.at("sequence"));
    }
    if(val.find("source") != val.end())
    {
        setSource(val.at("source"));
    }
    if(val.find("urgent_pointer") != val.end())
    {
        setUrgentPointer(val.at("urgent_pointer"));
    }
    if(val.find("window") != val.end())
    {
        setWindow(val.at("window"));
    }
    
}


int64_t PacketProtocolTcp::getAck() const
{
    return m_Ack;
}
void PacketProtocolTcp::setAck(int64_t value)
{
    m_Ack = value;
    m_AckIsSet = true;
}
bool PacketProtocolTcp::ackIsSet() const
{
    return m_AckIsSet;
}
void PacketProtocolTcp::unsetAck()
{
    m_AckIsSet = false;
}
int32_t PacketProtocolTcp::getChecksum() const
{
    return m_Checksum;
}
void PacketProtocolTcp::setChecksum(int32_t value)
{
    m_Checksum = value;
    m_ChecksumIsSet = true;
}
bool PacketProtocolTcp::checksumIsSet() const
{
    return m_ChecksumIsSet;
}
void PacketProtocolTcp::unsetChecksum()
{
    m_ChecksumIsSet = false;
}
int32_t PacketProtocolTcp::getDataOffset() const
{
    return m_Data_offset;
}
void PacketProtocolTcp::setDataOffset(int32_t value)
{
    m_Data_offset = value;
    m_Data_offsetIsSet = true;
}
bool PacketProtocolTcp::dataOffsetIsSet() const
{
    return m_Data_offsetIsSet;
}
void PacketProtocolTcp::unsetData_offset()
{
    m_Data_offsetIsSet = false;
}
int32_t PacketProtocolTcp::getDestination() const
{
    return m_Destination;
}
void PacketProtocolTcp::setDestination(int32_t value)
{
    m_Destination = value;
    m_DestinationIsSet = true;
}
bool PacketProtocolTcp::destinationIsSet() const
{
    return m_DestinationIsSet;
}
void PacketProtocolTcp::unsetDestination()
{
    m_DestinationIsSet = false;
}
std::vector<std::string>& PacketProtocolTcp::getFlags()
{
    return m_Flags;
}
bool PacketProtocolTcp::flagsIsSet() const
{
    return m_FlagsIsSet;
}
void PacketProtocolTcp::unsetFlags()
{
    m_FlagsIsSet = false;
}
int32_t PacketProtocolTcp::getReserved() const
{
    return m_Reserved;
}
void PacketProtocolTcp::setReserved(int32_t value)
{
    m_Reserved = value;
    m_ReservedIsSet = true;
}
bool PacketProtocolTcp::reservedIsSet() const
{
    return m_ReservedIsSet;
}
void PacketProtocolTcp::unsetReserved()
{
    m_ReservedIsSet = false;
}
int64_t PacketProtocolTcp::getSequence() const
{
    return m_Sequence;
}
void PacketProtocolTcp::setSequence(int64_t value)
{
    m_Sequence = value;
    m_SequenceIsSet = true;
}
bool PacketProtocolTcp::sequenceIsSet() const
{
    return m_SequenceIsSet;
}
void PacketProtocolTcp::unsetSequence()
{
    m_SequenceIsSet = false;
}
int32_t PacketProtocolTcp::getSource() const
{
    return m_Source;
}
void PacketProtocolTcp::setSource(int32_t value)
{
    m_Source = value;
    m_SourceIsSet = true;
}
bool PacketProtocolTcp::sourceIsSet() const
{
    return m_SourceIsSet;
}
void PacketProtocolTcp::unsetSource()
{
    m_SourceIsSet = false;
}
int32_t PacketProtocolTcp::getUrgentPointer() const
{
    return m_Urgent_pointer;
}
void PacketProtocolTcp::setUrgentPointer(int32_t value)
{
    m_Urgent_pointer = value;
    m_Urgent_pointerIsSet = true;
}
bool PacketProtocolTcp::urgentPointerIsSet() const
{
    return m_Urgent_pointerIsSet;
}
void PacketProtocolTcp::unsetUrgent_pointer()
{
    m_Urgent_pointerIsSet = false;
}
int32_t PacketProtocolTcp::getWindow() const
{
    return m_Window;
}
void PacketProtocolTcp::setWindow(int32_t value)
{
    m_Window = value;
    m_WindowIsSet = true;
}
bool PacketProtocolTcp::windowIsSet() const
{
    return m_WindowIsSet;
}
void PacketProtocolTcp::unsetWindow()
{
    m_WindowIsSet = false;
}

}
}
}
