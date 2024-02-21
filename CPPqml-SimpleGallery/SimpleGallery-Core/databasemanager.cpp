#include "databasemanager.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete mDatabase;
}

void DatabaseManager::debugQuery(const QSqlQuery &query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK." << query.lastQuery();
    } else {
        qWarning() << "Query error:" << query.lastError().text();
        qWarning() << "Query text:" << query.lastQuery();
    }
}

DatabaseManager::DatabaseManager(const QString &path)
    : mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
    , albumDao(*mDatabase)
    , pictureDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.init();
}
