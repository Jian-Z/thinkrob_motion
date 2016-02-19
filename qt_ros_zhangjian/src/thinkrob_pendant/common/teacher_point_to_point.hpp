#ifndef TEACHER_POINT_TO_POINT_H
#define TEACHER_POINT_TO_POINT_H

#include <QDialog>
#include <QtGui/QMainWindow>

#include "common/ui_teacher_point_to_point.h"
#include "res.hpp"
#include <QTextCodec>

//namespace Ui {
//class teacher_point_to_point;
//}

class teacher_point_to_point : public QDialog
{
    Q_OBJECT
    
public:
    explicit teacher_point_to_point(QWidget *parent = 0);
    Ui::teacher_point_to_point get_teach_p2p_ui();
    teacher_point_position* get_teach_point_pos();
    void set_teacher_point_to_point(int row, int cloumn = 0);
    ~teacher_point_to_point();
    joint_coordinate_value* get_teacher_point_to_point_position_point();
    void set_teacher_speed(int speed);
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

private:
    //Ui::teacher_point_to_point *ui;
    Ui::teacher_point_to_point ui;
    teacher_point_position* teach_point_pos;
    int teacher_speed;
    ros::Publisher jog_cmd_publisher;
    joint_coordinate_value joint_value[6];
};

#endif // TEACHER_POINT_TO_POINT_H
