#ifndef LIVESTATUSFETCHER_H
#define LIVESTATUSFETCHER_H

#include <QMap>
#include <QObject>
#include <QScopedPointer>

#include "streamdata.h"
#include "streamfetcher.h"

/**
 * @brief 直播状态获取器，负责获取直播间的状态信息
 * 
 * 根据不同的平台需要设置不同的fethcer
 */
class LiveStatusFetcher : public QObject {
    Q_OBJECT

  public:
    explicit LiveStatusFetcher(const QMap<QString, QString>& proxy   = {},
                               const QByteArray&             cookies = {},
                               QObject*                      parent  = nullptr);

    /**
     * @brief 获取直播间的流信息
     * 
     * 此方法通过提供的直播间 URL 和清晰度参数，获取对应的直播流信息。
     * 
     * @param liveUrl 直播间的 URL 地址
     * @param quality 期望的直播流清晰度（如 "高清"、"标清" 等）
     * @return StreamData 包含直播间的详细信息，包括主播名称、标题、直播状态及流媒体地址
     */
    StreamData getStreamInfo(const QString& liveUrl, const QString& quality);

  private:
    QMap<QString, QString>         proxySettings;
    QByteArray                     cookieData;
    QScopedPointer<StreamFetcher> fetcher;
};

#endif // LIVESTATUSFETCHER_H