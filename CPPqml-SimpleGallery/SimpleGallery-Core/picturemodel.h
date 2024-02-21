#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <memory>
#include <vector>

#include <QAbstractListModel>

#include "SimpleGallery-Core_global.h"
#include "picture.h"

class Album;
class DatabaseManager;
class AlbumModel;

class SIMPLEGALLERYCORE_EXPORT PictureModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles { UrlRole = Qt::UserRole + 1, FilePathRole };

    PictureModel(const AlbumModel &albumModel, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QHash<int, QByteArray> roleNames() const override;

    QModelIndex addPicture(const Picture &picture);
    void setAlbumId(int albumId);
    void clearAlbum();

public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures(int albumId);
    bool isIndexValid(const QModelIndex &index) const;

    DatabaseManager &mDb;
    int mAlbumId;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> mPictures;
};

#endif // PICTUREMODEL_H
