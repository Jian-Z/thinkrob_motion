#include "sport_instruction_window.hpp"


Sport_Instruction_Window::Sport_Instruction_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sport_Instruction_Window)
{
    ui->setupUi(this);
    window_display_type = 0;
    input_number = new Input_Number();
    first_point_value = 0;
    second_point_value = 0;
    isopendialog = false;
    speed_value = 0;
    jointisSucceed = false;
    straightisSucceed = false;
    circleisSucceed = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Sport_Instruction_Window::~Sport_Instruction_Window()
{
    delete input_number;
    delete ui;
}

void Sport_Instruction_Window::sport_instruction_window_display_type(int type)
{
    window_display_type = type;
    if(window_display_type == JOINT_SPORT)
    {
        QString sport_name, speed, unit, notes;
        sport_name = "点位运动 J";
        speed = ", 速度=";
        unit = "%";
        notes = "点对点运动到指定点位置";
        ui->sport_name_label->setText(sport_name);
        ui->sport_speed_label->setText(speed);
        ui->sport_unit->setText(unit);
        ui->sport_instruction_note->setText(notes);
        ui->first_point_textEdit->setText("0");
        ui->third_point_textEdit->setText("0");
        ui->sport_second_point_label->hide();
        ui->second_point_textEdit->hide();
    }else if(window_display_type == STRAIGHT_SPORT)
    {
        QString sport_name, speed, unit, notes;
        sport_name = "直线运动 J";
        speed = ", 速度=";
        unit = "毫米/秒";
        notes = "以指定速度直线运动到指定位置";
        ui->sport_name_label->setText(sport_name);
        ui->sport_speed_label->setText(speed);
        ui->sport_unit->setText(unit);
        ui->sport_instruction_note->setText(notes);
        ui->first_point_textEdit->setText("0");
        ui->third_point_textEdit->setText("0");
        ui->sport_second_point_label->hide();
        ui->second_point_textEdit->hide();
    }else if(window_display_type == CIRCLE_SPORT)
    {
        QString sport_name, speed, unit, notes, second_joint;
        sport_name = "圆弧运动 J";
        speed = ", VL=";
        second_joint = ", J";
        unit = "mm/s";
        notes = "从当前位置经过第一点，到达第二点走圆弧，\n如果VL=0,则运动速度等于系统最大速度*SPEED\n指令速率*程序运行速率；如果VL>0,则运动速度\n等于VL速度*程序运行速率";
        ui->sport_second_point_label->setVisible(true);
        ui->second_point_textEdit->setVisible(true);
        ui->sport_name_label->setText(sport_name);
        ui->sport_speed_label->setText(speed);
        ui->sport_unit->setText(unit);
        ui->sport_instruction_note->setText(notes);
        ui->sport_second_point_label->setText(second_joint);
        ui->first_point_textEdit->setText("0");
        ui->second_point_textEdit->setText("0");
        ui->third_point_textEdit->setText("0");
    }
}

void Sport_Instruction_Window::set_max_point(int point_count)
{
    max_point = point_count;
}

void Sport_Instruction_Window::on_first_point_textEdit_selectionChanged()
{
    if(isopendialog == false)
    {
        input_number->getUiHandler()->min_value->setText(QString::number(0));
        input_number->getUiHandler()->max_value->setText(QString::number(max_point));
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        isopendialog = true;
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            input_number->set_succeed_write_status(false);
            ui->first_point_textEdit->setText(QString::number(input_number->value_number()));
            first_point_value = input_number->value_number();
        }
        isopendialog = false;
    }

}

void Sport_Instruction_Window::on_second_point_textEdit_selectionChanged()
{
    if(isopendialog == false)
    {
        input_number->getUiHandler()->min_value->setText(QString::number(0));
        input_number->getUiHandler()->max_value->setText(QString::number(max_point));
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        isopendialog = true;
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            input_number->set_succeed_write_status(false);
            ui->second_point_textEdit->setText(QString::number(input_number->value_number()));
            second_point_value = input_number->value_number();
        }
        isopendialog = false;
    }
}

void Sport_Instruction_Window::on_third_point_textEdit_selectionChanged()
{
    if(isopendialog == false)
    {
        input_number->getUiHandler()->min_value->setText(QString::number(0));
        if(window_display_type == JOINT_SPORT)
        {
            input_number->getUiHandler()->max_value->setText(QString::number(100));
        }else
        {
            input_number->getUiHandler()->max_value->setText(QString::number(CIRCLE_MAX_SPEED));
        }
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        isopendialog = true;
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            input_number->set_succeed_write_status(false);
            ui->third_point_textEdit->setText(QString::number(input_number->value_number()));
            speed_value = input_number->value_number();
        }
        isopendialog = false;
    }
}

void Sport_Instruction_Window::set_joint_succeed_status(bool status)
{
    jointisSucceed = status;
}

bool Sport_Instruction_Window::get_joint_succeed_status()
{
    return jointisSucceed;
}

void Sport_Instruction_Window::set_straight_succeed_status(bool status)
{
    straightisSucceed = status;
}

bool Sport_Instruction_Window::get_straight_succeed_status()
{
    return straightisSucceed;
}

void Sport_Instruction_Window::set_circle_succeed_status(bool status)
{
    circleisSucceed = status;
}

bool Sport_Instruction_Window::get_circle_succeed_status()
{
    return circleisSucceed;
}

void Sport_Instruction_Window::on_cancel_button_pressed()
{
    jointisSucceed = false;
    straightisSucceed = false;
    circleisSucceed = false;
    window_display_type = 0;
    this->close();
}

void Sport_Instruction_Window::on_ok_button_pressed()
{
    if(window_display_type == JOINT_SPORT)
    {
        jointisSucceed = true;
        straightisSucceed = false;
        circleisSucceed = false;
        window_display_type = 0;
        this->close();
    }else if(window_display_type == STRAIGHT_SPORT)
    {
        jointisSucceed = false;
        straightisSucceed = true;
        circleisSucceed = false;
        window_display_type = 0;
        this->close();
    }else if(window_display_type == CIRCLE_SPORT)
    {
        jointisSucceed = false;
        straightisSucceed = false;
        circleisSucceed = true;
        window_display_type = 0;
        this->close();
    }else
    {
        ROS_INFO("sport dialog display error!!!");
    }
}

double Sport_Instruction_Window::get_first_point_value()
{
    return first_point_value;
}

double Sport_Instruction_Window::get_second_point_value()
{
    return second_point_value;
}

double Sport_Instruction_Window::get_speed_value()
{
    return speed_value;
}

void Sport_Instruction_Window::init_sport_window_value_edittext(double first_point_init, double second_point_init, double speed_point_init)
{
    first_point_value = first_point_init;
    second_point_value = second_point_init;
    speed_value = speed_point_init;
}
