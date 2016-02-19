/********************************************************************************
** Form generated from reading UI file 'programmer_design_goto_instruction.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMER_DESIGN_GOTO_INSTRUCTION_H
#define UI_PROGRAMMER_DESIGN_GOTO_INSTRUCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Programmer_Design_Goto_Instruction
{
public:
    QLabel *display_text_first_label;
    QTextEdit *goto_instruction_row;
    QLabel *display_text_second_label_2;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *Programmer_Design_Goto_Instruction)
    {
        if (Programmer_Design_Goto_Instruction->objectName().isEmpty())
            Programmer_Design_Goto_Instruction->setObjectName(QString::fromUtf8("Programmer_Design_Goto_Instruction"));
        Programmer_Design_Goto_Instruction->resize(564, 297);
        display_text_first_label = new QLabel(Programmer_Design_Goto_Instruction);
        display_text_first_label->setObjectName(QString::fromUtf8("display_text_first_label"));
        display_text_first_label->setGeometry(QRect(60, 50, 66, 17));
        goto_instruction_row = new QTextEdit(Programmer_Design_Goto_Instruction);
        goto_instruction_row->setObjectName(QString::fromUtf8("goto_instruction_row"));
        goto_instruction_row->setGeometry(QRect(150, 47, 104, 30));
        display_text_second_label_2 = new QLabel(Programmer_Design_Goto_Instruction);
        display_text_second_label_2->setObjectName(QString::fromUtf8("display_text_second_label_2"));
        display_text_second_label_2->setGeometry(QRect(280, 50, 281, 61));
        cancel_button = new QPushButton(Programmer_Design_Goto_Instruction);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(60, 220, 65, 45));
        ok_button = new QPushButton(Programmer_Design_Goto_Instruction);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(450, 220, 65, 45));

        retranslateUi(Programmer_Design_Goto_Instruction);

        QMetaObject::connectSlotsByName(Programmer_Design_Goto_Instruction);
    } // setupUi

    void retranslateUi(QDialog *Programmer_Design_Goto_Instruction)
    {
        Programmer_Design_Goto_Instruction->setWindowTitle(QApplication::translate("Programmer_Design_Goto_Instruction", "Dialog", 0, QApplication::UnicodeUTF8));
        display_text_first_label->setText(QApplication::translate("Programmer_Design_Goto_Instruction", "TextLabel", 0, QApplication::UnicodeUTF8));
        display_text_second_label_2->setText(QApplication::translate("Programmer_Design_Goto_Instruction", "TextLabel", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Programmer_Design_Goto_Instruction", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Programmer_Design_Goto_Instruction", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Programmer_Design_Goto_Instruction: public Ui_Programmer_Design_Goto_Instruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMER_DESIGN_GOTO_INSTRUCTION_H
