#ifndef TSUNAMIEVACMODEL_H
#define TSUNAMIEVACMODEL_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include "grid.h"


namespace Ui {
class TsunamiEvacModel;
}

class TsunamiEvacModel : public QMainWindow
{
    Q_OBJECT

private:
    Grid* myGrid;
    QLabel status;
    void setStatus(QString mstatus);

public:
    explicit TsunamiEvacModel(QWidget *parent = 0);
    ~TsunamiEvacModel();

private slots:
    void on_actionLoad_cost_grid_triggered();

private:
    Ui::TsunamiEvacModel *ui;
};

#endif // TSUNAMIEVACMODEL_H
