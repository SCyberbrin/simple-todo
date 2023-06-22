cmake_minimum_required(VERSION 3.0.0)
project(simple-todo)

file(GLOB_RECURSE SRC
     "src/**.h"
     "src/**.cpp"
)

add_executable(simple-todo ${SRC})

