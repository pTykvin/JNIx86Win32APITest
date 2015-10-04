#include "mainwindow.h"
#include "ui_mainwindow.h"

void addButton(QString);
Ui::MainWindow* oui;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    oui = ui;
    ui->setupUi(this);
    setWindowTitle("QMainWindow");
}

void addButton(QString text) {
    QPushButton *pushButton;
    pushButton = new QPushButton(oui->centralWidget);
    oui->verticalLayout->addWidget(pushButton);
    pushButton->setText(text);
}

JNIEXPORT void JNICALL Java_ru_tykvin_jni_nativeinvokers_QTHelloWorld_addButton
  (JNIEnv *, jobject) {
    addButton("TEST");
}



MainWindow::~MainWindow()
{
    delete ui;
}
