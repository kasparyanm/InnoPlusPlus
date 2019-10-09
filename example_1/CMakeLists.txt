project(Example_1)
cmake_minimum_required(VERSION 2.8.12)
set(SOURCES
   "main.cpp"
)

add_executable(Example_1 ${HEADERS} ${SOURCES})
set(FLATBUFFERS_SRC_DIR "flatbuffers")
add_subdirectory(${FLATBUFFERS_SRC_DIR}
                 ${CMAKE_CURRENT_BINARY_DIR}/flatbuffers-build
                 EXCLUDE_FROM_ALL)
target_link_libraries(Example_1 PRIVATE flatbuffers)
