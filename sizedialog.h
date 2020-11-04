#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class SizeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SizeDialog(QWidget *parent = nullptr);
    int getSize();

signals:

private:
    QComboBox* _comboBox;
    QLabel* _label;
    QHBoxLayout* _hBox;
    QVBoxLayout* _vBox;
    QHBoxLayout* _hBox2;
    QPushButton* _acceptButton;
    QPushButton* _rejectButton;
    int _size;

};

#endif // SIZEDIALOG_H
