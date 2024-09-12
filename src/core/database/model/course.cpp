#include "course.h"

#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_QOT(course)

namespace qx {
template <> void register_class(QxClass<course> & t)
{
    t.setName("course");
    t.id(& course::id, "id");
    t.data(& course::courseName, "courseName");
    t.data(& course::teacher, "teacher");
    t.data(& course::room, "room");
    t.data(& course::timeInfo, "timeInfo");
    t.data(& course::start, "start");
    t.data(& course::end, "end");
    t.data(& course::startWeek, "startWeek");
    t.data(& course::endWeek, "endWeek");
    t.data(& course::type, "type");
}}// namespace qx