#include "grid.h"

Grid::Grid(QObject *parent,int row,int col) : QObject(parent), numrow(row), numcol(col)
{
    for(int i = 0; i < numrow; i++) {
        for(int j = 0; j < numcol; j++){
            currentPair = new QPair<int,int>(i,j);
            cost[currentPair] = 0;
        }
    }
}

void Grid::setValue(int row, int col, double value) {
    if (row < numrow) {
        if(col < numcol) {
            QPair<int,int> key(row,col);
            cost[&key] = value;
        }
    }
}

void Grid::calcShortPath(int xp, int yp, int xs, int ys){


}

int Grid::nrow(){
    return numrow;
}

int Grid::ncol(){
    return numcol;
}

