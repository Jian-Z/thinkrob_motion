execute_process(COMMAND "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/qt_create/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/qt_create/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
