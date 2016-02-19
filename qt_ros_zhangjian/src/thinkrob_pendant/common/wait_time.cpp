#include "wait_time.hpp"
#include <QTextCodec>

Wait_Time::Wait_Time(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wait_Time)
{
    ui->setupUi(this);
    isSucceed = false;
    input_number = new Input_Number();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QString note;
    note = "等待移动时间再运行下一行程序，范围（" + QString::number(MIN_WAIT_TIME) + "-" + QString::number(MAX_WAIT_TIME) + "）毫秒";
    ui->note->setText(note);
    wait_time_ms = 0;
    isopendialog = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Wait_Time::~Wait_Time()
{
    delete ui;
    delete input_number;
}

bool Wait_Time::get_wait_time_dialog_status()
{
    return isSucceed;
}

void Wait_Time::set_wait_time_dialog_status(bool status)
{
    isSucceed = status;
}

void Wait_Time::on_cancel_button_pressed()
{
    isSucceed = false;
    this->close();
}

void Wait_Time::on_ok_button_pressed()
{
    isSucceed = true;
    this->close();
}

double Wait_Time::get_wait_time_value()
{
    return wait_time_ms;
}

void Wait_Time::on_wait_time_value_selectionChanged()
{
    if(false == isopendialog)
    {
        //input_number->getUiHandler()->negative->setEnabled(false);
        //input_number->getUiHandler()->decimal_point->setEnabled(false);
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->getUiHandler()->min_value->setText(QString::number(MIN_WAIT_TIME));
        input_number->getUiHandler()->max_value->setText(QString::number(MAX_WAIT_TIME));
        input_number->getUiHandler()->textEdit->setText("");
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X + 100, WAIT_TIME_DIALOG_Y + 100);
        isopendialog = true;
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            input_number->set_succeed_write_status(false);
            ui->wait_time_value->setText(QString::number(input_number->value_number()));
            wait_time_ms =  input_number->value_number();
        }
        //input_number->clean_Value_positive_integer_type();
        isopendialog = false;
    }
}

Ui::Wait_Time* Wait_Time::get_wait_time_ui()
{
    return ui;
}

void Wait_Time::set_wait_time_value(double value)
{
    wait_time_ms = value;
}
