cmake_minimum_required(VERSION 2.8)

add_executable(main.elf main.cpp delay.c stm32f10x_it.c)
target_link_libraries(main.elf cmsis_sys stddriver cmsis_cm3)
add_bin_from_elf(main.bin main.elf)

