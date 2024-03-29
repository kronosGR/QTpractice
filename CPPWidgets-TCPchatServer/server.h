#ifndef SERVER_H
#define SERVER_H

#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    int count();
    void close();

    QString message() const;
    void setMessage(const QString &newMessage);

signals:
    void changed();

public slots:
    void disconnected();
    void readyRead();

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;

private:
    QString m_message;
    QList<QTcpSocket *> m_list;
};

#endif // SERVER_H
