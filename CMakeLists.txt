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

add_message_files(
   FILES
   Shape.msg
)

add_service_files(
   FILES
   AreaData.srv
)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )

catkin_package(
  INCLUDE_DIRS include/${PROJECT_NAME}/
  LIBRARIES ${PROJECT_NAME}
  #DEPENDS
)

include_directories(include/${PROJECT_NAME}/ ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})
include_directories(src/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(${CMAKE_INSTALL_PREFIX}/include) # this line is to find lemon include files.

set(area_SOURCES
	src/CreateArea.cpp
        src/SendArea.cpp
)

add_library(${PROJECT_NAME} SHARED ${area_SOURCES})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} lemon)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_gencpp base_math lemon)

add_executable(${PROJECT_NAME}_node ${area_SOURCES})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES} base_math lemon)
add_dependencies(${PROJECT_NAME}_node ${PROJECT_NAME}_gencpp base_math lemon)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
         EXPORT ${PROJECT_NAME}
         ARCHIVE DESTINATION "${CATKIN_PACKAGE_BIN_DESTINATION}" COMPONENT lib
         RUNTIME DESTINATION "${CATKIN_PACKAGE_BIN_DESTINATION}" COMPONENT bin
         LIBRARY DESTINATION "${CATKIN_PACKAGE_LIB_DESTINATION}" COMPONENT shlib
)
