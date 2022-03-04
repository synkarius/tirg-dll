add_compile_definitions(TIRG_VERSION="${TIRG_VERSION}" MYAPP_NAME="${MYAPP_NAME}")
                        
set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES
        dllmain.cpp 
        stdafx.cpp
        tirg_raw.cpp
    )

set(HEADERS_FILES
        stdafx.h 
        targetver.h
        trg.hpp
    )

source_group("Headers" FILES ${HEADERS_FILES}) 
source_group("Sources" FILES ${SRC_FILES})

add_library(TIRG_DLL SHARED ${SRC_FILES})

math(EXPR BITS "8*${CMAKE_SIZEOF_VOID_P}")
set_target_properties(TIRG_DLL PROPERTIES
        PREFIX ""
        SUFFIX "-${BITS}.dll"
        LINKER_LANGUAGE C)


set_property(TARGET TIRG_DLL PROPERTY OUTPUT_NAME "tirg")
target_compile_definitions(TIRG_DLL PRIVATE -Wall)

