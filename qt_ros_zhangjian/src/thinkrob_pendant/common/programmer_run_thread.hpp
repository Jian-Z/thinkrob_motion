/*
**Author:zhangjian
**Date:2016.01.21
*/
#ifndef __PROGRAMMER_RUN_THREAD_HPP__
#define __PROGRAMMER_RUN_THREAD_HPP__

#include <QThread>
#include "../thinkrob_pendant/listener.hpp"
#include "res.hpp"
#include "QTableWidget"
#include <QMutex>
#include <QWaitCondition>

class Programmer_Run_Thread : public QThread {
    Q_OBJECT
public:
    Programmer_Run_Thread(Listener* listener, QTableWidget* table);
    ~Programmer_Run_Thread();
    void run();
    void set_command_content(QString command);
    void set_command_execute_row(int row);
    void set_programmer_run_status(bool status);
    void set_signal(bool status);
    QWaitCondition* get_wait_condition();

Q_SIGNALS:
    void get_command_execute_row(int execute_row);
    void programmer_run_error_type(int error_type);

private:
    Listener* list;
    QString command_content;
    bool isRun;
    int command_execute_row;
    bool semaphore;
    joint_coordinate_value joint_value[6];
    QTableWidget* table_widget;
    ros::Publisher jog_cmd_publisher;
    QWaitCondition wait_condition;
    QMutex mutex;
    QMutex* common_mutex;
};

//file end programmer_run_thread
#endif
