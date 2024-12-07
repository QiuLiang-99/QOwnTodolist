#ifndef ADDTASKBUTTON_H
#define ADDTASKBUTTON_H

#include <QPushButton>

class AddTaskButton : public QPushButton {
    Q_OBJECT

  public:
    explicit AddTaskButton(QWidget* parent = nullptr);
    ~AddTaskButton() override;
};

#endif // ADDTASKBUTTON_H