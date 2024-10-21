#include <QUrl>
#include <qsettings.h>

namespace LR {
  namespace api {
    const QUrl get_huyaID_api =
        QUrl("https://www.huya.com/udb_web/checkLogin.php", QUrl::StrictMode);
  } // namespace api
} // namespace LR
QSettings settings("livereminder", "livereminder");
