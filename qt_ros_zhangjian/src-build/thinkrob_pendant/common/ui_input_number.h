/********************************************************************************
** Form generated from reading UI file 'input_number.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_NUMBER_H
#define UI_INPUT_NUMBER_H

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

class Ui_Input_Number
{
public:
    QLabel *min_value_label;
    QLabel *min_value;
    QLabel *max_value;
    QLabel *max_value_label;
    QPushButton *number_1;
    QTextEdit *textEdit;
    QPushButton *number_2;
    QPushButton *number_3;
    QPushButton *clear;
    QPushButton *reduce;
    QPushButton *number_4;
    QPushButton *number_5;
    QPushButton *number_6;
    QPushButton *number_8;
    QPushButton *number_7;
    QPushButton *number_9;
    QPushButton *negative;
    QPushButton *number_0;
    QPushButton *decimal_point;
    QPushButton *enter;
    QLabel *display_small_title;

    void setupUi(QDialog *Input_Number)
    {
        if (Input_Number->objectName().isEmpty())
            Input_Number->setObjectName(QString::fromUtf8("Input_Number"));
        Input_Number->resize(351, 340);
        min_value_label = new QLabel(Input_Number);
        min_value_label->setObjectName(QString::fromUtf8("min_value_label"));
        min_value_label->setGeometry(QRect(14, 29, 66, 17));
        min_value = new QLabel(Input_Number);
        min_value->setObjectName(QString::fromUtf8("min_value"));
        min_value->setGeometry(QRect(74, 29, 66, 17));
        max_value = new QLabel(Input_Number);
        max_value->setObjectName(QString::fromUtf8("max_value"));
        max_value->setGeometry(QRect(274, 29, 66, 17));
        max_value_label = new QLabel(Input_Number);
        max_value_label->setObjectName(QString::fromUtf8("max_value_label"));
        max_value_label->setGeometry(QRect(214, 29, 66, 17));
        number_1 = new QPushButton(Input_Number);
        number_1->setObjectName(QString::fromUtf8("number_1"));
        number_1->setGeometry(QRect(10, 99, 50, 50));
        textEdit = new QTextEdit(Input_Number);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(3, 49, 341, 41));
        number_2 = new QPushButton(Input_Number);
        number_2->setObjectName(QString::fromUtf8("number_2"));
        number_2->setGeometry(QRect(90, 99, 50, 50));
        number_3 = new QPushButton(Input_Number);
        number_3->setObjectName(QString::fromUtf8("number_3"));
        number_3->setGeometry(QRect(170, 99, 50, 50));
        clear = new QPushButton(Input_Number);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(250, 99, 50, 50));
        reduce = new QPushButton(Input_Number);
        reduce->setObjectName(QString::fromUtf8("reduce"));
        reduce->setGeometry(QRect(250, 159, 50, 50));
        number_4 = new QPushButton(Input_Number);
        number_4->setObjectName(QString::fromUtf8("number_4"));
        number_4->setGeometry(QRect(10, 159, 50, 50));
        number_5 = new QPushButton(Input_Number);
        number_5->setObjectName(QString::fromUtf8("number_5"));
        number_5->setGeometry(QRect(90, 159, 50, 50));
        number_6 = new QPushButton(Input_Number);
        number_6->setObjectName(QString::fromUtf8("number_6"));
        number_6->setGeometry(QRect(170, 159, 50, 50));
        number_8 = new QPushButton(Input_Number);
        number_8->setObjectName(QString::fromUtf8("number_8"));
        number_8->setGeometry(QRect(90, 219, 50, 50));
        number_7 = new QPushButton(Input_Number);
        number_7->setObjectName(QString::fromUtf8("number_7"));
        number_7->setGeometry(QRect(10, 219, 50, 50));
        number_9 = new QPushButton(Input_Number);
        number_9->setObjectName(QString::fromUtf8("number_9"));
        number_9->setGeometry(QRect(170, 219, 50, 50));
        negative = new QPushButton(Input_Number);
        negative->setObjectName(QString::fromUtf8("negative"));
        negative->setGeometry(QRect(250, 219, 50, 50));
        number_0 = new QPushButton(Input_Number);
        number_0->setObjectName(QString::fromUtf8("number_0"));
        number_0->setGeometry(QRect(10, 279, 50, 50));
        decimal_point = new QPushButton(Input_Number);
        decimal_point->setObjectName(QString::fromUtf8("decimal_point"));
        decimal_point->setGeometry(QRect(90, 279, 50, 50));
        enter = new QPushButton(Input_Number);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setGeometry(QRect(170, 279, 130, 50));
        display_small_title = new QLabel(Input_Number);
        display_small_title->setObjectName(QString::fromUtf8("display_small_title"));
        display_small_title->setGeometry(QRect(90, 10, 200, 16));

        retranslateUi(Input_Number);

        QMetaObject::connectSlotsByName(Input_Number);
    } // setupUi

    void retranslateUi(QDialog *Input_Number)
    {
        Input_Number->setWindowTitle(QApplication::translate("Input_Number", "Dialog", 0, QApplication::UnicodeUTF8));
        min_value_label->setText(QApplication::translate("Input_Number", "\346\234\200\345\260\217\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        min_value->setText(QString());
        max_value->setText(QString());
        max_value_label->setText(QApplication::translate("Input_Number", "\346\234\200\345\244\247\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        number_1->setText(QApplication::translate("Input_Number", "1", 0, QApplication::UnicodeUTF8));
        number_2->setText(QApplication::translate("Input_Number", "2", 0, QApplication::UnicodeUTF8));
        number_3->setText(QApplication::translate("Input_Number", "3", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("Input_Number", "CLR", 0, QApplication::UnicodeUTF8));
        reduce->setText(QApplication::translate("Input_Number", "<-", 0, QApplication::UnicodeUTF8));
        number_4->setText(QApplication::translate("Input_Number", "4", 0, QApplication::UnicodeUTF8));
        number_5->setText(QApplication::translate("Input_Number", "5", 0, QApplication::UnicodeUTF8));
        number_6->setText(QApplication::translate("Input_Number", "6", 0, QApplication::UnicodeUTF8));
        number_8->setText(QApplication::translate("Input_Number", "8", 0, QApplication::UnicodeUTF8));
        number_7->setText(QApplication::translate("Input_Number", "7", 0, QApplication::UnicodeUTF8));
        number_9->setText(QApplication::translate("Input_Number", "9", 0, QApplication::UnicodeUTF8));
        negative->setText(QApplication::translate("Input_Number", "-", 0, QApplication::UnicodeUTF8));
        number_0->setText(QApplication::translate("Input_Number", "0", 0, QApplication::UnicodeUTF8));
        decimal_point->setText(QApplication::translate("Input_Number", ".", 0, QApplication::UnicodeUTF8));
        enter->setText(QApplication::translate("Input_Number", "ENTER", 0, QApplication::UnicodeUTF8));
        display_small_title->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Input_Number: public Ui_Input_Number {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_NUMBER_H
