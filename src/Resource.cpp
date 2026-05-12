#include "Resource.hpp"

ResourceManager::ResourceManager()
{
    m_resorce_values[ResourceType::EXP] = 1;
    m_resorce_values[ResourceType::IRON] = 7;
    m_resorce_values[ResourceType::GOLD] = 11;
    m_resorce_values[ResourceType::GEMS] = 23;

    m_str_to_type = {
        {"iron", ResourceType::IRON},
        {"gold", ResourceType::GOLD},
        {"gems", ResourceType::GEMS},
        {"exp", ResourceType::EXP},
    };
}

bool ResourceManager::is_valid_resource(const std::string& res) const
{
    return m_str_to_type.find(res) != m_str_to_type.end();
}

ResourceType ResourceManager::str_to_res_type(const std::string& res) const
{
    return m_str_to_type.find(res)->second;
}

void ResourceManager::double_resource_value(ResourceType type)
{
    m_resorce_values[type] *= 2;
}
