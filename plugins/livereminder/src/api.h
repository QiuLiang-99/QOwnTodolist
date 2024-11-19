#include <QUrl>
#include <qsettings.h>

namespace LR {
  namespace api {
    const QUrl get_huyaID_api =
        QUrl("https://www.huya.com/udb_web/checkLogin.php", QUrl::StrictMode);
    const QUrl get_biliID_api = QUrl(
        "https://api.bilibili.com/x/relation/tag/special", QUrl::StrictMode);
  } // namespace api
} // namespace LR
QSettings settings("livereminder", "livereminder");

// const huyaurl = "https://fw.huya.com/dispatch?do=subscribeList&uid=";