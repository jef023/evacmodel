#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QVector>
#include <limits>
#include "node.h"

class Grid : public QObject
{
    Q_OBJECT
public:
    explicit Grid(int row, int col, QObject *parent = 0);
    QVector< QVector<Node> > grid;
    int ncol();
    int nrow();
    void setValue(int x, int y, double val);

    QPair<int,int> leastDistNode();
    void calcShortPath(int xp, int yp, int xs, int ys, QVector<QPair<int, int> > *path, QVector<double> *costdist);
    void resetGrid();

private:
    int maxcol;
    int maxrow;

signals:

public slots:
};

#endif // GRID_H
