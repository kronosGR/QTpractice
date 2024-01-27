#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    qDeleteAll(m_list);
    delete ui;
}

void Dialog::on_buttonBox_accepted() {}
// QTC_TEMP
void Dialog::clear() {}

void Dialog::add() {}

void Dialog::subtract() {}

void Dialog::multiply() {}

void Dialog::divide() {}

void Dialog::number() {}

void Dialog::update() {}

void Dialog::addEquation() {}

void Dialog::init()
{
    int row = 0;
    int col = 2;
    for (int i = 9; i >= 0; i--) {
        QPushButton *btn = new QPushButton(QString::number(i), this);
        connect(btn, &QPushButton::clicked, this, &Dialog::number);

        ui->gridLayout->addWidget(btn, row, col);
        col--;
        if (col < 0) {
            row++;
            col = 2;
            if (row == 3)
                col = 0;
        }
    }
}

Equation *Dialog::getLast() {}

void Dialog::updateValue(QString data) {}

void Dialog::updateAction(Equation::Action value) {}
