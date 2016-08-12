#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
}

Config::~Config()
{
    delete ui;
}

void Config::accept(){
    myParams.iniX = ui->Xini->text().toInt();
    myParams.iniY = ui->Yini->text().toInt();
    myParams.finX = ui->finX->text().toInt();
    myParams.finY = ui->finY->text().toInt();
    QDialog::accept();
}
