/********************************************************************************
** Form generated from reading UI file 'error_input.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_INPUT_H
#define UI_ERROR_INPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Error_input
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Error_input)
    {
        if (Error_input->objectName().isEmpty())
            Error_input->setObjectName(QString::fromUtf8("Error_input"));
        Error_input->resize(400, 300);
        label = new QLabel(Error_input);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 100, 211, 31));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        pushButton = new QPushButton(Error_input);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(163, 200, 65, 45));

        retranslateUi(Error_input);

        QMetaObject::connectSlotsByName(Error_input);
    } // setupUi

    void retranslateUi(QDialog *Error_input)
    {
        Error_input->setWindowTitle(QApplication::translate("Error_input", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Error_input", "\350\276\223\345\205\245\347\232\204\346\225\260\346\215\256\346\234\211\350\257\257\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Error_input", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Error_input: public Ui_Error_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_INPUT_H
