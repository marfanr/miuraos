PROJECT(MiuraKernel)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE KERNEL_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp       
)
add_library(${PROJECT_NAME} STATIC
    ${KERNEL_SOURCES}
)
target_link_libraries(${PROJECT_NAME} PUBLIC MiuraLibK)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

