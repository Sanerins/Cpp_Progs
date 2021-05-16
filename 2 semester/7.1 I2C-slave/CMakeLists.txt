cmake_minimum_required(VERSION 3.19)
project(7_1_I2C_slave)

include_directories(/usr/local/systemc233/include)
link_directories(/usr/local/systemc233/include)
include_directories(/usr/local/systemc233/lib-linux64)
link_directories(/usr/local/systemc233/lib-linux64)
link_libraries(systemc.a)

set(CMAKE_CXX_STANDARD 14)

add_executable(7_1_I2C_slave main.cpp I2CSlaveController.cpp I2CSlaveController.h I2CSlaveControllerTest.cpp I2CSlaveControllerTest.h)