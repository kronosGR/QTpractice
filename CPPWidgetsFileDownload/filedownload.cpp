#include "filedownload.h"
#include "./ui_filedownload.h"

FileDownload::FileDownload(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileDownload)
{
    ui->setupUi(this);

    m_network_manager = new QNetworkAccessManager(this);

    connect(m_network_manager,
            &QNetworkAccessManager::finished,
            this,
            &FileDownload::downloadFinished);
}

FileDownload::~FileDownload()
{
    delete ui;
}

void FileDownload::downloadFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        const QString error = reply->errorString();
        ui->plainTextEdit->setPlainText(error);
        return;
    }
    const QByteArray content = reply->readAll();
    ui->plainTextEdit->setPlainText(QString::fromUtf8(content));
    reply->deleteLater();
}

void FileDownload::on_pushButton_clicked()
{
    QUrl url("https://www.google.com/robots.txt");
    m_network_manager->get(QNetworkRequest(url));
}
