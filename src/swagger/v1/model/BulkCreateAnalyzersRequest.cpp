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


#include "BulkCreateAnalyzersRequest.h"

namespace swagger {
namespace v1 {
namespace model {

BulkCreateAnalyzersRequest::BulkCreateAnalyzersRequest()
{
    
}

BulkCreateAnalyzersRequest::~BulkCreateAnalyzersRequest()
{
}

void BulkCreateAnalyzersRequest::validate()
{
    // TODO: implement validation
}

nlohmann::json BulkCreateAnalyzersRequest::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    {
        nlohmann::json jsonArray;
        for( auto& item : m_Items )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        val["items"] = jsonArray;
            }
    

    return val;
}

void BulkCreateAnalyzersRequest::fromJson(nlohmann::json& val)
{
    {
        m_Items.clear();
        nlohmann::json jsonArray;
                for( auto& item : val["items"] )
        {
            
            if(item.is_null())
            {
                m_Items.push_back( std::shared_ptr<Analyzer>(nullptr) );
            }
            else
            {
                std::shared_ptr<Analyzer> newItem(new Analyzer());
                newItem->fromJson(item);
                m_Items.push_back( newItem );
            }
            
        }
    }
    
}


std::vector<std::shared_ptr<Analyzer>>& BulkCreateAnalyzersRequest::getItems()
{
    return m_Items;
}

}
}
}
