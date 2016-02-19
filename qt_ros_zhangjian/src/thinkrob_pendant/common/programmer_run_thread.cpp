/*
**Author:zhangjian
**Date:2016.01.21
*/
#include "programmer_run_thread.hpp"

Programmer_Run_Thread::Programmer_Run_Thread(Listener* listener, QTableWidget* table)
{
    list = listener;
    command_content = "";
    isRun = false;
    semaphore = false;
    table_widget = table;
    setTerminationEnabled();
    //QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
}

Programmer_Run_Thread::~Programmer_Run_Thread()
{

}

void Programmer_Run_Thread::run()
{
    QString start_programmer = "程序开始";
    QString end_programmer = "结束";
    QString goto_instruction = "转到行";
    QString wait_instruction = "等待毫秒";
    QString joint_sport_instruction = "点位运动 J, 速度=%";
    QString straight_sport_instruction = "直线运动 J, 速度=毫米/秒";
    QString circle_sport_instruction = "圆弧运动 J, J, 速度=毫米/秒";
    QString null_instruction = "";
    int wait_time_ms;
    int point_row;
    ros::NodeHandle n;
    jog_cmd_publisher = n.advertise<std_msgs::String>("/coordinator_command", 1000);
    std_msgs::String msg;
    std::stringstream newstr;
    std::stringstream speed;
    bool istimeout = false;
    bool issendmsg = false;
    while(isRun)
    {
        if(semaphore == true)
        {
            semaphore = false;
            QString command_remove_number = command_content.split(QRegExp("\\d+")).join("");
            if(command_remove_number.operator ==(start_programmer))
            {
                ++command_execute_row;
                get_command_execute_row(command_execute_row);
            }else if(command_remove_number.operator ==(end_programmer))
            {
                isRun = false;
                ++command_execute_row;
                get_command_execute_row(command_execute_row);
            }else if(command_remove_number.operator ==(goto_instruction))
            {
                command_execute_row = command_content.section(QRegExp("\\D+"), 1, 1).toInt();
                get_command_execute_row(command_execute_row);
            }else if(command_remove_number.operator ==(wait_instruction))
            {
                wait_time_ms = command_content.section(QRegExp("\\D+"), 1, 1).toInt();
                //msleep(wait_time_ms);
                //++command_execute_row;
                //get_command_execute_row(command_execute_row);
                mutex.lock();
                istimeout = wait_condition.wait(&mutex, wait_time_ms);
                if(!istimeout)
                {
                    ++command_execute_row;
                    get_command_execute_row(command_execute_row);
                }
                mutex.unlock();
            }else if(command_remove_number.operator ==(joint_sport_instruction))
            {
                list->get_mutex()->lock();
                if(issendmsg == false)
                {
                    issendmsg = true;
                    msg.data = "";
                    speed.str("");
                    newstr.str("");
                    point_row = command_content.section(QRegExp("\\D+"), 1, 1).toInt();
                    for(int i=0; i<6; i++)
                    {
                        newstr<<table_widget->item(point_row, i+2)->text().toDouble()<<' ';
                    }
                    speed<<command_content.section(QRegExp("\\D+"), 2, 2).toInt();
                    msg.data = "<0001> MOVJ {joints} " + newstr.str()
                            + "(mm,deg,s) {joints} " + speed.str();
                    jog_cmd_publisher.publish(msg);
                    //ROS_INFO("send MOVJ message");
                    semaphore = true;
                }else
                {
                    if(list->get_result_value() == INITIALIZE)//not receive message
                    {
                        semaphore = true;
                        //ROS_INFO("MOVJ wait ros message [%d]", list->get_result_value());
                    }else if(list->get_result_value() == ABNORMAL)//receive a error message
                    {
                        //ROS_INFO("MOVJ receive a error message: [%d]", list->get_result_value());
                        list->init_result_value(INITIALIZE);
                        programmer_run_error_type(PROGRAMMER_NOT_ARRIVE);
                        issendmsg = false;
                    }else if(list->get_result_value() == NORMAL)//receive a true message, programmer run
                    {
                        //ROS_INFO("MOVJ receive a true message: [%d]", list->get_result_value());
                        list->init_result_value(INITIALIZE);
                        ++command_execute_row;
                        get_command_execute_row(command_execute_row);
                        issendmsg = false;
                    }
                }
                list->get_mutex()->unlock();
            }else if(command_remove_number.operator ==(straight_sport_instruction))
            {
                //get_command_execute_row(command_execute_row);
                list->get_mutex()->lock();
                if(issendmsg == false)
                {
                    issendmsg = true;
                    msg.data = "";
                    speed.str("");
                    newstr.str("");
                    point_row = command_content.section(QRegExp("\\D+"), 1, 1).toInt();
                    for(int i=0; i<6; i++)
                    {
                        newstr<<table_widget->item(point_row, i+2)->text().toDouble()<<' ';
                    }
                    speed<<command_content.section(QRegExp("\\D+"), 2, 2).toInt();
                    msg.data = "<0001> MOVL {joints} " + newstr.str()
                            + "(mm,deg,s) {joints} " + speed.str();
                    jog_cmd_publisher.publish(msg);
                    //ROS_INFO("send MOVJ message");
                    semaphore = true;
                }else
                {
                    if(list->get_result_value() == INITIALIZE)//not receive message
                    {
                        semaphore = true;
                        //ROS_INFO("MOVJ wait ros message [%d]", list->get_result_value());
                    }else if(list->get_result_value() == ABNORMAL)//receive a error message
                    {
                        //ROS_INFO("MOVJ receive a error message: [%d]", list->get_result_value());
                        list->init_result_value(INITIALIZE);
                        programmer_run_error_type(PROGRAMMER_NOT_ARRIVE);
                        issendmsg = false;
                    }else if(list->get_result_value() == NORMAL)//receive a true message, programmer run
                    {
                        //ROS_INFO("MOVJ receive a true message: [%d]", list->get_result_value());
                        list->init_result_value(INITIALIZE);
                        ++command_execute_row;
                        get_command_execute_row(command_execute_row);
                        issendmsg = false;
                    }
                }
                list->get_mutex()->unlock();
            }else if(command_remove_number.operator ==(circle_sport_instruction))
            {
                get_command_execute_row(command_execute_row);
            }else if(command_remove_number.operator ==(null_instruction))
            {
                ++command_execute_row;
                get_command_execute_row(command_execute_row);
            }
        }
    }
    isRun = false;
}

void Programmer_Run_Thread::set_command_content(QString command)
{
    command_content = command;
}

void Programmer_Run_Thread::set_programmer_run_status(bool status)
{
    isRun = status;
}

void Programmer_Run_Thread::set_command_execute_row(int row)
{
    command_execute_row = row;
}

void Programmer_Run_Thread::set_signal(bool status)
{
    semaphore = status;
}

QWaitCondition* Programmer_Run_Thread::get_wait_condition()
{
    return &wait_condition;
}
