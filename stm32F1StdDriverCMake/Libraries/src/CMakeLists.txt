cmake_minimum_required(VERSION 2.8) 
aux_source_directory(. DIR_LIB_SRC)
add_library(stddriver ${DIR_LIB_SRC})
