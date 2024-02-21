#include "picturedao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "databasemanager.h"
#include "picture.h"

using namespace std;

PictureDao::PictureDao(QSqlDatabase &database)
    : mDatabase(database)
{}

void PictureDao::init() const
{
    if (!mDatabase.tables().contains("pictures")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("create table pictures") + " (id integer primary kay autoincrement, "
                   + " album_id integer, url text) ");
        DatabaseManager::debugQuery(query);
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture &picture) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("insert into pictures") + " (album_id, url)" + " values ("
                  + ":album_id, :url" + ")");
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", picture.fileUrl());
    query.exec();
    DatabaseManager::debugQuery(query);
    picture.setId(query.lastInsertId().toInt());
    picture.setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("delete from pictures where id=(:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void PictureDao::removePicturesForAlbum(int albumId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("delete from pictures where album_id = (:album_id)");
    query.bindValue("album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);
}

unique_ptr<vector<unique_ptr<Picture>>> PictureDao::picturesForAlbum(int albumId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from pictures where album_id=(:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Picture>>> list(new vector<unique_ptr<Picture>>());
    while (query.next()) {
        unique_ptr<Picture> picture(new Picture());
        picture->setId(query.value("id").toInt());
        picture->setAlbumId(query.value("album_id").toInt());
        picture->setFileUrl(query.value("url").toString());
        list->push_back(move(picture));
    }
    return list;
}
