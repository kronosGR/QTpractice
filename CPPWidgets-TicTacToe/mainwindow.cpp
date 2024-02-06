#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "tictactoewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->startNewGame, &QPushButton::clicked, this, &MainWindow::startNewGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    ui->player1Name->setText(tr("Kronos"));
    ui->player2Name->setText(tr("Zeus"));
}
