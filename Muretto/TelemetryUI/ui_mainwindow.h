/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *worstTempPlot;
    QCustomPlot *totalCurrPlot;
    QCustomPlot *branchCurrPlot;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QLabel *lblSerial;
    QPushButton *btnSerialRetry;
    QLabel *lblFile;
    QLabel *lblLog;
    QPushButton *btnLogRetry;
    QLabel *lblTempErr;
    QLabel *lblVoltErr;
    QLabel *lblCurrErr;
    QLabel *lblSkippedData;
    QLabel *lblFile_2;
    QTextEdit *txtSerialName;
    QCustomPlot *voltControlPlot;
    QCustomPlot *endurCurrPlot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1209, 730);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        worstTempPlot = new QCustomPlot(centralWidget);
        worstTempPlot->setObjectName(QStringLiteral("worstTempPlot"));
        worstTempPlot->setGeometry(QRect(420, 20, 791, 421));
        totalCurrPlot = new QCustomPlot(centralWidget);
        totalCurrPlot->setObjectName(QStringLiteral("totalCurrPlot"));
        totalCurrPlot->setGeometry(QRect(820, 460, 391, 201));
        branchCurrPlot = new QCustomPlot(centralWidget);
        branchCurrPlot->setObjectName(QStringLiteral("branchCurrPlot"));
        branchCurrPlot->setGeometry(QRect(420, 460, 381, 201));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setEnabled(false);
        btnStart->setGeometry(QRect(10, 30, 181, 25));
        btnPause = new QPushButton(centralWidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setEnabled(false);
        btnPause->setGeometry(QRect(210, 30, 181, 25));
        lblSerial = new QLabel(centralWidget);
        lblSerial->setObjectName(QStringLiteral("lblSerial"));
        lblSerial->setGeometry(QRect(20, 100, 67, 17));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lblSerial->setPalette(palette);
        lblSerial->setAutoFillBackground(true);
        lblSerial->setScaledContents(false);
        lblSerial->setAlignment(Qt::AlignCenter);
        lblSerial->setWordWrap(false);
        btnSerialRetry = new QPushButton(centralWidget);
        btnSerialRetry->setObjectName(QStringLiteral("btnSerialRetry"));
        btnSerialRetry->setGeometry(QRect(10, 130, 89, 25));
        lblFile = new QLabel(centralWidget);
        lblFile->setObjectName(QStringLiteral("lblFile"));
        lblFile->setGeometry(QRect(20, 170, 371, 17));
        lblLog = new QLabel(centralWidget);
        lblLog->setObjectName(QStringLiteral("lblLog"));
        lblLog->setGeometry(QRect(120, 100, 67, 17));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lblLog->setPalette(palette1);
        lblLog->setAutoFillBackground(true);
        lblLog->setScaledContents(false);
        lblLog->setAlignment(Qt::AlignCenter);
        lblLog->setWordWrap(false);
        btnLogRetry = new QPushButton(centralWidget);
        btnLogRetry->setObjectName(QStringLiteral("btnLogRetry"));
        btnLogRetry->setGeometry(QRect(110, 130, 89, 25));
        lblTempErr = new QLabel(centralWidget);
        lblTempErr->setObjectName(QStringLiteral("lblTempErr"));
        lblTempErr->setGeometry(QRect(20, 200, 67, 17));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lblTempErr->setPalette(palette2);
        lblTempErr->setAutoFillBackground(true);
        lblTempErr->setScaledContents(false);
        lblTempErr->setAlignment(Qt::AlignCenter);
        lblTempErr->setWordWrap(false);
        lblVoltErr = new QLabel(centralWidget);
        lblVoltErr->setObjectName(QStringLiteral("lblVoltErr"));
        lblVoltErr->setGeometry(QRect(120, 200, 67, 17));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lblVoltErr->setPalette(palette3);
        lblVoltErr->setAutoFillBackground(true);
        lblVoltErr->setScaledContents(false);
        lblVoltErr->setAlignment(Qt::AlignCenter);
        lblVoltErr->setWordWrap(false);
        lblCurrErr = new QLabel(centralWidget);
        lblCurrErr->setObjectName(QStringLiteral("lblCurrErr"));
        lblCurrErr->setGeometry(QRect(220, 200, 67, 17));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lblCurrErr->setPalette(palette4);
        lblCurrErr->setAutoFillBackground(true);
        lblCurrErr->setScaledContents(false);
        lblCurrErr->setAlignment(Qt::AlignCenter);
        lblCurrErr->setWordWrap(false);
        lblSkippedData = new QLabel(centralWidget);
        lblSkippedData->setObjectName(QStringLiteral("lblSkippedData"));
        lblSkippedData->setGeometry(QRect(320, 200, 67, 17));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lblSkippedData->setPalette(palette5);
        lblSkippedData->setAutoFillBackground(true);
        lblSkippedData->setScaledContents(false);
        lblSkippedData->setAlignment(Qt::AlignCenter);
        lblSkippedData->setWordWrap(false);
        lblFile_2 = new QLabel(centralWidget);
        lblFile_2->setObjectName(QStringLiteral("lblFile_2"));
        lblFile_2->setGeometry(QRect(20, 70, 131, 17));
        txtSerialName = new QTextEdit(centralWidget);
        txtSerialName->setObjectName(QStringLiteral("txtSerialName"));
        txtSerialName->setGeometry(QRect(150, 70, 231, 21));
        voltControlPlot = new QCustomPlot(centralWidget);
        voltControlPlot->setObjectName(QStringLiteral("voltControlPlot"));
        voltControlPlot->setGeometry(QRect(0, 240, 399, 199));
        voltControlPlot->setMinimumSize(QSize(380, 0));
        endurCurrPlot = new QCustomPlot(centralWidget);
        endurCurrPlot->setObjectName(QStringLiteral("endurCurrPlot"));
        endurCurrPlot->setGeometry(QRect(0, 460, 399, 199));
        endurCurrPlot->setMinimumSize(QSize(380, 0));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1209, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        btnPause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        lblSerial->setText(QApplication::translate("MainWindow", "Serial", Q_NULLPTR));
        btnSerialRetry->setText(QApplication::translate("MainWindow", "Retry", Q_NULLPTR));
        lblFile->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        lblLog->setText(QApplication::translate("MainWindow", "Log", Q_NULLPTR));
        btnLogRetry->setText(QApplication::translate("MainWindow", "Retry", Q_NULLPTR));
        lblTempErr->setText(QApplication::translate("MainWindow", "OverTemp", Q_NULLPTR));
        lblVoltErr->setText(QApplication::translate("MainWindow", "UnderVolt", Q_NULLPTR));
        lblCurrErr->setText(QApplication::translate("MainWindow", "CurrErr", Q_NULLPTR));
        lblSkippedData->setText(QApplication::translate("MainWindow", "SkipData", Q_NULLPTR));
        lblFile_2->setText(QApplication::translate("MainWindow", "Serial Port Path:", Q_NULLPTR));
        txtSerialName->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">/dev/ttyUSB7</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
