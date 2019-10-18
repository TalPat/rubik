cmake_minimum_required(VERSION 3.0)

project(Rubik)
set(CMAKE_CXX_STANDARD 17)

include_directories(
		app/include
)

add_subdirectory(app)