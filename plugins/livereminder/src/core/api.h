#ifndef LR_API_H
#define LR_API_H

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <qlogging.h>

namespace LR {
  namespace api {
    namespace huya {
      const QUrl get_huyaID_api =
          QUrl("https://www.huya.com/udb_web/checkLogin.php", QUrl::StrictMode);
      const QUrl get_huya_user_subscribe_status =
          QUrl("https://fw.huya.com/dispatch", QUrl::StrictMode);
    } // namespace huya
    const QUrl get_biliID_api = QUrl(
        "https://api.bilibili.com/x/relation/tag/special", QUrl::StrictMode);
  } // namespace api
} // namespace LR

void callApi() {
  // 创建 QNetworkAccessManager
  QNetworkAccessManager* manager = new QNetworkAccessManager();

  // 构造 URL 和参数
  QUrl      url = LR::api::huya::get_huya_user_subscribe_status;
  QUrlQuery query;
  query.addQueryItem("do", "subscribeList");
  query.addQueryItem("uid", "1426804866"); // 添加参数 uid=1426804866
  url.setQuery(query);

  // 创建请求
  QNetworkRequest request(url);

  // 设置 Cookie
  QByteArray cookie = "todo"; // 替换为实际的 Cookie 值

  request.setRawHeader("Cookie", cookie);

  // 发送 GET 请求
  QNetworkReply* reply = manager->get(request);

  // 处理响应
  QObject::connect(reply, &QNetworkReply::finished, [reply]() {
    if (reply->error() == QNetworkReply::NoError) {
      // 请求成功，读取返回的数据
      QByteArray responseData = reply->readAll();

      // 将 QByteArray 转换为 JSON
      QJsonDocument jsonDoc   = QJsonDocument::fromJson(responseData);
      if (!jsonDoc.isNull()) {
        if (jsonDoc.isObject()) {
          QJsonObject jsonObj = jsonDoc.object();
          qDebug() << "Parsed JSON Object:" << jsonObj;
        } else if (jsonDoc.isArray()) {
          QJsonArray jsonArray = jsonDoc.array();
          qDebug() << "Parsed JSON Array:" << jsonArray;
        }
      } else {
        qDebug() << "Failed to parse JSON.";
      }
    } else {
      // 请求失败，打印错误信息
      qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
  });

  // 清理 QNetworkAccessManager
  QObject::connect(manager, &QNetworkAccessManager::finished, manager,
                   &QNetworkAccessManager::deleteLater);
}
#endif // LR_API_H
