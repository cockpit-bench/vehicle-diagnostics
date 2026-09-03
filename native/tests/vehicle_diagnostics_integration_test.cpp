
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <fw07/hal/in_memory_port.h>
#include <fw07/middleware/vehicle_diagnostics_service.h>
namespace { class FixedClock final : public cockpit::fw07::Clock { public: std::uint64_t nowMillis() const override { return 42; }; }; }
TEST(VehicleDiagnosticsIntegration, WritesAndReadsThroughBoundary) { cockpit::fw07::InMemoryPort port; FixedClock clock; cockpit::fw07::Service service(port, clock); auto result=service.execute(7,18.5); ASSERT_TRUE(result); EXPECT_EQ(result.value.id,7u); EXPECT_DOUBLE_EQ(result.value.severity,18.5); EXPECT_EQ(result.value.sequence,42u); }
TEST(VehicleDiagnosticsIntegration, RejectsMissingIdentifier) { cockpit::fw07::InMemoryPort port; FixedClock clock; cockpit::fw07::Service service(port, clock); EXPECT_FALSE(service.execute(0,1.0)); }
TEST(VehicleDiagnosticsIntegration, RejectsOutOfRangeValue) { cockpit::fw07::InMemoryPort port; FixedClock clock; cockpit::fw07::Service service(port, clock); EXPECT_FALSE(service.execute(1,100001.0)); }
TEST(VehicleDiagnosticsIntegration, DeliversSubscriptionEvent) { cockpit::fw07::InMemoryPort port; FixedClock clock; cockpit::fw07::Service service(port, clock); std::uint32_t observed=0; service.observe([&](const auto& event){observed=event.id;}); ASSERT_TRUE(service.execute(9,2.0)); EXPECT_EQ(observed,9u); }
TEST(VehicleDiagnosticsIntegration, PreservesSequence) { cockpit::fw07::InMemoryPort port; FixedClock clock; cockpit::fw07::Service service(port, clock); EXPECT_EQ(service.execute(3,4.0).value.sequence,42u); }
