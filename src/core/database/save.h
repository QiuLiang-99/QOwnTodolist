#ifndef SAVE_H
#define SAVE_H

struct QX_QOT_DLL_EXPORT save {

    QX_REGISTER_FRIEND_CLASS(save)

  public:
    long    id;
    QString name;
};
// QX_REGISTER_HPP_IMPORT_DLL(save, qx::trait::no_base_class_defined, 0)
QX_REGISTER_HPP_QX_QOT(save, qx::trait::no_base_class_defined, 0)
// QX_REGISTER_HPP_EXPORT_DLL(save, qx::trait::no_base_class_defined, 0)

#endif // SAVE_H