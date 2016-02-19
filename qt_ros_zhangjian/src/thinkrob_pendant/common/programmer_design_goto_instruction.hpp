#ifndef PROGRAMMER_DESIGN_GOTO_INSTRUCTION_HPP
#define PROGRAMMER_DESIGN_GOTO_INSTRUCTION_HPP

#include <QDialog>
#include "common/ui_programmer_design_goto_instruction.h"
#include "input_number.hpp"

namespace Ui {
class Programmer_Design_Goto_Instruction;
}

class Programmer_Design_Goto_Instruction : public QDialog
{
    Q_OBJECT
    
public:
    explicit Programmer_Design_Goto_Instruction(QWidget *parent = 0);
    ~Programmer_Design_Goto_Instruction();
    bool get_programmer_design_goto_instruction_status();
    void set_programmer_design_goto_instructuin_status(bool status);
    double get_goto_row();
    void set_goto_row(double row);
    Ui::Programmer_Design_Goto_Instruction* get_programmer_design_instruction_ui();
    void set_max_row(int rowcount);
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

    void on_goto_instruction_row_selectionChanged();

private:
    Ui::Programmer_Design_Goto_Instruction *ui;
    Input_Number* input_number;
    bool isSucceed;
    double goto_row;
    int max_row;
    bool isopendialog;
};

#endif // PROGRAMMER_DESIGN_GOTO_INSTRUCTION_HPP
