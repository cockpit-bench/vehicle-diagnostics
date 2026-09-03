
#include <fw07/middleware/vehicle_diagnostics_service.h>
namespace cockpit::fw07 { cockpit::Result<Event> Service::execute(std::uint32_t id, double value) { if (value < -100000.0 || value > 100000.0) return {Event{}, 3, "out of range"}; return port_.transact(Request{id, value, clock_.nowMillis()}); } void Service::observe(EventCallback callback) { port_.subscribe(std::move(callback)); } }
