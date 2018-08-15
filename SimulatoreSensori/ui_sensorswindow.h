/********************************************************************************
** Form generated from reading UI file 'sensorswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORSWINDOW_H
#define UI_SENSORSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensorsWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vl_simSens;
    QHBoxLayout *hl_status;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnInvRight;
    QPushButton *btnInvLeft;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnUPyFront;
    QPushButton *btnUPyRear;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnBMSHV;
    QPushButton *btnBMSLV;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hl_inverter;
    QPushButton *btnInvDx;
    QPushButton *btnInvSx;
    QPushButton *btnPreCh;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *hl_errors;
    QVBoxLayout *verticalLayout;
    QPushButton *btnApps;
    QPushButton *btnWheelLeft;
    QPushButton *btnIMUFront;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnBSE;
    QPushButton *btnIMUCenter;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnSteer;
    QPushButton *btnWheelRight;
    QPushButton *btnIMURear;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout;
    QPushButton *btnErrApps3;
    QSlider *sliderSteer;
    QPushButton *btnErrBse2;
    QSlider *sliderBse;
    QPushButton *btnErrApps4;
    QPushButton *btnErrApps2;
    QPushButton *btnErrApps5;
    QPushButton *btnErrBse1;
    QPushButton *btnErrBse3;
    QPushButton *btnErrSteer1;
    QPushButton *btnErrApps1;
    QPushButton *btnErrBse4;
    QSlider *sliderApps;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSlider *verticalSlider;
    QFormLayout *formLayout;
    QLabel *lblHV_TMax;
    QLineEdit *leHV_TMax;
    QLabel *lblHV_TAvg;
    QLineEdit *leHV_TAvg;
    QLabel *lblHV_TMin;
    QLineEdit *leHV_TMin;
    QLabel *lblHV_VMax;
    QLineEdit *leHV_VMax;
    QLabel *lblHV_VAvg;
    QLineEdit *leHV_VAvg;
    QLabel *lblHV_VMin;
    QLineEdit *leHV_VMin;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_2;
    QLabel *lblLV_V1;
    QLineEdit *leLV_V1;
    QLineEdit *leLV_V2;
    QLabel *lblLV_V2;
    QLineEdit *leLV_V3;
    QLabel *lblLV_V3;
    QLineEdit *leLV_V4;
    QLineEdit *leLV_V5;
    QLineEdit *leLV_TotE;
    QLabel *lblLV_V4;
    QLabel *lblLV_V5;
    QLabel *lblLV_TotE;
    QSlider *verticalSlider_2;
    QFrame *line;
    QVBoxLayout *vl_volante;
    QWidget *widget;
    QGridLayout *gl_bottoniVolante;
    QPushButton *btnVolanteA;
    QPushButton *btnVolanteR;
    QPushButton *btnVolanteD;
    QPushButton *btnVolanteQ;
    QSpacerItem *horizontalSpacer;
    QSpinBox *sbVolanteManettino;

    void setupUi(QMainWindow *SensorsWindow)
    {
        if (SensorsWindow->objectName().isEmpty())
            SensorsWindow->setObjectName(QStringLiteral("SensorsWindow"));
        SensorsWindow->resize(974, 509);
        centralWidget = new QWidget(SensorsWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        vl_simSens = new QVBoxLayout();
        vl_simSens->setSpacing(6);
        vl_simSens->setObjectName(QStringLiteral("vl_simSens"));
        hl_status = new QHBoxLayout();
        hl_status->setSpacing(6);
        hl_status->setObjectName(QStringLiteral("hl_status"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnInvRight = new QPushButton(centralWidget);
        btnInvRight->setObjectName(QStringLiteral("btnInvRight"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(239, 41, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 147, 147, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(247, 94, 94, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(119, 20, 20, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(159, 27, 27, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(247, 148, 148, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnInvRight->setPalette(palette);

        verticalLayout_6->addWidget(btnInvRight);

        btnInvLeft = new QPushButton(centralWidget);
        btnInvLeft->setObjectName(QStringLiteral("btnInvLeft"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnInvLeft->setPalette(palette1);

        verticalLayout_6->addWidget(btnInvLeft);


        hl_status->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        btnUPyFront = new QPushButton(centralWidget);
        btnUPyFront->setObjectName(QStringLiteral("btnUPyFront"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnUPyFront->setPalette(palette2);

        verticalLayout_5->addWidget(btnUPyFront);

        btnUPyRear = new QPushButton(centralWidget);
        btnUPyRear->setObjectName(QStringLiteral("btnUPyRear"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnUPyRear->setPalette(palette3);

        verticalLayout_5->addWidget(btnUPyRear);


        hl_status->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btnBMSHV = new QPushButton(centralWidget);
        btnBMSHV->setObjectName(QStringLiteral("btnBMSHV"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnBMSHV->setPalette(palette4);

        verticalLayout_4->addWidget(btnBMSHV);

        btnBMSLV = new QPushButton(centralWidget);
        btnBMSLV->setObjectName(QStringLiteral("btnBMSLV"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnBMSLV->setPalette(palette5);

        verticalLayout_4->addWidget(btnBMSLV);


        hl_status->addLayout(verticalLayout_4);


        vl_simSens->addLayout(hl_status);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vl_simSens->addItem(verticalSpacer);

        hl_inverter = new QHBoxLayout();
        hl_inverter->setSpacing(6);
        hl_inverter->setObjectName(QStringLiteral("hl_inverter"));
        btnInvDx = new QPushButton(centralWidget);
        btnInvDx->setObjectName(QStringLiteral("btnInvDx"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnInvDx->setPalette(palette6);

        hl_inverter->addWidget(btnInvDx);

        btnInvSx = new QPushButton(centralWidget);
        btnInvSx->setObjectName(QStringLiteral("btnInvSx"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnInvSx->setPalette(palette7);

        hl_inverter->addWidget(btnInvSx);

        btnPreCh = new QPushButton(centralWidget);
        btnPreCh->setObjectName(QStringLiteral("btnPreCh"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnPreCh->setPalette(palette8);

        hl_inverter->addWidget(btnPreCh);


        vl_simSens->addLayout(hl_inverter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vl_simSens->addItem(verticalSpacer_2);

        hl_errors = new QHBoxLayout();
        hl_errors->setSpacing(6);
        hl_errors->setObjectName(QStringLiteral("hl_errors"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnApps = new QPushButton(centralWidget);
        btnApps->setObjectName(QStringLiteral("btnApps"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnApps->setPalette(palette9);

        verticalLayout->addWidget(btnApps);

        btnWheelLeft = new QPushButton(centralWidget);
        btnWheelLeft->setObjectName(QStringLiteral("btnWheelLeft"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnWheelLeft->setPalette(palette10);

        verticalLayout->addWidget(btnWheelLeft);

        btnIMUFront = new QPushButton(centralWidget);
        btnIMUFront->setObjectName(QStringLiteral("btnIMUFront"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnIMUFront->setPalette(palette11);

        verticalLayout->addWidget(btnIMUFront);


        hl_errors->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnBSE = new QPushButton(centralWidget);
        btnBSE->setObjectName(QStringLiteral("btnBSE"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnBSE->setPalette(palette12);

        verticalLayout_2->addWidget(btnBSE);

        btnIMUCenter = new QPushButton(centralWidget);
        btnIMUCenter->setObjectName(QStringLiteral("btnIMUCenter"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnIMUCenter->setPalette(palette13);

        verticalLayout_2->addWidget(btnIMUCenter);


        hl_errors->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btnSteer = new QPushButton(centralWidget);
        btnSteer->setObjectName(QStringLiteral("btnSteer"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnSteer->setPalette(palette14);

        verticalLayout_3->addWidget(btnSteer);

        btnWheelRight = new QPushButton(centralWidget);
        btnWheelRight->setObjectName(QStringLiteral("btnWheelRight"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnWheelRight->setPalette(palette15);

        verticalLayout_3->addWidget(btnWheelRight);

        btnIMURear = new QPushButton(centralWidget);
        btnIMURear->setObjectName(QStringLiteral("btnIMURear"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnIMURear->setPalette(palette16);

        verticalLayout_3->addWidget(btnIMURear);


        hl_errors->addLayout(verticalLayout_3);


        vl_simSens->addLayout(hl_errors);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vl_simSens->addItem(verticalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnErrApps3 = new QPushButton(centralWidget);
        btnErrApps3->setObjectName(QStringLiteral("btnErrApps3"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(213, 213, 213, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush10(QColor(234, 234, 234, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(106, 106, 106, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(142, 142, 142, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrApps3->setPalette(palette17);

        gridLayout->addWidget(btnErrApps3, 1, 3, 1, 1);

        sliderSteer = new QSlider(centralWidget);
        sliderSteer->setObjectName(QStringLiteral("sliderSteer"));
        QPalette palette18;
        QBrush brush13(QColor(211, 209, 206, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette18.setBrush(QPalette::Active, QPalette::Highlight, brush13);
        palette18.setBrush(QPalette::Inactive, QPalette::Highlight, brush13);
        QBrush brush14(QColor(145, 141, 126, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette18.setBrush(QPalette::Disabled, QPalette::Highlight, brush14);
        sliderSteer->setPalette(palette18);
        sliderSteer->setMaximum(100);
        sliderSteer->setSliderPosition(50);
        sliderSteer->setTracking(true);
        sliderSteer->setOrientation(Qt::Horizontal);
        sliderSteer->setInvertedAppearance(false);
        sliderSteer->setInvertedControls(false);
        sliderSteer->setTickPosition(QSlider::TicksBothSides);
        sliderSteer->setTickInterval(50);

        gridLayout->addWidget(sliderSteer, 3, 0, 1, 1);

        btnErrBse2 = new QPushButton(centralWidget);
        btnErrBse2->setObjectName(QStringLiteral("btnErrBse2"));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette19.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette19.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette19.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette19.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush);
        palette19.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette19.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette19.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette19.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette19.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette19.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette19.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette19.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette19.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette19.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette19.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette19.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette19.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrBse2->setPalette(palette19);

        gridLayout->addWidget(btnErrBse2, 2, 2, 1, 1);

        sliderBse = new QSlider(centralWidget);
        sliderBse->setObjectName(QStringLiteral("sliderBse"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sliderBse->sizePolicy().hasHeightForWidth());
        sliderBse->setSizePolicy(sizePolicy);
        sliderBse->setMaximum(100);
        sliderBse->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderBse, 2, 0, 1, 1);

        btnErrApps4 = new QPushButton(centralWidget);
        btnErrApps4->setObjectName(QStringLiteral("btnErrApps4"));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette20.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette20.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette20.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette20.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush);
        palette20.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette20.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette20.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette20.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette20.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette20.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette20.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette20.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrApps4->setPalette(palette20);

        gridLayout->addWidget(btnErrApps4, 1, 4, 1, 1);

        btnErrApps2 = new QPushButton(centralWidget);
        btnErrApps2->setObjectName(QStringLiteral("btnErrApps2"));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette21.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette21.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette21.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette21.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush);
        palette21.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette21.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette21.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette21.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette21.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette21.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette21.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette21.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette21.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette21.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette21.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette21.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette21.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette21.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrApps2->setPalette(palette21);

        gridLayout->addWidget(btnErrApps2, 1, 2, 1, 1);

        btnErrApps5 = new QPushButton(centralWidget);
        btnErrApps5->setObjectName(QStringLiteral("btnErrApps5"));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette22.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette22.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette22.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette22.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush);
        palette22.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette22.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette22.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette22.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette22.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette22.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette22.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette22.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette22.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette22.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette22.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette22.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette22.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette22.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette22.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette22.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette22.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette22.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrApps5->setPalette(palette22);

        gridLayout->addWidget(btnErrApps5, 1, 5, 1, 1);

        btnErrBse1 = new QPushButton(centralWidget);
        btnErrBse1->setObjectName(QStringLiteral("btnErrBse1"));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette23.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette23.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette23.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette23.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush);
        palette23.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette23.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette23.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette23.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette23.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette23.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette23.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette23.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette23.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette23.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette23.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette23.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette23.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette23.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette23.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette23.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette23.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette23.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette23.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette23.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette23.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette23.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrBse1->setPalette(palette23);

        gridLayout->addWidget(btnErrBse1, 2, 1, 1, 1);

        btnErrBse3 = new QPushButton(centralWidget);
        btnErrBse3->setObjectName(QStringLiteral("btnErrBse3"));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette24.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette24.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette24.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette24.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette24.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush);
        palette24.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette24.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette24.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette24.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette24.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette24.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette24.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette24.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette24.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette24.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette24.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette24.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette24.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette24.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette24.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette24.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrBse3->setPalette(palette24);

        gridLayout->addWidget(btnErrBse3, 2, 3, 1, 1);

        btnErrSteer1 = new QPushButton(centralWidget);
        btnErrSteer1->setObjectName(QStringLiteral("btnErrSteer1"));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette25.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette25.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette25.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette25.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush);
        palette25.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette25.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette25.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette25.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette25.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette25.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette25.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette25.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette25.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette25.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette25.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette25.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette25.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette25.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette25.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette25.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette25.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette25.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette25.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette25.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrSteer1->setPalette(palette25);

        gridLayout->addWidget(btnErrSteer1, 3, 1, 1, 1);

        btnErrApps1 = new QPushButton(centralWidget);
        btnErrApps1->setObjectName(QStringLiteral("btnErrApps1"));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette26.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette26.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette26.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette26.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush);
        palette26.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette26.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette26.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette26.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette26.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette26.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette26.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette26.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette26.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette26.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette26.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette26.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette26.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette26.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette26.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette26.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette26.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette26.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette26.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette26.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrApps1->setPalette(palette26);

        gridLayout->addWidget(btnErrApps1, 1, 1, 1, 1);

        btnErrBse4 = new QPushButton(centralWidget);
        btnErrBse4->setObjectName(QStringLiteral("btnErrBse4"));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette27.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette27.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette27.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette27.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush);
        palette27.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette27.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette27.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette27.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette27.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette27.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette27.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette27.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette27.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette27.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette27.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette27.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette27.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette27.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette27.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette27.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette27.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette27.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette27.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette27.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette27.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette27.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette27.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette27.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette27.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnErrBse4->setPalette(palette27);

        gridLayout->addWidget(btnErrBse4, 2, 4, 1, 1);

        sliderApps = new QSlider(centralWidget);
        sliderApps->setObjectName(QStringLiteral("sliderApps"));
        sizePolicy.setHeightForWidth(sliderApps->sizePolicy().hasHeightForWidth());
        sliderApps->setSizePolicy(sizePolicy);
        sliderApps->setMaximum(100);
        sliderApps->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderApps, 1, 0, 1, 1);


        vl_simSens->addLayout(gridLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vl_simSens->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        QPalette palette28;
        QBrush brush15(QColor(255, 165, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette28.setBrush(QPalette::Active, QPalette::Highlight, brush15);
        palette28.setBrush(QPalette::Inactive, QPalette::Highlight, brush15);
        palette28.setBrush(QPalette::Disabled, QPalette::Highlight, brush14);
        verticalSlider->setPalette(palette28);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lblHV_TMax = new QLabel(centralWidget);
        lblHV_TMax->setObjectName(QStringLiteral("lblHV_TMax"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblHV_TMax);

        leHV_TMax = new QLineEdit(centralWidget);
        leHV_TMax->setObjectName(QStringLiteral("leHV_TMax"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leHV_TMax);

        lblHV_TAvg = new QLabel(centralWidget);
        lblHV_TAvg->setObjectName(QStringLiteral("lblHV_TAvg"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblHV_TAvg);

        leHV_TAvg = new QLineEdit(centralWidget);
        leHV_TAvg->setObjectName(QStringLiteral("leHV_TAvg"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leHV_TAvg);

        lblHV_TMin = new QLabel(centralWidget);
        lblHV_TMin->setObjectName(QStringLiteral("lblHV_TMin"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblHV_TMin);

        leHV_TMin = new QLineEdit(centralWidget);
        leHV_TMin->setObjectName(QStringLiteral("leHV_TMin"));

        formLayout->setWidget(2, QFormLayout::FieldRole, leHV_TMin);

        lblHV_VMax = new QLabel(centralWidget);
        lblHV_VMax->setObjectName(QStringLiteral("lblHV_VMax"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblHV_VMax);

        leHV_VMax = new QLineEdit(centralWidget);
        leHV_VMax->setObjectName(QStringLiteral("leHV_VMax"));

        formLayout->setWidget(3, QFormLayout::FieldRole, leHV_VMax);

        lblHV_VAvg = new QLabel(centralWidget);
        lblHV_VAvg->setObjectName(QStringLiteral("lblHV_VAvg"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblHV_VAvg);

        leHV_VAvg = new QLineEdit(centralWidget);
        leHV_VAvg->setObjectName(QStringLiteral("leHV_VAvg"));

        formLayout->setWidget(4, QFormLayout::FieldRole, leHV_VAvg);

        lblHV_VMin = new QLabel(centralWidget);
        lblHV_VMin->setObjectName(QStringLiteral("lblHV_VMin"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblHV_VMin);

        leHV_VMin = new QLineEdit(centralWidget);
        leHV_VMin->setObjectName(QStringLiteral("leHV_VMin"));

        formLayout->setWidget(5, QFormLayout::FieldRole, leHV_VMin);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        lblLV_V1 = new QLabel(centralWidget);
        lblLV_V1->setObjectName(QStringLiteral("lblLV_V1"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lblLV_V1);

        leLV_V1 = new QLineEdit(centralWidget);
        leLV_V1->setObjectName(QStringLiteral("leLV_V1"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, leLV_V1);

        leLV_V2 = new QLineEdit(centralWidget);
        leLV_V2->setObjectName(QStringLiteral("leLV_V2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, leLV_V2);

        lblLV_V2 = new QLabel(centralWidget);
        lblLV_V2->setObjectName(QStringLiteral("lblLV_V2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lblLV_V2);

        leLV_V3 = new QLineEdit(centralWidget);
        leLV_V3->setObjectName(QStringLiteral("leLV_V3"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, leLV_V3);

        lblLV_V3 = new QLabel(centralWidget);
        lblLV_V3->setObjectName(QStringLiteral("lblLV_V3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, lblLV_V3);

        leLV_V4 = new QLineEdit(centralWidget);
        leLV_V4->setObjectName(QStringLiteral("leLV_V4"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, leLV_V4);

        leLV_V5 = new QLineEdit(centralWidget);
        leLV_V5->setObjectName(QStringLiteral("leLV_V5"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, leLV_V5);

        leLV_TotE = new QLineEdit(centralWidget);
        leLV_TotE->setObjectName(QStringLiteral("leLV_TotE"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, leLV_TotE);

        lblLV_V4 = new QLabel(centralWidget);
        lblLV_V4->setObjectName(QStringLiteral("lblLV_V4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, lblLV_V4);

        lblLV_V5 = new QLabel(centralWidget);
        lblLV_V5->setObjectName(QStringLiteral("lblLV_V5"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, lblLV_V5);

        lblLV_TotE = new QLabel(centralWidget);
        lblLV_TotE->setObjectName(QStringLiteral("lblLV_TotE"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, lblLV_TotE);


        horizontalLayout->addLayout(formLayout_2);

        verticalSlider_2 = new QSlider(centralWidget);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        QPalette palette29;
        QBrush brush16(QColor(255, 170, 170, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette29.setBrush(QPalette::Active, QPalette::Highlight, brush16);
        palette29.setBrush(QPalette::Inactive, QPalette::Highlight, brush16);
        palette29.setBrush(QPalette::Disabled, QPalette::Highlight, brush14);
        verticalSlider_2->setPalette(palette29);
        verticalSlider_2->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_2);


        vl_simSens->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(vl_simSens);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        vl_volante = new QVBoxLayout();
        vl_volante->setSpacing(6);
        vl_volante->setObjectName(QStringLiteral("vl_volante"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(498, 290));

        vl_volante->addWidget(widget);

        gl_bottoniVolante = new QGridLayout();
        gl_bottoniVolante->setSpacing(6);
        gl_bottoniVolante->setObjectName(QStringLiteral("gl_bottoniVolante"));
        gl_bottoniVolante->setContentsMargins(0, 0, 0, 0);
        btnVolanteA = new QPushButton(centralWidget);
        btnVolanteA->setObjectName(QStringLiteral("btnVolanteA"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnVolanteA->sizePolicy().hasHeightForWidth());
        btnVolanteA->setSizePolicy(sizePolicy2);
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush17(QColor(207, 204, 201, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette30.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette30.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush18(QColor(231, 229, 228, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette30.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        QBrush brush19(QColor(103, 102, 100, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette30.setBrush(QPalette::Active, QPalette::Dark, brush19);
        QBrush brush20(QColor(138, 136, 134, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette30.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush);
        palette30.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette30.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette30.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette30.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette30.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette30.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette30.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette30.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette30.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette30.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette30.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette30.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette30.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette30.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette30.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette30.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette30.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette30.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette30.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette30.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette30.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette30.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette30.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette30.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnVolanteA->setPalette(palette30);

        gl_bottoniVolante->addWidget(btnVolanteA, 2, 1, 1, 1);

        btnVolanteR = new QPushButton(centralWidget);
        btnVolanteR->setObjectName(QStringLiteral("btnVolanteR"));
        sizePolicy2.setHeightForWidth(btnVolanteR->sizePolicy().hasHeightForWidth());
        btnVolanteR->setSizePolicy(sizePolicy2);
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette31.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette31.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        palette31.setBrush(QPalette::Active, QPalette::Dark, brush19);
        palette31.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette31.setBrush(QPalette::Active, QPalette::Text, brush);
        palette31.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette31.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette31.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette31.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette31.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette31.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette31.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette31.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette31.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette31.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette31.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette31.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette31.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette31.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette31.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette31.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette31.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette31.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette31.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette31.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette31.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette31.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette31.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette31.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette31.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette31.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette31.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnVolanteR->setPalette(palette31);

        gl_bottoniVolante->addWidget(btnVolanteR, 0, 5, 1, 1);

        btnVolanteD = new QPushButton(centralWidget);
        btnVolanteD->setObjectName(QStringLiteral("btnVolanteD"));
        sizePolicy2.setHeightForWidth(btnVolanteD->sizePolicy().hasHeightForWidth());
        btnVolanteD->setSizePolicy(sizePolicy2);
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette32.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette32.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        palette32.setBrush(QPalette::Active, QPalette::Dark, brush19);
        palette32.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette32.setBrush(QPalette::Active, QPalette::Text, brush);
        palette32.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette32.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette32.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette32.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette32.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette32.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette32.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette32.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette32.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette32.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette32.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette32.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette32.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette32.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette32.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette32.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette32.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette32.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette32.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette32.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette32.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette32.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette32.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette32.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette32.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette32.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette32.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette32.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnVolanteD->setPalette(palette32);

        gl_bottoniVolante->addWidget(btnVolanteD, 2, 3, 1, 1);

        btnVolanteQ = new QPushButton(centralWidget);
        btnVolanteQ->setObjectName(QStringLiteral("btnVolanteQ"));
        sizePolicy2.setHeightForWidth(btnVolanteQ->sizePolicy().hasHeightForWidth());
        btnVolanteQ->setSizePolicy(sizePolicy2);
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette33.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette33.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette33.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        palette33.setBrush(QPalette::Active, QPalette::Dark, brush19);
        palette33.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette33.setBrush(QPalette::Active, QPalette::Text, brush);
        palette33.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette33.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette33.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette33.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette33.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette33.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette33.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette33.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette33.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette33.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette33.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette33.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette33.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette33.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette33.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette33.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette33.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette33.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette33.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette33.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette33.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette33.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette33.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette33.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette33.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette33.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette33.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette33.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette33.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette33.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette33.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnVolanteQ->setPalette(palette33);

        gl_bottoniVolante->addWidget(btnVolanteQ, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gl_bottoniVolante->addItem(horizontalSpacer, 2, 2, 1, 1);

        sbVolanteManettino = new QSpinBox(centralWidget);
        sbVolanteManettino->setObjectName(QStringLiteral("sbVolanteManettino"));
        QPalette palette34;
        palette34.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette34.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette34.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette34.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        palette34.setBrush(QPalette::Active, QPalette::Dark, brush19);
        palette34.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette34.setBrush(QPalette::Active, QPalette::Text, brush);
        palette34.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette34.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette34.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette34.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette34.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette34.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette34.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette34.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette34.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette34.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette34.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette34.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette34.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette34.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette34.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette34.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette34.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette34.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette34.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette34.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette34.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette34.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette34.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette34.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette34.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette34.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette34.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette34.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette34.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette34.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette34.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette34.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette34.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        sbVolanteManettino->setPalette(palette34);
        sbVolanteManettino->setMinimum(1);
        sbVolanteManettino->setMaximum(8);

        gl_bottoniVolante->addWidget(sbVolanteManettino, 1, 2, 1, 1);


        vl_volante->addLayout(gl_bottoniVolante);

        vl_volante->setStretch(0, 1);

        horizontalLayout_2->addLayout(vl_volante);

        SensorsWindow->setCentralWidget(centralWidget);

        retranslateUi(SensorsWindow);

        QMetaObject::connectSlotsByName(SensorsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SensorsWindow)
    {
        SensorsWindow->setWindowTitle(QApplication::translate("SensorsWindow", "SensorsWindow", Q_NULLPTR));
        btnInvRight->setText(QApplication::translate("SensorsWindow", "Inv Right", Q_NULLPTR));
        btnInvLeft->setText(QApplication::translate("SensorsWindow", "Inv Left", Q_NULLPTR));
        btnUPyFront->setText(QApplication::translate("SensorsWindow", "UPyFront", Q_NULLPTR));
        btnUPyRear->setText(QApplication::translate("SensorsWindow", "UPyRear", Q_NULLPTR));
        btnBMSHV->setText(QApplication::translate("SensorsWindow", "BMS HV", Q_NULLPTR));
        btnBMSLV->setText(QApplication::translate("SensorsWindow", "BMS LV", Q_NULLPTR));
        btnInvDx->setText(QApplication::translate("SensorsWindow", "Inverter Dx", Q_NULLPTR));
        btnInvSx->setText(QApplication::translate("SensorsWindow", "Inverter Sx", Q_NULLPTR));
        btnPreCh->setText(QApplication::translate("SensorsWindow", "Pre Charge", Q_NULLPTR));
        btnApps->setText(QApplication::translate("SensorsWindow", "APPS", Q_NULLPTR));
        btnWheelLeft->setText(QApplication::translate("SensorsWindow", "Wheel Left", Q_NULLPTR));
        btnIMUFront->setText(QApplication::translate("SensorsWindow", "IMU Front", Q_NULLPTR));
        btnBSE->setText(QApplication::translate("SensorsWindow", "BSE", Q_NULLPTR));
        btnIMUCenter->setText(QApplication::translate("SensorsWindow", "IMU Center", Q_NULLPTR));
        btnSteer->setText(QApplication::translate("SensorsWindow", "Steer", Q_NULLPTR));
        btnWheelRight->setText(QApplication::translate("SensorsWindow", "Wheel Right", Q_NULLPTR));
        btnIMURear->setText(QApplication::translate("SensorsWindow", "IMU Rear", Q_NULLPTR));
        btnErrApps3->setText(QString());
        btnErrBse2->setText(QString());
        btnErrApps4->setText(QString());
        btnErrApps2->setText(QString());
        btnErrApps5->setText(QString());
        btnErrBse1->setText(QString());
        btnErrBse3->setText(QString());
        btnErrSteer1->setText(QString());
        btnErrApps1->setText(QString());
        btnErrBse4->setText(QString());
        lblHV_TMax->setText(QApplication::translate("SensorsWindow", "T. Max", Q_NULLPTR));
        lblHV_TAvg->setText(QApplication::translate("SensorsWindow", "T. Avg", Q_NULLPTR));
        lblHV_TMin->setText(QApplication::translate("SensorsWindow", "T. Min", Q_NULLPTR));
        lblHV_VMax->setText(QApplication::translate("SensorsWindow", "V. Max", Q_NULLPTR));
        lblHV_VAvg->setText(QApplication::translate("SensorsWindow", "V. Avg", Q_NULLPTR));
        lblHV_VMin->setText(QApplication::translate("SensorsWindow", "V. Min", Q_NULLPTR));
        lblLV_V1->setText(QApplication::translate("SensorsWindow", "V1", Q_NULLPTR));
        lblLV_V2->setText(QApplication::translate("SensorsWindow", "V2", Q_NULLPTR));
        lblLV_V3->setText(QApplication::translate("SensorsWindow", "V3", Q_NULLPTR));
        lblLV_V4->setText(QApplication::translate("SensorsWindow", "V4", Q_NULLPTR));
        lblLV_V5->setText(QApplication::translate("SensorsWindow", "V5", Q_NULLPTR));
        lblLV_TotE->setText(QApplication::translate("SensorsWindow", "Tot. E", Q_NULLPTR));
        btnVolanteA->setText(QApplication::translate("SensorsWindow", "A", Q_NULLPTR));
        btnVolanteR->setText(QApplication::translate("SensorsWindow", "R", Q_NULLPTR));
        btnVolanteD->setText(QApplication::translate("SensorsWindow", "D", Q_NULLPTR));
        btnVolanteQ->setText(QApplication::translate("SensorsWindow", "Q", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SensorsWindow: public Ui_SensorsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORSWINDOW_H
