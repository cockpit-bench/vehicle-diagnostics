
#include <fw07/platform/clock.h>
#include <chrono>
std::uint64_t cockpit::fw07::SteadyClock::nowMillis() const { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count(); }
