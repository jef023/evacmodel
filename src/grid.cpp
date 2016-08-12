#include "grid.h"

Grid::Grid(int row, int col, QObject *parent) : QObject(parent)
{
    int count = 0;
    for(int i = 0; i < col; i++){
        QVector<Node> temp;
        for(int j = 0; j < row; j++){
            Node tempnode(count, i,j);
            temp.append(tempnode);
            count++;
        }
        grid.append(temp);
    }
    maxcol = grid.size();
    maxrow = grid.first().size();
}

void Grid::setValue(int x, int y, double val){
    if(x < maxcol && y <maxrow)
        grid[x][y].setValue(val);
}

void Grid::calcShortPath(int xp, int yp, int xs, int ys, QVector< QPair<int,int> >* path, QVector<double>* costdist){

    /*(if(xp < maxcol || yp < maxrow)
        return;
    if(xs < maxcol || ys < maxrow)
        return;
    */

    // Prepare the source and target node
    grid[xp][yp].setCostDistance(0+grid[xp][yp].z());
    QPair<int,int> target(xs,ys);
    // End prepare source and target node

    // Init temp coord
    QPair<int,int> coord(-1,-1);
    // End temp coord

    // Start for each node
    do {
        // Select least distant node
        coord = leastDistNode();
        Node* currentNode = &grid[coord.first][coord.second];
        currentNode->check();
        // End select distant node

        // Make a list with all the current coordinates neighboors
        int curX = 0, curY = 0;
        curX = currentNode->x();
        curY = currentNode->y();
        QList<Node*> neighborhood;
        if(curX+1 < maxcol && curX+1 >= 0 ){
            neighborhood.append(&grid[curX+1][curY]);
            if(curY+1 < maxrow && curY+1 >= 0 )
                neighborhood.append(&grid[curX+1][curY+1]);
            if(curY-1 < maxrow && curY-1 >= 0 )
                neighborhood.append(&grid[curX+1][curY-1]);
        }
        if(curX-1 < maxcol && curX-1 >= 0 ){
            neighborhood.append(&grid[curX-1][curY]);
            if(curY+1 < maxrow && curY+1 >= 0 )
                neighborhood.append(&grid[curX-1][curY+1]);
            if(curY-1 < maxrow && curY-1 >= 0 )
                neighborhood.append(&grid[curX-1][curY-1]);

        }
        if(curY+1 < maxrow && curY+1 >= 0 ){
            neighborhood.append(&grid[curX][curY+1]);
        }
        if(curY-1 < maxrow && curY-1 >= 0 ){
            neighborhood.append(&grid[curX][curY-1]);
        }
        // End list neighbors

        // Dist for this node
        double dist = std::numeric_limits<double>::max();
        QPair<int,int> lcoord(-1,-1);

        // For each neighbor i
        for (int i = 0; i < neighborhood.size(); i++){
            if(!neighborhood[i]->isChecked()){
                if(neighborhood[i]->z()+currentNode->costdist()+1 < neighborhood[i]->costdist()){
                    neighborhood[i]->setCostDistance(neighborhood[i]->z()+currentNode->costdist()+1);
                    neighborhood[i]->path.clear();
                    for (int j = 0; j < currentNode->path.size(); j++)
                        neighborhood[i]->path.append(currentNode->path.at(j));
                    neighborhood[i]->path.append(currentNode->coordinates());
                }
                if(neighborhood[i]->costdist() < dist ){
                    dist = neighborhood[i]->costdist();
                    lcoord = neighborhood[i]->coordinates();
                }
            }
        }
    } while (coord != target);
    // End for each node

    for(int i = 0; i < grid[xs][ys].path.size(); i++){
        QPair<int,int> lpc = grid[xs][ys].path.at(i);
        path->append(lpc);
        costdist->append(grid[lpc.first][lpc.second].costdist());
    }
    path->append(grid[xs][ys].coordinates());
    costdist->append(grid[xs][ys].costdist());
    resetGrid();
}

QPair<int,int> Grid::leastDistNode(){
    double leastDist = std::numeric_limits<double>::max();
    int idx = 0, idy = 0;
    for(int i = 0; i < maxrow; i++) {
        for(int j = 0; j < maxcol; j++){
            double currentCD = grid[i][j].costdist();
            if(currentCD < leastDist && !grid[i][j].isChecked()){
                leastDist = grid[i][j].costdist();
                idx = i;
                idy = j;
            }
        }
    }
    return QPair<int,int>(idx,idy);
}

void Grid::resetGrid(){
    for (int i = 0; i < grid.size(); i++){
        for(int j=0; j < grid.at(0).size(); j++){
            grid[i][j].reset();
        }
    }
}

int Grid::nrow(){
    return maxrow;
}

int Grid::ncol(){
    return maxcol;
}

