cmake_minimum_required(VERSION 3.13)
project(objInfo)

set(DLL_VERSION 0.1.0)

set(SOURCE_FILES
    src/objInfo.cpp
)

set(CMAKE_CXX_STANDARD 17)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
if (_cpp_latest_flag_supported)
	add_compile_options("/std:c++latest")
endif()

set(PLUGIN_SUFFIX ".dll")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ${PLUGIN_SUFFIX})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ../SubtoolUpdater_2022 LIBRARY DESTINATION ../SubtoolUpdater_2022)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
