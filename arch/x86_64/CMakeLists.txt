PROJECT(MiuraArchX86_64)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_language(C ASM)

file(GLOB_RECURSE CPU_SOURCES
    ${PROJECT_SOURCE_DIR}/src/miura/cpu/*.cpp       
    ${PROJECT_SOURCE_DIR}/src/miura/cpu/*.s       
)
add_library(${PROJECT_NAME}_cpu STATIC
    ${CPU_SOURCES}
)
add_executable(miura.elf    
    ${PROJECT_SOURCE_DIR}/src/miura/boot.cpp    
    ${PROJECT_SOURCE_DIR}/src/miura/serial.cpp    
)

target_compile_options(miura.elf
  PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -ffreestanding -mno-sse>
  )
target_link_libraries(miura.elf 
    ${PROJECT_NAME}_cpu 
    MiuraLibK
    MiuraKernel)
target_include_directories(miura.elf PUBLIC ${PROJECT_SOURCE_DIR}/include)
set_target_properties(miura.elf 
    PROPERTIES
    LINK_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld -ffreestanding -nostdlib -lgcc  -z max-page-size=0x1000"
)
