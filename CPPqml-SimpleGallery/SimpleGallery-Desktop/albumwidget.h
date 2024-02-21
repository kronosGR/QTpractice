#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QWidget>

namespace Ui {
class AlbumWidget;
}

class AlbumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumWidget(QWidget *parent = nullptr);
    ~AlbumWidget();

private:
    Ui::AlbumWidget *ui;
};

#endif // ALBUMWIDGET_H
