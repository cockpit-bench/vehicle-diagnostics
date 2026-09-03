
#pragma once
#include <cstdint>
#include <functional>
#include <string>
#include <fw07/common/result.h>
#define FW07_API_VERSION_MAJOR 2
#define FW07_API_VERSION_MINOR 1
#define FW07_API_VERSION_PATCH 0
#if FW07_API_VERSION_MAJOR < 2
#error "Unsupported Vehicle Diagnostics API"
#endif
namespace cockpit::fw07 {
struct Request { std::uint32_t id{0}; double severity{0.0}; std::uint64_t sequence{0}; };
struct Event { std::uint32_t id{0}; double severity{0.0}; std::uint64_t sequence{0}; };
using EventCallback = std::function<void(const Event&)>;
class Port { public: virtual ~Port() = default; virtual cockpit::Result<Event> transact(const Request&) = 0; virtual void subscribe(EventCallback) = 0; };
}
