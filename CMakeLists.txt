cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( include ${OpenCV_INCLUDE_DIRS} )

file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})
target_link_libraries( main ${OpenCV_LIBS} )
