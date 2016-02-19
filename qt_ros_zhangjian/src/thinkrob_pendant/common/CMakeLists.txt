##############################################################################
# Sections
##############################################################################

set(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/images.qrc)
set(QT_FORMS ${CMAKE_CURRENT_SOURCE_DIR}/../ui/main_window.ui)
set(QT_TEACH_P2P ${CMAKE_CURRENT_SOURCE_DIR}/../ui/teacher_point_to_point.ui)
set(QT_TEACH_STR ${CMAKE_CURRENT_SOURCE_DIR}/../ui/teacher_straight_line.ui)
set(QT_INPUT_NUMBER ${CMAKE_CURRENT_SOURCE_DIR}/../ui/input_number.ui)
set(QT_ERROR_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/../ui/error_input.ui)
set(QT_DELETE_SELETE_POINT ${CMAKE_CURRENT_SOURCE_DIR}/../ui/delete_select_point.ui)
set(QT_MODIFY_POINT_POSITION ${CMAKE_CURRENT_SOURCE_DIR}/../ui/modify_point_position.ui)
set(QT_COMMON_FUNCTION ${CMAKE_CURRENT_SOURCE_DIR}/../ui/common_function.ui)
set(QT_SPORT_INSTRUCTION ${CMAKE_CURRENT_SOURCE_DIR}/../ui/sport_instruction.ui)
set(QT_COMMON_DIALOG ${CMAKE_CURRENT_SOURCE_DIR}/../ui/commondialog.ui)
set(QT_WAIT_TIME ${CMAKE_CURRENT_SOURCE_DIR}/../ui/wait_time.ui)
set(QT_PROGRAMMER_DESIGN_GOTO_INSTRUCTION ${CMAKE_CURRENT_SOURCE_DIR}/../ui/programmer_design_goto_instruction.ui)
set(QT_SPORT_INSTRUCTION_WINDOW ${CMAKE_CURRENT_SOURCE_DIR}/../ui/sport_instruction_window.ui)
set(QT_VIRTUALKEYBOARD ${CMAKE_CURRENT_SOURCE_DIR}/../ui/virtualkeyboard.ui)

file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS *.hpp)
#file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/delect_select_point.hpp)
#file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/../ui/delete_select_point.ui)

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP  ${QT_FORMS} ${QT_TEACH_P2P} ${QT_TEACH_STR} ${QT_INPUT_NUMBER} ${QT_ERROR_INPUT} ${QT_DELETE_SELETE_POINT}
${QT_MODIFY_POINT_POSITION} ${QT_COMMON_FUNCTION} ${QT_SPORT_INSTRUCTION} ${QT_COMMON_DIALOG} ${QT_WAIT_TIME} ${QT_PROGRAMMER_DESIGN_GOTO_INSTRUCTION}
${QT_SPORT_INSTRUCTION_WINDOW} ${QT_VIRTUALKEYBOARD})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS *.cpp)

##############################################################################
# Binaries
##############################################################################

add_library(qtutorials ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(qtutorials ${QT_LIBRARIES})
target_link_libraries(qtutorials ${catkin_LIBRARIES})
install(TARGETS qtutorials 
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
