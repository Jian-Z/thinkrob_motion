#ifndef SPORT_INSTRUCTION_WINDOW_HPP
#define SPORT_INSTRUCTION_WINDOW_HPP

#include <QDialog>
#include "common/ui_sport_instruction_window.h"
#include "res.hpp"
#include "input_number.hpp"

namespace Ui {
class Sport_Instruction_Window;
}

class Sport_Instruction_Window : public QDialog
{
    Q_OBJECT
    
public:
    explicit Sport_Instruction_Window(QWidget *parent = 0);
    ~Sport_Instruction_Window();

    void sport_instruction_window_display_type(int type);

    void set_max_point(int point_count);

    void set_joint_succeed_status(bool status);

    bool get_joint_succeed_status();

    void set_straight_succeed_status(bool status);

    bool get_straight_succeed_status();

    void set_circle_succeed_status(bool status);

    bool get_circle_succeed_status();

    double get_first_point_value();

    double get_second_point_value();

    double get_speed_value();

    void init_sport_window_value_edittext(double first_point_init, double second_point_init, double speed_point_init);
    
private Q_SLOTS:
    void on_first_point_textEdit_selectionChanged();

    void on_second_point_textEdit_selectionChanged();

    void on_third_point_textEdit_selectionChanged();

    void on_cancel_button_pressed();

    void on_ok_button_pressed();

private:
    Ui::Sport_Instruction_Window *ui;
    Input_Number* input_number;
    int window_display_type;
    int max_point;
    double first_point_value;
    bool isopendialog;
    double second_point_value;
    double speed_value;
    bool jointisSucceed;
    bool straightisSucceed;
    bool circleisSucceed;
};

#endif // SPORT_INSTRUCTION_WINDOW_HPP
