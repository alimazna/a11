#pragma once

#include "DataQualityState.h"
#include "Timestamp.h"
#include "ValidationOutcome.h"

#include <string>
#include <utility>

namespace xauusd::sovereign {

struct DataValidationResult {
    ValidationOutcome  outcome;
    DataQualityState   quality;
    std::string        reason;
    Timestamp          observed_at;

    DataValidationResult() = default;

    DataValidationResult(ValidationOutcome outcome,
                         DataQualityState quality,
                         std::string reason,
                         Timestamp observed_at)
        : outcome(outcome), quality(quality),
          reason(std::move(reason)), observed_at(observed_at) {}
};

} // namespace xauusd::sovereign
