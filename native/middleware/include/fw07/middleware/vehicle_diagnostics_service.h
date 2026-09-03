
#pragma once
#include <fw07/api/vehicle_diagnostics_api.h>
#include <fw07/platform/clock.h>
namespace cockpit::fw07 { class Service final { public: Service(Port& port, const Clock& clock) : port_(port), clock_(clock) {} cockpit::Result<Event> execute(std::uint32_t id, double value); void observe(EventCallback callback); private: Port& port_; const Clock& clock_; }; }
