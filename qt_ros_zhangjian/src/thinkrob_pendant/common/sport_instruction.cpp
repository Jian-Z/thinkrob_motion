#include "sport_instruction.hpp"


Sport_Instruction::Sport_Instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sport_Instruction)
{
    ui->setupUi(this);
    sport_instruction_window = new Sport_Instruction_Window();
    joint_sport_isSucceed = false;
    straight_sport_isSucceed = false;
    circle_sport_isSucceed = false;
    first_point_value = 0;
    second_point_value = 0;
    speed_value = 0;
    max_point = 0;
}

Sport_Instruction::~Sport_Instruction()
{
    delete ui;
}

Ui::Sport_Instruction* Sport_Instruction::get_sport_instruction_ui()
{
    return ui;
}

void Sport_Instruction::set_joint_sport_status(bool status)
{
    joint_sport_isSucceed = status;
}

bool Sport_Instruction::get_joint_sport_status()
{
    return joint_sport_isSucceed;
}

void Sport_Instruction::set_straight_sport_status(bool status)
{
    straight_sport_isSucceed = status;
}

bool Sport_Instruction::get_straight_sport_status()
{
    return straight_sport_isSucceed;
}

void Sport_Instruction::set_circle_sport_status(bool status)
{
    circle_sport_isSucceed = status;
}

bool Sport_Instruction::get_circle_sport_status()
{
    return circle_sport_isSucceed;
}

void Sport_Instruction::on_joint_sport_button_pressed()
{
    sport_instruction_window->sport_instruction_window_display_type(JOINT_SPORT);
    sport_instruction_window->set_max_point(max_point);
    sport_instruction_window->setWindowFlags(Qt::WindowStaysOnTopHint);
    sport_instruction_window->setModal(false);
    sport_instruction_window->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
    sport_instruction_window->exec();
    if(sport_instruction_window->get_joint_succeed_status())
    {
        sport_instruction_window->set_joint_succeed_status(false);
        first_point_value = sport_instruction_window->get_first_point_value();
        //second_point_value = sport_instruction_window->get_second_point_value();
        speed_value = sport_instruction_window->get_speed_value();
        joint_sport_isSucceed = true;
        sport_instruction_window->init_sport_window_value_edittext(0, 0, 0);
        this->close();
    }
}

void Sport_Instruction::on_exit_button_pressed()
{
    this->close();
}

void Sport_Instruction::on_straight_sport_button_pressed()
{
    sport_instruction_window->sport_instruction_window_display_type(STRAIGHT_SPORT);
    sport_instruction_window->set_max_point(max_point);
    sport_instruction_window->setWindowFlags(Qt::WindowStaysOnTopHint);
    sport_instruction_window->setModal(false);
    sport_instruction_window->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
    sport_instruction_window->exec();
    if(sport_instruction_window->get_straight_succeed_status())
    {
        sport_instruction_window->set_straight_succeed_status(false);
        first_point_value = sport_instruction_window->get_first_point_value();
        //second_point_value = sport_instruction_window->get_second_point_value();
        speed_value = sport_instruction_window->get_speed_value();
        straight_sport_isSucceed = true;
        sport_instruction_window->init_sport_window_value_edittext(0, 0, 0);
        this->close();
    }
}

void Sport_Instruction::on_circular_sport_button_pressed()
{
    sport_instruction_window->sport_instruction_window_display_type(CIRCLE_SPORT);
    sport_instruction_window->set_max_point(max_point);
    sport_instruction_window->setWindowFlags(Qt::WindowStaysOnTopHint);
    sport_instruction_window->setModal(false);
    sport_instruction_window->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
    sport_instruction_window->exec();
    if(sport_instruction_window->get_circle_succeed_status())
    {
        sport_instruction_window->set_circle_succeed_status(false);
        first_point_value = sport_instruction_window->get_first_point_value();
        //second_point_value = sport_instruction_window->get_second_point_value();
        speed_value = sport_instruction_window->get_speed_value();
        circle_sport_isSucceed = true;
        sport_instruction_window->init_sport_window_value_edittext(0, 0, 0);
        this->close();
    }
}

void Sport_Instruction::set_max_point(int point_count)
{
    max_point = point_count;
}

double Sport_Instruction::get_first_point_value()
{
    return first_point_value;
}

double Sport_Instruction::get_second_point_value()
{
    return second_point_value;
}

double Sport_Instruction::get_speed_value()
{
    return speed_value;
}
