project(Example_1)
cmake_minimum_required(VERSION 2.8.12)
execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/flatc.exe -c ${CMAKE_CURRENT_BINARY_DIR}/person.fbs) 
set(SOURCES
   "main.cpp"
)
set(HEADERS
   "person_generated.h"
)

add_executable(Example_1 ${HEADERS} ${SOURCES})
set(FLATBUFFERS_SRC_DIR "flatbuffers")
add_subdirectory(${FLATBUFFERS_SRC_DIR}
                 ${CMAKE_CURRENT_BINARY_DIR}/flatbuffers-build)
target_link_libraries(Example_1 PRIVATE flatbuffers)
