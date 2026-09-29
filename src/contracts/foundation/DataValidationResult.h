#pragma once

#include "DataQualityState.h"
#include "ValidationOutcome.h"
#include "Timestamp.h"

#include <string>
#include <utility>

namespace xauusd::sovereign {

struct DataValidationResult
{
    ValidationOutcome outcome{};
    DataQualityState quality{};
    std::string reason{};
    Timestamp observed_at{};

    DataValidationResult() = default;

    DataValidationResult(
        ValidationOutcome outcome_value,
        DataQualityState quality_value,
        std::string reason_value,
        Timestamp timestamp)
        :
        outcome(outcome_value),
        quality(quality_value),
        reason(std::move(reason_value)),
        observed_at(timestamp)
    {}
};

}