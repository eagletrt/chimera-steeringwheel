#include "tempswindow.h"
#include "ui_tempswindow.h"

TempsWindow::TempsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TempsWindow)
{
    ui->setupUi(this);
}

TempsWindow::~TempsWindow()
{
    delete ui;
}

//override closeEvent when the window is closed to signal the main window
void TempsWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "emit temps windowClosed";
    emit windowClosed(0);
}
