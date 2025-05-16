#ifndef LR_API_H
#define LR_API_H

#include <QUrl>

#include <QDebug>
namespace LR {
  namespace api {
    namespace get_stream_info {} // namespace get_stream_info
    namespace huya {
      const QUrl get_huyaID_api =
          QUrl("https://www.huya.com/udb_web/checkLogin.php", QUrl::StrictMode);
      const QUrl get_huya_user_subscribe_status =
          QUrl("https://fw.huya.com/dispatch", QUrl::StrictMode);
    } // namespace huya
    namespace bili {
      const QUrl get_biliID_api = QUrl(
          "https://api.bilibili.com/x/relation/tag/special", QUrl::StrictMode);
    } // namespace bili
  } // namespace api
} // namespace LR

#endif // LR_API_H
