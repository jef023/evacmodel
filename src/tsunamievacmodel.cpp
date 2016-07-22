#include "tsunamievacmodel.h"
#include "ui_tsunamievacmodel.h"

TsunamiEvacModel::TsunamiEvacModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TsunamiEvacModel)
{
    ui->setupUi(this);
    myGrid = new Grid;
    ui->statusBar->addWidget(&status);
    ui->mainToolBar->hide();
}

TsunamiEvacModel::~TsunamiEvacModel()
{
    delete ui;
}

void TsunamiEvacModel::setStatus(QString mstatus){
    status.setText(mstatus);
}

void TsunamiEvacModel::on_actionLoad_cost_grid_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QDir::homePath(), tr("Image Files (*.csv)"));
    QList<QStringList> myMat;

    QFile file;
    file.setFileName(fileName);
    if(file.open(QIODevice::ReadOnly))
        setStatus("File opened");
    else
        setStatus("Could not open file");

    while (!file.atEnd()){
        QByteArray line = file.readLine();
        QStringList temp;
        for(int i = 0; i < line.split(',').size(); i++)
            temp.append(line.split(',').at(i));
        myMat.append(temp);
    }

    QString temp;
    for(int i = 0; i < myMat.size(); i++){
        for(int j = 0; j < myMat.at(i).size(); j++){
            temp.append(myMat.at(i).at(j));
            temp.append(" ");
        }
        temp.append("\n");
        ui->textBrowser->append(temp);
    }

}
