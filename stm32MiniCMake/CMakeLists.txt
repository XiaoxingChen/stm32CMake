cmake_minimum_required(VERSION 2.8)

project(stm32MiniCMake)

IF(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Cross compiling only, Please use -DCMAKE_TOOLCHAIN_FILE=/PATH/TO/TOOLCHAIN_FILE.")
ENDIF(NOT CMAKE_CROSSCOMPILING)
#add_definitions(-DSTM32F1)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -mcpu=cortex-m3 -mthumb -nostartfiles")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ./stm32-linux.ld -nostartfiles --specs=rdimon.specs")

function(add_bin_from_elf bin elf)
    add_custom_target(${bin} ALL ${CMAKE_OBJCOPY} -Obinary ${elf} ${bin} DEPENDS ${elf})
endfunction(add_bin_from_elf)

add_executable(main.elf main.c)
add_bin_from_elf(main.bin main.elf)

