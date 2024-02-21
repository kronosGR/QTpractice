#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "albumdao.h"
#include "picturedao.h"

class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager &instance();
    ~DatabaseManager();

    static void debugQuery(const QSqlQuery &query);

    const AlbumDao albumDao;
    const PictureDao pictureDao;

protected:
    DatabaseManager(const QString &path = DATABASE_FILENAME);
    DatabaseManager &operator=(const DatabaseManager &rhs);

private:
    QSqlDatabase *mDatabase;
};

#endif // DATABASEMANAGER_H
