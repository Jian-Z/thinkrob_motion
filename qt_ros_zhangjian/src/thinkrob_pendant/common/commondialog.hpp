#ifndef COMMONDIALOG_HPP
#define COMMONDIALOG_HPP

#include <QDialog>
#include "common/ui_commondialog.h"
#include <QTextCodec>
namespace Ui {
class CommonDialog;
}

class CommonDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CommonDialog(QWidget *parent = 0);
    ~CommonDialog();
    bool get_common_dialog_succeed_status();
    void set_common_dialog_succeed_status(bool status);
    Ui::CommonDialog* get_common_dialog_ui();
    
private Q_SLOTS:
    void on_cancel_button_pressed();

    void on_ok_button_pressed();

private:
    Ui::CommonDialog *ui;
    bool isSucceed;
};

#endif // COMMONDIALOG_HPP
