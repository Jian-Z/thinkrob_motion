#include "common_function.hpp"

Common_Function::Common_Function(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Common_Function)
{
    ui->setupUi(this);
    wait_time_dialog = new Wait_Time();
    prog_des_goto_instr = new Programmer_Design_Goto_Instruction;

    wait_time_isSucceed = false;
    goto_instruction_isSucceed = false;
    wait_time_value = 0;
    command_total = 0;
    goto_row = 0;
}

Common_Function::~Common_Function()
{
    delete wait_time_dialog;
    delete prog_des_goto_instr;
    delete ui;
}

void Common_Function::on_prog_design_exit_button_pressed()
{
    this->close();
}

Ui::Common_Function* Common_Function::get_common_function_ui()
{
    return ui;
}

bool Common_Function::get_wait_time_dialog_status()
{
    return wait_time_isSucceed;
}

void Common_Function::set_wait_time_dialog_status(bool status)
{
    wait_time_isSucceed = status;
}

void Common_Function::on_prog_design_wait_button_pressed()
{
    wait_time_dialog->get_wait_time_ui()->wait_time_value->setText("0");
    wait_time_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
    wait_time_dialog->setModal(false);
    wait_time_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
    wait_time_dialog->exec();
    if(wait_time_dialog->get_wait_time_dialog_status())
    {
        wait_time_dialog->set_wait_time_dialog_status(false);
        wait_time_value = wait_time_dialog->get_wait_time_value();
        wait_time_dialog->set_wait_time_value(0);
        wait_time_isSucceed = true;
        this->close();
    }
    wait_time_dialog->set_wait_time_value(0);
}

double Common_Function::get_wait_time_value()
{
    return wait_time_value;
}

void Common_Function::on_prog_design_goto_instruction_button_pressed()
{
    QString title, note;
    title = "跳转";
    note = "跳转指令，程序跳到指定行（0-" + QString::number(command_total - 1) + "），Goto\n语句禁忌跳入Repeat Begin/End循环等\n特殊语句，否则可能会引起程序运行混乱。";
    prog_des_goto_instr->get_programmer_design_instruction_ui()->display_text_first_label->setText(title);
    prog_des_goto_instr->get_programmer_design_instruction_ui()->display_text_second_label_2->setText(note);
    prog_des_goto_instr->get_programmer_design_instruction_ui()->display_text_second_label_2->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    prog_des_goto_instr->get_programmer_design_instruction_ui()->goto_instruction_row->setText("0");
    prog_des_goto_instr->set_max_row(command_total);
    prog_des_goto_instr->setWindowFlags(Qt::WindowStaysOnTopHint);
    prog_des_goto_instr->setModal(false);
    prog_des_goto_instr->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
    prog_des_goto_instr->exec();
    if(prog_des_goto_instr->get_programmer_design_goto_instruction_status())
    {
        prog_des_goto_instr->set_programmer_design_goto_instructuin_status(false);
        goto_row = prog_des_goto_instr->get_goto_row();
        goto_instruction_isSucceed = true;
        prog_des_goto_instr->set_goto_row(0);
        this->close();
    }
    prog_des_goto_instr->set_goto_row(0);
}

void Common_Function::set_command_total(int row_count)
{
    command_total = row_count;
}

double Common_Function::get_goto_row()
{
    return goto_row;
}

void Common_Function::set_goto_instruction_status(bool status)
{
    goto_instruction_isSucceed = status;
}

bool Common_Function::get_goto_instruction_status()
{
    return goto_instruction_isSucceed;
}
