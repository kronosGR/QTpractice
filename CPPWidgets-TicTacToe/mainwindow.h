#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <TicTacToeWidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setLabelBold(QLabel *label, bool isBold);
private slots:
    void updateNameLabels();
    void handleGameOver(TicTacToeWidget::Player winner);
public slots:
    void startNewGame();
};
#endif // MAINWINDOW_H
