#ifndef IBOT_HPP
#define IBOT_HPP

#include <memory>

#include "actions/IAction.hpp"

class IBot
{
public:
    virtual std::unique_ptr<IAction> act() = 0;
    virtual ~IBot() = default;
};

#endif