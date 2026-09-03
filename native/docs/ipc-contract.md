
# Vehicle Diagnostics IPC contract v2.1.0

`vehicle_diagnostics.proto` is the canonical interface. Request fields are `id`, `severity`, and monotonic `sequence`; responses add `error_code`. Error 2 means invalid identifier and error 3 means range rejection. Clients send `Transact` and receive the matching event. Minor releases only add optional fields; breaking field or semantic changes require a new major package. The integration test demonstrates request, error, sequence, and callback behavior.
