#include "commondialog.hpp"

CommonDialog::CommonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommonDialog)
{
    ui->setupUi(this);
    isSucceed = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

CommonDialog::~CommonDialog()
{
    delete ui;
}

void CommonDialog::on_cancel_button_pressed()
{
    isSucceed = false;
    this->close();
}

void CommonDialog::on_ok_button_pressed()
{
    isSucceed = true;
    this->close();
}

bool CommonDialog::get_common_dialog_succeed_status()
{
    return isSucceed;
}

void CommonDialog::set_common_dialog_succeed_status(bool status)
{
    isSucceed = status;
}

Ui::CommonDialog* CommonDialog::get_common_dialog_ui()
{
    return ui;
}
