#ifndef JOB_H
#define JOB_H

#include <QAtomicInteger>
#include <QObject>
#include <QPointF>
#include <QRunnable>
#include <QSize>

#include "JobResult.h"

class Job : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Job(QObject *parent = nullptr);

signals:
    void jobCompleted(JobResult JobResult);

public slots:
    void abort();

public:
    void run() override;

    void setPixelPositionY(int newPixelPositionY);

    void setMoveOffset(QPointF newMoveOffset);

    void setScaleFactor(double newScaleFactor);

    void setAreaSize(const QSize &newAreaSize);

    void setIterationMax(int newIterationMax);

private:
    QAtomicInteger<bool> mAbort;
    int mPixelPositionY;
    QPointF mMoveOffset;
    double mScaleFactor;
    QSize mAreaSize;
    int mIterationMax;
};

#endif // JOB_H
