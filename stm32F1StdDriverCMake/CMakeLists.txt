cmake_minimum_required(VERSION 2.8)

project(stm32F1StdDriverCMake)

IF(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Cross compiling only, Please use -DCMAKE_TOOLCHAIN_FILE=/PATH/TO/TOOLCHAIN_FILE.")
ENDIF(NOT CMAKE_CROSSCOMPILING)

#add_definitions(-DSTM32F1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -mcpu=cortex-m3 -mthumb -nostartfiles")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ../../stm32_flash.ld -nostartfiles --specs=rdimon.specs")

function(add_bin_from_elf bin elf)
    add_custom_target(${bin} ALL ${CMAKE_OBJCOPY} -Obinary ${elf} ${bin} DEPENDS ${elf})
endfunction(add_bin_from_elf)

set(SRC_LIST "")
include_directories(Libraries/inc)
include_directories(Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10X)
add_subdirectory(Libraries)
add_subdirectory(user)
add_subdirectory(Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10X)

#add_executable(main.elf ${SRC_LIST})
message(STATUS "src_list: " ${SRC_LIST})
#add_bin_from_elf(main.bin main.elf)

