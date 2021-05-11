#ifndef TICK8_H
#define TICK8_H

#include <QMainWindow>

#include<QLabel>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QCheckBox>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class tick8; }
QT_END_NAMESPACE

class tick8 : public QMainWindow
{
    Q_OBJECT
    QLabel* word;
    QLabel* word1;
    QLabel* answer;
    QWidget* central;
    QWidget* central2;
    QVBoxLayout* gl_main;
    QVBoxLayout* gl_back;
    QCheckBox* check_b;
    QHBoxLayout* row_check;
    QHBoxLayout* row_w;
    QPushButton *button;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QCheckBox** all;
     QAction *addAct;

public:

    tick8(QWidget *parent = nullptr);
    QWidget* Page1();

    ~tick8();
public slots:
    void clicked_add();
    void clicked_add_new();
    void clicked_pass();
private:
    Ui::tick8 *ui;

};
#endif // TICK8_H
