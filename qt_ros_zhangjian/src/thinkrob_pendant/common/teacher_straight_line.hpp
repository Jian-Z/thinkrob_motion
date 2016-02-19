#ifndef TEACHER_STRAIGHT_LINE_H
#define TEACHER_STRAIGHT_LINE_H

#include <QDialog>
#include <QtGui/QMainWindow>
#include "common/ui_teacher_straight_line.h"
#include "res.hpp"
#include <QTextCodec>

namespace Ui {
class Teacher_Straight_Line;
}

class Teacher_Straight_Line : public QDialog
{
    Q_OBJECT
    
public:
    explicit Teacher_Straight_Line(QWidget *parent = 0);
    ~Teacher_Straight_Line();
    Ui::Teacher_Straight_Line get_teach_str_ui();
    teacher_point_position* get_teach_point_pos();
    void set_teacher_point_to_point(int row, int cloumn = 0);
    void set_teacher_speed(int speed);
    joint_coordinate_value* get_teacher_straight_line_position_point();
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

private:
    Ui::Teacher_Straight_Line ui;
    teacher_point_position* teach_point_pos;
    int teacher_speed;
    ros::Publisher jog_cmd_publisher;
    joint_coordinate_value joint_value[6];
};

#endif // TEACHER_STRAIGHT_LINE_H
