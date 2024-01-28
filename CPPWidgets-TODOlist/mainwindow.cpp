#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->listWidget);
    ui->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    create();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered() {}

void MainWindow::on_actionSave_triggered() {}

void MainWindow::on_actionOpen_triggered() {}

void MainWindow::on_actionSave_As_triggered() {}

void MainWindow::on_actionExit_triggered() {}

void MainWindow::on_actionAdd_triggered() {}

void MainWindow::on_actionRemove_triggered() {}

void MainWindow::on_actionClear_triggered() {}

void MainWindow::on_actionSelect_All_triggered() {}

void MainWindow::on_actionSelect_None_triggered() {}

void MainWindow::on_actionChecked_triggered() {}

void MainWindow::on_actionUnchecked_triggered() {}

void MainWindow::on_actionPartially_triggered() {}

void MainWindow::create() {}
// QTC_TEMP
void MainWindow::open(QString path) {}
// QTC_TEMP
void MainWindow::save(QString path) {}
// QTC_TEMP
void MainWindow::checkSave() {}
// QTC_TEMP
void MainWindow::createItem(Qt::CheckState state, QString name) {}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}
