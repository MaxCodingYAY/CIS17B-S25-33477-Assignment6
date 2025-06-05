/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QLineEdit *lineEditID;
    QLineEdit *lineEditDesc;
    QLineEdit *lineEditLoc;
    QPushButton *pushButtonAdd;
    QLineEdit *lineEditFindID;
    QPushButton *pushButtonFind;
    QLineEdit *lineEditRemoveID;
    QPushButton *pushButtonRemove;
    QListWidget *listWidgetItems;
    QLabel *labelID;
    QLabel *labelDesc;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(724, 635);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEditID = new QLineEdit(centralwidget);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setGeometry(QRect(140, 50, 91, 24));
        lineEditDesc = new QLineEdit(centralwidget);
        lineEditDesc->setObjectName("lineEditDesc");
        lineEditDesc->setGeometry(QRect(300, 50, 121, 24));
        lineEditLoc = new QLineEdit(centralwidget);
        lineEditLoc->setObjectName("lineEditLoc");
        lineEditLoc->setGeometry(QRect(480, 50, 91, 24));
        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(320, 90, 80, 24));
        lineEditFindID = new QLineEdit(centralwidget);
        lineEditFindID->setObjectName("lineEditFindID");
        lineEditFindID->setGeometry(QRect(470, 160, 113, 24));
        pushButtonFind = new QPushButton(centralwidget);
        pushButtonFind->setObjectName("pushButtonFind");
        pushButtonFind->setGeometry(QRect(490, 200, 80, 24));
        lineEditRemoveID = new QLineEdit(centralwidget);
        lineEditRemoveID->setObjectName("lineEditRemoveID");
        lineEditRemoveID->setGeometry(QRect(140, 160, 113, 24));
        pushButtonRemove = new QPushButton(centralwidget);
        pushButtonRemove->setObjectName("pushButtonRemove");
        pushButtonRemove->setGeometry(QRect(150, 200, 80, 24));
        listWidgetItems = new QListWidget(centralwidget);
        listWidgetItems->setObjectName("listWidgetItems");
        listWidgetItems->setGeometry(QRect(220, 290, 291, 241));
        labelID = new QLabel(centralwidget);
        labelID->setObjectName("labelID");
        labelID->setGeometry(QRect(160, 30, 49, 16));
        labelDesc = new QLabel(centralwidget);
        labelDesc->setObjectName("labelDesc");
        labelDesc->setGeometry(QRect(330, 30, 61, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 30, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 130, 71, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(500, 130, 49, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 550, 241, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 724, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuFile);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);
        menuFile->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        lineEditID->setText(QString());
        lineEditDesc->setText(QString());
        lineEditLoc->setText(QString());
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
        lineEditFindID->setText(QString());
        pushButtonFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        lineEditRemoveID->setText(QString());
        pushButtonRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        labelID->setText(QCoreApplication::translate("MainWindow", "      ID", nullptr));
        labelDesc->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Remove Item", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Find Item", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Look in File - Help - About for more details", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
