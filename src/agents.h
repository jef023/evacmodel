#ifndef AGENTS_H
#define AGENTS_H

#include <QObject>

class Agents : QObject
{
    Q_OBJECT
public:
    explicit Agents(QObject* parent = 0);
    int age;
    int ID, GID;
    bool gender, HSSize;
    int  distance;
    double fatigue;
    int x,y;
    bool atRoad;
    bool withGroup;
    // int state
    void determinePath();
    void safeZone();
    void move();
    double group();

private:
    double speed;


signals:

public slots:
};

#endif // AGENTS_H
