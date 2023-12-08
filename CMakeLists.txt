cmake_minimum_required(VERSION 3.26)
project(Eksamensopgaver)

set(CMAKE_CXX_STANDARD 17)

configure_file(Fodboldturnering/kampe-2023-2024.txt Fodboldturnering/kampe-2023-2024.txt COPYONLY)

add_executable(${PROJECT_NAME} Fodboldturnering/main.c)
