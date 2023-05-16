/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCustomPlot *plot;
    QLabel *label_2;
    QCustomPlot *plot_2;
    QLabel *label_3;
    QCustomPlot *plot_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1197, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));

        verticalLayout->addWidget(plot);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        plot_2 = new QCustomPlot(centralwidget);
        plot_2->setObjectName(QString::fromUtf8("plot_2"));

        verticalLayout->addWidget(plot_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        plot_3 = new QCustomPlot(centralwidget);
        plot_3->setObjectName(QString::fromUtf8("plot_3"));

        verticalLayout->addWidget(plot_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 6);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 6);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1197, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \321\202\321\200\320\265\320\275\320\264\320\260 \320\264\320\260\320\275\320\275\321\213\321\205.", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\203\321\202\321\201\321\202\320\262\320\270\320\265 \321\202\321\200\320\265\320\275\320\264\320\260 \320\264\320\260\320\275\320\275\321\213\321\205.", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\267\320\262\321\203\320\272\320\260 \320\276\321\202 \321\200\320\260\321\201\321\207\320\270\321\202\320\260\320\275\320\275\320\276\320\263\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217(\320\223\321\200\320\260\321\204\320\270\320\272 \320\272\321\200\320\260\321\201\320\275\320\276\320\263\320\276 \321\206\320\262\320\265\321\202\320\260).", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
