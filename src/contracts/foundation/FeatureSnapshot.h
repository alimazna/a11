#pragma once
#include "EntityId.h"
#include "FeatureKey.h"
#include "FeatureValue.h"
#include "Timestamp.h"
#include "Timeframe.h"
#include "DataQualityState.h"
#include <map>
#include <utility>
namespace xauusd::sovereign {
struct FeatureSnapshot {
 EntityId snapshot_id{};EntityId source_bar_id{};Timeframe timeframe{Timeframe::M1};Timestamp computed_at{};DataQualityState data_quality{DataQualityState::UNKNOWN};std::map<FeatureKey,FeatureValue> features;
 FeatureSnapshot()=default;
 FeatureSnapshot(EntityId a,EntityId b,Timeframe t,Timestamp c,std::map<FeatureKey,FeatureValue> f):snapshot_id(a),source_bar_id(b),timeframe(t),computed_at(c),features(std::move(f)){}
};
}
