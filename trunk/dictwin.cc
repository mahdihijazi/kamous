/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@gmail.com
*/
#include <iostream>
#include <QMessageBox>
#include "dictwin.h"
#include "ui_dictwin.h"
#include "util.h"

using namespace std;

DictWin::DictWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DictWin)
{
    ui->setupUi(this);
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
    string searchWord = ui->wordTxt->text().toStdString();
    if (searchWord.length() == 0)
	return;
    try
    {
	Entry entry = dictionary.search(searchWord);
	int transNo = entry.transNumber();
	string* trans = entry.getTranslations();

	for (int i=0; i<=transNo; i++)
	{
	    ui->listWidget->addItem(QString::fromUtf8(trans[i].data()));
	}
	
    }catch(int eType)
    {
	ui->statusBar->showMessage(QString::fromUtf8(Util::getExceptionMessage(eType).data()), 2000);
	if (eType == 100)
	    clog << eType << " : " << "Data files not found, try to re-install the application!"<<endl;
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
