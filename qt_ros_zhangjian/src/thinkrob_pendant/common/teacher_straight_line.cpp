#include "teacher_straight_line.hpp"


Teacher_Straight_Line::Teacher_Straight_Line(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    teach_point_pos = new teacher_point_position;
    ui.diaplay_value->setText(QString::number(teach_point_pos->row));
    teacher_speed = 0;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Teacher_Straight_Line::~Teacher_Straight_Line()
{
    //delete teacher_point_position;
    //delete ui;
}

void Teacher_Straight_Line::on_cancel_button_pressed()
{
    this->close();
}

void Teacher_Straight_Line::set_teacher_point_to_point(int row, int cloumn)
{
    teach_point_pos->row = row;
    teach_point_pos->cloumn = cloumn;
}

void Teacher_Straight_Line::on_ok_button_pressed()
{
    ros::NodeHandle n;
    jog_cmd_publisher = n.advertise<std_msgs::String>("/coordinator_command", 1000);
    std_msgs::String msg;
    std::stringstream newstr;
    std::stringstream speed;
    for(int i=0; i<6; i++)
    {
        newstr<<joint_value[i]<<' ';
    }
    speed<<teacher_speed;
    msg.data = "<0001> MOVL_JOG_START {joints} " + newstr.str()
            + "(mm,deg,s) {joints} " + speed.str();
    jog_cmd_publisher.publish(msg);
    this->close();
}

void Teacher_Straight_Line::set_teacher_speed(int speed)
{
    teacher_speed = speed;
}

joint_coordinate_value* Teacher_Straight_Line::get_teacher_straight_line_position_point()
{
    return joint_value;
}

Ui::Teacher_Straight_Line Teacher_Straight_Line::get_teach_str_ui()
{
    return ui;
}
