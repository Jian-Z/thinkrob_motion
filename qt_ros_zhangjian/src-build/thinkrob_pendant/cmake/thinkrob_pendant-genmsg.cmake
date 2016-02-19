# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "thinkrob_pendant: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(thinkrob_pendant_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(thinkrob_pendant
  "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/thinkrob_pendant/srv/TwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thinkrob_pendant
)

### Generating Module File
_generate_module_cpp(thinkrob_pendant
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thinkrob_pendant
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(thinkrob_pendant_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(thinkrob_pendant_generate_messages thinkrob_pendant_generate_messages_cpp)

# target for backward compatibility
add_custom_target(thinkrob_pendant_gencpp)
add_dependencies(thinkrob_pendant_gencpp thinkrob_pendant_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS thinkrob_pendant_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(thinkrob_pendant
  "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/thinkrob_pendant/srv/TwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thinkrob_pendant
)

### Generating Module File
_generate_module_lisp(thinkrob_pendant
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thinkrob_pendant
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(thinkrob_pendant_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(thinkrob_pendant_generate_messages thinkrob_pendant_generate_messages_lisp)

# target for backward compatibility
add_custom_target(thinkrob_pendant_genlisp)
add_dependencies(thinkrob_pendant_genlisp thinkrob_pendant_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS thinkrob_pendant_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(thinkrob_pendant
  "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/thinkrob_pendant/srv/TwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thinkrob_pendant
)

### Generating Module File
_generate_module_py(thinkrob_pendant
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thinkrob_pendant
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(thinkrob_pendant_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(thinkrob_pendant_generate_messages thinkrob_pendant_generate_messages_py)

# target for backward compatibility
add_custom_target(thinkrob_pendant_genpy)
add_dependencies(thinkrob_pendant_genpy thinkrob_pendant_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS thinkrob_pendant_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thinkrob_pendant)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/thinkrob_pendant
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(thinkrob_pendant_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thinkrob_pendant)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/thinkrob_pendant
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(thinkrob_pendant_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thinkrob_pendant)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thinkrob_pendant\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/thinkrob_pendant
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(thinkrob_pendant_generate_messages_py std_msgs_generate_messages_py)
