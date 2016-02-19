/*
**Author: zhangjian
**date: 2016-01-13
*/
#ifndef __RES_HPP__
#define __RES_HPP__

//C++ Includes
#include <vector>
#include <iostream>
#include <string>
#include <list>

//#ifndef Q_MOC_RUN

//ROS includes.
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_listener.h>
#include <tf/LinearMath/Matrix3x3.h>

//Boost includes.
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

//#endif //Q_MOC_RUN

//axes motion range
#define LIMIT_MIN_POSITION_JOINT_1          (-170.000)
#define LIMIT_MIN_POSITION_JOINT_2          (-135.000)
#define LIMIT_MIN_POSITION_JOINT_3          (-60)
#define LIMIT_MIN_POSITION_JOINT_4          (-180)
#define LIMIT_MIN_POSITION_JOINT_5          (-145)
#define LIMIT_MIN_POSITION_JOINT_6          (-360)
#define LIMIT_MIN_POSITION_JOINT_2_AND_3    (-135)

#define LIMIT_MAX_POSITION_JOINT_1          (170)
#define LIMIT_MAX_POSITION_JOINT_2          (80)
#define LIMIT_MAX_POSITION_JOINT_3          (55)
#define LIMIT_MAX_POSITION_JOINT_4          (180)
#define LIMIT_MAX_POSITION_JOINT_5          (145)
#define LIMIT_MAX_POSITION_JOINT_6          (360)
#define LIMIT_MAX_POSITION_JOINT_2_AND_3    (135)

//define PI value and tansform angle
#define PI                                  (3.141592653589793238462643383279)
#define TRANSFORM_ANGLE                     (180/PI)

//teacher speed range
#define MIN_SPEED                           (0)
#define MAX_SPEED                           (100)
//define wait time range
#define MIN_WAIT_TIME                       (0)
#define MAX_WAIT_TIME                       (18000000)
//define window total size
#define WINDOW_WIDTH                        (1024)
#define WINDOW_LENGTH                       (768)
//define window display postion
#define FRAME_ORIGIN_X                      (0)
#define FRAME_ORIGIN_Y                      (0)
//the total width if the window is not defined, so the total width of the modified window is not vaild.
#define MAIN_WINDOW_CENTER_X                (WINDOW_WIDTH/2)
//the total length if the window is not defined, so the total length of the modified window is not vaild.
#define MAIN_WINDOW_CENTER_Y                (WINDOW_LENGTH/2)
//main window diaplay frameless redefine origin position
#define FRAMELESS_ORIGIN_X                  (0)
#define FRAMELESS_ORIGIN_Y                  (55)
//define window origin
#define WINDOW_ORIGIN_X                     (0)
#define WINDOW_ORIGIN_Y                     (0)
//define wait time dialog display position
#define WAIT_TIME_DIALOG_X                  (200)
#define WAIT_TIME_DIALOG_Y                  (100)
//define display window center
#define WINDOW_CENTER_X                     (400)
#define WINDOW_CENTER_Y                     (200)

//define input number dialog input value type
#define POSITIVE_INTEGER                    (1)

#define ANY_NUMBER                          (32)

//define sport instructions display window type. eg:joint, straight, circle sport.
#define JOINT_SPORT                         (1)
#define STRAIGHT_SPORT                      (2)
#define CIRCLE_SPORT                        (4)

//define programmer run status
#define READY_PROGRAMMER                    (1)
#define RUN_PROGRAMMER                      (2)
#define PAUSE_PROGRAMMER                    (3)
#define STOP_PROGRAMMER                     (4)

//define circle sport max speed. unit mm/s
#define CIRCLE_MAX_SPEED                    (3000)

//define max programmer design row
#define MAX_PROGRAMMER_ROW                  (1000)
#define MAX_PROGRAMMER_COLUMN               (2)
#define MAX_POINT_ROW                       (1000)
#define MAX_POINT_COLUMN                    (8)
#define INIT_PROGRAMMER_ROW_COUNT           (2)
//ros interaction cycle
#define ROS_INTERACTION_CYCLE               (10)

//define receive ros message result value
#define NORMAL                              (0)
#define ABNORMAL                            (1)
#define INITIALIZE                          (7)

//define programmer running error type
#define INITIALIZE_PROGRAMMER_RUN_ERROR     (0)
#define PROGRAMMER_NOT_ARRIVE               (1)

//define user login status
#define NO_LOGIN                            (1)
#define ADMINISTRATORS_LOGIN                (2)
#define SYSTEM_LOGIN                        (3)

//define new file version no
#define OPERATOR_SYSTEM                     (1)
#define USER_NOT_SELECT_PATH                (2)



//joint coordinate value type is double
typedef double joint_coordinate_value;
//rectangular coordinate value type is double
typedef double rectangular_coordinate_value;
//robot rotation angle
//typedef double
struct Parameter
{
    //workspace space
    std::vector<joint_coordinate_value> joint_min_limit_position;
    std::vector<joint_coordinate_value> joint_max_limit_position;

    //robot states
    std::vector<joint_coordinate_value> joint_states;
    std::vector<rectangular_coordinate_value> cartesian_state;

    //command id
    int id;

};
//modify teacher point position information value
struct teacher_point_position
{
    int row;
    int cloumn;
};

//teacher_point_position* teach_point_pos = new teacher_point_position;
/*class teacher_point_position
{
    //Q_OBJECT
public:
    //teacher_point_position* get_teacher_point();
    static teacher_point_position* Instantialize();
    static teacher_point_position* pInstance;
    int get_Column();
    int get_Row();
    void set_Column(int value);
    void set_Row(int value);
    ~teacher_point_position();
private:
    //teacher_point_position* teach_point_pos;
    int column;
    int row;
    explicit teacher_point_position();
};*/
//RES_HPP
#endif
