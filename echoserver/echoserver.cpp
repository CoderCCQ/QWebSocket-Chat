/****************************************************************************
**
** Copyright (C) 2016 Kurt Pattyn <pattyn.kurt@gmail.com>.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebSockets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "echoserver.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

//! [constructor]
EchoServer::EchoServer(quint16 port, bool debug, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                            QWebSocketServer::NonSecureMode, this)),
    m_debug(debug)
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {
        if (m_debug)
            qDebug() << "Echoserver listening on port LOL" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &EchoServer::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &EchoServer::closed);
    }
}
//! [constructor]

EchoServer::~EchoServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

//! [onNewConnection]
void EchoServer::onNewConnection()
{
    qDebug() << "new connection!";
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    if (!pSocket)
        return;

    connect(pSocket, &QWebSocket::textMessageReceived, this, &EchoServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &EchoServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &EchoServer::socketDisconnected);

    // load all previous messages
    foreach (auto k, log) {
        pSocket->sendTextMessage(k);
    }
    m_clients << pSocket;
}
//! [onNewConnection]

//! [processTextMessage]
void EchoServer::processTextMessage(QString message)
{
    foreach (auto k, m_clients)
    {
        QWebSocket *pClient = qobject_cast<QWebSocket *>(k);
        if (pClient)
        {
            log.push_back(message);
            pClient->sendTextMessage(message);
        }
    }
}
//! [processTextMessage]

//! [processBinaryMessage]
void EchoServer::processBinaryMessage(QByteArray message)
{
    qDebug() << "new Binary Message";

    QJsonObject json = QJsonDocument::fromJson(message).object();
    qDebug() << json;
    if (json.contains("textMessage"))
        textMessage(sender(), json);
    else if (json.contains("loginIn"))
        loginIn(sender(), json);
    else if (json.contains("getCurrentUsers"))
        getCurrentUsers(sender(), json);
    else if (json.contains("getHistory"))
        getHistory(sender(), json);
    else if (json.contains("newRegistration"))
        newRegistration(sender(), json);
}
//! [processBinaryMessage]

//! [socketDisconnected]
void EchoServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        currentUsers.remove(pClient);
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

void EchoServer::textMessage(QObject *sender, const QJsonObject &json)
{
    QString name = json["textMessage"].toArray().at(0).toString();
    QString msg = json["textMessage"].toArray().at(1).toString();
    QString finalMessage = name + ": " + msg;

    log.push_back(finalMessage);
    foreach (auto k, m_clients)
    {
        QWebSocket *pClient = qobject_cast<QWebSocket *>(k);
        if (pClient)
            pClient->sendTextMessage(finalMessage);
    }
}

void EchoServer::loginIn(QObject *sender, const QJsonObject &json)
{
    QString login = json["loginIn"].toArray().at(0).toString();
    QString password = json["loginIn"].toArray().at(1).toString();
    QWebSocket *p = qobject_cast<QWebSocket *>(sender);
    if (p)
        currentUsers[p] = login;
}

void EchoServer::getCurrentUsers(QObject *sender, const QJsonObject &json)
{
    QString name = json["getCurrentUsers"].toArray().at(0).toString();
    // we don't need name right now, but let it be
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender);
    if (pClient)
    {
        QJsonObject json;
        QJsonArray array;
        foreach (auto k, currentUsers) {
            array << k;
        }
        json["currentUsers"] = array;
        QJsonDocument doc(json);
        qDebug() << json;
        pClient->sendBinaryMessage(doc.toJson());
    }
}

void EchoServer::getHistory(QObject *sender, const QJsonObject &json)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender);
    if (pClient)
    {
        QJsonObject json;
        QJsonArray array;
        foreach (auto k, log) {
            array << k;
        }
        json["history"] = array;
        QJsonDocument doc(json);
        qDebug() << json;
        pClient->sendBinaryMessage(doc.toJson());
    }
}

void EchoServer::newRegistration(QObject *sender, const QJsonObject &json)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender);
    if (pClient)
    {
        QJsonObject json;
        QJsonArray array;
        if (true) // if account OK
            array <<
        json["registration"] = array;
    }
}
//! [socketDisconnected]
