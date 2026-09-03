
#include <fw07/hal/in_memory_port.h>
namespace cockpit::fw07 {
cockpit::Result<Event> InMemoryPort::transact(const Request& request) { std::lock_guard<std::mutex> lock(mutex_); if (request.id == 0) return {Event{}, 2, "invalid id"}; values_[request.id] = request.severity; Event event{request.id, request.severity, request.sequence}; if (callback_) callback_(event); return {event, 0, {}}; }
void InMemoryPort::subscribe(EventCallback callback) { std::lock_guard<std::mutex> lock(mutex_); callback_ = std::move(callback); }
}
