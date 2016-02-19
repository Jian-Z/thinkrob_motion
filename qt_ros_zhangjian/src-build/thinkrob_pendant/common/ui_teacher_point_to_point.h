/********************************************************************************
** Form generated from reading UI file 'teacher_point_to_point.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_POINT_TO_POINT_H
#define UI_TEACHER_POINT_TO_POINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_teacher_point_to_point
{
public:
    QLabel *display_first;
    QLabel *point_value;
    QLabel *display_third;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *teacher_point_to_point)
    {
        if (teacher_point_to_point->objectName().isEmpty())
            teacher_point_to_point->setObjectName(QString::fromUtf8("teacher_point_to_point"));
        teacher_point_to_point->resize(400, 300);
        display_first = new QLabel(teacher_point_to_point);
        display_first->setObjectName(QString::fromUtf8("display_first"));
        display_first->setGeometry(QRect(74, 90, 131, 16));
        point_value = new QLabel(teacher_point_to_point);
        point_value->setObjectName(QString::fromUtf8("point_value"));
        point_value->setGeometry(QRect(212, 90, 45, 16));
        point_value->setAlignment(Qt::AlignCenter);
        display_third = new QLabel(teacher_point_to_point);
        display_third->setObjectName(QString::fromUtf8("display_third"));
        display_third->setGeometry(QRect(258, 90, 131, 16));
        cancel_button = new QPushButton(teacher_point_to_point);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(80, 220, 65, 35));
        ok_button = new QPushButton(teacher_point_to_point);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(230, 220, 65, 35));

        retranslateUi(teacher_point_to_point);

        QMetaObject::connectSlotsByName(teacher_point_to_point);
    } // setupUi

    void retranslateUi(QDialog *teacher_point_to_point)
    {
        teacher_point_to_point->setWindowTitle(QApplication::translate("teacher_point_to_point", "Dialog", 0, QApplication::UnicodeUTF8));
        display_first->setText(QApplication::translate("teacher_point_to_point", "\347\241\256\350\256\244\347\202\271\345\257\271\347\202\271\350\277\220\345\212\250\345\210\260\347\254\254", 0, QApplication::UnicodeUTF8));
        point_value->setText(QString());
        display_third->setText(QApplication::translate("teacher_point_to_point", "\347\202\271\345\235\220\346\240\207\345\200\274\357\274\237", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("teacher_point_to_point", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("teacher_point_to_point", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class teacher_point_to_point: public Ui_teacher_point_to_point {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_POINT_TO_POINT_H
