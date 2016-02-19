/********************************************************************************
** Form generated from reading UI file 'modify_point_position.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_POINT_POSITION_H
#define UI_MODIFY_POINT_POSITION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Modify_Point_Position
{
public:
    QLabel *first_display_label;
    QLabel *display_modify_point_label;
    QLabel *third_display_label;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *Modify_Point_Position)
    {
        if (Modify_Point_Position->objectName().isEmpty())
            Modify_Point_Position->setObjectName(QString::fromUtf8("Modify_Point_Position"));
        Modify_Point_Position->resize(400, 300);
        first_display_label = new QLabel(Modify_Point_Position);
        first_display_label->setObjectName(QString::fromUtf8("first_display_label"));
        first_display_label->setGeometry(QRect(18, 90, 170, 21));
        display_modify_point_label = new QLabel(Modify_Point_Position);
        display_modify_point_label->setObjectName(QString::fromUtf8("display_modify_point_label"));
        display_modify_point_label->setGeometry(QRect(176, 90, 60, 21));
        display_modify_point_label->setAlignment(Qt::AlignCenter);
        third_display_label = new QLabel(Modify_Point_Position);
        third_display_label->setObjectName(QString::fromUtf8("third_display_label"));
        third_display_label->setGeometry(QRect(236, 90, 265, 21));
        cancel_button = new QPushButton(Modify_Point_Position);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(70, 200, 65, 45));
        ok_button = new QPushButton(Modify_Point_Position);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(260, 200, 65, 45));

        retranslateUi(Modify_Point_Position);

        QMetaObject::connectSlotsByName(Modify_Point_Position);
    } // setupUi

    void retranslateUi(QDialog *Modify_Point_Position)
    {
        Modify_Point_Position->setWindowTitle(QApplication::translate("Modify_Point_Position", "Dialog", 0, QApplication::UnicodeUTF8));
        first_display_label->setText(QApplication::translate("Modify_Point_Position", "\347\241\256\350\256\244\345\260\206\345\275\223\345\211\215\344\275\215\347\275\256\344\277\256\346\224\271\344\270\272\347\254\254", 0, QApplication::UnicodeUTF8));
        display_modify_point_label->setText(QString());
        third_display_label->setText(QApplication::translate("Modify_Point_Position", "\344\270\252\347\202\271\344\275\215\345\210\260\345\235\220\346\240\207\345\200\274\345\220\227\357\274\237", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Modify_Point_Position", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Modify_Point_Position", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Modify_Point_Position: public Ui_Modify_Point_Position {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_POINT_POSITION_H
