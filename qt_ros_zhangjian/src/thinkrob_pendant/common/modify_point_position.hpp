#ifndef MODIFY_POINT_POSITION_HPP
#define MODIFY_POINT_POSITION_HPP

#include <QDialog>
#include "common/ui_modify_point_position.h"
#include <QTextCodec>

namespace Ui {
class Modify_Point_Position;
}

class Modify_Point_Position : public QDialog
{
    Q_OBJECT
    
public:
    explicit Modify_Point_Position(QWidget *parent = 0);
    ~Modify_Point_Position();
    bool get_succeed_status();
    void set_succeed_status(bool status);
    Ui::Modify_Point_Position* get_modify_point_position_dialog_ui_point();
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

private:
    Ui::Modify_Point_Position *ui;
    bool isSucceed;
};

#endif // MODIFY_POINT_POSITION_HPP
