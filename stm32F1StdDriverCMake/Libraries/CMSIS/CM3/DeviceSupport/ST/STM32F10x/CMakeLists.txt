cmake_minimum_required(VERSION 2.8)
aux_source_directory(. DIR_CMSIS_SYS_SRC)
add_library(cmsis_sys ${DIR_CMSIS_SYS_SRC})