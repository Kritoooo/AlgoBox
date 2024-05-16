add_executable(SegmentTreeExample SegmentTreeExample.cpp)
set_target_properties(SegmentTreeExample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
target_link_libraries(SegmentTreeExample PUBLIC SegmentTreeModule StlModule)