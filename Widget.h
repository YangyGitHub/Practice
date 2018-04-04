#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "TaskImport.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButtonSelFile_clicked();

private:
    Ui::Widget *ui;

    TaskImport*     _pTask;
};

#endif // WIDGET_H
