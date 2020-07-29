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


#include "PacketCapture.h"

namespace swagger {
namespace v1 {
namespace model {

PacketCapture::PacketCapture()
{
    m_Id = "";
    m_Source_id = "";
    m_Direction = "";
    m_Active = false;
    
}

PacketCapture::~PacketCapture()
{
}

void PacketCapture::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketCapture::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["id"] = ModelBase::toJson(m_Id);
    val["source_id"] = ModelBase::toJson(m_Source_id);
    val["direction"] = ModelBase::toJson(m_Direction);
    val["active"] = m_Active;
    val["config"] = ModelBase::toJson(m_Config);
    

    return val;
}

void PacketCapture::fromJson(nlohmann::json& val)
{
    setId(val.at("id"));
    setSourceId(val.at("source_id"));
    setDirection(val.at("direction"));
    setActive(val.at("active"));
    
}


std::string PacketCapture::getId() const
{
    return m_Id;
}
void PacketCapture::setId(std::string value)
{
    m_Id = value;
    
}
std::string PacketCapture::getSourceId() const
{
    return m_Source_id;
}
void PacketCapture::setSourceId(std::string value)
{
    m_Source_id = value;
    
}
std::string PacketCapture::getDirection() const
{
    return m_Direction;
}
void PacketCapture::setDirection(std::string value)
{
    m_Direction = value;
    
}
bool PacketCapture::isActive() const
{
    return m_Active;
}
void PacketCapture::setActive(bool value)
{
    m_Active = value;
    
}
std::shared_ptr<PacketCaptureConfig> PacketCapture::getConfig() const
{
    return m_Config;
}
void PacketCapture::setConfig(std::shared_ptr<PacketCaptureConfig> value)
{
    m_Config = value;
    
}

}
}
}

