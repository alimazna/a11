#pragma once

#include <cstdint>

namespace xauusd::sovereign {

enum class ValidationOutcome : std::uint8_t {
    ACCEPTED,
    REJECTED,
    QUARANTINED,
    PARTIAL,
    UNKNOWN
};

} // namespace xauusd::sovereign
