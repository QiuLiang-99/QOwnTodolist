#ifndef USERSIGNININFO_H
#define USERSIGNININFO_H

#include <QSettings>
#include <QString>


/**
 * @class UserSignInInfo
 * @brief 一个用于保存和加载用户ID的类，并加密保存到ini文件中。
 */
class UserSignInInfo {
  public:
    /**
     * @brief UserSignInInfo 的构造函数。
     */
    UserSignInInfo();

    /**
     * @brief 保存用户ID到ini文件中。
     * @param userId 要保存的用户ID。
     */
    void saveUserId(const QString& userId);

    /**
     * @brief 从ini文件中加载用户ID。
     * @return 加密后的用户ID。
     */
    QString loadUserId() const;

  private:
    /**
     * @brief 使用SHA-256算法对用户ID进行加密。
     * @param userId 要加密的用户ID。
     * @return 加密后的用户ID。
     */
    QString hashUserId(const QString& userId) const;

    /**
     * @brief 获取ini文件的路径。
     * @return ini文件的路径。
     */
    QString iniFilePath() const;

    const QString m_iniFileName = "user_signin_info.ini"; ///< ini文件的名称。
    const QString m_userIdKey = "UserId"; ///< 用于存储用户ID的键。
};

#endif // USERSIGNININFO_H