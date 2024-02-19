#include "album.h"

Album::Album(const QString &name)
    : mId(-1)
    , mName(name)
{}

QString Album::name() const
{
    return mName;
}

void Album::setName(const QString &newName)
{
    mName = newName;
}

int Album::id() const
{
    return mId;
}

void Album::setId(int newId)
{
    mId = newId;
}
