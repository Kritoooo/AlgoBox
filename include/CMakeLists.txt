# Assuming we're using the STL module across the project
add_library(StlModule)
target_sources(StlModule
    PUBLIC
    FILE_SET CXX_MODULES TYPE CXX_MODULES FILES
    stl.cppm
)