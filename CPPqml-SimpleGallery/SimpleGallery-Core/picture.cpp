#include "picture.h"

Picture::Picture(const QString &filePath)
    : Picture(QUrl::fromLocalFile(filePath))
{}

Picture::Picture(const QUrl &fileUrl)
    : mId(-1)
    , mAlbumId(-1)
    , mFileUrl(fileUrl)
{}

int Picture::id() const
{
    return mId;
}

void Picture::setId(int newId)
{
    mId = newId;
}

int Picture::albumId() const
{
    return mAlbumId;
}

void Picture::setAlbumId(int newAlbumId)
{
    mAlbumId = newAlbumId;
}

QUrl Picture::fileUrl() const
{
    return mFileUrl;
}

void Picture::setFileUrl(const QUrl &newFileUrl)
{
    mFileUrl = newFileUrl;
}
