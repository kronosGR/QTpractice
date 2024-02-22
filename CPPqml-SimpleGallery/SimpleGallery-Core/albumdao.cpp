#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <memory>

#include "album.h"
#include "databasemanager.h"

AlbumDao::AlbumDao(QSqlDatabase &database)
    : mDatabase(database)
{}

void AlbumDao::init() const
{
    if (!mDatabase.tables().contains("albums")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("insert into albums (name) values (:name");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toUInt());
}

void AlbumDao::updateAlbum(const Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("update albums set name =(:name) where id=(:id)");
    query.bindValue(":name", album.name());
    query.bindValue(":id", album.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AlbumDao::removeAlbum(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("delere from albums where id =(:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Album>>> AlbumDao::albums() const
{
    QSqlQuery query("select * from albums", mDatabase);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> list(
        new std::vector<std::unique_ptr<Album>>());
    while (query.next()) {
        std::unique_ptr<Album> album(new Album());
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list->push_back(std::move(album));
    }
    return list;
}
