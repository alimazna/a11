#pragma once

#include <cstdint>

namespace xauusd::sovereign {

enum class FreshnessState : std::uint8_t
{
    FRESH,
    AGING,
    STALE,
    MISSING,
    UNKNOWN
};

}