#ifndef COMMON_FUNCTION_HPP
#define COMMON_FUNCTION_HPP

#include <QDialog>
#include "common/ui_common_function.h"
#include "wait_time.hpp"
#include "programmer_design_goto_instruction.hpp"
#include "res.hpp"
namespace Ui {
class Common_Function;
}

class Common_Function : public QDialog
{
    Q_OBJECT
    
public:
    explicit Common_Function(QWidget *parent = 0);
    ~Common_Function();
    Ui::Common_Function* get_common_function_ui();
    void set_wait_time_dialog_status(bool status);
    bool get_wait_time_dialog_status();

    void set_goto_instruction_status(bool status);
    bool get_goto_instruction_status();

    double get_wait_time_value();
    void set_command_total(int row_count);

    double get_goto_row();

    
private Q_SLOTS:
    void on_prog_design_exit_button_pressed();

    void on_prog_design_wait_button_pressed();

    void on_prog_design_goto_instruction_button_pressed();

private:
    Ui::Common_Function *ui;
    Wait_Time* wait_time_dialog;
    Programmer_Design_Goto_Instruction* prog_des_goto_instr;
    bool wait_time_isSucceed;
    bool goto_instruction_isSucceed;

    double wait_time_value;
    double goto_row;
    int command_total;

};

#endif // COMMON_FUNCTION_HPP
