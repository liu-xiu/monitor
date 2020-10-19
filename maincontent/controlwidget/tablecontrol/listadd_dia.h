#ifndef LISTADD_DIA_H
#define LISTADD_DIA_H

#include <QDialog>


namespace Ui {
class ListAdd_Dia;
}

class ListAdd_Dia : public QDialog
{
    Q_OBJECT

public:
    explicit ListAdd_Dia(QWidget *parent = nullptr);
    ~ListAdd_Dia();

private slots:
    void on_pBn_Add_clicked();

    void on_pBn_Close_clicked();

private:
    Ui::ListAdd_Dia *ui;
};

#endif // LISTADD_DIA_H
