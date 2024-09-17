#ifndef COURSE_H
#define COURSE_H
enum courseType {
  everyweek,
  oddweek,
  evenweek
};
struct QX_QOT_DLL_EXPORT course {
    // QX_REGISTER_FRIEND_CLASS(course)
    long       id;
    QString    courseName;
    QString    teacher;
    QString    room;
    QString    timeInfo;
    QString    weekInfo;
    int        start;
    int        end;
    int        startWeek;
    int        endWeek;
    int        dayOfWeek;
    courseType type;
    // todo 课表归于一个课程表
};
QX_REGISTER_HPP_QX_QOT(course, qx::trait::no_base_class_defined, 0)

QDebug operator<<(QDebug dbg, const course& c);
#endif // COURSE_H