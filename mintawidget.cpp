#include "mintawidget.h"
#include "ui_mintawidget.h"
#include "QMessageBox"
#include <sizedialog.h>

MintaWidget::MintaWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MintaWidget)
{
    ui->setupUi(this);
    _mainColumn = new QVBoxLayout;
    _buttonGrid = new QGridLayout;
    _newGameButton = new QPushButton ("Új játék");
    _model = new Mintamodel;
    _sizeDialog = nullptr;

    setLayout(_mainColumn);
    _mainColumn->addWidget(_newGameButton);
    _mainColumn->setAlignment(Qt::AlignTop);
    _mainColumn->setSpacing(0);
    _mainColumn->setStretchFactor(_newGameButton,20);
    _mainColumn->addLayout(_buttonGrid);
    _mainColumn->setAlignment(_buttonGrid,Qt::AlignCenter);

    setFixedSize(500,500);
    setWindowTitle("Játék");
    connect(_model,SIGNAL(fieldsChanged()),this,SLOT(changeFields()));
    connect(_model,SIGNAL(gameStarted()),this,SLOT(generateFields()));
    connect(_newGameButton,SIGNAL(clicked()),this,SLOT(newGameButtonPressed()));

    _model->startNewGame(8); //Ha kéri a feladat, hogy alapból mondjuk 8x8as tábla legyen


}

MintaWidget::~MintaWidget()
{
    delete ui;
    delete _sizeDialog;
}

void MintaWidget::changeButton(QPushButton *p, int v)
{
    //Beállítani a gomb kinézetét olyanra amit a feladat kér. pl:
    if(v == 0) p->setStyleSheet("background-color: white;");
    else if(v ==1) p->setStyleSheet("background-color:blue;");
    else if (v == 2) p->setStyleSheet("background-color:red;");

}

void MintaWidget::changeFields()
{
    for(int i=0; i<_model->n();i++) {
        for(int j=0; j<_model->n();j++) {
            int v = _model->getField(i,j);
            changeButton(_fields[i][j],v);
        }
    }

    //Itt a labelt beállítani hogy mutassa az eltelt időt, ha a feladat kéri.
}

void MintaWidget::generateFields()
{
    for(QVector<QPushButton*> v : _fields) {
        for(QPushButton* p : v) delete p;
    }
    _fields.clear();

    for(int i=0;i<_model->n();i++) {
        QVector<QPushButton*> v;
        for(int j=0;j<_model->n();j++) {
            QPushButton* p = new QPushButton;
            p->setFixedSize(50,50);
            int val = _model->getField(i,j);
            changeButton(p,val);
            v.push_back(p);
            connect(p,SIGNAL(clicked()),this,SLOT(boardButtonPressed()));
            _buttonGrid->addWidget(p,i,j);
        }
        _fields.push_back(v);
    }


}

void MintaWidget::endGame()
{
    QMessageBox msg;
    msg.setWindowTitle("Játék vége!");
    msg.setText("A játék végetért! Az OK gombra kattintva új játékot kezdhetsz!");
    _model->startNewGame(_model->n());
}

void MintaWidget::newGameButtonPressed()
{
    if(_sizeDialog == nullptr) {
        _sizeDialog = new SizeDialog;
        connect(_sizeDialog,SIGNAL(accepted()),this,SLOT(sizeDialogAccepted()));
    }
    _sizeDialog->exec();
    //Ha kell méretbeállítós dialógus.

}

void MintaWidget::sizeDialogAccepted()
{
    _model->startNewGame(_sizeDialog->getSize());
}

void MintaWidget::boardButtonPressed()
{
    QPushButton* p = dynamic_cast<QPushButton*>(sender());
    int ind = _buttonGrid->indexOf(p);
    _model->fieldPressed(ind);



}

