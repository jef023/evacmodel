#include "tsunamievacmodel.h"
#include "ui_tsunamievacmodel.h"

TsunamiEvacModel::TsunamiEvacModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TsunamiEvacModel)
{
    ui->setupUi(this);
    ui->statusBar->addWidget(&status);
    ui->mainToolBar->hide();
    myConfig = new Config;
    connect(myConfig,SIGNAL(accepted()),this,SLOT(ConfAcc()));
    haveParams = false;

}

TsunamiEvacModel::~TsunamiEvacModel()
{
    delete ui;
}

void TsunamiEvacModel::setStatus(QString mstatus){
    status.setText(mstatus);
}

void TsunamiEvacModel::ConfAcc(){
    if(!haveParams){
        myParams = myConfig->myParams;
        haveParams = true;
    }
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
    delete myGrid;
    myGrid = new Grid(myMat.size(),myMat.at(1).size(),this);

    for(int i = 0; i < myMat.size(); i++){
        for(int j = 0; j < myMat.at(i).size(); j++){

            myGrid->setValue(i,j,myMat.at(i).at(j).toInt());
            temp.append(myMat.at(i).at(j));
            temp.append(" ");
        }
        temp.append("\n");
    }
    ui->textBrowser->append(temp);
}

void TsunamiEvacModel::on_actionTest_config_triggered()
{
    myConfig->exec();
    QVector<double>  costdist;
    QVector< QPair<int,int> > path;
    myGrid->calcShortPath(myParams.iniX,myParams.iniY,myParams.finX,myParams.finY, &path, &costdist);
    for (int i = 0; i < path.size(); i++)
        ui->textBrowser->append("Path: " + QString::number(path.at(i).first) + "," + QString::number(path.at(i).second) + "  Distance: "+ QString::number(costdist.at(i)));
    haveParams = false;
    ui->textBrowser->append("\n");
}
