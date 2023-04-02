cmake_minimum_required(VERSION 3.9)

project(ilerp
        LANGUAGES C
        VERSION 1.0
        DESCRIPTION "Integer based interpolation for non-floating point calculations"
)

set_target_properties(ilerp PROPERTIES
        VERSION ${PROJECT_VERSION}
        PUBLIC_HEADER ilerp.h
)

target_include_directories(ilerp PRIVATE .)
