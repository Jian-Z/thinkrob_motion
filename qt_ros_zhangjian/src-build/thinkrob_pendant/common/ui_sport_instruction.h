/********************************************************************************
** Form generated from reading UI file 'sport_instruction.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPORT_INSTRUCTION_H
#define UI_SPORT_INSTRUCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sport_Instruction
{
public:
    QPushButton *joint_sport_button;
    QPushButton *straight_sport_button;
    QPushButton *circular_sport_button;
    QPushButton *smooth_function_button;
    QPushButton *arc_auxiliary_point;
    QPushButton *arc_end_point;
    QPushButton *tool_conversion;
    QPushButton *workpiece_coordinate;
    QPushButton *exit_button;

    void setupUi(QDialog *Sport_Instruction)
    {
        if (Sport_Instruction->objectName().isEmpty())
            Sport_Instruction->setObjectName(QString::fromUtf8("Sport_Instruction"));
        Sport_Instruction->resize(133, 600);
        joint_sport_button = new QPushButton(Sport_Instruction);
        joint_sport_button->setObjectName(QString::fromUtf8("joint_sport_button"));
        joint_sport_button->setGeometry(QRect(15, 20, 100, 39));
        straight_sport_button = new QPushButton(Sport_Instruction);
        straight_sport_button->setObjectName(QString::fromUtf8("straight_sport_button"));
        straight_sport_button->setGeometry(QRect(15, 60, 100, 39));
        circular_sport_button = new QPushButton(Sport_Instruction);
        circular_sport_button->setObjectName(QString::fromUtf8("circular_sport_button"));
        circular_sport_button->setGeometry(QRect(15, 100, 100, 39));
        smooth_function_button = new QPushButton(Sport_Instruction);
        smooth_function_button->setObjectName(QString::fromUtf8("smooth_function_button"));
        smooth_function_button->setGeometry(QRect(15, 140, 100, 39));
        arc_auxiliary_point = new QPushButton(Sport_Instruction);
        arc_auxiliary_point->setObjectName(QString::fromUtf8("arc_auxiliary_point"));
        arc_auxiliary_point->setEnabled(true);
        arc_auxiliary_point->setGeometry(QRect(15, 270, 100, 39));
        arc_end_point = new QPushButton(Sport_Instruction);
        arc_end_point->setObjectName(QString::fromUtf8("arc_end_point"));
        arc_end_point->setGeometry(QRect(15, 310, 100, 39));
        tool_conversion = new QPushButton(Sport_Instruction);
        tool_conversion->setObjectName(QString::fromUtf8("tool_conversion"));
        tool_conversion->setGeometry(QRect(15, 350, 100, 39));
        workpiece_coordinate = new QPushButton(Sport_Instruction);
        workpiece_coordinate->setObjectName(QString::fromUtf8("workpiece_coordinate"));
        workpiece_coordinate->setGeometry(QRect(15, 390, 100, 39));
        exit_button = new QPushButton(Sport_Instruction);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(15, 500, 100, 39));

        retranslateUi(Sport_Instruction);

        QMetaObject::connectSlotsByName(Sport_Instruction);
    } // setupUi

    void retranslateUi(QDialog *Sport_Instruction)
    {
        Sport_Instruction->setWindowTitle(QApplication::translate("Sport_Instruction", "Dialog", 0, QApplication::UnicodeUTF8));
        joint_sport_button->setText(QApplication::translate("Sport_Instruction", "\347\202\271\344\275\215\350\277\220\345\212\250", 0, QApplication::UnicodeUTF8));
        straight_sport_button->setText(QApplication::translate("Sport_Instruction", "\347\233\264\347\272\277\350\277\220\345\212\250", 0, QApplication::UnicodeUTF8));
        circular_sport_button->setText(QApplication::translate("Sport_Instruction", "\345\234\206\345\274\247\350\277\220\345\212\250", 0, QApplication::UnicodeUTF8));
        smooth_function_button->setText(QApplication::translate("Sport_Instruction", "\345\271\263\346\273\221\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
        arc_auxiliary_point->setText(QApplication::translate("Sport_Instruction", "\345\234\206\345\274\247\350\276\205\345\212\251\347\202\271", 0, QApplication::UnicodeUTF8));
        arc_end_point->setText(QApplication::translate("Sport_Instruction", "\345\234\206\345\274\247\347\273\223\346\235\237\347\202\271", 0, QApplication::UnicodeUTF8));
        tool_conversion->setText(QApplication::translate("Sport_Instruction", "\345\267\245\345\205\267\350\275\254\346\215\242", 0, QApplication::UnicodeUTF8));
        workpiece_coordinate->setText(QApplication::translate("Sport_Instruction", "\345\267\245\344\273\266\345\235\220\346\240\207", 0, QApplication::UnicodeUTF8));
        exit_button->setText(QApplication::translate("Sport_Instruction", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sport_Instruction: public Ui_Sport_Instruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPORT_INSTRUCTION_H
