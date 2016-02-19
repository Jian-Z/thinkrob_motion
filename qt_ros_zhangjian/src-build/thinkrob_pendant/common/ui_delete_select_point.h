/********************************************************************************
** Form generated from reading UI file 'delete_select_point.ui'
**
** Created: Fri Feb 19 10:29:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_SELECT_POINT_H
#define UI_DELETE_SELECT_POINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Delete_Select_Point
{
public:
    QLabel *display_label;
    QPushButton *cancel_button;
    QPushButton *ok_button;

    void setupUi(QDialog *Delete_Select_Point)
    {
        if (Delete_Select_Point->objectName().isEmpty())
            Delete_Select_Point->setObjectName(QString::fromUtf8("Delete_Select_Point"));
        Delete_Select_Point->resize(400, 300);
        display_label = new QLabel(Delete_Select_Point);
        display_label->setObjectName(QString::fromUtf8("display_label"));
        display_label->setGeometry(QRect(100, 80, 201, 21));
        cancel_button = new QPushButton(Delete_Select_Point);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setGeometry(QRect(60, 180, 65, 45));
        ok_button = new QPushButton(Delete_Select_Point);
        ok_button->setObjectName(QString::fromUtf8("ok_button"));
        ok_button->setGeometry(QRect(270, 180, 65, 45));

        retranslateUi(Delete_Select_Point);

        QMetaObject::connectSlotsByName(Delete_Select_Point);
    } // setupUi

    void retranslateUi(QDialog *Delete_Select_Point)
    {
        Delete_Select_Point->setWindowTitle(QApplication::translate("Delete_Select_Point", "Dialog", 0, QApplication::UnicodeUTF8));
        display_label->setText(QApplication::translate("Delete_Select_Point", "\347\241\256\345\256\232\345\210\240\351\231\244\346\234\200\345\220\216\344\270\200\344\270\252\347\202\271\344\275\215\345\220\227\357\274\237", 0, QApplication::UnicodeUTF8));
        cancel_button->setText(QApplication::translate("Delete_Select_Point", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        ok_button->setText(QApplication::translate("Delete_Select_Point", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Delete_Select_Point: public Ui_Delete_Select_Point {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_SELECT_POINT_H
