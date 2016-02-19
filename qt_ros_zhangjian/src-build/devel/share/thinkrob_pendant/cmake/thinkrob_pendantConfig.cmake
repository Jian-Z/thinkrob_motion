# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^debug|optimized|general$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(thinkrob_pendant_CONFIG_INCLUDED)
  return()
endif()
set(thinkrob_pendant_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
  set(thinkrob_pendant_SOURCE_PREFIX /home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/thinkrob_pendant)
  set(thinkrob_pendant_DEVEL_PREFIX /home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/devel)
  set(thinkrob_pendant_INSTALL_PREFIX "")
  set(thinkrob_pendant_PREFIX ${thinkrob_pendant_DEVEL_PREFIX})
else()
  set(thinkrob_pendant_SOURCE_PREFIX "")
  set(thinkrob_pendant_DEVEL_PREFIX "")
  set(thinkrob_pendant_INSTALL_PREFIX /usr/local)
  set(thinkrob_pendant_PREFIX ${thinkrob_pendant_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'thinkrob_pendant' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(thinkrob_pendant_FOUND_CATKIN_PROJECT TRUE)

if(NOT "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/devel/include" STREQUAL "")
  set(thinkrob_pendant_INCLUDE_DIRS "")
  set(_include_dirs "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/devel/include")
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir}" STREQUAL "include")
      get_filename_component(include "${thinkrob_pendant_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'thinkrob_pendant' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  Ask the maintainer 'Daniel Stonier <d.stonier@gmail.com>' to fix it.")
      endif()
    else()
      message(FATAL_ERROR "Project 'thinkrob_pendant' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/thinkrob_pendant/${idir}'.  Ask the maintainer 'Daniel Stonier <d.stonier@gmail.com>' to fix it.")
    endif()
    _list_append_unique(thinkrob_pendant_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^debug|optimized|general$")
    list(APPEND thinkrob_pendant_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND thinkrob_pendant_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND thinkrob_pendant_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/devel/lib;/opt/ros/hydro/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(thinkrob_pendant_LIBRARY_DIRS ${lib_path})
      list(APPEND thinkrob_pendant_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'thinkrob_pendant'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND thinkrob_pendant_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(thinkrob_pendant_EXPORTED_TARGETS "thinkrob_pendant_generate_messages_cpp;thinkrob_pendant_generate_messages_lisp;thinkrob_pendant_generate_messages_py")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${thinkrob_pendant_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "message_runtime;std_msgs;roscpp")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 thinkrob_pendant_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${thinkrob_pendant_dep}_FOUND)
      find_package(${thinkrob_pendant_dep} REQUIRED)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${thinkrob_pendant_dep} REQUIRED ${depend_list})
  endif()
  _list_append_unique(thinkrob_pendant_INCLUDE_DIRS ${${thinkrob_pendant_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(thinkrob_pendant_LIBRARIES ${thinkrob_pendant_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${thinkrob_pendant_dep}_LIBRARIES})
  _list_append_deduplicate(thinkrob_pendant_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(thinkrob_pendant_LIBRARIES ${thinkrob_pendant_LIBRARIES})

  _list_append_unique(thinkrob_pendant_LIBRARY_DIRS ${${thinkrob_pendant_dep}_LIBRARY_DIRS})
  list(APPEND thinkrob_pendant_EXPORTED_TARGETS ${${thinkrob_pendant_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "thinkrob_pendant-msg-extras.cmake")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${thinkrob_pendant_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
