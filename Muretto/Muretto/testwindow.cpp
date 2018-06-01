#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
}

TestWindow::~TestWindow()
{
    delete ui;
}

//override closeEvent when the window is closed to signal the main window
void TestWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "emit test windowClosed";
    emit windowClosed(1);
}
