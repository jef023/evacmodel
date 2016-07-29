#ifndef GRID_H
#define GRID_H
#include "matrix/armadillo"
#include <QObject>
#include <QPair>
#include <QMap>

class Grid : public QObject
{
    Q_OBJECT
public:
    explicit Grid(QObject *parent = 0, int row = 0, int col = 0);
    QPair<int,int>* currentPair;
    QMap<QPair<int,int>*, double> cost;
    void setValue(int row,int col, double value);
    int nrow();
    int ncol();
    void calcShortPath(int xp, int yp, int xs, int ys);

private:
    int numrow;
    int numcol;

signals:

public slots:

};

#endif // GRID_H
