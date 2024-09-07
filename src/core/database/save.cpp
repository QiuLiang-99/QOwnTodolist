#include "precompiled.h"

#include "save.h"

// QX_REGISTER_CPP_EXPORT_DLL(save)
QX_REGISTER_CPP_QX_QOT(save)

namespace qx {
  template <>
  void register_class(QxClass<save>& t) {
    t.setName("persons");        // 'person' C++ class is mapped to 't_person' database table
    t.id(&save::id, "id");       // Register 'person::id' <=> primary key in your database
    t.data(&save::name, "name"); // Register 'person::id' <=> primary key in your database
    // t.data(& person::firstName, "first_name");      // Register 'person::firstName' property
    // mapped to 'first_name' database column name
  }
} // namespace qx