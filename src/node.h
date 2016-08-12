#ifndef NODE_H
#define NODE_H
#include <QPair>
#include <limits>
#include <QVector>


class Node
{
public:
    explicit Node();
    explicit Node(int id, int xval, int yval);
    explicit Node(int id,int xval, int yval, double zval);
    explicit Node(int id,int xval, int yval, double zval, bool check = false);

    bool operator==(Node &rhs);
    bool operator==(QPair<int,int> &rhs);

    QVector< QPair<int,int> > path;

    void reset();
    QPair<int,int> coordinates();
    void check();
    bool isChecked();
    void setValue(double value);
    void setCostDistance(double costD);
    double costdist();
    int x();
    int y();
    int z();
    int getID();

private:
    int ID;
    int nx, ny;
    double nz;
    double costdistance;
    bool checked;
};

#endif // NODE_H
