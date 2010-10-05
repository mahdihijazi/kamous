/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@gmail.com
*/
#ifndef DICTWIN_H
#define DICTWIN_H

#include <QMainWindow>
#include "dictionary.h"

namespace Ui {
    class DictWin;
}

class DictWin : public QMainWindow {
    Q_OBJECT
public:
    DictWin(QWidget *parent = 0);
    ~DictWin();
    void invokeSearch();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DictWin *ui;
    Dictionary dictionary;
    void clearWidgets();

private slots:
    void on_action_triggered();
    void on_wordTxt_returnPressed();
    void on_pushButton_clicked();
    void on_actionExit_triggered();
};

#endif // DICTWIN_H
