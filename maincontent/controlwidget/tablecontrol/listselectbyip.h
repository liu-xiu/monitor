#ifndef LISTSELECTBYIP_H
#define LISTSELECTBYIP_H

#include <QDialog>

namespace Ui {
class ListSelectByIP;
}

class ListSelectByIP : public QDialog
{
    Q_OBJECT

public:
    explicit ListSelectByIP(QWidget *parent = nullptr);
    ~ListSelectByIP();

private slots:
    void on_pBn_Close_clicked();

private:
    Ui::ListSelectByIP *ui;
};

#endif // LISTSELECTBYIP_H
