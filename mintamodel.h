#ifndef MINTAMODEL_H
#define MINTAMODEL_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Mintamodel : public QObject
{
    Q_OBJECT
public:
    explicit Mintamodel(QObject *parent = nullptr);
    void startNewGame(int size);
    int n() const;
    int getField(int i, int j);
    int getElapsedTime() const;
    void fieldPressed(int ind);

private:
    int _n;
    int _elapsedTime;
    QVector<QVector<int>> _fields;
    QTimer* _timer;

signals:
    void gameStarted();
    void fieldsChanged();

private slots:
    void timerTicked();
};

#endif // MINTAMODEL_H
