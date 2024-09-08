#include "course.h"

#include <QxOrm_Impl.h>

QX_REGISTER_CPP_QX_QOT(course)

namespace qx {
template <> void register_class(QxClass<course> & t)
{
    t.setName("course");
    t.id(& course::id, "id");
    t.data(& course::name, "name");
}}// namespace qx