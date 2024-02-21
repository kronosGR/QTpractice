#include "albumwidget.h"
#include "ui_albumwidget.h"

AlbumWidget::AlbumWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AlbumWidget)
{
    ui->setupUi(this);
}

AlbumWidget::~AlbumWidget()
{
    delete ui;
}
