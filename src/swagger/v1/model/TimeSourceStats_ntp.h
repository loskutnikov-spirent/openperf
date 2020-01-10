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
 * TimeSourceStats_ntp.h
 *
 * NTP statistics
 */

#ifndef TimeSourceStats_ntp_H_
#define TimeSourceStats_ntp_H_


#include "ModelBase.h"


namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// NTP statistics
/// </summary>
class  TimeSourceStats_ntp
    : public ModelBase
{
public:
    TimeSourceStats_ntp();
    virtual ~TimeSourceStats_ntp();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TimeSourceStats_ntp members

    /// <summary>
    /// Received packets
    /// </summary>
    int64_t getRxPackets() const;
    void setRxPackets(int64_t value);
        /// <summary>
    /// Transmitted packets
    /// </summary>
    int64_t getTxPackets() const;
    void setTxPackets(int64_t value);
    
protected:
    int64_t m_Rx_packets;

    int64_t m_Tx_packets;

};

}
}
}

#endif /* TimeSourceStats_ntp_H_ */