#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{}

int Server::count()
{
    return m_list.count();
}

void Server::close()
{
    foreach (QTcpSocket *socket, m_list) {
        socket->close();
    }

    qDeleteAll(m_list);
    m_list.clear();

    emit changed();
    QTcpServer::close();
}

void Server::disconnect() {}

void Server::readyRead() {}

void Server::incomingConnection(qintptr handle) {}

QString Server::message() const
{
    return m_message;
}

void Server::setMessage(const QString &newMessage)
{
    m_message = newMessage;
}
