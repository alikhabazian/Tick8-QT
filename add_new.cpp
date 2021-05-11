#include "add_new.h"

add_new::add_new(QWidget *parent) : QMainWindow(parent)
{

QWidget* c=new QWidget();
QVBoxLayout* lay=new QVBoxLayout();

text1=new QLineEdit();
lay->addWidget(text1);
//text1->setFixedHeight(10);
text2=new QTextEdit();
lay->addWidget(text2);


add=new QPushButton("Add");
cancel=new QPushButton("cancel");
lay->addWidget(add);
lay->addWidget(cancel);

 connect(add,SIGNAL(clicked()),this,SLOT(clicked_add()));
 connect(cancel,SIGNAL(clicked()),this,SLOT(close()));
c->setLayout(lay);
setCentralWidget(c);
}
void add_new::clicked_add(){
    QString a=text1->text()+","+text2->toPlainText()+",0,0,0,0,0,0,0,0\n";
    QFile qFile("C:\\Users\\Ali\\Desktop\\a.text");
    if (qFile.open(QIODevice::Append)) {
        QTextStream out(&qFile);
        out << a;
        qFile.close();
        this->close();
    }

}
