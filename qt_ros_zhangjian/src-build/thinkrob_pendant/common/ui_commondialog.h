/********************************************************************************
** Form generated from reading UI file 'commondialog.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONDIALOG_H
#define UI_COMMONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CommonDialog
{
public:
    QLabel *display_text_label;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *CommonDialog)
    {
        if (CommonDialog->objectName().isEmpty())
            CommonDialog->setObjectName(QString::fromUtf8("CommonDialog"));
        CommonDialog->resize(400, 300);
        display_text_label = new QLabel(CommonDialog);
        display_text_label->setObjectName(QString::fromUtf8("display_text_label"));
        display_text_label->setGeometry(QRect(50, 60, 291, 21));
        cancel_button = new QPushButton(CommonDialog);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(65, 210, 65, 45));
        ok_button = new QPushButton(CommonDialog);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(260, 210, 65, 45));

        retranslateUi(CommonDialog);

        QMetaObject::connectSlotsByName(CommonDialog);
    } // setupUi

    void retranslateUi(QDialog *CommonDialog)
    {
        CommonDialog->setWindowTitle(QApplication::translate("CommonDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        display_text_label->setText(QApplication::translate("CommonDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("CommonDialog", " \345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("CommonDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CommonDialog: public Ui_CommonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONDIALOG_H
