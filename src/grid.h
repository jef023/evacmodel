#ifndef GRID_H
#define GRID_H
#include "matrix/armadillo"
#include <QObject>


class Grid : public QObject
{
    Q_OBJECT
public:
    explicit Grid(QObject *parent = 0);
    arma::Mat<double> test;

signals:

public slots:

};

#endif // GRID_H
