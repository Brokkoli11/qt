#include "mintamodel.h"

Mintamodel::Mintamodel(QObject *parent) : QObject(parent)
{
    _timer = new QTimer;
    _timer->setInterval(1000); // 1 másodperc
    connect(_timer,SIGNAL(timeout()),this,SLOT(timerTicked()));
}

void Mintamodel::startNewGame(int size)
{
    _n = size;
    _fields.clear();

    for(int i=0;i<size;i++) {
        QVector<int> v;
        for(int j=0;j<size;j++) {
            v.push_back(0);
        }
        _fields.push_back(v);
    }

    //Itt átállítani bizonyos mezőket amiket a feladat kér

    gameStarted();
    _elapsedTime = 0;
    _timer->start();

}

int Mintamodel::n() const
{
    return _n;
}

int Mintamodel::getField(int i, int j)
{
    return _fields[i][j];
}

int Mintamodel::getElapsedTime() const
{
    return _elapsedTime;
}

void Mintamodel::fieldPressed(int ind)
{
    int i=ind/_n;
    int j = ind%_n;
    qDebug() << i << "\t" << j << "\n";
    //Csinálni valamit a boarddal, ha kell
    fieldsChanged();
}

void Mintamodel::timerTicked()
{
    _elapsedTime++;
    fieldsChanged();
}
