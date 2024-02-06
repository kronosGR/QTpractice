#include "tictactoewidget.h"

#include <QGridLayout>

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *gridLayout = new QGridLayout(this);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = new QPushButton(" ");
            gridLayout->addWidget(button, row, col);
            m_board.append(button);
        }
    }
}
