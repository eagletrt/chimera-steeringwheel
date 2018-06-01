#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();

signals:
    void windowClosed(int windowID);

private:
    Ui::TestWindow *ui;

protected:
     void closeEvent(QCloseEvent *event);
};

#endif // TESTWINDOW_H
