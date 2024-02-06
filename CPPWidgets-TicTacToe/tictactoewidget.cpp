#include "tictactoewidget.h"

#include <QDebug>
#include <QGridLayout>
#include <QSignalMapper>

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);

    m_currentPlayer = Player::Invalid;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton *button = new QPushButton(" ");
            button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            gridLayout->addWidget(button, row, col);
            m_board.append(button);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            mapper->setMapping(button, m_board.count() - 1);
        }
    }

    connect(mapper, SIGNAL(mappedInt(int)), this, SLOT(handleButtonClick(int)));
}

TicTacToeWidget::Player TicTacToeWidget::currentPlayer() const
{
    return m_currentPlayer;
}

void TicTacToeWidget::setCurrentPlayer(Player newCurrentPlayer)
{
    if (m_currentPlayer == newCurrentPlayer) {
        return;
    }
    m_currentPlayer = newCurrentPlayer;
    emit currentPlayerChanged(newCurrentPlayer);
}

void TicTacToeWidget::initNewGame()
{
    for (QPushButton *button : m_board) {
        button->setText(" ");
    }
    setCurrentPlayer(Player::Player1);
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition() {}

void TicTacToeWidget::handleButtonClick(int index)
{
    if (m_currentPlayer == Player::Invalid) {
        return;
    }

    if (index < 0 || index >= m_board.size()) {
        return;
    }

    QPushButton *button = m_board[index];
    if (button->text() != " ")
        return;
    button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
    TicTacToeWidget::Player winner = checkWinCondition();
    if (winner == Player::Invalid) {
        setCurrentPlayer(m_currentPlayer == Player::Player1 ? Player::Player2 : Player::Player1);
        return;
    } else {
        emit GameOver(winner);
    }
}
