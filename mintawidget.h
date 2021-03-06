#ifndef MINTAWIDGET_H
#define MINTAWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include "mintamodel.h"
#include "sizedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MintaWidget; }
QT_END_NAMESPACE

class MintaWidget : public QWidget
{
    Q_OBJECT

public:
    MintaWidget(QWidget *parent = nullptr);
    ~MintaWidget();

private:
    Ui::MintaWidget *ui;
    QVBoxLayout* _mainColumn;
    QGridLayout* _buttonGrid;
    QPushButton* _newGameButton;
    QVector<QVector<QPushButton*>> _fields;
    Mintamodel* _model;
    SizeDialog* _sizeDialog;
    void changeButton(QPushButton* p, int v);


private slots:
    void changeFields();
    void generateFields();
    void endGame();
    void newGameButtonPressed();
    void sizeDialogAccepted();
    void boardButtonPressed();


};
#endif // MINTAWIDGET_H
