set(XCALC_LIB ${PROJECT_NAME})

if(APPLE)
    set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
endif(APPLE)

set(PUBLIC_SOURCES ./public/xcalc.cpp ./public/include/xcalc.h)

add_library(${XCALC_LIB} SHARED ${PUBLIC_SOURCES})
target_include_directories(${XCALC_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public/include)
