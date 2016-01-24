/*
 * qmqtt_network.h - qmqtt network header
 *
 * Copyright (c) 2013  Ery Lee <ery.lee at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of mqttc nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef QMQTT_NETWORK_INTERFACE_H
#define QMQTT_NETWORK_INTERFACE_H

#include "qmqtt_frame.h"
#include <QObject>
#include <QAbstractSocket>
#include <QString>

namespace QMQTT {

class NetworkInterface : public QObject
{
    Q_OBJECT
public:
    explicit NetworkInterface(QObject* parent = NULL) : QObject(parent) {}
    virtual ~NetworkInterface() {}

    virtual void sendFrame(Frame& frame) = 0;
    virtual bool isConnectedToHost() const = 0;
    virtual bool autoReconnect() const = 0;
    virtual void setAutoReconnect(const bool value) = 0;
    virtual QAbstractSocket::SocketState state() const = 0;

public slots:
    virtual void connectToHost(const QHostAddress& host, const quint16 port) = 0;
    virtual void disconnectFromHost() = 0;

signals:
    void connected();
    void disconnected();
    void received(const QMQTT::Frame& frame);
    void error(QAbstractSocket::SocketError error);
};

} // namespace QMQTT

#endif // QMQTT_NETWORK_INTERFACE_H
