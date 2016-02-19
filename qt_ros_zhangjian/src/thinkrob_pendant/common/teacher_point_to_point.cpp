#include "teacher_point_to_point.hpp"


teacher_point_to_point::teacher_point_to_point(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    teach_point_pos = new teacher_point_position;
    ui.point_value->setText(QString::number(teach_point_pos->row));
    teacher_speed = 0;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

teacher_point_to_point::~teacher_point_to_point()
{
    //delete teacher_point_position;
    //delete ui;
}

void teacher_point_to_point::on_cancel_button_pressed()
{
    this->close();
}

Ui::teacher_point_to_point teacher_point_to_point::get_teach_p2p_ui()
{
    return ui;
}

teacher_point_position* teacher_point_to_point::get_teach_point_pos()
{
    return teach_point_pos;
}

void teacher_point_to_point::set_teacher_point_to_point(int row, int cloumn)
{
    teach_point_pos->row = row;
    teach_point_pos->cloumn = cloumn;
}

void teacher_point_to_point::on_ok_button_pressed()
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
    msg.data = "<0001> MOVJ {joints} " + newstr.str()
            + "(mm,deg,s) {joints} " + speed.str();
    jog_cmd_publisher.publish(msg);
    this->close();
}

void teacher_point_to_point::set_teacher_speed(int speed)
{
    teacher_speed = speed;
}

joint_coordinate_value* teacher_point_to_point::get_teacher_point_to_point_position_point()
{
    return joint_value;
}
