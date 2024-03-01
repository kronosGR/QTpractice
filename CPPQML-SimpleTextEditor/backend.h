#ifndef BACKEND_H
#define BACKEND_H

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTextStream>

class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
public:
    explicit Backend(QObject *parent = nullptr);

    QString path();
    void setPath(QString value);
    QString data();
    void setData(QString value);

signals:
    void pathChanged();
    void dataChanged();

private:
    QString m_path;
};

#endif // BACKEND_H
