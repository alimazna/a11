#pragma once

#include <cstdint>

namespace xauusd::sovereign {

enum class ServiceState : std::uint8_t
{
    STARTING,
    ONLINE,
    DEGRADED,
    OFFLINE,
    RECOVERING,
    PAUSED,
    BLOCKED,
    ERROR
};

}