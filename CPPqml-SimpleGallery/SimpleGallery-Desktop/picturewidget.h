#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QItemSelection>
#include <QWidget>

namespace Ui {
class PictureWidget;
}

class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class PictureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PictureWidget(QWidget *parent = nullptr);
    ~PictureWidget();

    void setModel(ThumbnailProxyModel *model);
    void setSelectionModel(QItemSelectionModel *selectionModel);

signals:
    void backToGallery();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void deletePicture();
    void loadPicture(const QItemSelection &selected);

private:
    Ui::PictureWidget *ui;

    void updatePixturePixmap();

    ThumbnailProxyModel *mModel;
    QItemSelectionModel *mSelectionModel;
    QPixmap mPixmap;
};

#endif // PICTUREWIDGET_H
