#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCpuWidget(this)
{
    ui->setupUi(this);

    SysInfo::instance().init();
    ui->verticalLayout->addWidget(&mCpuWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
