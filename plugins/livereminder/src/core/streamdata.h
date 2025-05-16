#ifndef STREAMDATA_H
#define STREAMDATA_H

#include <QString>

/**
 * @brief 直播间数据，包括主播名称、直播状态、标题以及各类流媒体地址
 * 
 */
 struct StreamData {
    QString anchorName; ///< 主播名称
    bool    isLive = false; ///< 是否正在直播，默认为 false
    QString title; ///< 直播间标题
    QString m3u8Url; ///< m3u8 格式的直播流地址
    QString flvUrl; ///< flv 格式的直播流地址
    QString recordUrl; ///< 录播地址
};

#endif // STREAMDATA_H