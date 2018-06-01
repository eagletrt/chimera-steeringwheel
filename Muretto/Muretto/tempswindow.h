#ifndef TEMPSWINDOW_H
#define TEMPSWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class TempsWindow;
}

class TempsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TempsWindow(QWidget *parent = 0);
    ~TempsWindow();

signals:
    void windowClosed(int windowID);

private:
    Ui::TempsWindow *ui;

protected:
     void closeEvent(QCloseEvent *event);
};

#endif // TEMPSWINDOW_H
