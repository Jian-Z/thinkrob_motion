/********************************************************************************
** Form generated from reading UI file 'sport_instruction_window.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPORT_INSTRUCTION_WINDOW_H
#define UI_SPORT_INSTRUCTION_WINDOW_H

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

class Ui_Sport_Instruction_Window
{
public:
    QLabel *sport_name_label;
    QTextEdit *first_point_textEdit;
    QLabel *sport_second_point_label;
    QTextEdit *second_point_textEdit;
    QLabel *sport_speed_label;
    QTextEdit *third_point_textEdit;
    QLabel *sport_unit;
    QLabel *sport_instruction_note;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *Sport_Instruction_Window)
    {
        if (Sport_Instruction_Window->objectName().isEmpty())
            Sport_Instruction_Window->setObjectName(QString::fromUtf8("Sport_Instruction_Window"));
        Sport_Instruction_Window->resize(728, 315);
        sport_name_label = new QLabel(Sport_Instruction_Window);
        sport_name_label->setObjectName(QString::fromUtf8("sport_name_label"));
        sport_name_label->setGeometry(QRect(66, 80, 90, 16));
        first_point_textEdit = new QTextEdit(Sport_Instruction_Window);
        first_point_textEdit->setObjectName(QString::fromUtf8("first_point_textEdit"));
        first_point_textEdit->setGeometry(QRect(160, 74, 104, 30));
        sport_second_point_label = new QLabel(Sport_Instruction_Window);
        sport_second_point_label->setObjectName(QString::fromUtf8("sport_second_point_label"));
        sport_second_point_label->setGeometry(QRect(270, 80, 31, 16));
        second_point_textEdit = new QTextEdit(Sport_Instruction_Window);
        second_point_textEdit->setObjectName(QString::fromUtf8("second_point_textEdit"));
        second_point_textEdit->setGeometry(QRect(310, 74, 104, 30));
        sport_speed_label = new QLabel(Sport_Instruction_Window);
        sport_speed_label->setObjectName(QString::fromUtf8("sport_speed_label"));
        sport_speed_label->setGeometry(QRect(420, 80, 81, 16));
        third_point_textEdit = new QTextEdit(Sport_Instruction_Window);
        third_point_textEdit->setObjectName(QString::fromUtf8("third_point_textEdit"));
        third_point_textEdit->setGeometry(QRect(510, 74, 104, 30));
        sport_unit = new QLabel(Sport_Instruction_Window);
        sport_unit->setObjectName(QString::fromUtf8("sport_unit"));
        sport_unit->setGeometry(QRect(620, 80, 81, 16));
        sport_instruction_note = new QLabel(Sport_Instruction_Window);
        sport_instruction_note->setObjectName(QString::fromUtf8("sport_instruction_note"));
        sport_instruction_note->setGeometry(QRect(170, 130, 321, 91));
        cancel_button = new QPushButton(Sport_Instruction_Window);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(60, 252, 65, 45));
        ok_button = new QPushButton(Sport_Instruction_Window);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(570, 252, 65, 45));

        retranslateUi(Sport_Instruction_Window);

        QMetaObject::connectSlotsByName(Sport_Instruction_Window);
    } // setupUi

    void retranslateUi(QDialog *Sport_Instruction_Window)
    {
        Sport_Instruction_Window->setWindowTitle(QApplication::translate("Sport_Instruction_Window", "Dialog", 0, QApplication::UnicodeUTF8));
        sport_name_label->setText(QApplication::translate("Sport_Instruction_Window", "1", 0, QApplication::UnicodeUTF8));
        sport_second_point_label->setText(QApplication::translate("Sport_Instruction_Window", "1", 0, QApplication::UnicodeUTF8));
        sport_speed_label->setText(QApplication::translate("Sport_Instruction_Window", "1", 0, QApplication::UnicodeUTF8));
        sport_unit->setText(QApplication::translate("Sport_Instruction_Window", "1", 0, QApplication::UnicodeUTF8));
        sport_instruction_note->setText(QApplication::translate("Sport_Instruction_Window", "1", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Sport_Instruction_Window", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Sport_Instruction_Window", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sport_Instruction_Window: public Ui_Sport_Instruction_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPORT_INSTRUCTION_WINDOW_H
