#include "tick8.h"
#include "ui_tick8.h"
#include"add_new.h"
using namespace Qt;
tick8::tick8(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tick8)
{


    word=new QLabel("Name:");
    answer=new QLabel("Name:");
    answer->setText("goodbye");
    word->setText("hi");
    int count=8;

    all=new QCheckBox*[count];
    for (int i=0;i<count ;i++ ) {
        all[i]=new QCheckBox();
        all[i]->setTristate(true);
        all[i]->setDisabled(true);
    }

//    all[0]->setChecked(true);
//    all[0]->setEnabled(false);
//    all[2]->setTristate(true);
//    all[2]->setCheckState(PartiallyChecked);
//    all[1]->setEnabled(false);



    QFile qFile("C:\\Users\\Ali\\Desktop\\a.text");
    QString tmp;
    if (qFile.open(QIODevice::ReadOnly)) {
        QTextStream out(&qFile);
         tmp=out.readLine();
        qFile.close();
    }
    QStringList b=tmp.split(',');
    word->setText(b[0]);
    answer->setText(b[1]);
    for (int i=2;i<b.size() ;i++ ) {
        if (b[i]=='2'){
           all[i-2]->setCheckState(PartiallyChecked);
        }
        else if(b[i]=='0'){
            all[i-2]->setChecked(false);
        }
        else{
            all[i-2]->setChecked(true);
        }

    }


    gl_main=new QVBoxLayout;
    check_b=new QCheckBox();

    gl_main->addWidget(word);
     gl_main->addWidget(answer);
     answer->hide();

     row_w=new QHBoxLayout();
           button1 = new QPushButton("Pass");
           button2 = new QPushButton("Reject");

          row_w->addWidget(button1);
          row_w->addWidget(button2);
     gl_main->addLayout(row_w);


    gl_main->setAlignment(word,AlignCenter);
    gl_main->setAlignment(answer,AlignCenter);

//    gl_main->addWidget(check_b);
    row_check=new QHBoxLayout();
    for (int i=0;i<count ;i++ ) {
       row_check->addWidget(all[i]);
    }
    button = new QPushButton("flipp!");


    gl_main->addLayout(row_check);
    gl_main->addWidget(button);
QMenuBar* aa=new QMenuBar();

addAct =new QAction();
addAct->setText("add");



aa->addAction(addAct);

setMenuBar(aa);

//    word1=new QLabel("goodbuy");

//    gl_back=new QVBoxLayout;

//    gl_back->addWidget(word1);
//     row_w=new QHBoxLayout();
//      button1 = new QPushButton("A");
//      button2 = new QPushButton("B");
//      button3=new QPushButton("flipp!");
//     row_w->addWidget(button1);
//     row_w->addWidget(button2);
//     gl_back->addLayout(row_w);
//     gl_back->addWidget(button3);



    central=new QWidget();
    central->setLayout(gl_main);
//    central2=new QWidget();
//    central2->setLayout(gl_back);

     connect(button,SIGNAL(clicked()),this,SLOT(clicked_add()));
     connect(addAct, SIGNAL(triggered()), this,SLOT(clicked_add_new()) );
     connect(button1, SIGNAL(clicked()), this,SLOT(clicked_pass()) );
//     connect( button3,SIGNAL(clicked()),this,SLOT(clicked_add()));

    setCentralWidget(Page1());
//    ui->setupUi(this);
}


void tick8::clicked_add_new(){
    QMainWindow* new_page=new add_new();

    new_page->show();
}
void tick8::clicked_pass(){
    QFile qFile("C:\\Users\\Ali\\Desktop\\a.text");
    QString tmp;
    qDebug()<<"aas";
    int q=0;
    if (qFile.open(QIODevice::ReadWrite)) {
        QTextStream out(&qFile);
         tmp=out.readAll();
//          qDebug()<<tmp;
//          qDebug()<<answer->text();
         q=tmp.indexOf(answer->text());
         qDebug()<<q;
         while(tmp[q]!='0'){
             q++;
         }
         tmp[q]='1';
          qDebug()<<tmp;

         out<<tmp;
        qFile.close();
    }
    if (qFile.open(QIODevice::ReadWrite|QFile::Truncate)) {
        QTextStream out(&qFile);
         qFile.resize(qFile.pos());

         out<<tmp;
        qFile.close();
    }


}

void tick8::clicked_add()
{
  qDebug()<< answer->isHidden();
  if(answer->isHidden()){
    answer->show();
  }
  else{
      answer->hide();
  }


//qDebug()<<central2;

//    qDebug()<<centralWidget();
//  if(centralWidget()==central2){
//      qDebug()<<"hi";

//    setCentralWidget(Page1());
//  }
//  else if(centralWidget()==central){
//    qDebug()<<"hi3";
//     setCentralWidget(central2);
//  }

//  central->unsetLayoutDirection();

}
QWidget* tick8::Page1(){
    central=new QWidget();
    central->setLayout(gl_main);
    return central;
}
tick8::~tick8()
{
    delete ui;
}

