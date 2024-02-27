#include "job.h"

Job::Job(QObject *parent)
    : QObject{parent}
    , mAbort(false)
    , mPixelPositionY(0)
    , mMoveOffset(0.0, 0.0)
    , mScaleFactor(0.0)
    , mAreaSize(0, 0)
    , mIterationMax(1)
{}

void Job::abort()
{
    mAbort.storeRelaxed(true);
}

void Job::run()
{
    JobResult jobResult(mAreaSize.width());
    jobResult.areaSize = mAreaSize;
    jobResult.pixelPositionY = mPixelPositionY;
    jobResult.moveOffset = mMoveOffset;
    jobResult.scaleFactor = mScaleFactor;

    double imageHalfWidth = mAreaSize.width() / 2.0;
    double imageHalfHeight = mAreaSize.height() / 2.0;
    for (int imageX = 0; imageX < mAreaSize.width(); ++imageX) {
        if (mAbort.loadRelaxed()) {
            return;
        }
        int iteration = 0;

        double x0 = (imageX - imageHalfWidth) * mScaleFactor + mMoveOffset.x();
        double y0 = (mPixelPositionY - imageHalfHeight) * mScaleFactor - mMoveOffset.y();
        double x = 0.0;
        double y = 0.0;
        do {
            double nextX = (x * x) - (y * y) + x0;
            y = 2.0 * x * y + y0;
            x = nextX;
            iteration++;

        } while (iteration < mIterationMax && (x * x) + (y * y) < 4.0);

        jobResult.values[imageX] = iteration;
    }

    emit jobCompleted(jobResult);
}

void Job::setPixelPositionY(int newPixelPositionY)
{
    mPixelPositionY = newPixelPositionY;
}

void Job::setMoveOffset(QPointF newMoveOffset)
{
    mMoveOffset = newMoveOffset;
}

void Job::setScaleFactor(double newScaleFactor)
{
    mScaleFactor = newScaleFactor;
}

void Job::setAreaSize(const QSize &newAreaSize)
{
    mAreaSize = newAreaSize;
}

void Job::setIterationMax(int newIterationMax)
{
    mIterationMax = newIterationMax;
}
