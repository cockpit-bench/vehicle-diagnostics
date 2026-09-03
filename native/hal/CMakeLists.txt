add_library(fw07_hal src/in_memory_port.cpp)
target_include_directories(fw07_hal PUBLIC include)
target_link_libraries(fw07_hal PUBLIC fw07_contract)
