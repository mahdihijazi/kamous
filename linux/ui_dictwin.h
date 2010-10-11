/********************************************************************************
** Form generated from reading UI file 'dictwin.ui'
**
** Created: Mon Sep 27 14:39:00 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTWIN_H
#define UI_DICTWIN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DictWin
{
public:
    QAction *actionExit;
    QAction *action;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *wordTxt;
    QLabel *label;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menuHello;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DictWin)
    {
        if (DictWin->objectName().isEmpty())
            DictWin->setObjectName(QString::fromUtf8("DictWin"));
        DictWin->resize(380, 280);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DictWin->sizePolicy().hasHeightForWidth());
        DictWin->setSizePolicy(sizePolicy);
        DictWin->setMinimumSize(QSize(380, 280));
        DictWin->setMaximumSize(QSize(380, 280));
        DictWin->setLayoutDirection(Qt::RightToLeft);
        DictWin->setLocale(QLocale(QLocale::Arabic, QLocale::Egypt));
        DictWin->setDocumentMode(false);
        actionExit = new QAction(DictWin);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        action = new QAction(DictWin);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(DictWin);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 71, 24));
        wordTxt = new QLineEdit(centralWidget);
        wordTxt->setObjectName(QString::fromUtf8("wordTxt"));
        wordTxt->setGeometry(QRect(100, 10, 191, 25));
        wordTxt->setLayoutDirection(Qt::LeftToRight);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 10, 41, 20));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 341, 161));
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        font.setPointSize(10);
        listWidget->setFont(font);
        listWidget->setLayoutDirection(Qt::RightToLeft);
        listWidget->setViewMode(QListView::ListMode);
        DictWin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DictWin);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 25));
        menuHello = new QMenu(menuBar);
        menuHello->setObjectName(QString::fromUtf8("menuHello"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        DictWin->setMenuBar(menuBar);
        statusBar = new QStatusBar(DictWin);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DictWin->setStatusBar(statusBar);

        menuBar->addAction(menuHello->menuAction());
        menuBar->addAction(menu->menuAction());
        menuHello->addAction(actionExit);
        menu->addAction(action);

        retranslateUi(DictWin);

        QMetaObject::connectSlotsByName(DictWin);
    } // setupUi

    void retranslateUi(QMainWindow *DictWin)
    {
        DictWin->setWindowTitle(QApplication::translate("DictWin", "Kamous", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("DictWin", "\330\256\330\261\331\210\330\254", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("DictWin", "\330\271\331\206 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DictWin", "\330\250\330\255\330\253", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DictWin", "\330\247\331\204\331\203\331\204\331\205\330\251", 0, QApplication::UnicodeUTF8));
        menuHello->setTitle(QApplication::translate("DictWin", "&\331\205\331\204\331\201", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("DictWin", "\330\247\331\204\331\205\330\263\330\247&\330\271\330\257\331\207", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DictWin: public Ui_DictWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTWIN_H
