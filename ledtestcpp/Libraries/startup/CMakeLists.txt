cmake_minimum_required(VERSION 2.8) 
aux_source_directory(. DIR_LIB_START)
add_library(stdstart ${DIR_LIB_START})
set_target_properties(stdstart PROPERTIES LINKER_LANGUAGE ASM)
