#include "SignalEngine.h"
#include "EngineIdentity.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <variant>
namespace xauusd::sovereign {
namespace{
bool eligible(const EligibilityResult&e,StrategyFamily f){return std::find(e.eligible_families.begin(),e.eligible_families.end(),f)!=e.eligible_families.end();}
double getd(const FeatureSnapshot&s,const char*n){auto it=s.features.find(FeatureKey{n});if(it==s.features.end())return std::numeric_limits<double>::quiet_NaN();if(auto p=std::get_if<double>(&it->second.storage()))return *p;return std::numeric_limits<double>::quiet_NaN();}
}
Signal SignalEngine::generate(const EligibilityResult&e,const RegimeSnapshot&r,const StructureSnapshot&s,const FeatureSnapshot&f){
 Signal out; out.trigger_timeframe=f.timeframe;out.triggered_at=f.computed_at;out.strategy=StrategyFamily::NONE;out.direction=SignalDirection::NONE;
 const double close=getd(f,"close"),fast=getd(f,"ema_fast"),slow=getd(f,"ema_slow"),slope=getd(f,"ema_slope"),atr=getd(f,"atr");
 if(!std::isfinite(close)||!std::isfinite(fast)||!std::isfinite(slow)||!std::isfinite(slope)||!std::isfinite(atr)||atr<=0)return out;
 const bool tc=eligible(e,StrategyFamily::TREND_CONTINUATION);
 if(tc && r.regime==RegimeType::TREND_UP && s.is_bullish && slope>0 && close>slow && std::abs(close-fast)<=0.75*atr && s.last_swing_low>0 && close>s.last_swing_low){
   out.direction=SignalDirection::LONG;out.strategy=StrategyFamily::TREND_CONTINUATION;out.entry_reference=close;out.invalidating_price=s.last_swing_low;out.rationale="trend continuation long";
 } else if(tc && r.regime==RegimeType::TREND_DOWN && !s.is_bullish && slope<0 && close<slow && std::abs(close-fast)<=0.75*atr && s.last_swing_high>0 && close<s.last_swing_high){
   out.direction=SignalDirection::SHORT;out.strategy=StrategyFamily::TREND_CONTINUATION;out.entry_reference=close;out.invalidating_price=s.last_swing_high;out.rationale="trend continuation short";
 }
 if(out.direction!=SignalDirection::NONE){
   out.decision_id=detail::make_id("decision",static_cast<std::uint64_t>(out.triggered_at.value()),static_cast<std::uint64_t>(out.trigger_timeframe),static_cast<std::uint64_t>(out.strategy));
   out.signal_id=detail::make_id("signal",static_cast<std::uint64_t>(out.triggered_at.value()),static_cast<std::uint64_t>(out.trigger_timeframe),static_cast<std::uint64_t>(out.direction),static_cast<std::uint64_t>(out.strategy));
 }
 return out;
}
}
