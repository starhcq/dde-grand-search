/*
 * Copyright (C) 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     liuzhangjian<liuzhangjian@uniontech.com>
 *
 * Maintainer: liuzhangjian<liuzhangjian@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "filenamesearcher.h"
#include "global/builtinsearch.h"
#include "filenameworker.h"

#include <QDBusInterface>
#include <QDBusReply>

FileNameSearcher::FileNameSearcher(QObject *parent) : Searcher(parent)
{
}

QString FileNameSearcher::name() const
{
    return GRANDSEARCH_CLASS_FILE_DEEPIN;
}

bool FileNameSearcher::isActive() const
{
    QDBusInterface interface("com.deepin.anything",
                             "/com/deepin/anything",
                             "com.deepin.anything",
                             QDBusConnection::systemBus());
    interface.setTimeout(500);
    if (!interface.isValid()) {
        qWarning() << QDBusConnection::systemBus().lastError().message();
        return false;
    }

    // fix bug 90645
    // 如果allPath返回为空，则调用refresh刷新一次
    static bool isAvailable = false;
    if (!isAvailable) {
        QDBusReply<QStringList> reply = interface.call("allPath");
        if (reply.isValid()) {
            auto paths = reply.value();
            if (paths.isEmpty()) {
                QDBusReply<QStringList> re = interface.call("refresh", QByteArray());
                if (re.isValid()) {
                    isAvailable = true;
                    qInfo() << "refresh result:" << re.value();
                } else {
                    qWarning() << "refresh method called failed," << re.error().message();
                }
            }
        } else {
            qWarning() << "allPath method called failed," << reply.error().message();
        }
    }

    return true;
}

bool FileNameSearcher::activate()
{
    return false;
}

ProxyWorker *FileNameSearcher::createWorker() const
{
    auto worker = new FileNameWorker(name(), supportParallelSearch());
    return worker;
}

bool FileNameSearcher::action(const QString &action, const QString &item)
{
    Q_UNUSED(item)
    qWarning() << "no such action:" << action << ".";
    return false;
}

bool FileNameSearcher::supportParallelSearch() const
{
    static QStringList methodNameList;
    if (!methodNameList.isEmpty())
        return methodNameList.contains("parallelsearch");

    QDBusInterface introspectable("com.deepin.anything",
                                  "/com/deepin/anything",
                                  "org.freedesktop.DBus.Introspectable",
                                  QDBusConnection::systemBus());
    QDBusReply<QString> reply = introspectable.call("Introspect");
    if (!reply.isValid())
        return false;

    QXmlStreamReader xmlReader;
    xmlReader.addData(reply.value());
    xmlReader.readNext();
    while (!xmlReader.atEnd()) {
        if (xmlReader.isStartElement() && xmlReader.name() == "method") {
            methodNameList << xmlReader.attributes().value("name").toString();
            xmlReader.skipCurrentElement();
        } else {
            xmlReader.readNext();
        }
    }

    return methodNameList.contains("parallelsearch");
}
