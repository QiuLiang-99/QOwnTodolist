#ifndef STREAMFETCHER_H
#define STREAMFETCHER_H

#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QMap>
#include <QVariantMap>

#include "streamdata.h"

/**
 * @brief 虎牙直播间数据获取器
 * 
 */
class StreamFetcher : public QObject {
    Q_OBJECT
public:
    explicit StreamFetcher(QObject* parent = nullptr);
    QVariantMap fetchAppStreamData(const QString& url, bool processData = true);
    StreamData fetchStreamUrl(const QVariantMap& jsonData, const QString& quality);

private:
    QNetworkAccessManager* manager;
    QByteArray syncGet(const QUrl& url, const QMap<QString, QString>& headers);
    QMap<QString, QString> mobileHeaders() const;
    QMap<QString, QString> pcHeaders() const;
};



#endif // STREAMFETCHER_H