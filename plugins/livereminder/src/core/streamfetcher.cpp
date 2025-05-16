#include "StreamFetcher.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>
#include <QDebug>

#include <QObject>
#include <QMap>
#include <QByteArray>

StreamFetcher::StreamFetcher(QObject* parent)
    : QObject(parent), manager(new QNetworkAccessManager(this)) {}

QVariantMap StreamFetcher::fetchAppStreamData(const QString& url, bool processData) {
    QString roomId = QUrl(url).path().split('/', Qt::SkipEmptyParts).last();
    if (roomId.contains(QRegularExpression("[A-Za-z]"))) {//todo 解耦
        QString html = syncGet(QUrl(url), mobileHeaders());
        QRegularExpression re("ProfileRoom\\\":(\\d+),\"sPrivateHost");
        auto match = re.match(html);
        if (match.hasMatch()) {
            roomId = match.captured(1);
        } else {
            qFatal("Please use \"https://www.huya.com/+room_number\" for recording");
        }
    }
    QUrl apiUrl("https://mp.huya.com/cache.php");
    QUrlQuery query;
    query.addQueryItem("m", "Live");
    query.addQueryItem("do", "profileRoom");
    query.addQueryItem("roomid", roomId);
    query.addQueryItem("showSecret", "1");
    apiUrl.setQuery(query);

    QByteArray jsonStr = syncGet(apiUrl, pcHeaders());
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr);
    QJsonObject root = doc.object();
    return processData ? root.toVariantMap() : root.toVariantMap();//bug 为什么是这样设计的
}

StreamData StreamFetcher::fetchStreamUrl(const QVariantMap& jsonData, const QString& quality) {
    StreamData result;
    auto data = jsonData.value("data").toMap();
    result.anchorName = data.value("profileInfo").toMap().value("nick").toString();
    result.isLive = (data.value("realLiveStatus").toString() == "ON");
    if (!result.isLive) { return result;
}
    auto liveData = data.value("liveData").toMap();
    result.title = liveData.value("introduction").toString();

    auto baseList = data.value("stream").toMap().value("baseSteamInfoList").toList();
    QVariantMap selected;
    for (auto& v : baseList) {
        auto m = v.toMap();
        if (m.value("sCdnType").toString() == quality) {
            selected = m; break;
        }
    }
    if (selected.isEmpty() && !baseList.isEmpty()) { selected = baseList.first().toMap();
}

    QString name = selected.value("sStreamName").toString();
    QString flv = selected.value("sFlvUrl").toString() + "/" + name + ".flv?" + selected.value("sFlvAntiCode").toString();
    QString m3u8 = selected.value("sHlsUrl").toString() + "/" + name + ".m3u8?" + selected.value("sHlsAntiCode").toString();
    QString cdn = selected.value("sCdnType").toString();
    if (cdn == "TX" || cdn == "HW") {
        flv.replace("&ctype=tars_mp", "&ctype=huya_webh5");
        flv.replace("&fs=bhct", "&fs=bgct");
        m3u8.replace("&ctype=tars_mp", "&ctype=huya_webh5");
        m3u8.replace("&fs=bhct", "&fs=bgct");
    }
    result.flvUrl = flv;
    result.m3u8Url = m3u8;
    result.recordUrl = flv.isEmpty() ? m3u8 : flv;
    return result;
}

QByteArray StreamFetcher::syncGet(const QUrl& url, const QMap<QString, QString>& headers) {
    QNetworkRequest req(url);
    for (auto it = headers.constBegin(); it != headers.constEnd(); ++it) {
        req.setRawHeader(it.key().toUtf8(), it.value().toUtf8());
}
    QNetworkReply* reply = manager->get(req);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QByteArray d = reply->readAll(); reply->deleteLater();
    return d;
}

QMap<QString, QString> StreamFetcher::mobileHeaders() const {
    return {{"User-Agent","Mozilla/5.0 (iPhone; CPU iPhone OS 10_3 like Mac OS X)..."}};
}

QMap<QString, QString> StreamFetcher::pcHeaders() const {
    return {{"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64)..."}};
}


