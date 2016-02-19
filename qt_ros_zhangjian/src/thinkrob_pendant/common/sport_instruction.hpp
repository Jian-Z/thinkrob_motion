/*
**Date:2016-01-19 15:35
**Author:zhangjian
*/
#ifndef SPORT_INSTRUCTION_HPP
#define SPORT_INSTRUCTION_HPP

#include <QDialog>
#include "common/ui_sport_instruction.h"
#include "sport_instruction_window.hpp"
namespace Ui {
class Sport_Instruction;
}

class Sport_Instruction : public QDialog
{
    Q_OBJECT
    
public:
    explicit Sport_Instruction(QWidget *parent = 0);
    ~Sport_Instruction();
    Ui::Sport_Instruction* get_sport_instruction_ui();

    void set_joint_sport_status(bool status);
    bool get_joint_sport_status();

    void set_straight_sport_status(bool status);
    bool get_straight_sport_status();
    
    void set_circle_sport_status(bool status);
    bool get_circle_sport_status();

    void set_max_point(int point_count);

    double get_first_point_value();

    double get_second_point_value();

    double get_speed_value();

private Q_SLOTS:
    void on_joint_sport_button_pressed();

    void on_exit_button_pressed();

    void on_straight_sport_button_pressed();

    void on_circular_sport_button_pressed();

private:
    Ui::Sport_Instruction *ui;
    Sport_Instruction_Window* sport_instruction_window;
    bool joint_sport_isSucceed;
    bool straight_sport_isSucceed;
    bool circle_sport_isSucceed;
    double first_point_value;
    double second_point_value;
    double speed_value;
    int max_point;
};

#endif // SPORT_INSTRUCTION_HPP
