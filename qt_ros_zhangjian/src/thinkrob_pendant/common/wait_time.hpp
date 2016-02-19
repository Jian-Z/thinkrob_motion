#ifndef WAIT_TIME_HPP
#define WAIT_TIME_HPP

#include <QDialog>
#include "common/ui_wait_time.h"
#include "input_number.hpp"
#include "res.hpp"
#include <QTextCodec>

namespace Ui {
class Wait_Time;
}

class Wait_Time : public QDialog
{
    Q_OBJECT
    
public:
    explicit Wait_Time(QWidget *parent = 0);
    ~Wait_Time();
    bool get_wait_time_dialog_status();
    void set_wait_time_dialog_status(bool status);
    double get_wait_time_value();
    void set_wait_time_value(double value);
    Ui::Wait_Time* get_wait_time_ui();
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

    void on_wait_time_value_selectionChanged();

private:
    Ui::Wait_Time *ui;
    bool isSucceed;
    Input_Number* input_number;
    double wait_time_ms;
    bool isopendialog;
};

#endif // WAIT_TIME_HPP
