cmake_minimum_required(VERSION 3.24)
project(proxy)

set(CMAKE_CXX_STANDARD 17)

add_executable(proxy main.cpp Proxy.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/Utilites/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/Utilites/SFML/include)
target_link_libraries(proxy sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
