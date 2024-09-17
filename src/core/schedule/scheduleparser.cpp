#include "scheduleparser.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QRegularExpression>
#include <QString>
#include <qlogging.h>

ScheduleParser::ScheduleParser() {}

ScheduleParser::~ScheduleParser() {}

void ScheduleParser::selectFile() {
  QString filter = "JSON Files (*.json)";
  QString fileName =
      QFileDialog::getOpenFileName(nullptr, "Select JSON File", "", filter);
  if (!fileName.isEmpty()) { parse(fileName); }
}

void ScheduleParser::parse(const QString& path) {
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Could not open file for reading:" << path;
    return;
  }

  QByteArray fileData = file.readAll();
  file.close();

  QJsonDocument document = QJsonDocument::fromJson(fileData);
  if (document.isNull() || !document.isObject()) {
    qWarning() << "Invalid JSON document";
    return;
  }

  QJsonObject jsonObject = document.object();
  if (!jsonObject.contains("kbList") || !jsonObject["kbList"].isArray()) {
    qWarning() << "JSON does not contain kbList array";
    return;
  }

  QJsonArray kbList = jsonObject["kbList"].toArray();
  for (const QJsonValue& value : kbList) {
    if (value.isObject()) {
      QJsonObject kbObject   = value.toObject();
      course      sometosave = analyzeCourseObject(kbObject);
      sometosave             = analyzeCourseInfo(sometosave);
      // todo: save sometosave to database
      qDebug() << sometosave;
    }
  }
}

course ScheduleParser::analyzeCourseObject(const QJsonObject& courseObject) {
  course c = {
      .courseName = courseObject["kcmc"].toString(),
      .teacher    = courseObject["xm"].toString(),
      .room       = courseObject["cdmc"].toString(),
      .timeInfo   = courseObject["jcor"].toString(),
      .weekInfo   = courseObject["zcd"].toString(),
      .dayOfWeek  = courseObject["xqj"].toString().toInt(),
  };
  return c;
}

course ScheduleParser::analyzeCourseInfo(course& c) {
  QStringList timeParts = c.timeInfo.split('-');
  if (timeParts.size() == 2) {
    c.start = timeParts[0].toInt();
    c.end   = timeParts[1].toInt();
  } else if (timeParts.size() == 1) {
    c.start = c.end = timeParts[0].toInt();
  } else {
    qWarning() << "Invalid timeInfo:" << c.timeInfo;
  }
  QStringList weekParts =
      c.weekInfo.split(QRegularExpression("[^0-9]+"), Qt::SkipEmptyParts);
  // bug 单双周判定缺少素材！ type
  if (weekParts.size() == 2) {
    c.startWeek = weekParts[0].toInt();
    c.endWeek   = weekParts[1].toInt();
  } else {
    qWarning() << "Invalid weekInfo:" << c.weekInfo;
  }
  return c;
}