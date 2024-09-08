#ifndef SCHEDULEPARSER_H
#define SCHEDULEPARSER_H

#include <QList>
#include <QString>


class ScheduleParser
{
public:
    ScheduleParser();
    ~ScheduleParser();

    void parse(const QString &schedule);
    QList<int> getDays() const;
    QList<int> getPeriods() const;
    QList<int> getRooms() const;
    QList<int> getTeachers() const;
    QList<int> getCourses() const;

private:
    QList<int> m_days;
    QList<int> m_periods;
    QList<int> m_rooms;
    QList<int> m_teachers;
    QList<int> m_courses;
};

#endif // SCHEDULEPARSER_H