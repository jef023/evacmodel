#ifndef TSUNAMIEVACMODEL_H
#define TSUNAMIEVACMODEL_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include "node.h"
#include "grid.h"
#include "config.h"


namespace Ui {
class TsunamiEvacModel;
}

class TsunamiEvacModel : public QMainWindow
{
    Q_OBJECT

private:
    bool haveParams;
    Grid* myGrid;
    QLabel status;
    void setStatus(QString mstatus);
    Config * myConfig;
    Config::Params myParams;

public:
    explicit TsunamiEvacModel(QWidget *parent = 0);
    ~TsunamiEvacModel();

private slots:
    void ConfAcc();
    void on_actionLoad_cost_grid_triggered();

    void on_actionTest_config_triggered();

private:
    Ui::TsunamiEvacModel *ui;
};

#endif // TSUNAMIEVACMODEL_H
