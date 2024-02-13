#ifndef FILEDOWNLOAD_H
#define FILEDOWNLOAD_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class FileDownload;
}
QT_END_NAMESPACE

class FileDownload : public QWidget
{
    Q_OBJECT

public:
    FileDownload(QWidget *parent = nullptr);
    ~FileDownload();

private:
    Ui::FileDownload *ui;

    QNetworkAccessManager *m_network_manager;

private slots:
    void downloadFinished(QNetworkReply *reply);
    void on_pushButton_clicked();
};
#endif // FILEDOWNLOAD_H
