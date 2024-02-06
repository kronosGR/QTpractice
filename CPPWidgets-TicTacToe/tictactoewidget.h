#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QPushButton>
#include <QWidget>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);

    enum Player { Invalid, Player1, Player2, Draw };
    Q_ENUM(Player)

    Player currentPlayer() const;
    void setCurrentPlayer(Player newCurrentPlayer);
    void initNewGame();

signals:
    void currentPlayerChanged(Player);
    void GameOver(Player);

private:
    QVector<QPushButton *> m_board;

    Player m_currentPlayer;

    Player checkWinCondition();
private slots:
    void handleButtonClick(int index);
};

#endif // TICTACTOEWIDGET_H
