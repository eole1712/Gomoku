/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <modifiableQLabel.hpp>
#include <winchanger.hpp>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChangeName;
    QWidget *centralWidget;
    winChanger *stackedWidget;
    QWidget *page;
    QFrame *frame_2;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *page_2;
    QFrame *frame;
    QPushButton *PvP;
    QPushButton *PvE;
    QLabel *name;
    modifiableQLabel *Message;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(925, 635);
        actionChangeName = new QAction(MainWindow);
        actionChangeName->setObjectName(QStringLiteral("actionChangeName"));
        actionChangeName->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        stackedWidget = new winChanger(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 891, 571));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setSizeIncrement(QSize(2, 2));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        sizePolicy.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy);
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setEnabled(true);
        frame_2->setGeometry(QRect(0, 10, 901, 571));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setSizeIncrement(QSize(10, 10));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(760, 240, 111, 41));
        gridLayoutWidget = new QWidget(frame_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 16, 741, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        sizePolicy.setHeightForWidth(page_2->sizePolicy().hasHeightForWidth());
        page_2->setSizePolicy(sizePolicy);
        frame = new QFrame(page_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(0, 0, 871, 531));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        PvP = new QPushButton(frame);
        PvP->setObjectName(QStringLiteral("PvP"));
        PvP->setGeometry(QRect(570, 240, 211, 51));
        PvE = new QPushButton(frame);
        PvE->setObjectName(QStringLiteral("PvE"));
        PvE->setGeometry(QRect(570, 330, 211, 61));
        name = new QLabel(frame);
        name->setObjectName(QStringLiteral("name"));
        name->setEnabled(true);
        name->setGeometry(QRect(70, 30, 491, 201));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(8);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        name->setMinimumSize(QSize(10, 0));
        name->setSizeIncrement(QSize(100, 100));
        QFont font;
        font.setFamily(QStringLiteral("URW Palladio L"));
        font.setPointSize(42);
        font.setItalic(true);
        name->setFont(font);
        name->setLineWidth(4);
        name->setTextFormat(Qt::AutoText);
        name->setScaledContents(true);
        name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        name->setWordWrap(false);
        Message = new modifiableQLabel(frame);
        Message->setObjectName(QStringLiteral("Message"));
        Message->setGeometry(QRect(30, 130, 141, 81));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 20));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
#ifndef QT_NO_SHORTCUT
        name->setBuddy(name);
        Message->setBuddy(PvP);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);
        QObject::connect(PvP, SIGNAL(clicked()), Message, SLOT(setQLabel()));
        QObject::connect(PvE, SIGNAL(clicked()), frame_2, SLOT(setFocus()));
        QObject::connect(pushButton, SIGNAL(clicked()), frame, SLOT(setFocus()));
        QObject::connect(PvP, SIGNAL(clicked()), stackedWidget, SLOT(nextWidget()));
        QObject::connect(pushButton, SIGNAL(clicked()), stackedWidget, SLOT(prevWidget()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionChangeName->setText(QApplication::translate("MainWindow", "changeName", 0));
#ifndef QT_NO_TOOLTIP
        actionChangeName->setToolTip(QApplication::translate("MainWindow", "change the name", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "Back", 0));
        PvP->setText(QApplication::translate("MainWindow", "Player vs Player", 0));
        PvE->setText(QApplication::translate("MainWindow", "Player vs IA", 0));
        name->setText(QApplication::translate("MainWindow", "Gomoku !", 0));
        Message->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
