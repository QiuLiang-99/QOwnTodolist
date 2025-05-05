#ifndef STREAMFETCHER_H
#define STREAMFETCHER_H

#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QMap>
#include <QVariantMap>
struct StreamData {
    QString anchorName;
    bool    isLive = false;
    QString title;
    QString m3u8Url;
    QString flvUrl;
    QString recordUrl;
};



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

class LiveClient : public QObject {
    Q_OBJECT
public:
    explicit LiveClient(const QMap<QString, QString>& proxy = {}, const QByteArray& cookies = {}, QObject* parent = nullptr);
    StreamData getStreamInfo(const QString& liveUrl, const QString& quality);

private:
    QMap<QString, QString> proxySettings;
    QByteArray             cookieData;
    std::unique_ptr<StreamFetcher> fetcher;
};

#endif // STREAMFETCHER_H