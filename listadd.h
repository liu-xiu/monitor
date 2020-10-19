#ifndef LISTADD_H
#define LISTADD_H

#include <QDialog>
#include "systemtray/systemtray.h"
namespace Ui {
class ListAdd;
}

class ListAdd : public QDialog
{
    Q_OBJECT

public:
    explicit ListAdd(QWidget *parent = nullptr);
    ~ListAdd();
private:
    SystemTray *syetemTray;
private:
    Ui::ListAdd *ui;
    void initValue();
};

#endif // LISTADD_H
