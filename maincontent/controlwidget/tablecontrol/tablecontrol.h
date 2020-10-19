/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：表格
 * ***************************************/
#ifndef TABLECONTROL_H
#define TABLECONTROL_H

#include <QWidget>
#include <QMap>
#include "tablewidget.h"
#include "listadd_dia.h"
#include "listedit_dia.h"
#include "listselectbyip.h"
#include <QFileDialog>


namespace Ui {
class TableControl;
}

typedef struct CellData
{
    enum DataType
    {
        DANGER,
        WARNING,
        NORMAL
    };
    CellData() : color(Qt::white)
    {

    }
    void setDataType(DataType dataType)
    {
        if (dataType == DANGER)
        {
            color = QColor(240, 0, 0);
        }
        else if (dataType == WARNING)
        {
            color = QColor(238, 184, 76);
        }
        else {
            color = QColor(Qt::white);
        }
    }
    QString data;
    QColor color;
}CellData;

using MapTableData = QMap<int, CellData>;

class TableControl : public QWidget
{
    Q_OBJECT

public:
    enum TableDataType
    {
        ID,
        NAME,
        IP,
        TYPE,
        TYPEID,
        /////////
        Port
    };
    explicit TableControl(QWidget *parent = nullptr);
    ~TableControl();
    void appendTableData(const MapTableData &mapTableData);
    void updateTableData(const QList<MapTableData> &mapListData);
    void select_Bind();
    void changeCheck(int row, int col);
    Ui::TableControl *ui;
private slots:
    void on_pBn_Add_clicked();
    void on_pBn_PutIn_clicked();
    void on_pBn_Push_clicked();
    void on_pBn_Delete_clicked();
    void on_pBn_Edit_clicked();
    void on_pBn_Search_clicked();

    void GetStr(QString);
    void on_pBn_SelectByIP_clicked();

signals:
        void sendStr(QString);
private:
    ListAdd_Dia *list_d;
    ListEdit_dia *list_e;
    ListSelectByIP *listselect;
    //ListAdd *list;
    QList<MapTableData> m_mapListTableData;
private:
    void initValue();
};

#endif // TABLECONTROL_H
