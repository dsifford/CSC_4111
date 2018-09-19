cmake_minimum_required(VERSION 2.8)
 
project(QtTest)

if(APPLE AND EXISTS /usr/local/opt/qt5)
	# Homebrew installs Qt5 (up to at least 5.9.1) in
	# /usr/local/qt5, ensure it can be found by CMake since
	# it is not in the default /usr/local prefix.
	list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt5")
endif()

find_package(Qt5Widgets REQUIRED)

add_definitions(${QT_DEFINITIONS}) 
 
# support for out-of-source build
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR} #this is where ui_SimpleViewUI.h is generated
  ${CMAKE_CURRENT_SOURCE_DIR}
  (${Qt5Widgets_INCLUDE_DIRS})
)
 
# Set your files and resources here
set(SimpleViewSrcs main.cpp qtprogramwin.cpp)
set(SimpleViewUI qtprogramwin.ui)
set(SimpleViewHeaders qtprogramwin.h)
 
qt5_wrap_ui(UISrcs ${SimpleViewUI})
qt5_wrap_cpp(MOCSrcs ${SimpleViewHeaders} )
 
source_group("Resources" FILES
  ${SimpleViewUI}
)
 
source_group("Generated" FILES
  ${UISrcs}
  ${MOCSrcs}
)
add_executable( QtTest ${SimpleViewSrcs} ${UISrcs} ${MOCSrcs} ${SimpleViewHeaders} )
target_link_libraries( QtTest ${Qt5Widgets_LIBRARIES})
