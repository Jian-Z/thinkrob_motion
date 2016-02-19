/**
 * @file /qlistener/listener.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <sstream>
#include "listener.hpp"
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_srvs/Empty.h>

/*****************************************************************************
** Implementation
*****************************************************************************/
class JointStateHandler
{
public:
    void callback(const sensor_msgs::JointState::ConstPtr& message)
    {
        //ROS_INFO("callback");
        mCrtMsg = *message;
        mNewMsg = true;
    }

    JointStateHandler() : mCrtMsg() , mNewMsg(false)
    {}

    const bool newMsg()
    {
        return mNewMsg;
    }
    const sensor_msgs::JointState& fetchMsg()
    {
        mNewMsg = false;
        return mCrtMsg;
    }
    sensor_msgs::JointState mCrtMsg;
protected:
    bool mNewMsg;
};

class StringMsgsHandler
{
public:
    void callback(const std_msgs::String::ConstPtr& message)
    {
        mCrtMsg = *message;
        mNewMsg = true;
    }
    StringMsgsHandler() : mCrtMsg(), mNewMsg(false)
    {}

    const bool newMsg()
    {
        return mNewMsg;
    }

    const std_msgs::String& fetchMsg()
    {
        mNewMsg = false;
        return mCrtMsg;
    }
    std_msgs::String mCrtMsg;
protected:
    bool mNewMsg;
};

class Int32MsgsHandler
{
public:
    void callback(const std_msgs::Int32::ConstPtr& message)
    {
        mCrtMsg = *message;
        mNewMsg = true;
    }
    Int32MsgsHandler() : mCrtMsg(), mNewMsg(false)
    {}

    const bool newMsg()
    {
        return mNewMsg;
    }

    const std_msgs::Int32& fetchMsg()
    {
        mNewMsg = false;
        return mCrtMsg;
    }
    std_msgs::Int32 mCrtMsg;
protected:
    bool mNewMsg;
};

class Float64MultiArrayMsgsHandler
{
public:
    void callback(const std_msgs::Float64MultiArray::ConstPtr& message)
    {
        mCrtMsg = *message;
        mNewMsg = true;
    }
    Float64MultiArrayMsgsHandler() : mCrtMsg(), mNewMsg(false)
    {}

    const bool newMsg()
    {
        return mNewMsg;
    }

    const std_msgs::Float64MultiArray& fetchMsg()
    {
        mNewMsg = false;
        return mCrtMsg;
    }
    std_msgs::Float64MultiArray mCrtMsg;
protected:
    bool mNewMsg;
};

Listener::Listener(int argc, char** argv ) :
    QNode(argc,argv,"qlistener"),
    param(new Parameter)
{
    param->id = 0;
    //joint limit
    param->joint_min_limit_position.push_back(LIMIT_MIN_POSITION_JOINT_1);
    param->joint_min_limit_position.push_back(LIMIT_MIN_POSITION_JOINT_2);
    param->joint_min_limit_position.push_back(LIMIT_MIN_POSITION_JOINT_3);
    param->joint_min_limit_position.push_back(LIMIT_MIN_POSITION_JOINT_4);
    param->joint_min_limit_position.push_back(LIMIT_MIN_POSITION_JOINT_5);
    param->joint_min_limit_position.push_back(LIMIT_MIN_POSITION_JOINT_6);

    param->joint_max_limit_position.push_back(LIMIT_MAX_POSITION_JOINT_1);
    param->joint_max_limit_position.push_back(LIMIT_MAX_POSITION_JOINT_2);
    param->joint_max_limit_position.push_back(LIMIT_MAX_POSITION_JOINT_3);
    param->joint_max_limit_position.push_back(LIMIT_MAX_POSITION_JOINT_4);
    param->joint_max_limit_position.push_back(LIMIT_MAX_POSITION_JOINT_5);
    param->joint_max_limit_position.push_back(LIMIT_MAX_POSITION_JOINT_6);

    param->joint_states.resize(6);
    param->cartesian_state.resize(6);

    result_value = INITIALIZE;
    mutex = new QMutex();
    isprogrammerrun = false;
}

void Listener::ros_comms_init() {
	ros::NodeHandle n;
    //chatter_subscriber = n.subscribe("chatter", 1000, &Listener::chatterCallback, this);
    jog_cmd_publisher = n.advertise<std_msgs::String>("/coordinator_command", 1000);
    //result = n.subscribe("/thinkrob_motion/result", 1000, &Listener::set_result_status, this);
}

void Listener::chatterCallback(const std_msgs::String::ConstPtr &msg) {
    ROS_INFO("I heard: [%s]", msg->data.c_str());
	logging.insertRows(0,1);
	std::stringstream logging_msg;
	logging_msg << "[ INFO] [" << ros::Time::now() << "]: I heard: " << msg->data;
	QVariant new_row(QString(logging_msg.str().c_str()));
    logging.setData(logging.index(0),new_row);
}

void Listener::run() {
    //ros::spin();
    ros::NodeHandle n;

    ros::Rate rate_cycle(ROS_INTERACTION_CYCLE);

    //six axes data(double type)
    JointStateHandler joint_state_handler;
    Int32MsgsHandler result_msg;
    Float64MultiArrayMsgsHandler cartesian_coordinates_handle;
    //pendant axes sport message
    //StringMsgsHandler joint_sport_handler;

    ros::Subscriber joint_state_sub = n.subscribe("/actual_joint_states", 1000, &JointStateHandler::callback, &joint_state_handler);
    ros::Subscriber result = n.subscribe("/thinkrob_motion/result", 1000, &Int32MsgsHandler::callback, &result_msg);
    ros::Subscriber cartesian_coordinates_sub = n.subscribe("cartesian_coordinate", 1000, &Float64MultiArrayMsgsHandler::callback, &cartesian_coordinates_handle);
    //ros::Subscriber joint_sport_handler = n.subscribe("joint_sport", 2, &StringMsgsHandler::callback, &joint_sport_handler);
    //ros::ok
    while(ros::ok())
    {
        /*Subscribe*/
        ros::spinOnce();
        if(joint_state_handler.newMsg())
        {
            joint_state_handler.fetchMsg();
            for(int i = 0; i < 6; i++)
            {
                param->joint_states[i] = joint_state_handler.mCrtMsg.position[i];
            }
        }
        if(cartesian_coordinates_handle.newMsg())
        {
            cartesian_coordinates_handle.fetchMsg();
            for(int i=0; i<6; ++i)
            {
                param->cartesian_state[i] = cartesian_coordinates_handle.mCrtMsg.data[i];
            }
        }
        mutex->lock();
        if(result_msg.newMsg())
        {
            result_msg.fetchMsg();
            if(isprogrammerrun == true)
            {
                result_process((result_msg.mCrtMsg.data));
            }
        }
        mutex->unlock();
        update_pendant_gui();
        rate_cycle.sleep();
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void Listener::pub_jog_start_command(int cmd) {
    std_msgs::String msg;
    std::stringstream newstr;
    newstr<<cmd;
    msg.data = "<0001> MOVJ_JOG_START {joints} " + newstr.str()
            + " 0.0 0.0 0.0 0.0 0.0 (mm,deg,s) {joints} 0";
    jog_cmd_publisher.publish(msg);
}

void Listener::pub_jog_stop_command(int axes) {
    std_msgs::String msg;
    std::stringstream newstr;
    newstr<<axes;
    msg.data = "<0001> MOVJ_JOG_STOP {joints} " + newstr.str() + "0.0 0.0 0.0 0.0 0.0 0.0 (mm,deg,s) {joints} 0";
    jog_cmd_publisher.publish(msg);
}

void Listener::result_process(int result)
{
    result_value = result;
    //ROS_INFO("get send result flag value: [%d]", result_value);
}

int Listener::get_result_value()
{
    return result_value;
}

void Listener::init_result_value(int result)
{
    result_value = result;
}

QMutex* Listener::get_mutex()
{
    return mutex;
}

void Listener::set_programmer_status(bool status)
{
    isprogrammerrun = status;
}

bool Listener::set_zero_point()
{
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("/thinkrob_slave/setZeroPosition");
    std_srvs::Empty srv;
    return (client.call(srv));
}
