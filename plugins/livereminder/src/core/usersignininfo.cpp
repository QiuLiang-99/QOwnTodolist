#include "usersignininfo.h"
#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDir>

UserSignInInfo::UserSignInInfo() {}

void UserSignInInfo::saveUserId(const QString& userId) {
  QString   hashedUserId = hashUserId(userId);
  QSettings settings(iniFilePath(), QSettings::IniFormat);
  settings.setValue(m_userIdKey, hashedUserId);
}

QString UserSignInInfo::loadUserId() const {
  QSettings settings(iniFilePath(), QSettings::IniFormat);
  return settings.value(m_userIdKey).toString();
}

QString UserSignInInfo::hashUserId(const QString& userId) const {
  QByteArray hash =
      QCryptographicHash::hash(userId.toUtf8(), QCryptographicHash::Sha256);
  return QString(hash.toHex());
}

QString UserSignInInfo::iniFilePath() const {
  return QCoreApplication::applicationDirPath() + QDir::separator() +
         m_iniFileName;
}