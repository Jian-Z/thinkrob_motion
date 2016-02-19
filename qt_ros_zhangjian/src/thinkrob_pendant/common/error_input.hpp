#ifndef ERROR_INPUT_HPP
#define ERROR_INPUT_HPP

#include <QDialog>
#include "common/ui_error_input.h"
#include <QTextCodec>

namespace Ui {
class Error_input;
}

class Error_input : public QDialog
{
    Q_OBJECT
    
public:
    explicit Error_input(QWidget *parent = 0);
    ~Error_input();
    
private Q_SLOTS:
    void on_pushButton_pressed();

private:
    Ui::Error_input *ui;
};

#endif // ERROR_INPUT_HPP
