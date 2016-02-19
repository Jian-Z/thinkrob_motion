/*
* License:The MIT License (MIT)
*
* Copyright (c) 2013,2014 Yongzhuo Gao
* State Key Laboratory of Robotics and System, Harbin Institute of Technology
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "virtualkeyboard.hpp"


/*#define XK_LATIN1
#define XK_MISCELLANY
#define XK_TECHNICAL
#define XK_PUBLISHING

#include <X11/keysym.h>
#include <X11/extensions/XTest.h>*/

#define NORMAL_MODE 0
#define CAPS_MODE   1
#define NUM_MODE    2

VirtualKeyboard::VirtualKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VirtualKeyboard)
{
    ui->setupUi(this);
    shiftLock = false;
    modeFlag = NORMAL_MODE;
    project_name_string = "";
    virtualkeyboard_init();
    is_succeed = false;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(QString("新建工程"));
    cursor_current_position = 0;
    multi_select_start_position = 0;
    multi_select_end_position = 0;
}

VirtualKeyboard::~VirtualKeyboard()
{
    delete ui;
}
void VirtualKeyboard::on_pushButton_1_pressed()//q  1
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_q);
        insert_one_char(QString('q'));
        break;
    case CAPS_MODE:
        //sendkey(XK_Q);
        insert_one_char(QString('Q'));
        break;
    case NUM_MODE:
        //sendkey(XK_1);
        insert_one_char(QString('1'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_2_pressed()//w  2
{
    //QTextCursor cursor(ui->project_name->textCursor());
    //cursor_current_position = cursor.position();
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_w);
        //previous methods
        /*project_name_string += 'w';
        ui->project_name->setText(project_name_string);
        cursor.setPosition(2, QTextCursor::MoveAnchor);
        cursor.setPosition(5, QTextCursor::KeepAnchor);
        ui->project_name->setTextCursor(cursor);*/
        //after the methods
        /*project_name_string.insert(cursor_current_position, QString('w'));
        ui->project_name->setText(project_name_string);
        cursor.setPosition(cursor_current_position + 1, QTextCursor::MoveAnchor);
        ui->project_name->setTextCursor(cursor);
        cursor_current_position = cursor.position();*/
        //finish methods
        insert_one_char(QString('w'));
        break;
    case CAPS_MODE:
        //sendkey(XK_W);
        insert_one_char(QString('W'));
        break;
    case NUM_MODE:
        //sendkey(XK_2);
        insert_one_char(QString('2'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_3_pressed()//e  3
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_e);
        insert_one_char(QString('e'));
        break;
    case CAPS_MODE:
        //sendkey(XK_E);
        insert_one_char(QString('E'));
        break;
    case NUM_MODE:
        //sendkey(XK_3);
        insert_one_char(QString('3'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_4_pressed()//r  4
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_r);
        insert_one_char(QString('r'));
        break;
    case CAPS_MODE:
        //sendkey(XK_R);
        insert_one_char(QString('R'));
        break;
    case NUM_MODE:
        //sendkey(XK_4);
        insert_one_char(QString('4'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_5_pressed()//t  5
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_t);
        insert_one_char(QString('t'));
        break;
    case CAPS_MODE:
        //sendkey(XK_T);
        insert_one_char(QString('T'));
        break;
    case NUM_MODE:
        //sendkey(XK_5);
        insert_one_char(QString('5'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_6_pressed()//y  6
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_y);
        insert_one_char(QString('y'));
        break;
    case CAPS_MODE:
        //sendkey(XK_Y);
        insert_one_char(QString('Y'));
        break;
    case NUM_MODE:
        //sendkey(XK_6);
        insert_one_char(QString('6'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_7_pressed()//u  7
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_u);
        insert_one_char(QString('u'));
        break;
    case CAPS_MODE:
        //sendkey(XK_U);
        insert_one_char(QString('U'));
        break;
    case NUM_MODE:
        //sendkey(XK_7);
        insert_one_char(QString('7'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_8_pressed()//i  8
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_i);
        insert_one_char(QString('i'));
        break;
    case CAPS_MODE:
        //sendkey(XK_I);
        insert_one_char(QString('I'));
        break;
    case NUM_MODE:
        //sendkey(XK_8);
        insert_one_char(QString('8'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_9_pressed()//o  9
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_o);
        insert_one_char(QString('o'));
        break;
    case CAPS_MODE:
        //sendkey(XK_O);
        insert_one_char(QString('O'));
        break;
    case NUM_MODE:
        //sendkey(XK_9);
        insert_one_char(QString('9'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_10_pressed()//p  0
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_p);
        insert_one_char(QString('p'));
        break;
    case CAPS_MODE:
        //sendkey(XK_P);
        insert_one_char(QString('P'));
        break;
    case NUM_MODE:
        //sendkey(XK_0);
        insert_one_char(QString('0'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_41_pressed()//a  +
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_a);
        insert_one_char(QString('a'));
        break;
    case CAPS_MODE:
        //sendkey(XK_A);
        insert_one_char(QString('A'));
        break;
    case NUM_MODE:
        //sendkey(XK_KP_Add);
        insert_one_char(QString('+'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_42_pressed()//s  -
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_s);
        insert_one_char(QString('s'));
        break;
    case CAPS_MODE:
        //sendkey(XK_S);
        insert_one_char(QString('S'));
        break;
    case NUM_MODE:
        //sendkey(XK_minus);
        insert_one_char(QString('-'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_43_pressed()//d  *
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_d);
        insert_one_char(QString('d'));
        break;
    case CAPS_MODE:
        //sendkey(XK_D);
        insert_one_char(QString('D'));
        break;
    case NUM_MODE:
        //sendkey(XK_KP_Multiply);
        insert_one_char(QString('*'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_44_pressed()//f  /
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_f);
        insert_one_char(QString('f'));
        break;
    case CAPS_MODE:
        //sendkey(XK_F);
        insert_one_char(QString('F'));
        break;
    case NUM_MODE:
        //sendkey(XK_slash);
        insert_one_char(QString('/'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_45_pressed()//g  (
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_g);
        insert_one_char(QString('g'));
        break;
    case CAPS_MODE:
        //sendkey(XK_G);
        insert_one_char(QString('G'));
        break;
    case NUM_MODE:
        //sendkey(XK_parenleft);
        insert_one_char(QString('('));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_46_pressed()//h  )
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_h);
        insert_one_char(QString('h'));
        break;
    case CAPS_MODE:
        //sendkey(XK_H);
        insert_one_char(QString('H'));
        break;
    case NUM_MODE:
        //sendkey(XK_parenright);
        insert_one_char(QString(')'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_47_pressed()//j  {
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_j);
        insert_one_char(QString('j'));
        break;
    case CAPS_MODE:
        //sendkey(XK_J);
        insert_one_char(QString('J'));
        break;
    case NUM_MODE:
        //sendSpecialKey(XK_braceleft);
        insert_one_char(QString('{'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_48_pressed()//k  }
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_k);
        insert_one_char(QString('k'));
        break;
    case CAPS_MODE:
        //sendkey(XK_K);
        insert_one_char(QString('K'));
        break;
    case NUM_MODE:
        //sendSpecialKey(XK_braceright);
        insert_one_char(QString('}'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_49_pressed()//l  .
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_l);
        insert_one_char(QString('l'));
        break;
    case CAPS_MODE:
        //sendkey(XK_L);
        insert_one_char(QString('L'));
        break;
    case NUM_MODE:
        //sendkey(XK_period);
        insert_one_char(QString('.'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_52_pressed()//z  =
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_z);
        insert_one_char(QString('z'));
        break;
    case CAPS_MODE:
        //sendkey(XK_Z);
        insert_one_char(QString('Z'));
        break;
    case NUM_MODE:
        //sendkey(XK_equal);
        insert_one_char(QString('='));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_53_pressed()//x  ,
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_x);
        insert_one_char(QString('x'));
        break;
    case CAPS_MODE:
        //sendkey(XK_X);
        insert_one_char(QString('X'));
        break;
    case NUM_MODE:
        //sendkey(XK_comma);
        insert_one_char(QString(','));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_54_pressed()//c  ?
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_c);
        insert_one_char(QString('c'));
        break;
    case CAPS_MODE:
        //sendkey(XK_C);
        insert_one_char(QString('C'));
        break;
    case NUM_MODE:
        //sendSpecialKey(XK_question);
        insert_one_char(QString('?'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_55_pressed()//v  [
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_v);
        insert_one_char(QString('v'));
        break;
    case CAPS_MODE:
        //sendkey(XK_V);
        insert_one_char(QString('V'));
        break;
    case NUM_MODE:
        //sendkey(XK_bracketleft);
        insert_one_char(QString('['));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_56_pressed()//b  ]
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_b);
        insert_one_char(QString('b'));
        break;
    case CAPS_MODE:
        //sendkey(XK_B);
        insert_one_char(QString('B'));
        break;
    case NUM_MODE:
        //sendkey(XK_bracketright);
        insert_one_char(QString(']'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_57_pressed()//n  <
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_n);
        insert_one_char(QString('n'));
        break;
    case CAPS_MODE:
        //sendkey(XK_N);
        insert_one_char(QString('N'));
        break;
    case NUM_MODE:
        //sendkey(XK_less);
        insert_one_char(QString('<'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_58_pressed()//m  >
{
    switch (modeFlag) {
    case NORMAL_MODE:
        //sendkey(XK_m);
        insert_one_char(QString('m'));
        break;
    case CAPS_MODE:
        //sendkey(XK_M);
        insert_one_char(QString('M'));
        break;
    case NUM_MODE:
        //sendSpecialKey(XK_greater);
        insert_one_char(QString('>'));
        break;
    default:
        break;
    }
}

void VirtualKeyboard::on_pushButton_50_pressed()//backspace
{
    //sendkey(XK_BackSpace);
    QTextCursor cursor(ui->project_name->textCursor());
    cursor_current_position = cursor.position();
    if(cursor_current_position)
    {
        project_name_string.remove(cursor_current_position - 1, 1);
        ui->project_name->setText(project_name_string);
        cursor.setPosition(cursor_current_position - 1, QTextCursor::MoveAnchor);
        ui->project_name->setTextCursor(cursor);
        cursor_current_position = cursor.position();
    }
}

/*void VirtualKeyboard::on_pushButton_60_pressed()//enter
{
    //sendkey(XK_Return);
}*/

void VirtualKeyboard::on_pushButton_51_pressed()//cap
{
    //sendkey(XK_Caps_Lock);
    if(modeFlag != CAPS_MODE)
    {
        modeFlag = CAPS_MODE;
        ui->pushButton_1->setText("Q");
        ui->pushButton_2->setText("W");
        ui->pushButton_3->setText("E");
        ui->pushButton_4->setText("R");
        ui->pushButton_5->setText("T");
        ui->pushButton_6->setText("Y");
        ui->pushButton_7->setText("U");
        ui->pushButton_8->setText("I");
        ui->pushButton_9->setText("O");
        ui->pushButton_10->setText("P");
        ui->pushButton_41->setText("A");
        ui->pushButton_42->setText("S");
        ui->pushButton_43->setText("D");
        ui->pushButton_44->setText("F");
        ui->pushButton_45->setText("G");
        ui->pushButton_46->setText("H");
        ui->pushButton_47->setText("J");
        ui->pushButton_48->setText("K");
        ui->pushButton_49->setText("L");
        ui->pushButton_52->setText("Z");
        ui->pushButton_53->setText("X");
        ui->pushButton_54->setText("C");
        ui->pushButton_55->setText("V");
        ui->pushButton_56->setText("B");
        ui->pushButton_57->setText("N");
        ui->pushButton_58->setText("M");
        ui->pushButton_61->setChecked(0);
    }
    else
    {
        modeFlag = NORMAL_MODE;
        ui->pushButton_1->setText("q");
        ui->pushButton_2->setText("w");
        ui->pushButton_3->setText("e");
        ui->pushButton_4->setText("r");
        ui->pushButton_5->setText("t");
        ui->pushButton_6->setText("y");
        ui->pushButton_7->setText("u");
        ui->pushButton_8->setText("i");
        ui->pushButton_9->setText("o");
        ui->pushButton_10->setText("p");
        ui->pushButton_41->setText("a");
        ui->pushButton_42->setText("s");
        ui->pushButton_43->setText("d");
        ui->pushButton_44->setText("f");
        ui->pushButton_45->setText("g");
        ui->pushButton_46->setText("h");
        ui->pushButton_47->setText("j");
        ui->pushButton_48->setText("k");
        ui->pushButton_49->setText("l");
        ui->pushButton_52->setText("z");
        ui->pushButton_53->setText("x");
        ui->pushButton_54->setText("c");
        ui->pushButton_55->setText("v");
        ui->pushButton_56->setText("b");
        ui->pushButton_57->setText("n");
        ui->pushButton_58->setText("m");
    }
}

/*void VirtualKeyboard::on_pushButton_64_pressed()//shift
{
    if(shiftLock == false)
    {
        shiftLock = true;
    }
    else
    {
        shiftLock = false;
    }
}*/

void VirtualKeyboard::on_pushButton_67_pressed()//space
{
    //sendkey(XK_space);
    insert_one_char(QString(' '));
}

/*void VirtualKeyboard::on_pushButton_63_pressed()//up_arrow
{
    if(shiftLock == 0)
        sendkey(XK_Up);
    else
        sendSpecialKey(XK_Up);
    QTextCursor cursor(ui->project_name->textCursor());
    cursor_current_position = cursor.position();
    multi_select_start_position = cursor.position();
    cursor.movePosition(QTextCursor::Up);
    ui->project_name->setTextCursor(cursor);
    cursor_current_position = cursor.position();
    multi_select_end_position = cursor.position();
    if(shiftLock == true)
    {
        cursor.setPosition(multi_select_start_position, QTextCursor::MoveAnchor);
        cursor.setPosition(multi_select_end_position, QTextCursor::KeepAnchor);
        ui->project_name->setTextCursor(cursor);
    }

}*/

/*void VirtualKeyboard::on_pushButton_69_pressed()//down_arrow
{
    if(shiftLock == 0)
        sendkey(XK_Down);
    else
        sendSpecialKey(XK_Down);
    QTextCursor cursor(ui->project_name->textCursor());
    cursor_current_position = cursor.position();
    multi_select_start_position = cursor.position();
    cursor.movePosition(QTextCursor::Down);
    ui->project_name->setTextCursor(cursor);
    cursor_current_position = cursor.position();
    multi_select_end_position = cursor.position();
    if(shiftLock == true)
    {
        cursor.setPosition(multi_select_start_position, QTextCursor::MoveAnchor);
        cursor.setPosition(multi_select_end_position, QTextCursor::KeepAnchor);
        ui->project_name->setTextCursor(cursor);
    }
}*/

/*void VirtualKeyboard::on_pushButton_62_pressed()//left_arrow
{
    if(shiftLock == 0)
        sendkey(XK_Left);
    else
        sendSpecialKey(XK_Left);
    QTextCursor cursor(ui->project_name->textCursor());
    cursor_current_position = cursor.position();
    multi_select_start_position = cursor.position();
    cursor.movePosition(QTextCursor::Left);
    ui->project_name->setTextCursor(cursor);
    cursor_current_position = cursor.position();
    multi_select_end_position = cursor.position();
    if(shiftLock == true)
    {
        cursor.setPosition(multi_select_start_position, QTextCursor::MoveAnchor);
        cursor.setPosition(multi_select_end_position, QTextCursor::KeepAnchor);
        ui->project_name->setTextCursor(cursor);
    }
}*/

/*void VirtualKeyboard::on_pushButton_70_pressed()//right_arrow
{
    if(shiftLock == 0)
        sendkey(XK_Right);
    else
        sendSpecialKey(XK_Right);
    QTextCursor cursor(ui->project_name->textCursor());
    cursor_current_position = cursor.position();
    multi_select_start_position = cursor.position();
    cursor.movePosition(QTextCursor::Right);
    ui->project_name->setTextCursor(cursor);
    cursor_current_position = cursor.position();
    multi_select_end_position = cursor.position();
    if(shiftLock == true)
    {
        cursor.setPosition(multi_select_start_position, QTextCursor::MoveAnchor);
        cursor.setPosition(multi_select_end_position, QTextCursor::KeepAnchor);
        ui->project_name->setTextCursor(cursor);
    }
}*/

void VirtualKeyboard::on_pushButton_61_pressed()//number_mode
{
    if(modeFlag != NUM_MODE)
    {
        modeFlag = NUM_MODE;
        ui->pushButton_1->setText("1");
        ui->pushButton_2->setText("2");
        ui->pushButton_3->setText("3");
        ui->pushButton_4->setText("4");
        ui->pushButton_5->setText("5");
        ui->pushButton_6->setText("6");
        ui->pushButton_7->setText("7");
        ui->pushButton_8->setText("8");
        ui->pushButton_9->setText("9");
        ui->pushButton_10->setText("0");
        ui->pushButton_41->setText("+");
        ui->pushButton_42->setText("-");
        ui->pushButton_43->setText("*");
        ui->pushButton_44->setText("/");
        ui->pushButton_45->setText("(");
        ui->pushButton_46->setText(")");
        ui->pushButton_47->setText("{");
        ui->pushButton_48->setText("}");
        ui->pushButton_49->setText(".");
        ui->pushButton_52->setText("=");
        ui->pushButton_53->setText(",");
        ui->pushButton_54->setText("?");
        ui->pushButton_55->setText("[");
        ui->pushButton_56->setText("]");
        ui->pushButton_57->setText("<");
        ui->pushButton_58->setText(">");
        ui->pushButton_51->setChecked(0);
    }
    else
    {
        modeFlag = NORMAL_MODE;
        ui->pushButton_1->setText("q");
        ui->pushButton_2->setText("w");
        ui->pushButton_3->setText("e");
        ui->pushButton_4->setText("r");
        ui->pushButton_5->setText("t");
        ui->pushButton_6->setText("y");
        ui->pushButton_7->setText("u");
        ui->pushButton_8->setText("i");
        ui->pushButton_9->setText("o");
        ui->pushButton_10->setText("p");
        ui->pushButton_41->setText("a");
        ui->pushButton_42->setText("s");
        ui->pushButton_43->setText("d");
        ui->pushButton_44->setText("f");
        ui->pushButton_45->setText("g");
        ui->pushButton_46->setText("h");
        ui->pushButton_47->setText("j");
        ui->pushButton_48->setText("k");
        ui->pushButton_49->setText("l");
        ui->pushButton_52->setText("z");
        ui->pushButton_53->setText("x");
        ui->pushButton_54->setText("c");
        ui->pushButton_55->setText("v");
        ui->pushButton_56->setText("b");
        ui->pushButton_57->setText("n");
        ui->pushButton_58->setText("m");
    }
}

/*void VirtualKeyboard::sendkey(int key)
{
    Display *disp = XOpenDisplay(NULL);
    XTestFakeKeyEvent(disp, XKeysymToKeycode(disp, key), True, CurrentTime);
    XTestFakeKeyEvent(disp, XKeysymToKeycode(disp, key), False, CurrentTime);
    XCloseDisplay(disp);
}

void VirtualKeyboard::sendSpecialKey(int key)
{
    Display *disp = XOpenDisplay(NULL);
    XTestFakeKeyEvent(disp, XKeysymToKeycode(disp, XK_Shift_L), True, CurrentTime);
    XTestFakeKeyEvent(disp, XKeysymToKeycode(disp, key), True, CurrentTime);
    XTestFakeKeyEvent(disp, XKeysymToKeycode(disp, key), False, CurrentTime);
    XTestFakeKeyEvent(disp, XKeysymToKeycode(disp, XK_Shift_L), False, CurrentTime);
    XCloseDisplay(disp);
}*/

void VirtualKeyboard::virtualkeyboard_init()
{
    ui->pushButton_60->setVisible(false);
    ui->pushButton_62->setVisible(false);
    ui->pushButton_63->setVisible(false);
    ui->pushButton_64->setVisible(false);
    ui->pushButton_69->setVisible(false);
    ui->pushButton_70->setVisible(false);
}

void VirtualKeyboard::on_ok_button_pressed()
{
    is_succeed = true;
    project_name_string = ui->project_name->toPlainText();
    this->close();
}

void VirtualKeyboard::on_cancel_button_pressed()
{
    is_succeed = false;
    this->close();
}

QString VirtualKeyboard::get_project_name()
{
    return project_name_string;
}

void VirtualKeyboard::set_project_name(QString file)
{
    project_name_string = file;
    ui->project_name->setText(project_name_string);
}

bool VirtualKeyboard::get_succeed_status()
{
    return is_succeed;
}

void VirtualKeyboard::set_succeed_status(bool status)
{
    is_succeed = status;
}

void VirtualKeyboard::insert_one_char(QString ch)
{
    project_name_string = ui->project_name->toPlainText();
    QTextCursor cursor(ui->project_name->textCursor());
    cursor_current_position = cursor.position();
    project_name_string.insert(cursor_current_position, ch);
    ui->project_name->setText(project_name_string);
    cursor.setPosition(cursor_current_position + 1, QTextCursor::MoveAnchor);
    ui->project_name->setTextCursor(cursor);
    cursor_current_position = cursor.position();
}
