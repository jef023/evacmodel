#include "tsunamievacmodel.h"
#include "ui_tsunamievacmodel.h"

TsunamiEvacModel::TsunamiEvacModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TsunamiEvacModel)
{
    ui->setupUi(this);
}

TsunamiEvacModel::~TsunamiEvacModel()
{
    delete ui;
}
