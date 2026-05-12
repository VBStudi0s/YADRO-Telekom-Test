#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <unordered_map>
#include <string>

enum class ResourceType
{
    IRON,
    GOLD,
    GEMS,
    EXP
};

class ResourceManager
{
    std::unordered_map<std::string, ResourceType> m_str_to_type;
    std::unordered_map<ResourceType, int> m_resorce_values;
public:
    ResourceManager();

    bool is_valid_resource(const std::string& res) const;
    ResourceType str_to_res_type(const std::string& res) const;
    void double_resource_value(ResourceType type);
};

#endif
