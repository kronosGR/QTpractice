#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QModelIndex>
#include <QWidget>

namespace Ui {
class AlbumWidget;
}

class AlbumModel;
class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class AlbumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumWidget(QWidget *parent = nullptr);
    ~AlbumWidget();

    void setAlbumModel(AlbumModel *albumModel);
    void setAlbumSelectionModel(QItemSelectionModel *albumSelectionModel);
    void setPictureModel(ThumbnailProxyModel *pictureModel);
    void setPictureSelectionModel(QItemSelectionModel *selectionModel);

signals:
    void pictureActivated(const QModelIndex &index);

private slots:
    void deleteAlbum();
    void editAlbum();
    void addPictures();

private:
    Ui::AlbumWidget *ui;

    clearUi();
    void loadAlbum(const QModelIndex &albumIndex);

    AlbumModel *mAlbumModel;
    QItemSelectionModel *mAlbumSelectionModel;
    ThumbnailProxyModel *mPictureModel;
    QItemSelectionModel *mPictureSelectionModel;
};

#endif // ALBUMWIDGET_H
