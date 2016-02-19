#ifndef DELECT_SELECT_POINT_HPP
#define DELECT_SELECT_POINT_HPP

#include <QDialog>
#include "common/ui_delete_select_point.h"
#include <QTextCodec>

namespace Ui {
class Delete_Select_Point;
}

class Delete_Select_Point : public QDialog
{
    Q_OBJECT
    
public:
    explicit Delete_Select_Point(QWidget *parent = 0);
    bool get_succeed_status();
    void set_succeed_status(bool succeed_status);
    ~Delete_Select_Point();
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

private:
    Ui::Delete_Select_Point *ui;
    bool isSucceed;
};

#endif // DELECT_SELECT_POINT_HPP
