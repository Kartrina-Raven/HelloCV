cmake_minimum_required(VERSION 3.22.1)

project(TrafficLight)

find_package(OpenCV REQUIRED)

add_executable(TrafficLight task.cpp)

target_link_libraries(TrafficLight ${OpenCV_LIBS})