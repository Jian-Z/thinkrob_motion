/********************************************************************************
** Form generated from reading UI file 'teacher_straight_line.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_STRAIGHT_LINE_H
#define UI_TEACHER_STRAIGHT_LINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Teacher_Straight_Line
{
public:
    QLabel *display_first;
    QLabel *diaplay_value;
    QLabel *display_third;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *Teacher_Straight_Line)
    {
        if (Teacher_Straight_Line->objectName().isEmpty())
            Teacher_Straight_Line->setObjectName(QString::fromUtf8("Teacher_Straight_Line"));
        Teacher_Straight_Line->resize(400, 300);
        display_first = new QLabel(Teacher_Straight_Line);
        display_first->setObjectName(QString::fromUtf8("display_first"));
        display_first->setGeometry(QRect(45, 88, 121, 16));
        diaplay_value = new QLabel(Teacher_Straight_Line);
        diaplay_value->setObjectName(QString::fromUtf8("diaplay_value"));
        diaplay_value->setGeometry(QRect(170, 88, 66, 17));
        diaplay_value->setAlignment(Qt::AlignCenter);
        display_third = new QLabel(Teacher_Straight_Line);
        display_third->setObjectName(QString::fromUtf8("display_third"));
        display_third->setGeometry(QRect(245, 88, 71, 20));
        cancel_button = new QPushButton(Teacher_Straight_Line);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(60, 202, 65, 35));
        ok_button = new QPushButton(Teacher_Straight_Line);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(240, 202, 65, 35));

        retranslateUi(Teacher_Straight_Line);

        QMetaObject::connectSlotsByName(Teacher_Straight_Line);
    } // setupUi

    void retranslateUi(QDialog *Teacher_Straight_Line)
    {
        Teacher_Straight_Line->setWindowTitle(QApplication::translate("Teacher_Straight_Line", "Dialog", 0, QApplication::UnicodeUTF8));
        display_first->setText(QApplication::translate("Teacher_Straight_Line", "\347\241\256\350\256\244\347\233\264\347\272\277\350\277\220\345\212\250\345\210\260\347\254\254", 0, QApplication::UnicodeUTF8));
        diaplay_value->setText(QApplication::translate("Teacher_Straight_Line", "0", 0, QApplication::UnicodeUTF8));
        display_third->setText(QApplication::translate("Teacher_Straight_Line", "\347\202\271\345\235\220\346\240\207\345\200\274\357\274\237", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Teacher_Straight_Line", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Teacher_Straight_Line", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Teacher_Straight_Line: public Ui_Teacher_Straight_Line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_STRAIGHT_LINE_H
