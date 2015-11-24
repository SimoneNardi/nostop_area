cmake_minimum_required(VERSION 2.8.3)
project(nostop_area)

ENABLE_LANGUAGE(CXX)

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(catkin REQUIRED COMPONENTS
  base_math
  message_generation
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include/${PROJECT_NAME}/
  LIBRARIES ${PROJECT_NAME}
  #DEPENDS
)

include_directories(include/${PROJECT_NAME}/ ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

set(area_SOURCES
        src/SendArea.cpp
        
)

add_executable(Analysis ${area_SOURCES})
target_link_libraries(Analysis ${catkin_LIBRARIES})
add_dependencies(Analysis ${PROJECT_NAME}_gencpp)

install(TARGETS Analysis
 EXPORT nostop_analysis
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )
