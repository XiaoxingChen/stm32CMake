cmake_minimum_required(VERSION 2.8)
aux_source_directory(. DIR_CMSIS_CM3_SRC)
add_library(cmsis_cm3 ${DIR_CMSIS_CM3_SRC})
