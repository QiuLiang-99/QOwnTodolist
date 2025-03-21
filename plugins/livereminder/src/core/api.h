#include <QUrl>
#include <qsettings.h>

namespace LR {
  namespace api {
    namespace huya {
      const QUrl get_huyaID_api =
          QUrl("https://www.huya.com/udb_web/checkLogin.php", QUrl::StrictMode);
      const QUrl get_huya_user_subscribe_status =
          QUrl("https://fw.huya.com/dispatch?do=subscribeList&uid=",
               QUrl::StrictMode);
    } // namespace huya
    const QUrl get_biliID_api = QUrl(
        "https://api.bilibili.com/x/relation/tag/special", QUrl::StrictMode);
  } // namespace api
} // namespace LR

struct HuyaUserInfo {
    /**
     * @uid 用户ID
     */
    int uid; // 294636272

    /**
     * @yyid YY号
     */
    int yyid; // 229813522

    /**
     * @nick 主播名称
     */
    QString nick; // "狂鸟丶楚河-90327"

    /**
     * @privateHost 房间地址(一般是房号 或者 靓号)
     */
    QString privateHost; // "chuhe"

    /**
     * @avatar180 头像URL
     */
    QString
        avatar180; // "https://huyaimg.msstatic.com/avatar/1086/bf/fd6f69d69c0015eaface1f6024869e_180_135.jpg?1619540458"

    /**
     * @activityId 活动ID
     */
    int activityId; // 0

    /**
     * @activityCount 活动计数
     */
    int activityCount; // 9766087

    /**
     * @channel 频道ID
     */
    int channel; // 294636272

    /**
     * @subChannel 子频道ID
     */
    int subChannel; // 294636272

    /**
     * @totalCount 总计数
     */
    int totalCount; // 6784889

    /**
     * @isLive 开播状态
     */
    bool isLive; // true

    /**
     * @gameId 游戏ID
     */
    int gameId; // 1964

    /**
     * @gameName 游戏名称
     */
    QString gameName; // "主机游戏"

    /**
     * @screenshot 截图URL
     */
    QString
        screenshot; // "http://live-cover.msstatic.com/huyalive/294636272-294636272-1265453152455360512-589396000-10057-A-0-1-imgplus/20250123181548.jpg"

    /**
     * @intro 房间名称
     */
    QString intro; // "新主播，第一天直播，很紧张！！！"

    /**
     * @startTime 开播时间
     */
    qint64 startTime; // 1737608737

    /**
     * @profileRoom 房间房号
     */
    int profileRoom; // 998

    /**
     * @iRelation 关系状态
     */
    int iRelation; // 1
};
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

// 从 JSON 数据中提取直播信息并返回 HuyaUserInfo 结构体
HuyaUserInfo parseHuyaUserInfo(const QByteArray& jsonData) {
  QJsonDocument jsonDoc     = QJsonDocument::fromJson(jsonData);
  QJsonObject   jsonObj     = jsonDoc.object();
  QJsonObject   resultObj   = jsonObj["result"].toObject();
  QJsonArray    listArray   = resultObj["list"].toArray();
  QJsonObject   userInfoObj = listArray[0].toObject();

  HuyaUserInfo userInfo;
  userInfo.uid           = userInfoObj["uid"].toInt();
  userInfo.yyid          = userInfoObj["yyid"].toInt();
  userInfo.nick          = userInfoObj["nick"].toString();
  userInfo.privateHost   = userInfoObj["privateHost"].toString();
  userInfo.avatar180     = userInfoObj["avatar180"].toString();
  userInfo.activityId    = userInfoObj["activityId"].toInt();
  userInfo.activityCount = userInfoObj["activityCount"].toInt();
  userInfo.channel       = userInfoObj["channel"].toInt();
  userInfo.subChannel    = userInfoObj["subChannel"].toInt();
  userInfo.totalCount    = userInfoObj["totalCount"].toInt();
  userInfo.isLive        = userInfoObj["isLive"].toBool();
  userInfo.gameId        = userInfoObj["gameId"].toInt();
  userInfo.gameName      = userInfoObj["gameName"].toString();
  userInfo.screenshot    = userInfoObj["screenshot"].toString();
  userInfo.intro         = userInfoObj["intro"].toString();
  userInfo.startTime     = userInfoObj["startTime"].toVariant().toLongLong();
  userInfo.profileRoom   = userInfoObj["profileRoom"].toInt();
  userInfo.iRelation     = userInfoObj["iRelation"].toInt();

  return userInfo;
}