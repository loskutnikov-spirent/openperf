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
 * TimeKeeperStats.h
 *
 * TimeKeeper statistics
 */

#ifndef TimeKeeperStats_H_
#define TimeKeeperStats_H_


#include "ModelBase.h"

#include "TimeKeeperStats_round_trip_times.h"

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// TimeKeeper statistics
/// </summary>
class  TimeKeeperStats
    : public ModelBase
{
public:
    TimeKeeperStats();
    virtual ~TimeKeeperStats();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TimeKeeperStats members

    /// <summary>
    /// The number of times the frequency calculation has been updated.
    /// </summary>
    double getFrequencyAccept() const;
    void setFrequencyAccept(double value);
        /// <summary>
    /// The number of times the frequency calculation has been rejected due to an excessive delta between old and new values. 
    /// </summary>
    double getFrequencyReject() const;
    void setFrequencyReject(double value);
        /// <summary>
    /// The number of times the local frequency calculation has been updated.
    /// </summary>
    double getLocalFrequencyAccept() const;
    void setLocalFrequencyAccept(double value);
        /// <summary>
    /// The number of times the local frequency calculation has been rejected due to an excessive delta between old and new values. 
    /// </summary>
    double getLocalFrequencyReject() const;
    void setLocalFrequencyReject(double value);
        /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TimeKeeperStats_round_trip_times> getRoundTripTimes() const;
    void setRoundTripTimes(std::shared_ptr<TimeKeeperStats_round_trip_times> value);
        /// <summary>
    /// The number of times the theta calculation has been updated.
    /// </summary>
    double getThetaAccept() const;
    void setThetaAccept(double value);
        /// <summary>
    /// Then umber of times the theta calculation has been rejected due to excessive delta between old and new values. 
    /// </summary>
    double getThetaReject() const;
    void setThetaReject(double value);
        /// <summary>
    /// The number of timestamps in the current working set of timestamps. Old timestamps are dropped from the history of timestamps as they become irrelevant. 
    /// </summary>
    double getTimestamps() const;
    void setTimestamps(double value);
    
protected:
    double m_Frequency_accept;

    double m_Frequency_reject;

    double m_Local_frequency_accept;

    double m_Local_frequency_reject;

    std::shared_ptr<TimeKeeperStats_round_trip_times> m_Round_trip_times;

    double m_Theta_accept;

    double m_Theta_reject;

    double m_Timestamps;

};

}
}
}

#endif /* TimeKeeperStats_H_ */
