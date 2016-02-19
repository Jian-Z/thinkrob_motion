/**
 * @file /qlistener/listener.hpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef LISTENER_NODE_HPP_
#define LISTENER_NODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "../common/qnode.hpp"
#include "../common/res.hpp"
#endif

#include <std_msgs/String.h>
#include <string>
#include <QMutex>

/*****************************************************************************
** Class
*****************************************************************************/

class Listener : public QNode {
    Q_OBJECT
public:
	Listener(int argc, char** argv);
	virtual ~Listener() {}
    void run();
	void ros_comms_init();
    void pub_jog_start_command(int cmd);
    void pub_jog_stop_command(int axes);
    int get_result_value();
    void init_result_value(int result);
    void set_programmer_status(bool status);
    QMutex* get_mutex();
    bool set_zero_point();

    joint_coordinate_value joint_value[6];
    rectangular_coordinate_value cartesion_value[6];
    Parameter *param;
Q_SIGNALS:
    void update_pendant_gui();
private:
    void chatterCallback(const std_msgs::String::ConstPtr &msg);
    void result_process(int result);
    int result_value;
	ros::Subscriber chatter_subscriber;
    ros::Publisher jog_cmd_publisher;
    bool isprogrammerrun;
    QMutex* mutex;
    //ros::Subscriber result;
};

#endif /* LISTENER_NODE_HPP_ */
