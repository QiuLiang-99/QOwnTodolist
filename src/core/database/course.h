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
    short      start;
    short      end;
    short      startWeek;
    short      endWeek;
    courseType type;
};
QX_REGISTER_HPP_QX_QOT(course, qx::trait::no_base_class_defined, 0)

#endif // COURSE_H