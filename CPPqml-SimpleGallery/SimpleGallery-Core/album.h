#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "SimpleGallery-Core_global.h"

class SIMPLEGALLERYCORE_EXPORT Album
{
public:
    explicit Album(const QString &name = "");

    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString &name);

private:
    int mId;
    QString mName;
};

#endif // ALBUM_H
