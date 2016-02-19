#include "delete_select_point.hpp"

Delete_Select_Point::Delete_Select_Point(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_Select_Point)
{
    ui->setupUi(this);
    isSucceed = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Delete_Select_Point::~Delete_Select_Point()
{
    delete ui;
}

void Delete_Select_Point::on_cancel_button_pressed()
{
    isSucceed = false;
    this->close();
}

void Delete_Select_Point::on_ok_button_pressed()
{
    isSucceed = true;
    this->close();
}

void Delete_Select_Point::set_succeed_status(bool succeed_status)
{
    isSucceed = succeed_status;
}

bool Delete_Select_Point::get_succeed_status()
{
    return isSucceed;
}
