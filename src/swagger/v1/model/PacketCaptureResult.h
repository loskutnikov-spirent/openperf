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
/*
 * PacketCaptureResult.h
 *
 * Packet capture results
 */

#ifndef PacketCaptureResult_H_
#define PacketCaptureResult_H_


#include "ModelBase.h"

#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Packet capture results
/// </summary>
class  PacketCaptureResult
    : public ModelBase
{
public:
    PacketCaptureResult();
    virtual ~PacketCaptureResult();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// PacketCaptureResult members

    /// <summary>
    /// Unique capture result identifier
    /// </summary>
    std::string getId() const;
    void setId(std::string value);
        /// <summary>
    /// Unique capture identifier that generated this result
    /// </summary>
    std::string getCaptureId() const;
    void setCaptureId(std::string value);
        /// <summary>
    /// Indicates whether this object is currently capturing packets or not. 
    /// </summary>
    bool isActive() const;
    void setActive(bool value);
    bool activeIsSet() const;
    void unsetActive();
    /// <summary>
    /// Capture state
    /// </summary>
    std::string getState() const;
    void setState(std::string value);
        /// <summary>
    /// Number of packets captured
    /// </summary>
    int64_t getPackets() const;
    void setPackets(int64_t value);
        /// <summary>
    /// Number of bytes captured
    /// </summary>
    int64_t getBytes() const;
    void setBytes(int64_t value);
    
protected:
    std::string m_Id;

    std::string m_Capture_id;

    bool m_Active;
    bool m_ActiveIsSet;
    std::string m_State;

    int64_t m_Packets;

    int64_t m_Bytes;

};

}
}
}

#endif /* PacketCaptureResult_H_ */