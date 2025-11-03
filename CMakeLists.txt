cmake_minimum_required(VERSION 3.16)
project(Project2TopGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2 -pthread")

# Bridges source folder
set(BRIDGES_SRC_DIR bridges-cxx/src)

# Grab all Bridges .cpp files
file(GLOB BRIDGES_SRCS "${BRIDGES_SRC_DIR}/*.cpp" "${BRIDGES_SRC_DIR}/data_src/*.cpp"
)



# Your project files
set(SOURCES
        main.cpp
        HeapSort.cpp
        heap_test.cpp
        Menu.cpp
        MenuManager.cpp
        mergeSort.cpp
        ${BRIDGES_SRCS}
)

# Include dirs for Bridges + rapidjson
include_directories(
        ${BRIDGES_SRC_DIR}
        ${BRIDGES_SRC_DIR}/data_src
        /opt/homebrew/include
)

link_directories(/opt/homebrew/lib)

# Build executable
add_executable(main ${SOURCES})
target_link_libraries(main curl jsoncpp ssl crypto)

# read_ign target (same sources)
add_executable(read_ign ${SOURCES})
target_link_libraries(read_ign curl jsoncpp ssl crypto)
