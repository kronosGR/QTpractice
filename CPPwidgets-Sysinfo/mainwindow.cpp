#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCpuWidget(this)
    , mMemoryWidget(this)
{
    ui->setupUi(this);

    SysInfo::instance().init();
    ui->verticalLayout->addWidget(&mCpuWidget);
    ui->verticalLayout->addWidget(&mMemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
