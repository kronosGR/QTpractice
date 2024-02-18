#include "mainwindow.h"
#include <QInputDialog>
#include <QLineEdit>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTasks()
{
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         "Add task",
                                         "Task name",
                                         QLineEdit::Normal,
                                         "Untitled task",
                                         &ok);

    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        mTasks.append(task);
        ui->taskLayout->addWidget(task);
    }
}
