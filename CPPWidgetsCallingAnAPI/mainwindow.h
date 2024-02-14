#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QNetworkAccessManager;
class QNetworkReply;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendRequest();
    void requestFinished(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *m_network_manager;
    QNetworkReply *m_reply;
};
#endif // MAINWINDOW_H
