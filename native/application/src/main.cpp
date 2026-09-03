
#include <fw07/hal/in_memory_port.h>
#include <fw07/middleware/vehicle_diagnostics_service.h>
#include <fw07/platform/clock.h>
int main() { cockpit::fw07::InMemoryPort port; cockpit::fw07::SteadyClock clock; cockpit::fw07::Service service(port, clock); return service.execute(1, 1.0) ? 0 : 1; }
