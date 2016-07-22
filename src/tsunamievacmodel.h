#ifndef TSUNAMIEVACMODEL_H
#define TSUNAMIEVACMODEL_H

#include <QMainWindow>

namespace Ui {
class TsunamiEvacModel;
}

class TsunamiEvacModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit TsunamiEvacModel(QWidget *parent = 0);
    ~TsunamiEvacModel();

private:
    Ui::TsunamiEvacModel *ui;
};

#endif // TSUNAMIEVACMODEL_H
