#ifndef MANDELBROTCALCULATOR_H
#define MANDELBROTCALCULATOR_H

#include <QElapsedTimer>
#include <QList>
#include <QObject>
#include <QPointF>
#include <QSize>

#include "JobResult.h"

class Job;

class MandelbrotCalculator : public QObject
{
    Q_OBJECT
public:
    explicit MandelbrotCalculator(QObject *parent = nullptr);
    void init(QSize imageSize);

signals:
    void pictureLinesGenerated(QList<JobResult> jobResults);
    void abortAllJobs();

public slots:
    void generatePicture(QSize areaSize, QPointF moveOffset, double scaleFactor, int iterationMax);
    void process(JobResult jobResult);

private:
    Job *createJob(int pixelPositionY);
    void clearJobs();

    QPointF mMoveOffset;
    double mScaleFactor;
    QSize mAreaSize;
    int mIterationMax;
    int mReceivedJobResults;
    QList<JobResult> mJobResults;
    QElapsedTimer mTimer;
};

#endif // MANDELBROTCALCULATOR_H
