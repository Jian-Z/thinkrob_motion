#include "modify_point_position.hpp"

Modify_Point_Position::Modify_Point_Position(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify_Point_Position)
{
    ui->setupUi(this);
    isSucceed = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Modify_Point_Position::~Modify_Point_Position()
{
    delete ui;
}

void Modify_Point_Position::on_cancel_button_pressed()
{
    this->close();
}

void Modify_Point_Position::on_ok_button_pressed()
{
    isSucceed = true;
    this->close();
}

bool Modify_Point_Position::get_succeed_status()
{
    return isSucceed;
}

void Modify_Point_Position::set_succeed_status(bool status)
{
    isSucceed = status;
}

Ui::Modify_Point_Position* Modify_Point_Position::get_modify_point_position_dialog_ui_point()
{
    return ui;
}
