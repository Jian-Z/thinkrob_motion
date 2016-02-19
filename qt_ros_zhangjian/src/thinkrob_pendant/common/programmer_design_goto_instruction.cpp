#include "programmer_design_goto_instruction.hpp"


Programmer_Design_Goto_Instruction::Programmer_Design_Goto_Instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Programmer_Design_Goto_Instruction)
{
    ui->setupUi(this);
    isSucceed = false;
    goto_row = 0.0;
    input_number = new Input_Number();
    max_row = 0;
    isopendialog = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("系统对话框"));
}

Programmer_Design_Goto_Instruction::~Programmer_Design_Goto_Instruction()
{
    delete input_number;
    delete ui;
}

void Programmer_Design_Goto_Instruction::on_cancel_button_pressed()
{
    isSucceed = false;
    this->close();
}

void Programmer_Design_Goto_Instruction::on_ok_button_pressed()
{
    isSucceed = true;
    this->close();
}

bool Programmer_Design_Goto_Instruction::get_programmer_design_goto_instruction_status()
{
    return isSucceed;
}

void Programmer_Design_Goto_Instruction::set_programmer_design_goto_instructuin_status(bool status)
{
    isSucceed = status;
}

double Programmer_Design_Goto_Instruction::get_goto_row()
{
    return goto_row;
}

Ui::Programmer_Design_Goto_Instruction* Programmer_Design_Goto_Instruction::get_programmer_design_instruction_ui()
{
    return ui;
}

void Programmer_Design_Goto_Instruction::on_goto_instruction_row_selectionChanged()
{
    if(isopendialog == false)
    {
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->getUiHandler()->min_value->setText(QString::number(0));
        input_number->getUiHandler()->max_value->setText(QString::number(max_row - 1));
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X + 100, WAIT_TIME_DIALOG_Y + 100);
        isopendialog = true;
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            input_number->set_succeed_write_status(false);
            ui->goto_instruction_row->setText(QString::number(input_number->value_number()));
            goto_row = input_number->value_number();
        }
        isopendialog = false;
        //input_number->clean_Value_positive_integer_type();
    }
}

void Programmer_Design_Goto_Instruction::set_max_row(int rowcount)
{
    max_row = rowcount;
}

void Programmer_Design_Goto_Instruction::set_goto_row(double row)
{
    goto_row = row;
}
