#ifndef COURSE_H
#define COURSE_H

struct QX_QOT_DLL_EXPORT course {

    QX_REGISTER_FRIEND_CLASS(course)

  public:
    long    id;
    QString name;
};
QX_REGISTER_HPP_QX_QOT(course, qx::trait::no_base_class_defined, 0)

#endif // COURSE_H