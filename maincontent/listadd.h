#ifndef LISTADD_H
#define LISTADD_H

#include <QWidget>

namespace Ui {
class ListAdd;
}

class ListAdd : public QWidget
{
    Q_OBJECT

public:
    explicit ListAdd(QWidget *parent = 0);
    ~ListAdd();

private:
    Ui::ListAdd *ui;
    void initValue();
};

#endif // LISTADD_H
