#include "input_number.hpp"

Input_Number::Input_Number(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Number),
    value(""),
    error_input(new Error_input),
    //teach_point_position(new teacher_point_position),
    succeedwrite(false)
    //ui_mainwindow_object(new MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText(value);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Input_Number::~Input_Number()
{
    delete error_input;
    delete ui;
}

Ui::Input_Number * Input_Number::getUiHandler()
{
    return ui;
}

void Input_Number::on_number_1_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '1';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_2_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '2';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_3_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '3';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_4_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '4';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_5_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '5';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_6_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '6';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_7_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '7';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_8_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '8';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_9_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 1) && (value.operator [](0) == '0'))
    {
        value.remove(0,1);
    }else if((value.length() == 2) && ((value.operator [](0) == '-') && (value.operator [](1) == '0')))
    {
        value.remove(1,1);
    }
    value = value + '9';
    ui->textEdit->setText(value);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_number_0_pressed()
{
    value = ui->textEdit->toPlainText();
    if(value.operator [](0) == '0')
    {
        ui->number_0->setEnabled(false);
    }else if((value.operator [](0) == '-') && (value.operator [](1) == '0'))
    {
        ui->number_0->setEnabled(false);
    }else
    {
        value = value + '0';
        ui->textEdit->setText(value);
    }
}

void Input_Number::on_decimal_point_pressed()
{
    value = ui->textEdit->toPlainText();
    if((value.length() == 0) || ((value.length() == 1) && (value.operator [](0) == '-')))
    {
        value.push_back('0');
    }
    value.push_back('.');
    ui->textEdit->setText(value);
    ui->decimal_point->setEnabled(false);
    ui->number_0->setEnabled(true);
}

void Input_Number::on_clear_pressed()
{
    value = ui->textEdit->toPlainText();
    if(input_number_type == POSITIVE_INTEGER)
    {
        clean_Value_positive_integer_type();
    }else if(input_number_type == ANY_NUMBER)
    {
        clean_Value_any_type();
    }
}

void Input_Number::on_reduce_pressed()
{
    value = ui->textEdit->toPlainText();
    if(input_number_type == POSITIVE_INTEGER)
    {
        value.remove(value.length() - 1, 1);
        ui->textEdit->setText(value);
    }else if(input_number_type == ANY_NUMBER)
    {
        if(value.operator [](value.length() - 1) == '.')
        {
            ui->decimal_point->setEnabled(true);
        }
        value.remove(value.length() - 1, 1);

        ui->textEdit->setText(value);
    }
}

void Input_Number::on_negative_pressed()
{
    value = ui->textEdit->toPlainText();
    if(value.operator [](0) == '-')
    {
        value.remove(0, 1);
    }else
    {
        value.push_front('-');
    }
    ui->textEdit->setText(value);
}

void Input_Number::on_enter_pressed()
{

    //int row = 0, column = 0;
    bool ok;
    value = ui->textEdit->toPlainText();
    double get_value = value.toDouble(&ok);
    if(ok == true)
    {
        if((get_value > (ui->max_value->text().toDouble())) || (get_value < (ui->min_value->text().toDouble())))
        {
            //data out of range
            error_input->setWindowFlags(Qt::WindowStaysOnTopHint);
            error_input->setModal(false);
            error_input->move(WAIT_TIME_DIALOG_X + 100, WAIT_TIME_DIALOG_Y + 100);
            error_input->exec();
            if(input_number_type == POSITIVE_INTEGER)
            {
                clean_Value_positive_integer_type();
            }else if(input_number_type == ANY_NUMBER)
            {
                clean_Value_any_type();
            };
        }else
        {
            //row = teach_point_position->row;
            //column = teach_point_position->column;
            //ui_mainwindow_object->get_Ui_MainWindowDesign().teacher_point_tableWidget->setItem(row, column, new QTableWidgetItem(value));
            succeedwrite = true;
            this->close();
        }
    }else
    {
        /*if(!(ui->textEdit->toPlainText().length()))
        {
            error_input->setWindowFlags(Qt::WindowStaysOnTopHint);
            error_input->setModal(false);
            error_input->move(WAIT_TIME_DIALOG_X + 100, WAIT_TIME_DIALOG_Y + 100);
            error_input->exec();
            if(input_number_type == POSITIVE_INTEGER)
            {
                clean_Value_positive_integer_type();
            }else if(input_number_type == ANY_NUMBER)
            {
                clean_Value_any_type();
            }
        }*/
        error_input->setWindowFlags(Qt::WindowStaysOnTopHint);
        error_input->setModal(false);
        error_input->move(WAIT_TIME_DIALOG_X + 100, WAIT_TIME_DIALOG_Y + 100);
        error_input->exec();
        if(input_number_type == POSITIVE_INTEGER)
        {
            clean_Value_positive_integer_type();
        }else if(input_number_type == ANY_NUMBER)
        {
            clean_Value_any_type();
        }
        ROS_WARN("input value conversion error!");
    }
}

double Input_Number::value_number()
{
    return (value.toDouble());
}

bool Input_Number::get_succeed_write_status()
{
    return succeedwrite;
}

void Input_Number::set_succeed_write_status(bool status)
{
    succeedwrite = status;
}

void Input_Number::clean_Value_any_type()
{
    value.remove(0, value.length());
    ui->textEdit->setText(value);
    ui->decimal_point->setEnabled(true);
    ui->number_0->setEnabled(true);
    ui->negative->setEnabled(true);
}

void Input_Number::clean_Value_positive_integer_type()
{
    value.remove(0, value.length());
    ui->textEdit->setText(value);
    ui->decimal_point->setEnabled(false);
    ui->number_0->setEnabled(true);
    ui->negative->setEnabled(false);
}

void Input_Number::set_input_number_type(int type)
{
    input_number_type = type;
    if(type == POSITIVE_INTEGER)
    {
        clean_Value_positive_integer_type();
    }else if(type == ANY_NUMBER)
    {
        clean_Value_any_type();
    }
}
