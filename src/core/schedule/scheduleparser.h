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
    static course analyzeCourseObject(const QJsonObject& c);
    static course analyzeCourseInfo(course& c);
};

#endif // SCHEDULEPARSER_H