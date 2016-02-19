/**
 * @file common/main_window.hpp
 *
 * @brief Qt based gui for eros_qtalker.
 *
 * @date November 2010
 **/
#ifndef QTUTORIALS_MAIN_WINDOW_H
#define QTUTORIALS_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include <QWaitCondition>
#include <QFileDialog>

#ifndef Q_MOC_RUN
#include "common/ui_main_window.h"
#include "qnode.hpp"
#include "../thinkrob_pendant/listener.hpp"
#endif

/*Author: zhangjian
**Date: 2016.01.12
**/
#include "teacher_point_to_point.hpp"
#include "teacher_straight_line.hpp"
#include "input_number.hpp"
#include "delete_select_point.hpp"
#include "modify_point_position.hpp"
#include "common_function.hpp"
#include "commondialog.hpp"
#include "sport_instruction.hpp"
#include "programmer_run_thread.hpp"
#include "virtualkeyboard.hpp"
#include "res.hpp"
/*namespace Ui {
class MainWindow;
}*/
/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(Listener* list, QWidget *parent = 0);
	~MainWindow();
    //teacher_point_position* get_point_position();
    Ui::MainWindowDesign get_Ui_MainWindowDesign();
    void teacher_point_null_init();
    //void ReadSettings(); // Load up qt program settings at startup
    //void WriteSettings(); // Save qt program settings when closing

    //void closeEvent(QCloseEvent *event); // Overloaded function
    //void showNoMasterMessage();

public Q_SLOTS:
	// Put automatically triggered slots here (because of connectSlotsByName())
	// void on_button_enable_clicked(bool check); // example only
    //void on_actionAbout_triggered();
    //void on_button_connect_clicked(bool check );
    //void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    //void updateLoggingView(); // no idea why this can't connect automatically

private Q_SLOTS:
    //void on_jog_positive_button_pressed();

    //void on_jog_positive_button_released();

    //void on_jog_negative_button_pressed();

    //void on_jog_negative_button_released();

    void update_pendant_gui();

    void getItem(QTableWidgetItem* table_widget_item);

    void getProgDesItem(QTableWidgetItem* programmer_design_item);

    void get_command_execute_row(int execute_row);

    void programmer_run_error_type(int error_type);

    //void directoryEntered(QString);

    void on_parameter_setting_pressed();

    void on_point_teacher_pressed();

    void on_programmer_design_pressed();

    void on_run_programmer_pressed();

    void on_point_to_point_motion_pressed();

    void on_straight_line_motion_pressed();

    void on_new_point_pressed();

    void on_teacher_speed_edittext_selectionChanged();


    void on_delete_point_pressed();

    void on_modify_point_pressed();

    void on_J1_negative_direction_pressed();

    void on_J1_negative_direction_released();

    void on_J1_positive_direction_pressed();

    void on_J1_positive_direction_released();

    void on_J2_negative_direction_pressed();

    void on_J2_negative_direction_released();

    void on_J2_positive_direction_pressed();

    void on_J2_positive_direction_released();

    void on_J3_negative_direction_pressed();

    void on_J3_negative_direction_released();

    void on_J3_positive_direction_pressed();

    void on_J3_positive_direction_released();

    void on_J4_negative_direction_pressed();

    void on_J4_negative_direction_released();

    void on_J4_positive_direction_pressed();

    void on_J4_positive_direction_released();

    void on_J5_negative_direction_pressed();

    void on_J5_negative_direction_released();

    void on_J5_positive_direction_pressed();

    void on_J5_positive_direction_released();

    void on_J6_negative_direction_pressed();

    void on_J6_negative_direction_released();

    void on_J6_positive_direction_pressed();

    void on_J6_positive_direction_released();

    void on_common_function_instruction_pressed();

    void on_insert_button_pressed();

    void on_delete_button_pressed();

    void on_sport_control_instruction_pressed();

    void on_run_programmer_content_clicked(const QModelIndex &index);

    void on_run_button_pressed();

    void on_pause_programmer_button_pressed();

    void on_stop_programmer_button_pressed();

    void on_new_file_button_pressed();

    void on_save_button_pressed();

    void on_save_point_pressed();

    void on_open_button_pressed();

    void on_zero_setting_pressed();

    void on_administrators_login_pressed();

    void on_administrators_quit_pressed();

    void on_user_login_pressed();

    void on_user_quit_pressed();

private:
    void teacher_display_point_table_init();
    void programmer_design_interface_init();
    void programmer_design_robot_function_init();
    void programmer_design_tablewidget_init();
    void run_programmer_interface_init();
    void run_programmer_content_init();
    void project_file_init();
    void programmer_run_interface_init();
    void programmer_ready_interface_init();
    void administrators_login_succeed_init(int login_status);
    //because need add an administrators login interface, it is necessary to reinitialize the interface
    void reinitialize_interface();
    void initalize_system_login_status(int login_status);
    void user_and_administrators_login(int login_status, QString* passwd);


    Ui::MainWindowDesign ui;
    //Ui::MainWindow* ui;
    QNode* qnode;
    Listener* listener;

    //QDialog class object
    teacher_point_to_point* teach_p2p;
    Teacher_Straight_Line* teach_str_line;
    Input_Number* input_number;
    Delete_Select_Point* delete_select_point;
    Modify_Point_Position* modify_point;
    Common_Function* comm_function;
    CommonDialog* common_dialog;
    Sport_Instruction* sport_instr;
    Programmer_Run_Thread* programmer_run_thread;
    VirtualKeyboard* virtualkeyboard;

    //teacher point list point
    QTableWidget* tableWidget;
    QTableWidgetItem* programmer_design_point[MAX_PROGRAMMER_ROW][MAX_PROGRAMMER_COLUMN];
    QTableWidgetItem* programmer_run_point[MAX_PROGRAMMER_ROW][MAX_PROGRAMMER_COLUMN];
    QTableWidgetItem* tablewidgetitem[MAX_PROGRAMMER_ROW][MAX_PROGRAMMER_COLUMN];
    QTableWidgetItem* teacher_point[MAX_POINT_ROW][MAX_POINT_COLUMN];
    int teacher_point_list_count;
    int command_total;
    int current_select_command;
    int current_execute_row;
    int programmer_run_status;
    //new project programmer design txt version
    int version_no;
    //system login status
    int login_status;


    bool start_run_programmer;
    bool isopendialog;
    bool administratorsloginsucceed;
    bool is_point_to_point_motion;
    bool is_straight_line_motion;
    bool is_delete_point;
    bool is_modify_point;
    bool is_run_button;
    bool is_parameter_setting;
    bool is_point_teacher;
    bool is_programmer_design;
    bool is_run_programmer;
    bool is_sport_control_instruction;
    //current file path to QString type
    QString file_path;
    QFileDialog* file;
    QString* system_password;
    QString* user_password;
    //teacher_point_position* teach_point_pos;


};

#endif // QTUTORIALS_MAIN_WINDOW_H
