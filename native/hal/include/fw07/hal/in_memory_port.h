
#pragma once
#include <mutex>
#include <unordered_map>
#include <fw07/api/vehicle_diagnostics_api.h>
namespace cockpit::fw07 { class InMemoryPort final : public Port { public: cockpit::Result<Event> transact(const Request&) override; void subscribe(EventCallback) override; private: std::mutex mutex_; std::unordered_map<std::uint32_t,double> values_; EventCallback callback_; }; }
