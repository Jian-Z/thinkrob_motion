/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "main_window.hpp"
#include <QTextCodec>

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(Listener *list, QWidget *parent) :
    QMainWindow(parent),
    qnode(list),
    listener(list),
    teacher_point_list_count(0)
{
    ui.setupUi(this);
    //Anthor:zhangjian
    setWindowTitle(QString("thinkmotion"));
    tableWidget = ui.teacher_point_tableWidget;
    teach_p2p = new teacher_point_to_point();
    teach_str_line = new Teacher_Straight_Line();
    input_number = new Input_Number();
    delete_select_point = new Delete_Select_Point();
    modify_point = new Modify_Point_Position();
    comm_function = new Common_Function();
    common_dialog = new CommonDialog();
    sport_instr = new Sport_Instruction();
    programmer_run_thread = new Programmer_Run_Thread(list, tableWidget);
    file = new QFileDialog();
    system_password = new QString("12345678");
    user_password = new QString("33333333");
    virtualkeyboard = new VirtualKeyboard();

    command_total = 0;
    current_select_command = 0;
    current_execute_row = 0;
    start_run_programmer = false;
    file_path = "";
    programmer_run_status = READY_PROGRAMMER;
    isopendialog = false;
    administratorsloginsucceed = false;
    version_no = USER_NOT_SELECT_PATH;
    login_status = NO_LOGIN;

    //initialize QPushButton status
    is_point_to_point_motion = true;
    is_straight_line_motion = true;
    is_delete_point = true;
    is_modify_point = true;
    is_run_button = true;
    is_parameter_setting = true;
    is_point_teacher = true;
    is_programmer_design = true;
    is_run_programmer = true;
    is_sport_control_instruction = true;
    teacher_display_point_table_init();
    QObject::connect(tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(getItem(QTableWidgetItem*)));
    QObject::connect(ui.programmer_design_display,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(getProgDesItem(QTableWidgetItem*)));
    QObject::connect(listener, SIGNAL(update_pendant_gui()), this, SLOT(update_pendant_gui()));
    QObject::connect(programmer_run_thread, SIGNAL(get_command_execute_row(int)), this, SLOT(get_command_execute_row(int)));
    QObject::connect(programmer_run_thread, SIGNAL(programmer_run_error_type(int)), this, SLOT(programmer_run_error_type(int)));
    //QObject::connect(file, SIGNAL(directoryEntered(QString)), this, SLOT(directoryEntered(QString)));
    ui.main_interface->setCurrentIndex(0);
    ui.teacher_speed_edittext->setText("0");
    programmer_design_interface_init();
    run_programmer_interface_init();
    project_file_init();
    reinitialize_interface();
    /*int i=0, j=0;
    for(i=0; i<MAX_POINT_ROW; ++i)
    {
        for(j=0; j<MAX_POINT_COLUMN; ++j)
        {
            teacher_point[i][j] = new QTableWidgetItem;
            teacher_point[i][j]->setText("");
        }
    }
    for(i=0; i<MAX_PROGRAMMER_ROW; ++i)
    {
        for(j=0; j<MAX_PROGRAMMER_COLUMN; ++j)
        {
            programmer_design_point[i][j] = new QTableWidgetItem;
            programmer_design_point[i][j]->setText("");
        }
    }*/
    //qnode->on_init("http://192.168.3.188:11311/", "192.168.3.126");
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //ui.joint_coordinate_table->setText(QObject::tr("你哈1"));
}

MainWindow::~MainWindow()
{
    /*int i=0, j=0;
    for(i=0; i<MAX_POINT_ROW; ++i)
    {
        for(j=0; j<MAX_POINT_COLUMN; ++j)
        {
            delete teacher_point[i][j];
        }
    }*/
}

void MainWindow::on_parameter_setting_pressed()
{
    ui.main_interface->setCurrentIndex(0);
}

void MainWindow::on_point_teacher_pressed()
{
    ui.main_interface->setCurrentIndex(1);
}

void MainWindow::on_programmer_design_pressed()
{
    ui.main_interface->setCurrentIndex(2);
    if((login_status == ADMINISTRATORS_LOGIN) || (login_status == SYSTEM_LOGIN))
    {
        if((tableWidget->rowCount() == 0))
        {
            ui.sport_control_instruction->setEnabled(false);
            is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
        }else
        {
            ui.sport_control_instruction->setEnabled(true);
            is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
        }
    }
}

void MainWindow::on_run_programmer_pressed()
{
    static int row = 0, column = 0;
    int i = 0, j = 0;
    ui.run_programmer_content->setRowCount(ui.programmer_design_display->rowCount());
    if(((row > 0) && (column > 0)))
    {
        for(i=0; i<row; ++i)
        {
            for(j=0; j<column; ++j)
            {
                delete tablewidgetitem[row][column];
            }
        }
    }

    for(row=0; row<ui.programmer_design_display->rowCount(); row++)
    {
        for(column=0; column<ui.programmer_design_display->columnCount(); column++)
        {
            tablewidgetitem[row][column] = new QTableWidgetItem();
            if(ui.programmer_design_display->item(row, column) == NULL)
            {
                tablewidgetitem[row][column]->setText("");
            }else
            {
                tablewidgetitem[row][column]->setText((ui.programmer_design_display->item(row, column))->text());
            }
            ui.run_programmer_content->setItem(row, column, tablewidgetitem[row][column]);
        }
    }
    row = ui.programmer_design_display->rowCount();
    column = ui.programmer_design_display->columnCount();
    //current_execute_row = 0;
    ui.run_position->setText(QString::number(current_execute_row));
    ui.run_programmer_content->setCurrentCell(current_execute_row, 0);
    ui.main_interface->setCurrentIndex(3);
    //以非数字为界限
    //ui.run_position->setText(ui.run_programmer_content->item(1, 1)->text().section(QRegExp("\\D+"), 1, 1));
}

void MainWindow::on_point_to_point_motion_pressed()
{
    for(int i=0; i<6; i++)
    {
        (teach_p2p->get_teacher_point_to_point_position_point())[i] = tableWidget->item(tableWidget->currentRow(), i+2)->text().toDouble();
    }
    teach_p2p->set_teacher_speed(ui.teacher_speed_edittext->toPlainText().toInt());
    teach_p2p->get_teach_p2p_ui().point_value->setText(QString::number(tableWidget->currentRow()));
    teach_p2p->setWindowFlags(Qt::WindowStaysOnTopHint);
    teach_p2p->move(WINDOW_CENTER_X, WINDOW_CENTER_Y);
    teach_p2p->setModal(false);
    teach_p2p->exec();
}

void MainWindow::on_straight_line_motion_pressed()
{
    for(int i=0; i<6; i++)
    {
        (teach_str_line->get_teacher_straight_line_position_point())[i] = tableWidget->item(tableWidget->currentRow(), i+2)->text().toDouble();
    }
    teach_str_line->set_teacher_speed(ui.teacher_speed_edittext->toPlainText().toInt());
    teach_str_line->get_teach_str_ui().diaplay_value->setText(QString::number(tableWidget->currentRow()));
    teach_str_line->setWindowFlags(Qt::WindowStaysOnTopHint);
    teach_str_line->move(WINDOW_CENTER_X, WINDOW_CENTER_Y);
    teach_str_line->setModal(false);
    teach_str_line->exec();
}

void MainWindow::teacher_display_point_table_init()
{
    tableWidget->setColumnCount(8);
    QStringList header;
    header<<"J"<<"Remarks"<<"J1(deg)"<<"J2(deg)"<<"J3(deg)"<<"J4(deg)"<<"J5(deg)"<<"J6(deg)";
    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->setColumnWidth(0,78);
    tableWidget->setColumnWidth(1,0);
    tableWidget->setColumnWidth(2,79);
    tableWidget->setColumnWidth(3,78);
    tableWidget->setColumnWidth(4,78);
    tableWidget->setColumnWidth(5,78);
    tableWidget->setColumnWidth(6,78);
    tableWidget->setColumnWidth(7,78);

    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->verticalHeader()->setVisible(false);
    //only select row
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //only select one
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //single clicked
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //if row count greater then 0
    if(tableWidget->rowCount() > 0)
    {
        tableWidget->setCurrentCell(0,0);
        ui.point_to_point_motion->setEnabled(true);
        is_point_to_point_motion = ui.point_to_point_motion->isEnabled();
        ui.straight_line_motion->setEnabled(true);
        is_straight_line_motion = ui.straight_line_motion->isEnabled();
        ui.delete_point->setEnabled(true);
        is_delete_point = ui.delete_point->isEnabled();
        ui.modify_point->setEnabled(true);
        is_modify_point = ui.modify_point->isEnabled();
    }else
    {
        teacher_point_null_init();
    }
}

void MainWindow::update_pendant_gui()
{
    //six axes joint degress value
    ui.J1_value->setText(QString::number(listener->param->joint_states[0] * TRANSFORM_ANGLE, 'f', 5));
    ui.J2_value->setText(QString::number(listener->param->joint_states[1] * TRANSFORM_ANGLE, 'f', 5));
    ui.J3_value->setText(QString::number(listener->param->joint_states[2] * TRANSFORM_ANGLE, 'f', 5));
    ui.J4_value->setText(QString::number(listener->param->joint_states[3] * TRANSFORM_ANGLE, 'f', 5));
    ui.J5_value->setText(QString::number(listener->param->joint_states[4] * TRANSFORM_ANGLE, 'f', 5));
    ui.J6_value->setText(QString::number(listener->param->joint_states[5] * TRANSFORM_ANGLE, 'f', 5));
    ui.J1_value_2->setText(QString::number(listener->param->cartesian_state[0], 'f', 5));
    ui.J2_value_2->setText(QString::number(listener->param->cartesian_state[1], 'f', 5));
    ui.J3_value_2->setText(QString::number(listener->param->cartesian_state[2], 'f', 5));
    ui.J4_value_2->setText(QString::number(listener->param->cartesian_state[3], 'f', 5));
    ui.J5_value_2->setText(QString::number(listener->param->cartesian_state[4], 'f', 5));
    ui.J6_value_2->setText(QString::number(listener->param->cartesian_state[5], 'f', 5));

}

void MainWindow::on_new_point_pressed()
{
    //new QTableWidgetItem(QString::number(teacher_point_list_count))
    tableWidget->insertRow(teacher_point_list_count);
    //teacher_point[teacher_point_list_count][0]->setText(QString::number(teacher_point_list_count));
    tableWidget->setItem(teacher_point_list_count,0, new QTableWidgetItem(QString::number(teacher_point_list_count)));
    tableWidget->setItem(teacher_point_list_count,1, new QTableWidgetItem(QString("")));
    for(int i=0; i<6; i++)
    {
         //teacher_point[teacher_point_list_count][i+2]->setText(QString::number(listener->param->joint_states[i]));
         //tableWidget->setItem(teacher_point_list_count, i+2, teacher_point[teacher_point_list_count][i+2]);
         tableWidget->setItem(teacher_point_list_count, i+2, new QTableWidgetItem(QString::number(listener->param->joint_states[i])));
    }
    if(teacher_point_list_count == 0)
    {
        tableWidget->setCurrentCell(0,0);
    }
    teacher_point_list_count++;
    ui.point_to_point_motion->setEnabled(true);
    is_point_to_point_motion = ui.point_to_point_motion->isEnabled();
    ui.straight_line_motion->setEnabled(true);
    is_straight_line_motion = ui.straight_line_motion->isEnabled();
    ui.delete_point->setEnabled(true);
    is_delete_point = ui.delete_point->isEnabled();
    ui.modify_point->setEnabled(true);
    is_modify_point = ui.modify_point->isEnabled();
}

//input one number
void MainWindow::getItem(QTableWidgetItem* table_widget_item)
{
    if((login_status == ADMINISTRATORS_LOGIN) || (login_status == SYSTEM_LOGIN))
    {
        if(isopendialog == false)
        {
            int row = table_widget_item->row();
            int column = table_widget_item->column();
            if((column >= 2) && (row >= 0))
            {
                //set min_vlaue and set max_value
                switch(column)
                {
                    case 2:
                        input_number->getUiHandler()->min_value->setText(QString::number(LIMIT_MIN_POSITION_JOINT_1));
                        input_number->getUiHandler()->max_value->setText(QString::number(LIMIT_MAX_POSITION_JOINT_1));
                    break;

                    case 3:
                        input_number->getUiHandler()->min_value->setText(QString::number(LIMIT_MIN_POSITION_JOINT_2));
                        input_number->getUiHandler()->max_value->setText(QString::number(LIMIT_MAX_POSITION_JOINT_2));
                    break;
                    case 4:
                        input_number->getUiHandler()->min_value->setText(QString::number(LIMIT_MIN_POSITION_JOINT_3));
                        input_number->getUiHandler()->max_value->setText(QString::number(LIMIT_MAX_POSITION_JOINT_3));
                    break;
                    case 5:
                        input_number->getUiHandler()->min_value->setText(QString::number(LIMIT_MIN_POSITION_JOINT_4));
                        input_number->getUiHandler()->max_value->setText(QString::number(LIMIT_MAX_POSITION_JOINT_4));
                    break;
                    case 6:
                        input_number->getUiHandler()->min_value->setText(QString::number(LIMIT_MIN_POSITION_JOINT_5));
                        input_number->getUiHandler()->max_value->setText(QString::number(LIMIT_MAX_POSITION_JOINT_5));
                    break;
                    case 7:
                        input_number->getUiHandler()->min_value->setText(QString::number(LIMIT_MIN_POSITION_JOINT_6));
                        input_number->getUiHandler()->max_value->setText(QString::number(LIMIT_MAX_POSITION_JOINT_6));
                    break;
                    default:
                    break;
                }

                //display input_number.ui
                input_number->set_input_number_type(ANY_NUMBER);
                input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
                input_number->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
                input_number->setModal(false);
                isopendialog = true;
                input_number->exec();
                if(input_number->get_succeed_write_status())
                {
                    //teacher_point[row][column]->setText(QString::number(input_number->value_number()));
                    //tableWidget->setItem(row, column, teacher_point[row][column]);
                    tableWidget->setItem(row, column, new QTableWidgetItem(QString::number(input_number->value_number())));
                }
                input_number->set_succeed_write_status(false);
                isopendialog = false;
                //input_number->clean_Value_any_type();
            }
        }
    }
}

Ui::MainWindowDesign MainWindow::get_Ui_MainWindowDesign()
{
    return ui;
}

void MainWindow::on_teacher_speed_edittext_selectionChanged()
{
    if(isopendialog == false)
    {
        isopendialog = true;
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->getUiHandler()->min_value->setText(QString::number(MIN_SPEED));
        input_number->getUiHandler()->max_value->setText(QString::number(MAX_SPEED));
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            ui.teacher_speed_edittext->setText(QString::number(input_number->value_number()));
        }
        input_number->set_succeed_write_status(false);
        isopendialog = false;
        //input_number->clean_Value_positive_integer_type();
    }
}


void MainWindow::on_delete_point_pressed()
{
    delete_select_point->setWindowFlags(Qt::WindowStaysOnTopHint);
    delete_select_point->setModal(false);
    delete_select_point->move(WINDOW_CENTER_X, WINDOW_CENTER_Y);
    delete_select_point->exec();
    if(delete_select_point->get_succeed_status())
    {
        tableWidget->removeRow(tableWidget->rowCount() - 1);
        teacher_point_list_count--;
        delete_select_point->set_succeed_status(false);
    }
    if(0 == teacher_point_list_count)
    {
        teacher_point_null_init();
    }
}

void MainWindow::on_modify_point_pressed()
{
    modify_point->get_modify_point_position_dialog_ui_point()->display_modify_point_label->setText(QString::number(tableWidget->currentRow()));
    modify_point->setWindowFlags(Qt::WindowStaysOnTopHint);
    modify_point->setModal(false);
    modify_point->move(WINDOW_CENTER_X, WINDOW_CENTER_Y);
    modify_point->exec();
    if(modify_point->get_succeed_status())
    {
        for(int i=0; i<6; i++)
        {
            tableWidget->setItem(tableWidget->currentRow(), i+2, new QTableWidgetItem(QString::number(listener->param->joint_states[i])));
        }
        modify_point->set_succeed_status(false);
    }
}

void MainWindow::teacher_point_null_init()
{
    ui.point_to_point_motion->setEnabled(false);
    is_point_to_point_motion = ui.point_to_point_motion->isEnabled();
    ui.straight_line_motion->setEnabled(false);
    is_straight_line_motion = ui.straight_line_motion->isEnabled();
    ui.delete_point->setEnabled(false);
    is_delete_point = ui.delete_point->isEnabled();
    ui.modify_point->setEnabled(false);
    is_modify_point = ui.modify_point->isEnabled();
}

void MainWindow::on_J1_negative_direction_pressed()
{
    qnode->pub_jog_start_command(1);
}

void MainWindow::on_J1_negative_direction_released()
{
    qnode->pub_jog_stop_command(1);
}

void MainWindow::on_J1_positive_direction_pressed()
{
    qnode->pub_jog_start_command(2);
}

void MainWindow::on_J1_positive_direction_released()
{
    qnode->pub_jog_stop_command(2);
}

void MainWindow::on_J2_negative_direction_pressed()
{
    qnode->pub_jog_start_command(3);
}

void MainWindow::on_J2_negative_direction_released()
{
    qnode->pub_jog_stop_command(3);
}

void MainWindow::on_J2_positive_direction_pressed()
{
    qnode->pub_jog_start_command(4);
}

void MainWindow::on_J2_positive_direction_released()
{
    qnode->pub_jog_stop_command(4);
}

void MainWindow::on_J3_negative_direction_pressed()
{
    qnode->pub_jog_start_command(5);
}

void MainWindow::on_J3_negative_direction_released()
{
    qnode->pub_jog_stop_command(5);
}

void MainWindow::on_J3_positive_direction_pressed()
{
    qnode->pub_jog_start_command(6);
}

void MainWindow::on_J3_positive_direction_released()
{
    qnode->pub_jog_stop_command(6);
}

void MainWindow::on_J4_negative_direction_pressed()
{
    qnode->pub_jog_start_command(7);
}

void MainWindow::on_J4_negative_direction_released()
{
    qnode->pub_jog_stop_command(7);
}

void MainWindow::on_J4_positive_direction_pressed()
{
    qnode->pub_jog_start_command(8);
}

void MainWindow::on_J4_positive_direction_released()
{
    qnode->pub_jog_stop_command(8);
}

void MainWindow::on_J5_negative_direction_pressed()
{
    qnode->pub_jog_start_command(9);
}

void MainWindow::on_J5_negative_direction_released()
{
    qnode->pub_jog_stop_command(9);
}

void MainWindow::on_J5_positive_direction_pressed()
{
    qnode->pub_jog_start_command(10);
}

void MainWindow::on_J5_positive_direction_released()
{
    qnode->pub_jog_stop_command(10);
}

void MainWindow::on_J6_negative_direction_pressed()
{
    qnode->pub_jog_start_command(11);
}

void MainWindow::on_J6_negative_direction_released()
{
    qnode->pub_jog_stop_command(11);
}

void MainWindow::on_J6_positive_direction_pressed()
{
    qnode->pub_jog_start_command(12);
}

void MainWindow::on_J6_positive_direction_released()
{
    qnode->pub_jog_stop_command(12);
}

void MainWindow::on_common_function_instruction_pressed()
{
    QString goto_flag = "转到行", goto_instruction_text;
    int goto_row_change;
    //assert(ui.programmer_design_display->item(current_select_command, 1) != NULL);
    current_select_command = ui.programmer_design_display->currentRow();
    if((current_select_command == 0) || (current_select_command == (command_total - 1)))
    {
        QString display_text;
        display_text = "第0行和最后一行不能输入指令！";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    }else if((ui.programmer_design_display->item(current_select_command, 1) == NULL) ||
             (ui.programmer_design_display->item(current_select_command, 1)->text().isEmpty()))//create a new row ,return 0, not is have a value point
    {
        comm_function->set_command_total(command_total);
        comm_function->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
        comm_function->setModal(false);
        comm_function->move(FRAMELESS_ORIGIN_X, FRAMELESS_ORIGIN_Y);
        comm_function->exec();
        //which instruction to choose
        if(comm_function->get_wait_time_dialog_status())
        {
            comm_function->set_wait_time_dialog_status(false);
            QString wait_text;
            wait_text = "等待" + QString::number(comm_function->get_wait_time_value()) + "毫秒";
            ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(wait_text));
            ui.programmer_design_display->insertRow(current_select_command + 1);
            command_total = ui.programmer_design_display->rowCount();
            for(int i=1; i<command_total; i++)
            {
                ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                if(ui.programmer_design_display->item(i, 1) != NULL)
                {
                    if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                    {
                        goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                        if(goto_row_change >= current_select_command)
                        {
                            goto_instruction_text = "转到" + QString::number(goto_row_change + 1) + "行";
                            ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                        }
                    }
                }
            }
            ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
            current_select_command = ui.programmer_design_display->currentRow();
        }else if(comm_function->get_goto_instruction_status())
        {
            comm_function->set_goto_instruction_status(false);
            QString goto_instruction_text;
            if(comm_function->get_goto_row() > current_select_command)
            {
                goto_instruction_text = "转到" + QString::number(comm_function->get_goto_row() + 1) + "行";
            }else if(comm_function->get_goto_row() == current_select_command)
            {
                goto_instruction_text = "转到" + QString::number(0) + "行";
            }else
            {
                goto_instruction_text = "转到" + QString::number(comm_function->get_goto_row()) + "行";
            }
            ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(goto_instruction_text));
            ui.programmer_design_display->insertRow(current_select_command + 1);
            ui.programmer_design_display->setCurrentCell(current_select_command, 0);
            command_total = ui.programmer_design_display->rowCount();
            current_select_command = ui.programmer_design_display->currentRow();
            for(int i=1; i<command_total; i++)
            {
                ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                ui.programmer_design_display->setCurrentCell(current_select_command, 0);
                if((ui.programmer_design_display->item(i, 1) != NULL) && (i != current_select_command))
                {
                    if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                    {
                        goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                        if(goto_row_change >= current_select_command)
                        {
                            goto_instruction_text = "转到" + QString::number(goto_row_change + 1) + "行";
                            ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                        }
                    }
                }
            }
            ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
            current_select_command = ui.programmer_design_display->currentRow();
        }
    }else
    {
        QString display_text;
        display_text = "确定需要更改第" + QString::number(current_select_command) + "行程序指令？";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->exec();
        if(common_dialog->get_common_dialog_succeed_status())
        {
            common_dialog->set_common_dialog_succeed_status(false);
            comm_function->set_command_total(command_total);
            comm_function->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
            comm_function->setModal(false);
            comm_function->move(FRAMELESS_ORIGIN_X, FRAMELESS_ORIGIN_Y);
            comm_function->exec();
            //which instruction to choose
            if(comm_function->get_wait_time_dialog_status())
            {
                comm_function->set_wait_time_dialog_status(false);
                QString wait_text;
                wait_text = "等待" + QString::number(comm_function->get_wait_time_value()) + "毫秒";
                ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(wait_text));
                //ui.programmer_design_display->insertRow(current_select_command + 1);
                //ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
                command_total = ui.programmer_design_display->rowCount();
                current_select_command = ui.programmer_design_display->currentRow();
                for(int i=1; i<command_total; i++)
                {
                    ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                }
            }else if(comm_function->get_goto_instruction_status())
            {
                comm_function->set_goto_instruction_status(false);
                QString goto_instruction_text;
                if(comm_function->get_goto_row() > current_select_command)
                {
                    goto_instruction_text = "转到" + QString::number(comm_function->get_goto_row() + 1) + "行";
                }else if(comm_function->get_goto_row() == current_select_command)
                {
                    goto_instruction_text = "转到" + QString::number(0) + "行";
                }else
                {
                    goto_instruction_text = "转到" + QString::number(comm_function->get_goto_row() + 1) + "行";
                }
                ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(goto_instruction_text));
                //ui.programmer_design_display->insertRow(current_select_command + 1);
                //ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
                command_total = ui.programmer_design_display->rowCount();
                current_select_command = ui.programmer_design_display->currentRow();
                for(int i=1; i<command_total; i++)
                {
                    ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                }
            }
        }
    }
}

void MainWindow::programmer_design_interface_init()
{
    programmer_design_robot_function_init();
    programmer_design_tablewidget_init();
}

//initialize some of the required functions and some of the features which do not require
void MainWindow::programmer_design_robot_function_init()
{
    //Common_Function window initialization, delete not required functions
    comm_function->get_common_function_ui()->prog_design_acc_dec_time_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_count_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_input_judgment_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_loop_end_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_loop_start_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_notes_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_rate_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_set_output_button->setHidden(true);
    comm_function->get_common_function_ui()->prog_design_wait_input_button->setHidden(true);

    //Sport_Instruction window initialization, delete not required functions
    sport_instr->get_sport_instruction_ui()->smooth_function_button->setHidden(true);
    sport_instr->get_sport_instruction_ui()->arc_auxiliary_point->setHidden(true);
    sport_instr->get_sport_instruction_ui()->arc_end_point->setHidden(true);
    sport_instr->get_sport_instruction_ui()->tool_conversion->setHidden(true);
    sport_instr->get_sport_instruction_ui()->workpiece_coordinate->setHidden(true);
}

//initalize programmer design tablewidget
void MainWindow::programmer_design_tablewidget_init()
{
    //do not read on data from outside initalize tablewidget
    ui.programmer_design_display->setColumnCount(MAX_PROGRAMMER_COLUMN);
    QStringList header;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    header<<"行数"<<"程序内容";
    ui.programmer_design_display->setHorizontalHeaderLabels(header);
    ui.programmer_design_display->setColumnWidth(0, 78);
    ui.programmer_design_display->setColumnWidth(1, 482);
    ui.programmer_design_display->horizontalHeader()->setVisible(true);
    ui.programmer_design_display->verticalHeader()->setVisible(false);
    ui.programmer_design_display->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.programmer_design_display->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.programmer_design_display->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //initalize tablewidget content
    QString programmer_start = "程序开始";
    QString programmer_end = "结束";
    command_total = 2;
    current_select_command = 0;
    ui.programmer_design_display->setRowCount(command_total);
    ui.programmer_design_display->setItem(0, 0, new QTableWidgetItem(QString::number(0)));
    ui.programmer_design_display->setItem(0, 1, new QTableWidgetItem(programmer_start));
    ui.programmer_design_display->setItem(1, 0, new QTableWidgetItem(QString::number(1)));
    ui.programmer_design_display->setItem(1, 1, new QTableWidgetItem(programmer_end));
    ui.programmer_design_display->setCurrentCell(current_select_command, 0);
}

void MainWindow::on_insert_button_pressed()
{
    int i = 0;
    int goto_row_change;
    QString goto_flag = "转到行", goto_instruction_text;
    if(ui.programmer_design_display->currentRow() == 0)
    {
        ui.programmer_design_display->insertRow(1);
        command_total = ui.programmer_design_display->rowCount();
        for(i=1; i<command_total; i++)
        {
            ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
            if(ui.programmer_design_display->item(i, 1) != NULL)
            {
                if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                {
                    goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                    if(goto_row_change >= current_select_command)
                    {
                        if(goto_row_change != 0)
                        {
                            ++goto_row_change;
                        }
                        goto_instruction_text = "转到" + QString::number(goto_row_change) + "行";
                        ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                    }
                }
            }
        }
        ui.programmer_design_display->setCurrentCell(1, 0);
        current_select_command = 1;
    }else
    {
       current_select_command = ui.programmer_design_display->currentRow();
       ui.programmer_design_display-> insertRow(current_select_command);
       command_total = ui.programmer_design_display->rowCount();
       ui.programmer_design_display->setCurrentCell(current_select_command, 0);
       //ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(null_string));
       for(i=1; i<command_total; i++)
       {
           ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
           if(ui.programmer_design_display->item(i, 1) != NULL)
           {
               if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
               {
                   goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                   if(goto_row_change >= current_select_command)
                   {
                       goto_instruction_text = "转到" + QString::number(goto_row_change + 1) + "行";
                       ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                   }
               }
           }
       }
    }
}

void MainWindow::getProgDesItem(QTableWidgetItem* programmer_design_item)
{
    current_select_command = programmer_design_item->row();
}

void MainWindow::on_delete_button_pressed()
{
    int goto_row_change;
    QString goto_flag = "转到行", goto_instruction_text;
    current_select_command = ui.programmer_design_display->currentRow();
    common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    if(current_select_command == 0)//first row
    {
        ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
        current_select_command++;
    }else if(current_select_command == (command_total - 1))//end row
    {
        ui.programmer_design_display->setCurrentCell(current_select_command - 1, 0);
        current_select_command--;
    }else
    {
        if((ui.programmer_design_display->item(current_select_command, 1) == NULL) ||
                (ui.programmer_design_display->item(current_select_command, 1)->text().isEmpty()))
        {
            ui.programmer_design_display->removeRow(current_select_command);
            command_total = ui.programmer_design_display->rowCount();
            for(int i=1; i<command_total; i++)
            {
                ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                if(ui.programmer_design_display->item(i, 1) != NULL)
                {
                    if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                    {
                        goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                        if(goto_row_change >= current_select_command)
                        {
                            goto_instruction_text = "转到" + QString::number(goto_row_change - 1) + "行";
                            ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                        }
                    }
                }
            }
        }else
        {
            QString delete_row_text;
            delete_row_text = "确认删除第" + QString::number(current_select_command) + "行吗？";
            common_dialog->get_common_dialog_ui()->display_text_label->setText(delete_row_text);
            common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
            common_dialog->setModal(false);
            common_dialog->exec();
            if(common_dialog->get_common_dialog_succeed_status())
            {
                common_dialog->set_common_dialog_succeed_status(false);
                ui.programmer_design_display->removeRow(current_select_command);
                command_total = ui.programmer_design_display->rowCount();
                for(int i=1; i<command_total; i++)
                {
                    ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                    if(ui.programmer_design_display->item(i, 1) != NULL)
                    {
                        if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                        {
                            goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                            if(goto_row_change >= current_select_command)
                            {
                                goto_instruction_text = "转到" + QString::number(goto_row_change - 1) + "行";
                                ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                            }
                        }
                    }
                }
            }
        }
    }  
}

void MainWindow::on_sport_control_instruction_pressed()
{
    QString goto_flag = "转到行", goto_instruction_text;
    int goto_row_change;
    current_select_command = ui.programmer_design_display->currentRow();
    if((current_select_command == 0) || (current_select_command == (command_total - 1)))
    {
        QString display_text;
        display_text = "第0行和最后一行不能输入指令！";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    }else if((ui.programmer_design_display->item(current_select_command, 1) == NULL) ||
             (ui.programmer_design_display->item(current_select_command, 1)->text().isEmpty()))//create a new row ,return 0, not is have a vaild value point
    {
        //sport_instr->set_command_total(command_total);
        sport_instr->set_max_point(tableWidget->rowCount() - 1);
        sport_instr->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
        sport_instr->setModal(false);
        sport_instr->move(FRAMELESS_ORIGIN_X, FRAMELESS_ORIGIN_Y);
        sport_instr->exec();
        //which instruction to choose
        if(sport_instr->get_joint_sport_status())
        {
            sport_instr->set_joint_sport_status(false);
            QString joint_sport_text;
            joint_sport_text = "点位运动 J" + QString::number(sport_instr->get_first_point_value()) + ", 速度="
                    + QString::number(sport_instr->get_speed_value()) + "%";
            ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(joint_sport_text));
            ui.programmer_design_display->insertRow(current_select_command + 1);
            ui.programmer_design_display->setCurrentCell(current_select_command, 0);
            command_total = ui.programmer_design_display->rowCount();
            current_select_command = ui.programmer_design_display->currentRow();
            for(int i=1; i<command_total; i++)
            {
                ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                if(ui.programmer_design_display->item(i, 1) != NULL)
                {
                    if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                    {
                        goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                        if(goto_row_change >= current_select_command)
                        {
                            goto_instruction_text = "转到" + QString::number(goto_row_change + 1) + "行";
                            ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                        }
                    }
                }
            }
            ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
            current_select_command = ui.programmer_design_display->currentRow();
        }else if(sport_instr->get_straight_sport_status())
        {
            sport_instr->set_straight_sport_status(false);
            QString straight_sport_text;
            straight_sport_text = "直线运动 J" + QString::number(sport_instr->get_first_point_value()) + ", 速度="
                    + QString::number(sport_instr->get_speed_value()) + "毫米/秒";
            ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(straight_sport_text));
            ui.programmer_design_display->insertRow(current_select_command + 1);
            ui.programmer_design_display->setCurrentCell(current_select_command, 0);
            command_total = ui.programmer_design_display->rowCount();
            current_select_command = ui.programmer_design_display->currentRow();
            for(int i=1; i<command_total; i++)
            {
                ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                if(ui.programmer_design_display->item(i, 1) != NULL)
                {
                    if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                    {
                        goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                        if(goto_row_change >= current_select_command)
                        {
                            goto_instruction_text = "转到" + QString::number(goto_row_change + 1) + "行";
                            ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                        }
                    }
                }
            }
            ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
            current_select_command = ui.programmer_design_display->currentRow();
        }else if(sport_instr->get_circle_sport_status())
        {
            sport_instr->set_circle_sport_status(false);
            QString circle_sport_text;
            circle_sport_text = "圆弧运动 J" + QString::number(sport_instr->get_first_point_value()) +
                   ", J" + QString::number(sport_instr->get_second_point_value()) +", 速度=" + QString::number(sport_instr->get_speed_value()) + "毫米/秒";
            ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(circle_sport_text));
            ui.programmer_design_display->insertRow(current_select_command + 1);
            ui.programmer_design_display->setCurrentCell(current_select_command, 0);
            command_total = ui.programmer_design_display->rowCount();
            current_select_command = ui.programmer_design_display->currentRow();
            for(int i=1; i<command_total; i++)
            {
                ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                if(ui.programmer_design_display->item(i, 1) != NULL)
                {
                    if((ui.programmer_design_display->item(i, 1)->text().split(QRegExp("\\d+")).join("").operator ==(goto_flag)))
                    {
                        goto_row_change = ui.programmer_design_display->item(i, 1)->text().section(QRegExp("\\D+"), 1, 1).toInt();
                        if(goto_row_change >= current_select_command)
                        {
                            goto_instruction_text = "转到" + QString::number(goto_row_change + 1) + "行";
                            ui.programmer_design_display->setItem(i, 1, new QTableWidgetItem(goto_instruction_text));
                        }
                    }
                }
            }
            ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
            current_select_command = ui.programmer_design_display->currentRow();
        }

    }else
    {
        QString display_text;
        display_text = "确定需要更改第" + QString::number(current_select_command) + "行程序指令？";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->exec();
        if(common_dialog->get_common_dialog_succeed_status())
        {
            common_dialog->set_common_dialog_succeed_status(false);
            sport_instr->set_max_point(tableWidget->rowCount() - 1);
            sport_instr->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowTitleHint | Qt::FramelessWindowHint);
            sport_instr->setModal(false);
            sport_instr->move(FRAMELESS_ORIGIN_X, FRAMELESS_ORIGIN_Y);
            sport_instr->exec();
            //which instruction to choose
            if(sport_instr->get_joint_sport_status())
            {
                sport_instr->set_joint_sport_status(false);
                QString joint_sport_text;
                joint_sport_text = "点位运动 J" + QString::number(sport_instr->get_first_point_value()) + ", 速度="
                        + QString::number(sport_instr->get_speed_value()) + "%";
                ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(joint_sport_text));
                //ui.programmer_design_display->insertRow(current_select_command + 1);
                //ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
                command_total = ui.programmer_design_display->rowCount();
                current_select_command = ui.programmer_design_display->currentRow();
                for(int i=1; i<command_total; i++)
                {
                    ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                }
            }else if(sport_instr->get_straight_sport_status())
            {
                sport_instr->set_straight_sport_status(false);
                QString straight_sport_text;
                straight_sport_text = "直线运动 J" + QString::number(sport_instr->get_first_point_value()) + ", 速度="
                        + QString::number(sport_instr->get_speed_value()) + "毫米/秒";
                ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(straight_sport_text));
                //ui.programmer_design_display->insertRow(current_select_command + 1);
                //ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
                command_total = ui.programmer_design_display->rowCount();
                current_select_command = ui.programmer_design_display->currentRow();
                for(int i=1; i<command_total; i++)
                {
                    ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                }
            }else if(sport_instr->get_circle_sport_status())
            {
                sport_instr->set_circle_sport_status(false);
                QString circle_sport_text;
                circle_sport_text = "圆弧运动 J" + QString::number(sport_instr->get_first_point_value()) +
                       ", J" + QString::number(sport_instr->get_second_point_value()) +", 速度=" + QString::number(sport_instr->get_speed_value()) + "毫米/秒";
                ui.programmer_design_display->setItem(current_select_command, 1, new QTableWidgetItem(circle_sport_text));
                //ui.programmer_design_display->insertRow(current_select_command + 1);
                //ui.programmer_design_display->setCurrentCell(current_select_command + 1, 0);
                command_total = ui.programmer_design_display->rowCount();
                current_select_command = ui.programmer_design_display->currentRow();
                for(int i=1; i<command_total; i++)
                {
                    ui.programmer_design_display->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
                }
            }
        }
    }
}

void MainWindow::run_programmer_interface_init()
{
    run_programmer_content_init();
    //row = ui.programmer_design_display->rowCount();
    //column = ui.programmer_design_display->columnCount();
    current_execute_row = 0;
    ui.run_position->setText(QString::number(current_execute_row));
    ui.run_programmer_content->setCurrentCell(current_execute_row, 0);
}

void MainWindow::run_programmer_content_init()
{
    ui.run_programmer_content->setColumnCount(MAX_PROGRAMMER_COLUMN);
    QStringList header;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    header<<"行数"<<"程序内容";
    ui.run_programmer_content->setHorizontalHeaderLabels(header);
    ui.run_programmer_content->setColumnWidth(0, 78);
    ui.run_programmer_content->setColumnWidth(1, 541);
    ui.run_programmer_content->horizontalHeader()->setVisible(true);
    ui.run_programmer_content->verticalHeader()->setVisible(false);
    ui.run_programmer_content->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.run_programmer_content->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.run_programmer_content->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_run_programmer_content_clicked(const QModelIndex &index)
{
    ui.run_programmer_content->setCurrentCell(current_execute_row, 0);
}

void MainWindow::on_run_button_pressed()
{
    if(programmer_run_status == READY_PROGRAMMER)
    {
        current_execute_row = 0;
        ui.run_position->setText(QString::number(current_execute_row));
        programmer_run_thread->set_command_execute_row(current_execute_row);
        programmer_run_thread->set_command_content(ui.run_programmer_content->item(current_execute_row, 1)->text());
        programmer_run_thread->set_programmer_run_status(true);
        programmer_run_thread->set_signal(true);
        programmer_run_thread->start();
        //ui.run_button->setEnabled(false);
        programmer_run_interface_init();
        listener->set_programmer_status(true);
    }else if(programmer_run_status == PAUSE_PROGRAMMER)
    {
        ui.run_position->setText(QString::number(current_execute_row));
        programmer_run_thread->set_command_execute_row(current_execute_row);
        programmer_run_thread->set_command_content(ui.run_programmer_content->item(current_execute_row, 1)->text());
        programmer_run_thread->set_programmer_run_status(true);
        programmer_run_thread->set_signal(true);
        programmer_run_thread->start();
        //ui.run_button->setEnabled(false);
        programmer_run_interface_init();
        listener->set_programmer_status(true);
    }

}

void MainWindow::get_command_execute_row(int execute_row)
{
    if(!(ui.run_button->isEnabled()))
    {
        current_execute_row = execute_row;
        ui.run_programmer_content->setCurrentCell(current_execute_row, 0);
        if((current_execute_row < command_total))
        {
            ui.run_position->setText(QString::number(current_execute_row));
            programmer_run_thread->set_command_content(ui.run_programmer_content->item(current_execute_row, 1)->text());
            programmer_run_thread->set_signal(true);
        }else
        {
            ui.run_programmer_content->setCurrentCell(command_total - 1, 0);
            programmer_run_thread->set_programmer_run_status(false);
            programmer_run_thread->set_signal(false);
            programmer_run_thread->wait();
            //ui.run_button->setEnabled(true);
            programmer_ready_interface_init();
            listener->set_programmer_status(false);
            programmer_run_status = READY_PROGRAMMER;
        }
    }
}

void MainWindow::on_pause_programmer_button_pressed()
{
    programmer_run_thread->set_programmer_run_status(false);
    programmer_run_thread->set_signal(false);
    QWaitCondition* wait_condition = programmer_run_thread->get_wait_condition();
    wait_condition->wakeAll();
    programmer_run_thread->wait();
    //ui.run_button->setEnabled(true);
    programmer_ready_interface_init();
    listener->set_programmer_status(false);
    programmer_run_status = PAUSE_PROGRAMMER;
}

void MainWindow::on_stop_programmer_button_pressed()
{
    programmer_run_thread->set_programmer_run_status(false);
    programmer_run_thread->set_signal(false);
    QWaitCondition* wait_condition = programmer_run_thread->get_wait_condition();
    wait_condition->wakeAll();
    programmer_run_thread->wait();
    //ui.run_button->setEnabled(true);
    programmer_ready_interface_init();
    listener->set_programmer_status(false);
    current_execute_row = 0;
    ui.run_position->setText(QString::number(current_execute_row));
    ui.run_programmer_content->setCurrentCell(current_execute_row, 0);
    programmer_run_status = READY_PROGRAMMER;
}

void MainWindow::on_new_file_button_pressed()
{
    if(version_no == OPERATOR_SYSTEM)
    {
        //QDir directory = QString("../../../../");
        QDir directory = QString("./");
        directory.mkdir(QString("save"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QString file_dialog_title = "新建文件";
        //QString new_file_name = file->getSaveFileName(this, file_dialog_title, "../../../../save/", tr("Text Document (*.txt)"));
        QString new_file_name = file->getSaveFileName(this, file_dialog_title, "./save/", tr("Text Document (*.txt)"));
        //ROS_INFO("prject save path: [%s]", new_file_name.data());
        if(!new_file_name.isEmpty())
        {
            int i = 0, j=0, rowcount = ui.programmer_design_display->rowCount()-1, point_count = ui.teacher_point_tableWidget->rowCount();
            for(i=1; i<rowcount; ++i)
            {
                ui.programmer_design_display->removeRow(1);
            }
            command_total = ui.programmer_design_display->rowCount();
            current_select_command = 0;
            //ui.programmer_design_display->setCurrentCell(current_select_command, 0);
            //int i=0, j=MAX_PROGRAMMER_COLUMN;
            ui.programmer_design_display->setItem(1, 0, new QTableWidgetItem(QString::number(1)));
            for(i=0; i<point_count; ++i)
            {
                ui.teacher_point_tableWidget->removeRow(0);
            }
            teacher_point_list_count = 0;
            teacher_point_null_init();
            ui.programmer_design_display->setCurrentCell(0, 0);
            QFile new_file(new_file_name + ".txt");
            if(new_file.open(QIODevice::ReadWrite | QIODevice::Truncate))
            {
                file_path = new_file_name + ".txt";
                QString file_name_save_path = directory.absolutePath() + "/save/.filename.txt";
                QFile open_save_file_name(file_name_save_path);
                if(open_save_file_name.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    QTextStream write_file_name(&open_save_file_name);
                    write_file_name<<file_path;
                    write_file_name.flush();
                    ui.sport_control_instruction->setEnabled(false);
                    is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
                }
                QTextStream out(&new_file);
                QString start_programmer = "程序开始";
                QString end_programmer = "结束";
                QString goto_instruction = "转到行";
                QString wait_instruction = "等待毫秒";
                QString joint_sport_instruction = "点位运动 J, 速度=%";
                QString straight_sport_instruction = "直线运动 J, 速度=毫米/秒";
                QString circle_sport_instruction = "圆弧运动 J, J, 速度=毫米/秒";
                QString null_instruction = "";
                QString save_start_programmer = "Program Begin";
                QString save_end_programmer = "End";
                QString save_goto_instruction = "Goto ";
                QString save_wait_instruction = "Delay ";
                QString save_joint_sport_instruction = "MoveJ J(";
                QString save_straight_sport_instruction = "MoveL J(";
                QString save_circle_sport_instruction = "MoveC J(";
                //QString save_null_instruction = "";
                //int wait_time_ms;
                //int point_row;
                QString command_remove_number;
                QString command_content;
                for(i=0; i<ui.programmer_design_display->rowCount(); ++i)
                {
                    for(j=0; j<ui.programmer_design_display->columnCount(); ++j)
                    {
                        command_content = ui.programmer_design_display->item(i, j)->text();
                        if(j == 1)
                        {
                            //out<<ui.programmer_design_display->item(i, j)->text()<<'&';
                            command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                            if(command_remove_number.operator ==(start_programmer))
                            {
                                out<<save_start_programmer<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(end_programmer))
                            {
                                out<<save_end_programmer<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(goto_instruction))
                            {
                                out<<save_goto_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(wait_instruction))
                            {
                                out<<save_wait_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"ms"<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(joint_sport_instruction))
                            {
                                out<<save_joint_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"%"<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(straight_sport_instruction))
                            {
                                out<<save_straight_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"mm/s"<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(circle_sport_instruction))
                            {
                                out<<save_circle_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"), J("<<command_content.section(QRegExp("\\D+"), 2, 2)<<"),VL="<<command_content.section(QRegExp("\\D+"), 3, 3)<<"mm/s"<<'&';
                                out.flush();
                            }else if(command_remove_number.operator ==(null_instruction))
                            {
                                out<<'&';
                                out.flush();
                            }
                        }else
                        {
                            out<<command_content<<'&';
                            out.flush();
                        }
                    }
                }
                out<<'$';
                out.flush();
            }
        }
    }else if(version_no == USER_NOT_SELECT_PATH)
    {
        if(isopendialog == false)
        {
            QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
            QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
            virtualkeyboard->setWindowFlags(Qt::WindowStaysOnTopHint);
            virtualkeyboard->setModal(false);
            virtualkeyboard->move(FRAMELESS_ORIGIN_X, FRAMELESS_ORIGIN_Y);
            isopendialog = true;
            virtualkeyboard->exec();
            if(virtualkeyboard->get_succeed_status())
            {
                virtualkeyboard->set_succeed_status(false);
                QString project_name = virtualkeyboard->get_project_name();
                virtualkeyboard->set_project_name(QString(""));
                if(project_name.at(0) != QChar('/'))
                {
                    QDir directory = QString("./");
                    directory.mkdir(QString("save"));
                    QString new_file_name = directory.absolutePath() + "/save/" + project_name;

                    QFile new_file(new_file_name + ".txt");
                    if(new_file.open(QIODevice::ReadWrite | QIODevice::Truncate))
                    {
                        int i = 0, j=0, rowcount = ui.programmer_design_display->rowCount()-1, point_count = ui.teacher_point_tableWidget->rowCount();
                        for(i=1; i<rowcount; ++i)
                        {
                            ui.programmer_design_display->removeRow(1);
                        }
                        command_total = ui.programmer_design_display->rowCount();
                        current_select_command = 0;
                        //ui.programmer_design_display->setCurrentCell(current_select_command, 0);
                        //int i=0, j=MAX_PROGRAMMER_COLUMN;
                        ui.programmer_design_display->setItem(1, 0, new QTableWidgetItem(QString::number(1)));
                        for(i=0; i<point_count; ++i)
                        {
                            ui.teacher_point_tableWidget->removeRow(0);
                        }
                        teacher_point_list_count = 0;
                        teacher_point_null_init();
                        ui.programmer_design_display->setCurrentCell(0, 0);
                        file_path = new_file_name + ".txt";
                        QString file_name_save_path = directory.absolutePath() + "/save/.filename.txt";
                        QFile open_save_file_name(file_name_save_path);
                        if(open_save_file_name.open(QIODevice::WriteOnly | QIODevice::Truncate))
                        {
                            QTextStream write_file_name(&open_save_file_name);
                            write_file_name<<file_path;
                            write_file_name.flush();
                            ui.sport_control_instruction->setEnabled(false);
                            is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
                        }
                        QTextStream out(&new_file);
                        QString start_programmer = "程序开始";
                        QString end_programmer = "结束";
                        QString goto_instruction = "转到行";
                        QString wait_instruction = "等待毫秒";
                        QString joint_sport_instruction = "点位运动 J, 速度=%";
                        QString straight_sport_instruction = "直线运动 J, 速度=毫米/秒";
                        QString circle_sport_instruction = "圆弧运动 J, J, 速度=毫米/秒";
                        QString null_instruction = "";
                        QString save_start_programmer = "Program Begin";
                        QString save_end_programmer = "End";
                        QString save_goto_instruction = "Goto ";
                        QString save_wait_instruction = "Delay ";
                        QString save_joint_sport_instruction = "MoveJ J(";
                        QString save_straight_sport_instruction = "MoveL J(";
                        QString save_circle_sport_instruction = "MoveC J(";
                        //QString save_null_instruction = "";
                        //int wait_time_ms;
                        //int point_row;
                        QString command_remove_number;
                        QString command_content;
                        for(i=0; i<ui.programmer_design_display->rowCount(); ++i)
                        {
                            for(j=0; j<ui.programmer_design_display->columnCount(); ++j)
                            {
                                command_content = ui.programmer_design_display->item(i, j)->text();
                                if(j == 1)
                                {
                                    //out<<ui.programmer_design_display->item(i, j)->text()<<'&';
                                    command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                                    if(command_remove_number.operator ==(start_programmer))
                                    {
                                        out<<save_start_programmer<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(end_programmer))
                                    {
                                        out<<save_end_programmer<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(goto_instruction))
                                    {
                                        out<<save_goto_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(wait_instruction))
                                    {
                                        out<<save_wait_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"ms"<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(joint_sport_instruction))
                                    {
                                        out<<save_joint_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"%"<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(straight_sport_instruction))
                                    {
                                        out<<save_straight_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"mm/s"<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(circle_sport_instruction))
                                    {
                                        out<<save_circle_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"), J("<<command_content.section(QRegExp("\\D+"), 2, 2)<<"),VL="<<command_content.section(QRegExp("\\D+"), 3, 3)<<"mm/s"<<'&';
                                        out.flush();
                                    }else if(command_remove_number.operator ==(null_instruction))
                                    {
                                        out<<'&';
                                        out.flush();
                                    }
                                }else
                                {
                                    out<<command_content<<'&';
                                    out.flush();
                                }
                            }
                        }
                        out<<'$';
                        out.flush();
                    }else
                    {
                        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
                        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
                        QString display_text;
                        display_text = "文件创建失败";
                        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
                        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
                        common_dialog->setModal(false);
                        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
                        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
                        common_dialog->exec();
                        common_dialog->set_common_dialog_succeed_status(false);
                        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
                    }
                }else
                {
                    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
                    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
                    QString display_text;
                    display_text = "文件创建失败";
                    common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
                    common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
                    common_dialog->setModal(false);
                    common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
                    common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
                    common_dialog->exec();
                    common_dialog->set_common_dialog_succeed_status(false);
                    common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
                }
            }else
            {
                virtualkeyboard->set_project_name(QString(""));
            }
            isopendialog = false;
        }
    }
}

void MainWindow::on_save_button_pressed()
{
    int i=0, j=0;
    QFile save_file(file_path);
    if(save_file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        QTextStream out(&save_file);
        QString start_programmer = "程序开始";
        QString end_programmer = "结束";
        QString goto_instruction = "转到行";
        QString wait_instruction = "等待毫秒";
        QString joint_sport_instruction = "点位运动 J, 速度=%";
        QString straight_sport_instruction = "直线运动 J, 速度=毫米/秒";
        QString circle_sport_instruction = "圆弧运动 J, J, 速度=毫米/秒";
        QString null_instruction = "";
        QString save_start_programmer = "Program Begin";
        QString save_end_programmer = "End";
        QString save_goto_instruction = "Goto ";
        QString save_wait_instruction = "Delay ";
        QString save_joint_sport_instruction = "MoveJ J(";
        QString save_straight_sport_instruction = "MoveL J(";
        QString save_circle_sport_instruction = "MoveC J(";
        //QString save_null_instruction = "";
        //int wait_time_ms;
        //int point_row;
        QString command_remove_number;
        QString command_content;
        for(i=0; i<ui.programmer_design_display->rowCount(); ++i)
        {
            for(j=0; j<ui.programmer_design_display->columnCount(); ++j)
            {
                if(ui.programmer_design_display->item(i, j) == NULL)
                {
                    out<<'&';
                    out.flush();
                }else
                {
                    command_content = ui.programmer_design_display->item(i, j)->text();
                    if(j == 1)
                    {
                        //out<<ui.programmer_design_display->item(i, j)->text()<<'&';
                        command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                        if(command_remove_number.operator ==(start_programmer))
                        {
                            out<<save_start_programmer<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(end_programmer))
                        {
                            out<<save_end_programmer<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(goto_instruction))
                        {
                            out<<save_goto_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(wait_instruction))
                        {
                            out<<save_wait_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"ms"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(joint_sport_instruction))
                        {
                            out<<save_joint_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"%"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(straight_sport_instruction))
                        {
                            out<<save_straight_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"mm/s"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(circle_sport_instruction))
                        {
                            out<<save_circle_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"), J("<<command_content.section(QRegExp("\\D+"), 2, 2)<<"),VL="<<command_content.section(QRegExp("\\D+"), 3, 3)<<"mm/s"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(null_instruction))
                        {
                            out<<'&';
                            out.flush();
                        }
                    }else
                    {
                        out<<command_content<<'&';
                        out.flush();
                    }
                }
            }
        }
        out<<'$';
        out.flush();
        for(i=0; i<ui.teacher_point_tableWidget->rowCount(); ++i)
        {
            for(j=0; j<ui.teacher_point_tableWidget->columnCount(); ++j)
            {
                out<<ui.teacher_point_tableWidget->item(i, j)->text()<<'&';
                out.flush();
            }
        }
        out.flush();
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QString display_text;
        display_text = "保存成功";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    }
}

void MainWindow::on_save_point_pressed()
{
    int i=0, j=0;
    QFile save_file(file_path);
    if(save_file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&save_file);
        QString start_programmer = "程序开始";
        QString end_programmer = "结束";
        QString goto_instruction = "转到行";
        QString wait_instruction = "等待毫秒";
        QString joint_sport_instruction = "点位运动 J, 速度=%";
        QString straight_sport_instruction = "直线运动 J, 速度=毫米/秒";
        QString circle_sport_instruction = "圆弧运动 J, J, 速度=毫米/秒";
        QString null_instruction = "";
        QString save_start_programmer = "Program Begin";
        QString save_end_programmer = "End";
        QString save_goto_instruction = "Goto ";
        QString save_wait_instruction = "Delay ";
        QString save_joint_sport_instruction = "MoveJ J(";
        QString save_straight_sport_instruction = "MoveL J(";
        QString save_circle_sport_instruction = "MoveC J(";
        //QString save_null_instruction = "";
        //int wait_time_ms;
        //int point_row;
        QString command_remove_number;
        QString command_content;
        for(i=0; i<ui.programmer_design_display->rowCount(); ++i)
        {
            for(j=0; j<ui.programmer_design_display->columnCount(); ++j)
            {
                if(ui.programmer_design_display->item(i, j) == NULL)
                {
                    out<<'&';
                    out.flush();
                }else
                {
                    command_content = ui.programmer_design_display->item(i, j)->text();
                    if(j == 1)
                    {
                        //out<<ui.programmer_design_display->item(i, j)->text()<<'&';
                        command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                        if(command_remove_number.operator ==(start_programmer))
                        {
                            out<<save_start_programmer<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(end_programmer))
                        {
                            out<<save_end_programmer<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(goto_instruction))
                        {
                            out<<save_goto_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(wait_instruction))
                        {
                            out<<save_wait_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"ms"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(joint_sport_instruction))
                        {
                            out<<save_joint_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"%"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(straight_sport_instruction))
                        {
                            out<<save_straight_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"mm/s"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(circle_sport_instruction))
                        {
                            out<<save_circle_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"), J("<<command_content.section(QRegExp("\\D+"), 2, 2)<<"),VL="<<command_content.section(QRegExp("\\D+"), 3, 3)<<"mm/s"<<'&';
                            out.flush();
                        }else if(command_remove_number.operator ==(null_instruction))
                        {
                            out<<'&';
                            out.flush();
                        }
                    }else
                    {
                        out<<command_content<<'&';
                        out.flush();
                    }
                }
            }
        }
        out<<'$';
        out.flush();
        for(i=0; i<ui.teacher_point_tableWidget->rowCount(); ++i)
        {
            for(j=0; j<ui.teacher_point_tableWidget->columnCount(); ++j)
            {
                out<<ui.teacher_point_tableWidget->item(i, j)->text()<<'&';
                out.flush();
            }
        }
        out.flush();
        QString display_text;
        display_text = "保存成功";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    }
}

void MainWindow::on_open_button_pressed()
{
    //QDir directory = QString("../../../../");
    QDir directory = QString("./");
    directory.mkdir(QString("save"));
    QString file_dialog_title = "打开文件";
    //QString open_file_name = QFileDialog::getOpenFileName(this, file_dialog_title, "../../../../save/", tr("Text Document (*.txt)"));
    QString open_file_name = QFileDialog::getOpenFileName(this, file_dialog_title, "./save/", tr("Text Document (*.txt)"));
    if(!open_file_name.isNull())
    {
        file_path = open_file_name;
        QString read_string, programmer_design_txt, teacher_point_txt;
        int count = 0, i = 0, rowcount = ui.programmer_design_display->rowCount(), point_count = ui.teacher_point_tableWidget->rowCount();
        QFile open_file(file_path);
        for(i=1; i<rowcount; ++i)
        {
            ui.programmer_design_display->removeRow(1);
        }
        for(i=0; i<point_count; i++)
        {
            ui.teacher_point_tableWidget->removeRow(0);
        }
        /*teacher_point_list_count = 0;
        teacher_point_null_init();
        ui.programmer_design_display->setCurrentCell(0, 0);*/
        if(open_file.open(QIODevice::ReadOnly))
        {
            QString file_name_save_path = directory.absolutePath() + "/save/.filename.txt";
            QFile open_save_file_name(file_name_save_path);
            if(open_save_file_name.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
                QTextStream write_file_name(&open_save_file_name);
                write_file_name<<file_path;
                write_file_name.flush();
            }
            QTextStream in(&open_file);
            read_string = in.readAll();
            programmer_design_txt = read_string.section("$", 0, 0);
            teacher_point_txt = read_string.section("$", 1, 1);
            count = programmer_design_txt.count('&');
            QString start_programmer = "程序开始";
            QString end_programmer = "结束";
            QString goto_instruction = "转到";
            QString wait_instruction = "等待";
            QString joint_sport_instruction = "点位运动 J";
            QString straight_sport_instruction = "直线运动 J";
            QString circle_sport_instruction = "圆弧运动 J";
            QString null_instruction = "";
            QString save_start_programmer = "Program Begin";
            QString save_end_programmer = "End";
            QString save_goto_instruction = "Goto ";
            QString save_wait_instruction = "Delay ms";
            QString save_joint_sport_instruction = "MoveJ J(),VL=%";
            QString save_straight_sport_instruction = "MoveL J(),VL=mm/s";
            QString save_circle_sport_instruction = "MoveC J(), J(),VL=mm/s";
            //QString save_null_instruction = "";
            //int wait_time_ms;
            //int point_row;
            QString command_remove_number;
            QString command_content;
            for(i=2; i<count; i=i+2)
            {
                ui.programmer_design_display->insertRow(i/2);
                ui.programmer_design_display->setItem(i/2, i%2, new QTableWidgetItem(QString(programmer_design_txt.section('&', i, i))));
                command_content = programmer_design_txt.section('&', i+1, i+1);
                command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                if(command_remove_number.operator ==(save_start_programmer))
                {
                   ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(start_programmer));
                }else if(command_remove_number.operator ==(save_end_programmer))
                {
                   ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(end_programmer));
                }else if(command_remove_number.operator ==(save_goto_instruction))
                {
                    ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(goto_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + "行"));
                }else if(command_remove_number.operator ==(save_wait_instruction))
                {
                    ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(wait_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + "毫秒"));
                }else if(command_remove_number.operator ==(save_joint_sport_instruction))
                {
                    ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(joint_sport_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + ", 速度=" + command_content.section(QRegExp("\\D+"), 2, 2) + "%"));
                }else if(command_remove_number.operator ==(save_straight_sport_instruction))
                {
                    ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(straight_sport_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + ", 速度=" + command_content.section(QRegExp("\\D+"), 2, 2) + "毫米/秒"));
                }else if(command_remove_number.operator ==(save_circle_sport_instruction))
                {
                    ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(circle_sport_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + ", J=" + command_content.section(QRegExp("\\D+"), 2, 2) + ", 速度=" + command_content.section(QRegExp("\\D+"), 3, 3) + "毫米/秒"));
                }else if(command_remove_number.operator ==(null_instruction))
                {
                    ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(null_instruction));
                }
            }
            command_total = ui.programmer_design_display->rowCount();
            current_select_command = 0;
            ui.programmer_design_display->setCurrentCell(current_select_command, 0);
            count = teacher_point_txt.count('&');
            if(count < (MAX_POINT_COLUMN - 1))
            {
                teacher_point_list_count = 0;
                teacher_point_null_init();
                ui.sport_control_instruction->setEnabled(false);
                is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
            }else
            {
                for(i=0; i<count; i=i+MAX_POINT_COLUMN)
                {
                    ui.teacher_point_tableWidget->insertRow(i/MAX_POINT_COLUMN);
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN, new QTableWidgetItem(QString(teacher_point_txt.section('&', i, i))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+1, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+1, i+1))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+2, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+2, i+2))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+3, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+3, i+3))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+4, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+4, i+4))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+5, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+5, i+5))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+6, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+6, i+6))));
                    ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+7, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+7, i+7))));
                }
                teacher_point_list_count = ui.teacher_point_tableWidget->rowCount();
                ui.teacher_point_tableWidget->setCurrentCell(0, 0);
                ui.point_to_point_motion->setEnabled(true);
                is_point_to_point_motion = ui.point_to_point_motion->isEnabled();
                ui.straight_line_motion->setEnabled(true);
                is_straight_line_motion = ui.straight_line_motion->isEnabled();
                ui.delete_point->setEnabled(true);
                is_delete_point = ui.delete_point->isEnabled();
                ui.modify_point->setEnabled(true);
                is_modify_point = ui.modify_point->isEnabled();
                ui.sport_control_instruction->setEnabled(true);
                is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
            }
        }
    }
}

void MainWindow::project_file_init()
{
    //QDir file_name_directory = QString("../../../../");
    QDir file_name_directory = QString("./");
    file_name_directory.mkdir(QString("save"));
    QString file_name_save_path = file_name_directory.absolutePath() + "/save/.filename.txt", read_string;
    QFile open_file_name(file_name_save_path);
    if(open_file_name.open(QIODevice::ReadWrite))
    {
        QTextStream in_read(&open_file_name);
        read_string = in_read.readAll();
        QString start_programmer = "程序开始";
        QString end_programmer = "结束";
        QString goto_instruction = "转到行";
        QString wait_instruction = "等待毫秒";
        QString joint_sport_instruction = "点位运动 J, 速度=%";
        QString straight_sport_instruction = "直线运动 J, 速度=毫米/秒";
        QString circle_sport_instruction = "圆弧运动 J, J, 速度=毫米/秒";
        QString null_instruction = "";
        QString save_start_programmer = "Program Begin";
        QString save_end_programmer = "End";
        QString save_goto_instruction = "Goto ";
        QString save_wait_instruction = "Delay ";
        QString save_joint_sport_instruction = "MoveJ J(";
        QString save_straight_sport_instruction = "MoveL J(";
        QString save_circle_sport_instruction = "MoveC J(";
        //QString save_null_instruction = "";
        //int wait_time_ms;
        //int point_row;
        QString command_remove_number;
        QString command_content;
        if(read_string == "")
        {
            file_path = file_name_directory.absolutePath() + "/save/test.txt";
            in_read<<file_path;
            in_read.flush();
            int i=0, j=0;
            QFile save_file(file_path);
            if(save_file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
                QTextStream out(&save_file);
                for(i=0; i<ui.programmer_design_display->rowCount(); ++i)
                {
                    for(j=0; j<ui.programmer_design_display->columnCount(); ++j)
                    {
                        if(ui.programmer_design_display->item(i, j) == NULL)
                        {
                            out<<'&';
                            out.flush();
                        }else
                        {
                            command_content = ui.programmer_design_display->item(i, j)->text();
                            if(j == 1)
                            {
                                //out<<ui.programmer_design_display->item(i, j)->text()<<'&';
                                command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                                if(command_remove_number.operator ==(start_programmer))
                                {
                                    out<<save_start_programmer<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(end_programmer))
                                {
                                    out<<save_end_programmer<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(goto_instruction))
                                {
                                    out<<save_goto_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(wait_instruction))
                                {
                                    out<<save_wait_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"ms"<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(joint_sport_instruction))
                                {
                                    out<<save_joint_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"%"<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(straight_sport_instruction))
                                {
                                    out<<save_straight_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"),VL="<<command_content.section(QRegExp("\\D+"), 2, 2)<<"mm/s"<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(circle_sport_instruction))
                                {
                                    out<<save_circle_sport_instruction<<command_content.section(QRegExp("\\D+"), 1, 1)<<"), J("<<command_content.section(QRegExp("\\D+"), 2, 2)<<"),VL="<<command_content.section(QRegExp("\\D+"), 3, 3)<<"mm/s"<<'&';
                                    out.flush();
                                }else if(command_remove_number.operator ==(null_instruction))
                                {
                                    out<<'&';
                                    out.flush();
                                }
                            }else
                            {
                                out<<command_content<<'&';
                                out.flush();
                            }
                        }
                    }
                }
                out<<'$';
                out.flush();
                for(i=0; i<ui.teacher_point_tableWidget->rowCount(); ++i)
                {
                    for(j=0; j<ui.teacher_point_tableWidget->columnCount(); ++j)
                    {
                        out<<ui.teacher_point_tableWidget->item(i, j)->text()<<'&';
                        out.flush();
                    }
                }
                out.flush();
            }
        }else
        {
            file_path = read_string;
            QString read_string, programmer_design_txt, teacher_point_txt;
            int count = 0, i = 0, rowcount = ui.programmer_design_display->rowCount(), point_count = ui.teacher_point_tableWidget->rowCount();
            QFile open_file(file_path);
            for(i=1; i<rowcount; ++i)
            {
                ui.programmer_design_display->removeRow(1);
            }
            for(i=0; i<point_count; i++)
            {
                ui.teacher_point_tableWidget->removeRow(0);
            }
            /*teacher_point_list_count = 0;
            teacher_point_null_init();
            ui.programmer_design_display->setCurrentCell(0, 0);*/
            if(open_file.open(QIODevice::ReadOnly))
            {
                QTextStream in(&open_file);
                read_string = in.readAll();
                programmer_design_txt = read_string.section("$", 0, 0);
                teacher_point_txt = read_string.section("$", 1, 1);
                count = programmer_design_txt.count('&');
                QString start_programmer = "程序开始";
                QString end_programmer = "结束";
                QString goto_instruction = "转到";
                QString wait_instruction = "等待";
                QString joint_sport_instruction = "点位运动 J";
                QString straight_sport_instruction = "直线运动 J";
                QString circle_sport_instruction = "圆弧运动 J";
                QString null_instruction = "";
                QString save_start_programmer = "Program Begin";
                QString save_end_programmer = "End";
                QString save_goto_instruction = "Goto ";
                QString save_wait_instruction = "Delay ms";
                QString save_joint_sport_instruction = "MoveJ J(),VL=%";
                QString save_straight_sport_instruction = "MoveL J(),VL=mm/s";
                QString save_circle_sport_instruction = "MoveC J(), J(),VL=mm/s";
                //QString save_null_instruction = "";
                //int wait_time_ms;
                //int point_row;
                QString command_remove_number;
                QString command_content;
                for(i=2; i<count; i=i+2)
                {
                    ui.programmer_design_display->insertRow(i/2);
                    ui.programmer_design_display->setItem(i/2, i%2, new QTableWidgetItem(QString(programmer_design_txt.section('&', i, i))));
                    command_content = programmer_design_txt.section('&', i+1, i+1);
                    command_remove_number = command_content.split(QRegExp("\\d+")).join("");
                    if(command_remove_number.operator ==(save_start_programmer))
                    {
                       ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(start_programmer));
                    }else if(command_remove_number.operator ==(save_end_programmer))
                    {
                       ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(end_programmer));
                    }else if(command_remove_number.operator ==(save_goto_instruction))
                    {
                        ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(goto_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + "行"));
                    }else if(command_remove_number.operator ==(save_wait_instruction))
                    {
                        ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(wait_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + "毫秒"));
                    }else if(command_remove_number.operator ==(save_joint_sport_instruction))
                    {
                        ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(joint_sport_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + ", 速度=" + command_content.section(QRegExp("\\D+"), 2, 2) + "%"));
                    }else if(command_remove_number.operator ==(save_straight_sport_instruction))
                    {
                        ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(straight_sport_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + ", 速度=" + command_content.section(QRegExp("\\D+"), 2, 2) + "毫米/秒"));
                    }else if(command_remove_number.operator ==(save_circle_sport_instruction))
                    {
                        ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(circle_sport_instruction + command_content.section(QRegExp("\\D+"), 1, 1) + ", J=" + command_content.section(QRegExp("\\D+"), 2, 2) + ", 速度=" + command_content.section(QRegExp("\\D+"), 3, 3) + "毫米/秒"));
                    }else if(command_remove_number.operator ==(null_instruction))
                    {
                        ui.programmer_design_display->setItem(i/2, i%2+1, new QTableWidgetItem(null_instruction));
                    }
                }
                command_total = ui.programmer_design_display->rowCount();
                current_select_command = 0;
                ui.programmer_design_display->setCurrentCell(current_select_command, 0);
                count = teacher_point_txt.count('&');
                if(count < (MAX_POINT_COLUMN - 1))
                {
                    teacher_point_list_count = 0;
                    teacher_point_null_init();
                    ui.sport_control_instruction->setEnabled(false);
                    is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
                }else
                {
                    for(i=0; i<count; i=i+MAX_POINT_COLUMN)
                    {
                        ui.teacher_point_tableWidget->insertRow(i/MAX_POINT_COLUMN);
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN, new QTableWidgetItem(QString(teacher_point_txt.section('&', i, i))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+1, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+1, i+1))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+2, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+2, i+2))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+3, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+3, i+3))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+4, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+4, i+4))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+5, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+5, i+5))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+6, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+6, i+6))));
                        ui.teacher_point_tableWidget->setItem(i/MAX_POINT_COLUMN, i%MAX_POINT_COLUMN+7, new QTableWidgetItem(QString(teacher_point_txt.section('&', i+7, i+7))));
                    }
                    teacher_point_list_count = ui.teacher_point_tableWidget->rowCount();
                    ui.teacher_point_tableWidget->setCurrentCell(0, 0);
                    ui.point_to_point_motion->setEnabled(true);
                    is_point_to_point_motion = ui.point_to_point_motion->isEnabled();
                    ui.straight_line_motion->setEnabled(true);
                    is_straight_line_motion = ui.straight_line_motion->isEnabled();
                    ui.delete_point->setEnabled(true);
                    is_delete_point = ui.delete_point->isEnabled();
                    ui.modify_point->setEnabled(true);
                    is_modify_point = ui.modify_point->isEnabled();
                    ui.sport_control_instruction->setEnabled(true);
                    is_sport_control_instruction = ui.sport_control_instruction->isEnabled();
                }
            }
        }
    }
}

void MainWindow::programmer_run_error_type(int error_type)
{
    if(error_type == PROGRAMMER_NOT_ARRIVE)
    {
        //pop up error dialog
        QString display_text;
        display_text = "错误：机器人未到达指定位置!!!";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
        //programmer running stop
        programmer_run_thread->set_programmer_run_status(false);
        programmer_run_thread->set_signal(false);
        QWaitCondition* wait_condition = programmer_run_thread->get_wait_condition();
        wait_condition->wakeAll();
        programmer_run_thread->wait();
        //ui.run_button->setEnabled(true);
        programmer_ready_interface_init();
        listener->set_programmer_status(false);
        current_execute_row = 0;
        ui.run_position->setText(QString::number(current_execute_row));
        ui.run_programmer_content->setCurrentCell(current_execute_row, 0);
        programmer_run_status = READY_PROGRAMMER;
        //initialize variable
        listener->init_result_value(INITIALIZE);
    }
}

void MainWindow::programmer_run_interface_init()
{
    ui.run_button->setEnabled(false);
    is_run_button = ui.run_button->isEnabled();
    ui.parameter_setting->setEnabled(false);
    is_parameter_setting = ui.parameter_setting->isEnabled();
    ui.point_teacher->setEnabled(false);
    is_point_teacher = ui.point_teacher->isEnabled();
    ui.programmer_design->setEnabled(false);
    is_programmer_design = ui.programmer_design->isEnabled();
    ui.run_programmer->setEnabled(false);
    is_run_programmer = ui.run_programmer->isEnabled();
}

void MainWindow::programmer_ready_interface_init()
{
    ui.run_button->setEnabled(true);
    is_run_button = ui.run_button->isEnabled();
    ui.parameter_setting->setEnabled(true);
    is_parameter_setting = ui.parameter_setting->isEnabled();
    ui.point_teacher->setEnabled(true);
    is_point_teacher = ui.point_teacher->isEnabled();
    ui.programmer_design->setEnabled(true);
    is_programmer_design = ui.programmer_design->isEnabled();
    ui.run_programmer->setEnabled(true);
    is_run_programmer = ui.run_programmer->isEnabled();
}

void MainWindow::on_zero_setting_pressed()
{
    bool isSetZeroSucceed = listener->set_zero_point();
    if(isSetZeroSucceed)
    {
        QString display_text;
        display_text = "零点设置成功";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    }else
    {
        QString display_text;
        display_text = "零点设置失败";
        common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
        common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
        common_dialog->setModal(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
        common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
        common_dialog->exec();
        common_dialog->set_common_dialog_succeed_status(false);
        common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
    }
}

void MainWindow::on_administrators_login_pressed()
{
    user_and_administrators_login(SYSTEM_LOGIN, system_password);
}

void MainWindow::administrators_login_succeed_init(int login_status)
{
    //administrators login succeed
    //project running process will change a enable button initialize
    int row = ui.teacher_point_tableWidget->rowCount();
    if(row > 0)
    {
        is_point_to_point_motion = true;
        is_straight_line_motion = true;
        is_delete_point = true;
        is_modify_point = true;
        is_sport_control_instruction = true;
        ui.point_to_point_motion->setEnabled(is_point_to_point_motion);
        ui.straight_line_motion->setEnabled(is_straight_line_motion);
        ui.delete_point->setEnabled(is_delete_point);
        ui.modify_point->setEnabled(is_modify_point);
        ui.sport_control_instruction->setEnabled(is_sport_control_instruction);
    }else
    {
        is_point_to_point_motion = false;
        is_straight_line_motion = false;
        is_delete_point = false;
        is_modify_point = false;
        is_sport_control_instruction = false;
        ui.point_to_point_motion->setEnabled(is_point_to_point_motion);
        ui.straight_line_motion->setEnabled(is_straight_line_motion);
        ui.delete_point->setEnabled(is_delete_point);
        ui.modify_point->setEnabled(is_modify_point);
        ui.sport_control_instruction->setEnabled(is_sport_control_instruction);
    }
    is_run_button = true;
    ui.run_button->setEnabled(is_run_button);
    is_parameter_setting = true;
    ui.parameter_setting->setEnabled(is_parameter_setting);
    is_point_teacher = true;
    ui.point_teacher->setEnabled(is_point_teacher);
    is_programmer_design = true;
    ui.programmer_design->setEnabled(is_programmer_design);
    is_run_programmer = true;
    ui.run_programmer->setEnabled(is_run_programmer);
    //login_status = SYSTEM_LOGIN;
    //project running process will not change enable button
    initalize_system_login_status(login_status);
}

void MainWindow::reinitialize_interface()
{
    //project running process will change a enable button
    ui.point_to_point_motion->setEnabled(false);
    ui.straight_line_motion->setEnabled(false);
    ui.delete_point->setEnabled(false);
    ui.modify_point->setEnabled(false);
    ui.run_button->setEnabled(true);
    //ui.parameter_setting->setEnabled(false);
    //ui.point_teacher->setEnabled(false);
    //ui.programmer_design->setEnabled(false);
    //ui.run_programmer->setEnabled(false);
    ui.sport_control_instruction->setEnabled(false);

    login_status = NO_LOGIN;
    //initialize all interface not login succeed status button enable status
    initalize_system_login_status(login_status);
}

void MainWindow::initalize_system_login_status(int login_status)
{
    bool status = false;
    if(login_status == NO_LOGIN)
    {
        status = true;
        //programmer running interface initialize
        ui.pause_programmer_button->setEnabled(status);
        ui.stop_programmer_button->setEnabled(status);
        ui.cycle_switch_button->setEnabled(status);
        ui.run_speed_set_button->setEnabled(status);
        status = false;
        //parameter setting interface initialize
        ui.zero_setting->setEnabled(status);

        //point teacher interface initialize
        ui.J1_negative_direction->setEnabled(status);
        ui.J1_positive_direction->setEnabled(status);
        ui.J2_negative_direction->setEnabled(status);
        ui.J2_positive_direction->setEnabled(status);
        ui.J3_negative_direction->setEnabled(status);
        ui.J3_positive_direction->setEnabled(status);
        ui.J4_negative_direction->setEnabled(status);
        ui.J4_positive_direction->setEnabled(status);
        ui.J5_negative_direction->setEnabled(status);
        ui.J5_positive_direction->setEnabled(status);
        ui.J6_negative_direction->setEnabled(status);
        ui.J6_positive_direction->setEnabled(status);
        ui.new_point->setEnabled(status);
        ui.stop_point_motion->setEnabled(status);
        ui.save_point->setEnabled(status);
        ui.joint_coorinate_button->setEnabled(status);
        ui.world_coorinate_button->setEnabled(status);
        ui.tool_coorinate_button->setEnabled(status);
        ui.workpiece_coordinate_button->setEnabled(status);

        //programmer design interface initialize
        ui.common_function_instruction->setEnabled(status);
        ui.extended_instruction->setEnabled(status);
        ui.insert_button->setEnabled(status);
        ui.delete_button->setEnabled(status);
        ui.save_button->setEnabled(status);
        ui.save_as_button->setEnabled(status);
        ui.new_file_button->setEnabled(status);
        ui.open_button->setEnabled(status);
    }else if(login_status == ADMINISTRATORS_LOGIN)
    {
        status = true;
        //programmer running interface initialize
        ui.pause_programmer_button->setEnabled(status);
        ui.stop_programmer_button->setEnabled(status);
        ui.cycle_switch_button->setEnabled(status);
        ui.run_speed_set_button->setEnabled(status);

        //point teacher interface initialize
        ui.J1_negative_direction->setEnabled(status);
        ui.J1_positive_direction->setEnabled(status);
        ui.J2_negative_direction->setEnabled(status);
        ui.J2_positive_direction->setEnabled(status);
        ui.J3_negative_direction->setEnabled(status);
        ui.J3_positive_direction->setEnabled(status);
        ui.J4_negative_direction->setEnabled(status);
        ui.J4_positive_direction->setEnabled(status);
        ui.J5_negative_direction->setEnabled(status);
        ui.J5_positive_direction->setEnabled(status);
        ui.J6_negative_direction->setEnabled(status);
        ui.J6_positive_direction->setEnabled(status);
        ui.new_point->setEnabled(status);
        ui.stop_point_motion->setEnabled(status);
        ui.save_point->setEnabled(status);
        ui.joint_coorinate_button->setEnabled(status);
        ui.world_coorinate_button->setEnabled(status);
        ui.tool_coorinate_button->setEnabled(status);
        ui.workpiece_coordinate_button->setEnabled(status);

        //programmer design interface initialize
        ui.common_function_instruction->setEnabled(status);
        ui.extended_instruction->setEnabled(status);
        ui.insert_button->setEnabled(status);
        ui.delete_button->setEnabled(status);
        ui.save_button->setEnabled(status);
        ui.save_as_button->setEnabled(status);
        ui.new_file_button->setEnabled(status);
        ui.open_button->setEnabled(status);

        status = false;
        //parameter setting interface initialize
        ui.zero_setting->setEnabled(status);
    }else if(login_status == SYSTEM_LOGIN)
    {
        status = true;
        //programmer running interface initialize
        ui.pause_programmer_button->setEnabled(status);
        ui.stop_programmer_button->setEnabled(status);
        ui.cycle_switch_button->setEnabled(status);
        ui.run_speed_set_button->setEnabled(status);

        //point teacher interface initialize
        ui.J1_negative_direction->setEnabled(status);
        ui.J1_positive_direction->setEnabled(status);
        ui.J2_negative_direction->setEnabled(status);
        ui.J2_positive_direction->setEnabled(status);
        ui.J3_negative_direction->setEnabled(status);
        ui.J3_positive_direction->setEnabled(status);
        ui.J4_negative_direction->setEnabled(status);
        ui.J4_positive_direction->setEnabled(status);
        ui.J5_negative_direction->setEnabled(status);
        ui.J5_positive_direction->setEnabled(status);
        ui.J6_negative_direction->setEnabled(status);
        ui.J6_positive_direction->setEnabled(status);
        ui.new_point->setEnabled(status);
        ui.stop_point_motion->setEnabled(status);
        ui.save_point->setEnabled(status);
        ui.joint_coorinate_button->setEnabled(status);
        ui.world_coorinate_button->setEnabled(status);
        ui.tool_coorinate_button->setEnabled(status);
        ui.workpiece_coordinate_button->setEnabled(status);

        //programmer design interface initialize
        ui.common_function_instruction->setEnabled(status);
        ui.extended_instruction->setEnabled(status);
        ui.insert_button->setEnabled(status);
        ui.delete_button->setEnabled(status);
        ui.save_button->setEnabled(status);
        ui.save_as_button->setEnabled(status);
        ui.new_file_button->setEnabled(status);
        ui.open_button->setEnabled(status);

        //parameter setting interface initialize
        ui.zero_setting->setEnabled(status);
    }
}

void MainWindow::on_administrators_quit_pressed()
{
    if(login_status == SYSTEM_LOGIN)
    {
        reinitialize_interface();
    }
}

void MainWindow::on_user_login_pressed()
{
    user_and_administrators_login(ADMINISTRATORS_LOGIN, user_password);
}

void MainWindow::user_and_administrators_login(int user_login_status, QString* passwd)
{
    if(false == isopendialog)
    {
        //input_number->getUiHandler()->negative->setEnabled(false);
        //input_number->getUiHandler()->decimal_point->setEnabled(false);
        input_number->set_input_number_type(POSITIVE_INTEGER);
        input_number->getUiHandler()->min_value->setText(QString("0"));
        input_number->getUiHandler()->max_value->setText(QString("9999999999999999"));
        input_number->getUiHandler()->min_value->setVisible(false);
        input_number->getUiHandler()->max_value->setVisible(false);
        input_number->getUiHandler()->min_value_label->setVisible(false);
        input_number->getUiHandler()->max_value_label->setVisible(false);
        input_number->getUiHandler()->textEdit->setText("");
        input_number->getUiHandler()->display_small_title->setVisible(true);
        input_number->getUiHandler()->display_small_title->setText("请输入密码（1到16位数）");
        input_number->setWindowFlags(Qt::WindowStaysOnTopHint);
        input_number->setModal(false);
        input_number->move(WAIT_TIME_DIALOG_X + 100, WAIT_TIME_DIALOG_Y + 100);
        isopendialog = true;
        input_number->exec();
        if(input_number->get_succeed_write_status())
        {
            input_number->set_succeed_write_status(false);
            if((input_number->value_number()) == passwd->toDouble())
            {
                administrators_login_succeed_init(user_login_status);
                login_status = user_login_status;
                QString display_text;
                if(user_login_status == ADMINISTRATORS_LOGIN)
                {
                    display_text = "密码正确，操作员登录成功。";
                }else if(user_login_status == SYSTEM_LOGIN)
                {
                    display_text = "密码正确，系统登录成功。";
                }
                common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
                common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
                common_dialog->setModal(false);
                common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
                common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
                common_dialog->exec();
                common_dialog->set_common_dialog_succeed_status(false);
                common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
                administratorsloginsucceed = true;
            }else
            {
                QString display_text;
                if(user_login_status == ADMINISTRATORS_LOGIN)
                {
                    display_text = "密码错误，操作员登录失败。";
                }else if(user_login_status == SYSTEM_LOGIN)
                {
                    display_text = "密码错误，系统登录失败。";
                }
                common_dialog->get_common_dialog_ui()->display_text_label->setText(display_text);
                common_dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
                common_dialog->setModal(false);
                common_dialog->get_common_dialog_ui()->cancel_button->setVisible(false);
                common_dialog->move(WAIT_TIME_DIALOG_X, WAIT_TIME_DIALOG_Y);
                common_dialog->exec();
                common_dialog->set_common_dialog_succeed_status(false);
                common_dialog->get_common_dialog_ui()->cancel_button->setEnabled(true);
            }
        }
        input_number->getUiHandler()->min_value->setVisible(true);
        input_number->getUiHandler()->max_value->setVisible(true);
        input_number->getUiHandler()->min_value_label->setVisible(true);
        input_number->getUiHandler()->max_value_label->setVisible(true);
        input_number->getUiHandler()->display_small_title->setVisible(false);
        //input_number->clean_Value_positive_integer_type();
        isopendialog = false;
    }
}

void MainWindow::on_user_quit_pressed()
{
    if(login_status == ADMINISTRATORS_LOGIN)
    {
        reinitialize_interface();
    }
}
