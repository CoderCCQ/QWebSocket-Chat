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
#include "echoclient.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

//! [constructor]
EchoClient::EchoClient(const QUrl &url, bool debug, QString clientName, QObject *parent) :
    QObject(parent),
    m_url(url),
    name(clientName),
    m_debug(debug)
{
    if (m_debug)
        qDebug() << "WebSocket server:" << url;
    connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
    m_webSocket.open(QUrl(url));
}

void EchoClient::sendTextMessage(QString message)
{
    QJsonObject json;
    json["textMessage"] = QJsonArray() << name << message;
    QJsonDocument doc(json);
    m_webSocket.sendBinaryMessage(doc.toJson());
}

void EchoClient::requestChatHistory()
{
    QJsonObject json;
    json["getHistory"] = QJsonArray() << name;
    QJsonDocument doc(json);
    m_webSocket.sendBinaryMessage(doc.toJson());
}

void EchoClient::requestCurrentUsers()
{
    QJsonObject json;
    json["getCurrentUsers"] = QJsonArray() << name;
    QJsonDocument doc(json);
    m_webSocket.sendBinaryMessage(doc.toJson());
}
//! [constructor]

//! [onConnected]
void EchoClient::onConnected()
{
    if (m_debug)
        qDebug() << "WebSocket connected";

    QJsonObject json;
    json["loginIn"] = QJsonArray() << name;
    QJsonDocument doc(json);
    m_webSocket.sendBinaryMessage(doc.toJson());

    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &EchoClient::onTextMessageReceived);
    connect(&m_webSocket, &QWebSocket::binaryMessageReceived,
            this, &EchoClient::onBinaryMessageReceived);
    /*
    connect(&m_webSocket, &QWebSocket::disconnected,
            this, &EchoClient::socketDisconnected);*/
}
//! [onConnected]

//! [onTextMessageReceived]
void EchoClient::onTextMessageReceived(QString message)
{
    if (m_debug)
        qDebug() << "Message received:" << message;

    newTextMessage(message);

    //m_webSocket.close();
}

void EchoClient::onBinaryMessageReceived(QByteArray message)
{
    QJsonObject json = QJsonDocument::fromJson(message).object();
    qDebug() << json;
    if (json.contains("currentUsers"))
    {
        QList<QString> list;
        foreach (auto k, json["currentUsers"].toArray()) {
            list.push_back(k.toString());
        }
        gotCurrentUsers(list);
    }
    else if (json.contains("history"))
    {
        QList<QString> list;
        foreach (auto k, json["history"].toArray()) {
            list.push_back(k.toString());
        }
        gotHistory(list);
    }
}

void EchoClient::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        pClient->deleteLater();
    }
}
//! [onTextMessageReceived]