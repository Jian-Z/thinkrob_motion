#include "error_input.hpp"

Error_input::Error_input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error_input)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Error_input::~Error_input()
{
    delete ui;
}

void Error_input::on_pushButton_pressed()
{

    this->close();
}
