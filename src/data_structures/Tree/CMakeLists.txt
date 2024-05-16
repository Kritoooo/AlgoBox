add_library(SegmentTreeModule)
target_sources(SegmentTreeModule
    PUBLIC
    FILE_SET CXX_MODULES TYPE CXX_MODULES FILES
    SegmentTree.cppm
)
target_sources(SegmentTreeModule
    PUBLIC
    SegmentTree.cpp
)

target_link_libraries(SegmentTreeModule
    PUBLIC
    StlModule
)