#ifndef PICTURE_H
#define PICTURE_H

#include <QString>
#include <QUrl>

#include "SimpleGallery-Core_global.h"

class SIMPLEGALLERYCORE_EXPORT Picture
{
public:
    Picture(const QString &filePath = "");
    Picture(const QUrl &fileUrl);
};

#endif // PICTURE_H
