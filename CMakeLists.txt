# CMakeList.txt : CMake project for ReservationApp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ReservationApp")

add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)

# Add source to this project's executable.
add_executable (ReservationApp "ReservationApp.cpp" "ReservationApp.h" "Rental.cpp" "Customer.cpp" "Vehicle.cpp" "Location.cpp")

target_include_directories(ReservationApp PUBLIC "C:\\nana_1.7.4\\nana\\include")
target_link_libraries(ReservationApp "nana_v143_Debug_x64")
target_link_directories(ReservationApp PUBLIC "C:\\nana_1.7.4\\nana\\build\\bin")

# TODO: Add tests and install targets if needed.
