#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <QObject>
#include <memory>
#include <vector>

#include "SimpleGallery-Core_global.h"
#include "album.h"
#include "databasemanager.h"

class SIMPLEGALLERYCORE_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
    };

    AlbumModel(QObject *parent = nullptr);
    QModelIndex addAlbum(const Album &album);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
    bool isIndexValid(const QModelIndex &index) const;

    DatabaseManager &mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> mAlbums;
};

#endif // ALBUMMODEL_H
