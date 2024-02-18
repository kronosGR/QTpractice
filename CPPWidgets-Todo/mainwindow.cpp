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
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::updateStatus()
{
    int completedCount = 0;
    for (auto t : mTasks) {
        if (t->isCompleted())
            completedCount++;
    }

    int todoCount = mTasks.size() - completedCount;
    ui->statusLabel->setText(
        QString("Status: %1 todo / %2 completed").arg(todoCount).arg(completedCount));
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
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->taskLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->taskLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    updateStatus();
}
