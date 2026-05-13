#include "Resource.hpp"

#include <algorithm>

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

    m_type_to_str = {
        {ResourceType::IRON, "iron"},
        {ResourceType::GOLD, "gold"},
        {ResourceType::GEMS, "gems"},
        {ResourceType::EXP, "exp"},
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

std::string ResourceManager::res_type_to_str(ResourceType type) const
{
    return m_type_to_str.find(type)->second;
}

void ResourceManager::double_resource_value(ResourceType type)
{
    m_resorce_values[type] *= 2;
}

int ResourceManager::get_res_value(ResourceType type) const
{
    return m_resorce_values.find(type)->second;
}

std::vector<std::pair<ResourceType, int>> ResourceManager::get_resource_value_sorted() const
{
    std::vector<std::pair<ResourceType, int>> res_sorted;
    res_sorted.reserve(m_resorce_values.size());

    for(const auto& p: m_resorce_values)
        res_sorted.push_back(p);

    std::sort(res_sorted.begin(), res_sorted.end(), [](const auto& a, const auto& b){ return a.second > b.second; });
    return res_sorted;
}