#include "livestatusfetcher.h"

LiveStatusFetcher::LiveStatusFetcher(const QMap<QString, QString>& proxy,
                                     const QByteArray&             cookies,
                                     QObject*                      parent) :
    QObject(parent), proxySettings(proxy), cookieData(cookies) {}

StreamData LiveStatusFetcher::getStreamInfo(const QString& liveUrl,
                                            const QString& quality) {
  if (!fetcher) { fetcher.reset(new StreamFetcher(this)); }
  auto jsonData = fetcher->fetchAppStreamData(liveUrl, true);
  return fetcher->fetchStreamUrl(jsonData, quality);
}
