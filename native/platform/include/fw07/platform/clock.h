
#pragma once
#include <cstdint>
namespace cockpit::fw07 { class Clock { public: virtual ~Clock() = default; virtual std::uint64_t nowMillis() const = 0; }; class SteadyClock final : public Clock { public: std::uint64_t nowMillis() const override; }; }
