cmake_minimum_required(VERSION 3.16)

project(Booking_machine)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    Booking_machine
    ${Booking_machine_SOURCE_DIR}/src/date.cpp
    ${Booking_machine_SOURCE_DIR}/src/booking.cpp
    ${Booking_machine_SOURCE_DIR}/src/booking_machine.cpp
    ${Booking_machine_SOURCE_DIR}/main.cpp
)


target_include_directories(
    Booking_machine
    PRIVATE
    ${Booking_machine_SOURCE_DIR}/headers
)