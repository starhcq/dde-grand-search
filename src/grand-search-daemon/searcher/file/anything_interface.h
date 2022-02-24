/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -m -p anything_interface /usr/share/dbus-1/interfaces/com.deepin.anything.xml
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef ANYTHING_INTERFACE_H
#define ANYTHING_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.anything
 */
class ComDeepinAnythingInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.anything"; }

public:
    ComDeepinAnythingInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~ComDeepinAnythingInterface();

    Q_PROPERTY(bool autoIndexExternal READ autoIndexExternal WRITE setAutoIndexExternal)
    inline bool autoIndexExternal() const
    { return qvariant_cast< bool >(property("autoIndexExternal")); }
    inline void setAutoIndexExternal(bool value)
    { setProperty("autoIndexExternal", QVariant::fromValue(value)); }

    Q_PROPERTY(bool autoIndexInternal READ autoIndexInternal WRITE setAutoIndexInternal)
    inline bool autoIndexInternal() const
    { return qvariant_cast< bool >(property("autoIndexInternal")); }
    inline void setAutoIndexInternal(bool value)
    { setProperty("autoIndexInternal", QVariant::fromValue(value)); }

    Q_PROPERTY(int logLevel READ logLevel WRITE setLogLevel)
    inline int logLevel() const
    { return qvariant_cast< int >(property("logLevel")); }
    inline void setLogLevel(int value)
    { setProperty("logLevel", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<bool> addPath(const QString &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("addPath"), argumentList);
    }

    inline QDBusPendingReply<QStringList> allPath()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("allPath"), argumentList);
    }

    inline QDBusPendingReply<QString> cacheDir()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("cacheDir"), argumentList);
    }

    inline QDBusPendingReply<bool> cancelBuild(const QString &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("cancelBuild"), argumentList);
    }

    inline QDBusPendingReply<bool> hasLFT(const QString &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("hasLFT"), argumentList);
    }

    inline QDBusPendingReply<QStringList> hasLFTSubdirectories(const QString &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("hasLFTSubdirectories"), argumentList);
    }

    inline QDBusPendingReply<QStringList> insertFileToLFTBuf(const QByteArray &filePath)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(filePath);
        return asyncCallWithArgumentList(QStringLiteral("insertFileToLFTBuf"), argumentList);
    }

    inline QDBusPendingReply<bool> lftBuinding(const QString &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("lftBuinding"), argumentList);
    }

    inline QDBusPendingReply<QStringList, uint, uint> parallelsearch(const QString &path, uint startOffset, uint endOffset, const QString &keyword, const QStringList &rules)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path) << QVariant::fromValue(startOffset) << QVariant::fromValue(endOffset) << QVariant::fromValue(keyword) << QVariant::fromValue(rules);
        return asyncCallWithArgumentList(QStringLiteral("parallelsearch"), argumentList);
    }
    inline QDBusReply<QStringList> parallelsearch(const QString &path, uint startOffset, uint endOffset, const QString &keyword, const QStringList &rules, uint &startOffset_, uint &endOffset_)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path) << QVariant::fromValue(startOffset) << QVariant::fromValue(endOffset) << QVariant::fromValue(keyword) << QVariant::fromValue(rules);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("parallelsearch"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            startOffset_ = qdbus_cast<uint>(reply.arguments().at(1));
            endOffset_ = qdbus_cast<uint>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QStringList> parallelsearch(const QString &path, const QString &keyword, const QStringList &rules)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path) << QVariant::fromValue(keyword) << QVariant::fromValue(rules);
        return asyncCallWithArgumentList(QStringLiteral("parallelsearch"), argumentList);
    }

    inline QDBusPendingReply<> quit()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("quit"), argumentList);
    }

    inline QDBusPendingReply<QStringList> refresh(const QByteArray &serialUriFilter)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(serialUriFilter);
        return asyncCallWithArgumentList(QStringLiteral("refresh"), argumentList);
    }

    inline QDBusPendingReply<QStringList> removeFileFromLFTBuf(const QByteArray &filePath)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(filePath);
        return asyncCallWithArgumentList(QStringLiteral("removeFileFromLFTBuf"), argumentList);
    }

    inline QDBusPendingReply<bool> removePath(const QString &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("removePath"), argumentList);
    }

    inline QDBusPendingReply<QStringList> renameFileOfLFTBuf(const QByteArray &fromFilePath, const QByteArray &toFilePath)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(fromFilePath) << QVariant::fromValue(toFilePath);
        return asyncCallWithArgumentList(QStringLiteral("renameFileOfLFTBuf"), argumentList);
    }

    inline QDBusPendingReply<QStringList, uint, uint> search(int maxCount, qlonglong icase, uint startOffset, uint endOffset, const QString &path, const QString &keyword, bool useRegExp)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(maxCount) << QVariant::fromValue(icase) << QVariant::fromValue(startOffset) << QVariant::fromValue(endOffset) << QVariant::fromValue(path) << QVariant::fromValue(keyword) << QVariant::fromValue(useRegExp);
        return asyncCallWithArgumentList(QStringLiteral("search"), argumentList);
    }
    inline QDBusReply<QStringList> search(int maxCount, qlonglong icase, uint startOffset, uint endOffset, const QString &path, const QString &keyword, bool useRegExp, uint &startOffset_, uint &endOffset_)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(maxCount) << QVariant::fromValue(icase) << QVariant::fromValue(startOffset) << QVariant::fromValue(endOffset) << QVariant::fromValue(path) << QVariant::fromValue(keyword) << QVariant::fromValue(useRegExp);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("search"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            startOffset_ = qdbus_cast<uint>(reply.arguments().at(1));
            endOffset_ = qdbus_cast<uint>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QStringList> search(const QString &path, const QString &keyword, bool useRegExp)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path) << QVariant::fromValue(keyword) << QVariant::fromValue(useRegExp);
        return asyncCallWithArgumentList(QStringLiteral("search"), argumentList);
    }

    inline QDBusPendingReply<QByteArray> setCodecNameForLocale(const QByteArray &name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name);
        return asyncCallWithArgumentList(QStringLiteral("setCodecNameForLocale"), argumentList);
    }

    inline QDBusPendingReply<QStringList> sync(const QString &mountPoint)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mountPoint);
        return asyncCallWithArgumentList(QStringLiteral("sync"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void addPathFinished(const QString &path, bool success);
};

namespace com {
  namespace deepin {
    typedef ::ComDeepinAnythingInterface anything;
  }
}
#endif
