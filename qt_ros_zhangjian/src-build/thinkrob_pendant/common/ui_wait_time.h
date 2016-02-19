/********************************************************************************
** Form generated from reading UI file 'wait_time.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_TIME_H
#define UI_WAIT_TIME_H

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

class Ui_Wait_Time
{
public:
    QLabel *label;
    QTextEdit *wait_time_value;
    QLabel *label_2;
    QLabel *note;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *Wait_Time)
    {
        if (Wait_Time->objectName().isEmpty())
            Wait_Time->setObjectName(QString::fromUtf8("Wait_Time"));
        Wait_Time->resize(630, 275);
        label = new QLabel(Wait_Time);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 38, 41, 17));
        wait_time_value = new QTextEdit(Wait_Time);
        wait_time_value->setObjectName(QString::fromUtf8("wait_time_value"));
        wait_time_value->setGeometry(QRect(58, 31, 110, 31));
        label_2 = new QLabel(Wait_Time);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(174, 38, 41, 17));
        note = new QLabel(Wait_Time);
        note->setObjectName(QString::fromUtf8("note"));
        note->setGeometry(QRect(240, 38, 400, 17));
        cancel_button = new QPushButton(Wait_Time);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(40, 220, 65, 45));
        cancel_button->setAutoDefault(false);
        ok_button = new QPushButton(Wait_Time);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(530, 220, 65, 45));
        ok_button->setAutoDefault(false);

        retranslateUi(Wait_Time);

        QMetaObject::connectSlotsByName(Wait_Time);
    } // setupUi

    void retranslateUi(QDialog *Wait_Time)
    {
        Wait_Time->setWindowTitle(QApplication::translate("Wait_Time", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Wait_Time", "\347\255\211\345\276\205", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Wait_Time", "\346\257\253\347\247\222", 0, QApplication::UnicodeUTF8));
        note->setText(QApplication::translate("Wait_Time", "\347\255\211\345\276\205\347\247\273\345\212\250\346\227\266\351\227\264\345\206\215\350\277\220\350\241\214\344\270\213\344\270\200\350\241\214\347\250\213\345\272\217\357\274\214\350\214\203\345\233\264\357\274\2100-1800000\357\274\211\346\257\253\347\247\222", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Wait_Time", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Wait_Time", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Wait_Time: public Ui_Wait_Time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_TIME_H
