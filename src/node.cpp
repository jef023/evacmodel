#include "node.h"

using namespace std;

Node::Node(){
    ID = nx = ny = nz = 0;
    costdistance = numeric_limits<double>::max();
    checked = false;
}

Node::Node(int id, int xval, int yval) :
    ID(id), nx(xval), ny(yval)
{
    costdistance = numeric_limits<double>::max();
    nz = 0;
    checked = false;
}

Node::Node(int id, int xval, int yval, double zval) :
    ID(id), nx(xval), ny(yval), nz(zval)
{
    costdistance = numeric_limits<double>::max();
    checked = false;
}

Node::Node(int id, int xval, int yval, double zval, bool check):
    ID(id), nx(xval), ny(yval), nz(zval), checked(check)
{
    costdistance = numeric_limits<double>::max();
}

bool Node::operator ==(Node &rhs){
    if(this->nx == rhs.nx && this->ny == rhs.ny)
        return true;
    return false;
}

bool Node::operator ==(QPair<int,int> &rhs){
    if(this->coordinates() == rhs)
        return true;
    return false;
}

QPair<int,int> Node::coordinates(){
    return QPair<int,int>(nx,ny);
}

void Node::reset(){
    path.clear();
    costdistance = numeric_limits<double>::max();
    checked = false;
}

void Node::check(){
    if(!checked)
        checked = true;
}

bool Node::isChecked(){
    return checked;
}

int Node::x(){
    return nx;
}

int Node::y(){
    return ny;
}

int Node::z(){
    return nz;
}
int Node::getID(){
    return ID;
}

double Node::costdist(){
    return costdistance;
}

void Node::setValue(double value) {
    nz = value;
}

void Node::setCostDistance(double costD){
    costdistance = costD;
}
