#ifndef LISTEDIT_DIA_H
#define LISTEDIT_DIA_H

#include <QDialog>

namespace Ui {
class ListEdit_dia;
}

class ListEdit_dia : public QDialog
{
    Q_OBJECT

public:
    explicit ListEdit_dia(QWidget *parent = nullptr);
    ~ListEdit_dia();
private slots:
        void getStr(QString);
        void on_pBn_Edit_clicked();
        //void TableBind(int,QString);
        void on_pBn_Close_clicked();
signals:
        void SendStr(QString);
private:
    Ui::ListEdit_dia *ui;
};

#endif // LISTEDIT_DIA_H
