#include "sizedialog.h"

SizeDialog::SizeDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Új játék");
    _comboBox = new QComboBox;
    _comboBox->addItem("3x3");
    _comboBox->addItem("5x5");
    _comboBox->addItem("7x7");
    _label = new QLabel("Tábla mérete: ");
    _hBox = new QHBoxLayout;
    _hBox->addWidget(_label);
    _hBox->addWidget(_comboBox);

    _vBox = new QVBoxLayout;
    _hBox2 = new QHBoxLayout;
    _acceptButton = new QPushButton ("Oké");
    _rejectButton = new QPushButton ("Mégse");
    _hBox2->addWidget(_acceptButton);
    _hBox2->addWidget(_rejectButton);
    _vBox->addLayout(_hBox);
    _vBox->addLayout(_hBox2);
    setLayout(_vBox);
    connect(_acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(_rejectButton, SIGNAL(clicked()), this, SLOT(reject()));


}


int SizeDialog :: getSize() {
    QString s = "";
    s += _comboBox->currentText()[0]; //Csak akkor működik ha a legnagyobb méret is kisebb mint 10x10
    return s.toInt();
}






