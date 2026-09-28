#pragma once
#include "EntityId.h"
#include "ServiceState.h"
#include "FreshnessState.h"
#include "Timestamp.h"
#include "Version.h"
namespace xauusd::sovereign {
struct HealthSnapshot {
    EntityId service_id{};
    ServiceState service_state{};
    FreshnessState freshness{};
    Timestamp observed_at{};
    Version policy_version{};
    HealthSnapshot() = default;
    HealthSnapshot(const EntityId& id, ServiceState state, FreshnessState freshness_state,
                   const Timestamp& observed, const Version& policy)
        : service_id(id), service_state(state), freshness(freshness_state),
          observed_at(observed), policy_version(policy) {}
};
}
