#ifndef __INPUT_NUMBER_H__
#define __INPUT_NUMBER_H__

#include <QDialog>
#include "common/ui_input_number.h"
#include "res.hpp"
#include "error_input.hpp"
#include <QTextCodec>
//#include "main_window.hpp"
namespace Ui {
class Input_Number;
}

class Input_Number : public QDialog
{
    Q_OBJECT
    
public:
    explicit Input_Number(QWidget *parent = 0);
    Ui::Input_Number *getUiHandler();
    double value_number();
    bool get_succeed_write_status();
    void set_succeed_write_status(bool);
    void clean_Value_positive_integer_type();
    void clean_Value_any_type();
    void set_input_number_type(int type);
    ~Input_Number();

private Q_SLOTS:
    void on_number_1_pressed();
    void on_number_2_pressed();

    void on_number_3_pressed();

    void on_number_4_pressed();

    void on_number_5_pressed();

    void on_number_6_pressed();

    void on_number_7_pressed();

    void on_number_8_pressed();

    void on_number_9_pressed();

    void on_number_0_pressed();

    void on_decimal_point_pressed();

    void on_clear_pressed();

    void on_reduce_pressed();

    void on_negative_pressed();

    void on_enter_pressed();

private:
    Ui::Input_Number *ui;
    QString value;
    //class point and class object
    Error_input* error_input;
    //teacher_point_position* teach_point_position;
    //MainWindow* ui_mainwindow_object;
    bool succeedwrite;
    int input_number_type;
};

#endif // INPUT_NUMBER_H
