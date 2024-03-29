#include <QMessageBox>
#include <QStringList>
#include <QApplication>
#include <QAction>

#include "dictwin.h"
#include "ui_dictwin.h"
#include "util.h"

using namespace std;

DictWin::DictWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DictWin), dictionary()
{
    ui->setupUi(this);
    ui->wordTxt->setFocus();

    addSoftKeys();

}

DictWin::~DictWin()
{
    delete ui;
}

void DictWin::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DictWin::addSoftKeys() {
    #ifdef Q_OS_SYMBIAN
    this->menuBar()->addAction(tr("About"), this, SLOT(on_action_triggered()));

    // remove desktop menus
    this->menuBar()->removeAction(ui->menu->menuAction());
    this->menuBar()->removeAction(ui->menuHello->menuAction());

    this->menuBar()->removeAction(ui->action);
    this->menuBar()->removeAction(ui->actionExit);
    #endif

}

void DictWin::nextClicked()
{
//Your code here
}
void DictWin::on_actionExit_triggered()
{
    exit(0);
}

void DictWin::clearWidgets()
{
    ui->wordTxt->setFocus();
    ui->wordTxt->selectAll();
    ui->listWidget->clear();
}

void DictWin::invokeSearch()
{
    clearWidgets();

    QString searchWord = ui->wordTxt->text();
    if( searchWord.isEmpty() ) {
        return;

    } else {
        try {
            QStringList translations = dictionary.search(searchWord);
            for (int i=0; i<translations.size(); i++)
            {
                ui->listWidget->addItem(translations[i]);
            }

        } catch(int eType) {
            QApplication::beep();

        }

    }
    
}

void DictWin::on_pushButton_clicked()
{
    invokeSearch();
}

void DictWin::on_wordTxt_returnPressed()
{
    invokeSearch();
}

void DictWin::on_action_triggered()
{
    QMessageBox msg;
    msg.setTextFormat(Qt::RichText);
    msg.setText(QString::fromUtf8( 
		"<center><b>Kamous version 0.1 <br />"
		"قـاموس إنجليزي-عربي</b></center>"));
    msg.setInformativeText(
	    QString::fromUtf8("<center>"
			      "معتمد على قاعدة الكلمات من عرب أيز<br />"
			      "الترخيص: ترخيص وقف<br />"
			      "الكاتب: محمد هويدي<br />"
			      "<a href='http://m-hewedy.blogspot.com'>http://m-hewedy.blogspot.com</a><br />"
			      "إهداء لمنتديات الفريق العربي للبرمجه<br />"
			      "2010<br />"
			      "</center>"
			      )
	    );
    msg.exec();
}
