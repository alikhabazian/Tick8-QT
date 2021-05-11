#ifndef ADD_NEW_H
#define ADD_NEW_H

#include <QMainWindow>
#include<QVBoxLayout>
#include<QPushButton>
#include<QString>
#include<QTextEdit>
#include<QLineEdit>
#include<QFile>

class add_new : public QMainWindow
{
    Q_OBJECT
    QPushButton* add;
    QPushButton* cancel;
    QLineEdit* text1;
    QTextEdit* text2;
public:
    explicit add_new(QWidget *parent = nullptr);

signals:

public slots:
    void clicked_add();
};

#endif // ADD_NEW_H
