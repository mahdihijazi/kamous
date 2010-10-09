/********************************************************************************
** Form generated from reading UI file 'dictwin.ui'
**
** Created: Fri 8. Oct 14:55:36 2010
**      by: Qt User Interface Compiler version 4.6.3
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DictWin
{
public:
    QAction *actionExit;
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *wordTxt;
    QLabel *label;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DictWin)
    {
        if (DictWin->objectName().isEmpty())
            DictWin->setObjectName(QString::fromUtf8("DictWin"));
        DictWin->resize(380, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DictWin->sizePolicy().hasHeightForWidth());
        DictWin->setSizePolicy(sizePolicy);
        DictWin->setMinimumSize(QSize(380, 280));
        DictWin->setMaximumSize(QSize(16767604, 16769696));
        DictWin->setLayoutDirection(Qt::RightToLeft);
        DictWin->setLocale(QLocale(QLocale::Arabic, QLocale::Egypt));
        DictWin->setDocumentMode(false);
        actionExit = new QAction(DictWin);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        action = new QAction(DictWin);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(DictWin);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        wordTxt = new QLineEdit(centralWidget);
        wordTxt->setObjectName(QString::fromUtf8("wordTxt"));
        wordTxt->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(wordTxt, 0, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        font.setPointSize(10);
        listWidget->setFont(font);
        listWidget->setLayoutDirection(Qt::RightToLeft);
        listWidget->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(listWidget);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        DictWin->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DictWin);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DictWin->setStatusBar(statusBar);

        retranslateUi(DictWin);

        QMetaObject::connectSlotsByName(DictWin);
    } // setupUi

    void retranslateUi(QMainWindow *DictWin)
    {
        DictWin->setWindowTitle(QApplication::translate("DictWin", "Kamous", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("DictWin", "\330\256\330\261\331\210\330\254", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("DictWin", "\330\271\331\206 \330\247\331\204\330\250\330\261\331\206\330\247\331\205\330\254", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DictWin", "\330\247\331\204\331\203\331\204\331\205\330\251", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DictWin", "\330\250\330\255\330\253", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DictWin: public Ui_DictWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTWIN_H
