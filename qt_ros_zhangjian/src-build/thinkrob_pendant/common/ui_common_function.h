/********************************************************************************
** Form generated from reading UI file 'common_function.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMON_FUNCTION_H
#define UI_COMMON_FUNCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Common_Function
{
public:
    QPushButton *prog_design_rate_button;
    QPushButton *prog_design_set_output_button;
    QPushButton *prog_design_wait_input_button;
    QPushButton *prog_design_input_judgment_button;
    QPushButton *prog_design_goto_instruction_button;
    QPushButton *prog_design_wait_button;
    QPushButton *prog_design_notes_button;
    QPushButton *prog_design_loop_start_button;
    QPushButton *prog_design_loop_end_button;
    QPushButton *prog_design_acc_dec_time_button;
    QPushButton *prog_design_count_button;
    QPushButton *prog_design_exit_button;

    void setupUi(QDialog *Common_Function)
    {
        if (Common_Function->objectName().isEmpty())
            Common_Function->setObjectName(QString::fromUtf8("Common_Function"));
        Common_Function->resize(133, 600);
        Common_Function->setWindowTitle(QString::fromUtf8("Dialog"));
#ifndef QT_NO_TOOLTIP
        Common_Function->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Common_Function->setStatusTip(QString::fromUtf8(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Common_Function->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        Common_Function->setAccessibleName(QString::fromUtf8(""));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        Common_Function->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_NO_ACCESSIBILITY
        prog_design_rate_button = new QPushButton(Common_Function);
        prog_design_rate_button->setObjectName(QString::fromUtf8("prog_design_rate_button"));
        prog_design_rate_button->setGeometry(QRect(15, 20, 100, 39));
        prog_design_set_output_button = new QPushButton(Common_Function);
        prog_design_set_output_button->setObjectName(QString::fromUtf8("prog_design_set_output_button"));
        prog_design_set_output_button->setGeometry(QRect(15, 60, 100, 39));
        prog_design_wait_input_button = new QPushButton(Common_Function);
        prog_design_wait_input_button->setObjectName(QString::fromUtf8("prog_design_wait_input_button"));
        prog_design_wait_input_button->setGeometry(QRect(15, 100, 100, 39));
        prog_design_input_judgment_button = new QPushButton(Common_Function);
        prog_design_input_judgment_button->setObjectName(QString::fromUtf8("prog_design_input_judgment_button"));
        prog_design_input_judgment_button->setGeometry(QRect(15, 140, 100, 39));
        prog_design_goto_instruction_button = new QPushButton(Common_Function);
        prog_design_goto_instruction_button->setObjectName(QString::fromUtf8("prog_design_goto_instruction_button"));
        prog_design_goto_instruction_button->setGeometry(QRect(15, 180, 100, 39));
        prog_design_wait_button = new QPushButton(Common_Function);
        prog_design_wait_button->setObjectName(QString::fromUtf8("prog_design_wait_button"));
        prog_design_wait_button->setGeometry(QRect(15, 220, 100, 39));
        prog_design_notes_button = new QPushButton(Common_Function);
        prog_design_notes_button->setObjectName(QString::fromUtf8("prog_design_notes_button"));
        prog_design_notes_button->setGeometry(QRect(15, 260, 100, 39));
        prog_design_loop_start_button = new QPushButton(Common_Function);
        prog_design_loop_start_button->setObjectName(QString::fromUtf8("prog_design_loop_start_button"));
        prog_design_loop_start_button->setGeometry(QRect(15, 300, 100, 39));
        prog_design_loop_end_button = new QPushButton(Common_Function);
        prog_design_loop_end_button->setObjectName(QString::fromUtf8("prog_design_loop_end_button"));
        prog_design_loop_end_button->setGeometry(QRect(15, 340, 100, 39));
        prog_design_acc_dec_time_button = new QPushButton(Common_Function);
        prog_design_acc_dec_time_button->setObjectName(QString::fromUtf8("prog_design_acc_dec_time_button"));
        prog_design_acc_dec_time_button->setGeometry(QRect(15, 380, 100, 39));
        prog_design_count_button = new QPushButton(Common_Function);
        prog_design_count_button->setObjectName(QString::fromUtf8("prog_design_count_button"));
        prog_design_count_button->setEnabled(true);
        prog_design_count_button->setGeometry(QRect(15, 420, 100, 39));
        prog_design_exit_button = new QPushButton(Common_Function);
        prog_design_exit_button->setObjectName(QString::fromUtf8("prog_design_exit_button"));
        prog_design_exit_button->setGeometry(QRect(15, 460, 100, 39));

        retranslateUi(Common_Function);

        QMetaObject::connectSlotsByName(Common_Function);
    } // setupUi

    void retranslateUi(QDialog *Common_Function)
    {
        prog_design_rate_button->setText(QApplication::translate("Common_Function", "  \351\200\237\347\216\207", 0, QApplication::UnicodeUTF8));
        prog_design_set_output_button->setText(QApplication::translate("Common_Function", "\350\256\276\347\275\256\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
        prog_design_wait_input_button->setText(QApplication::translate("Common_Function", "\347\255\211\345\276\205\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        prog_design_input_judgment_button->setText(QApplication::translate("Common_Function", "\350\276\223\345\205\245\345\210\244\346\226\255", 0, QApplication::UnicodeUTF8));
        prog_design_goto_instruction_button->setText(QApplication::translate("Common_Function", "\350\267\263\350\275\254\346\214\207\344\273\244", 0, QApplication::UnicodeUTF8));
        prog_design_wait_button->setText(QApplication::translate("Common_Function", "\347\255\211\345\276\205", 0, QApplication::UnicodeUTF8));
        prog_design_notes_button->setText(QApplication::translate("Common_Function", "\346\263\250\351\207\212\350\257\255\345\217\245", 0, QApplication::UnicodeUTF8));
        prog_design_loop_start_button->setText(QApplication::translate("Common_Function", "\345\276\252\347\216\257\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        prog_design_loop_end_button->setText(QApplication::translate("Common_Function", "\345\276\252\347\216\257\347\273\223\346\235\237", 0, QApplication::UnicodeUTF8));
        prog_design_acc_dec_time_button->setText(QApplication::translate("Common_Function", "\345\212\240\345\207\217\351\200\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        prog_design_count_button->setText(QApplication::translate("Common_Function", "\350\256\241\346\225\260\345\231\250", 0, QApplication::UnicodeUTF8));
        prog_design_exit_button->setText(QApplication::translate("Common_Function", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Common_Function);
    } // retranslateUi

};

namespace Ui {
    class Common_Function: public Ui_Common_Function {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMON_FUNCTION_H
