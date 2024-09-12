#ifndef SCHEDULEPARSER_H
#define SCHEDULEPARSER_H

#include "core/database/model/course.h"
#include <QList>
#include <QString>
#include <qtmetamacros.h>

class ScheduleParser {
  public:
    ScheduleParser();
    ~ScheduleParser();
  public:
    static void selectFile();
    static void parse(const QString& path);

  private:
  static course analyzeCourse(const QJsonObject& courseObject);
};

#endif // SCHEDULEPARSER_H