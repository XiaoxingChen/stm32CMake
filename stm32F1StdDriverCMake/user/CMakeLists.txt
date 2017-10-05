cmake_minimum_required(VERSION 2.8)

add_executable(main.elf main.c)
add_bin_from_elf(main.bin main.elf)
