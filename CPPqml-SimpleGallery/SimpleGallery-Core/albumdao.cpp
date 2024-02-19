#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "album.h"
#include "databasemanager.h"

AlbumDao::AlbumDao(QSqlDatabase &database)
    : mDatabase(database)
{}

void AlbumDao::init() const
{
    if (!mDatabase.tables().contains("albums")) {
        QSqlQuery query(mDatabase);
        query.exec("create table albums (id integer primary key autoincrement, name text)");
    }
}

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("insert into albums (name) values (:name");
    query.bindValue(":name", album.name();
    query.exec();
    album.setId(query.lastInsertId().toUInt());
}
