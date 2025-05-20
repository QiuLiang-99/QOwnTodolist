#ifndef PREVIEWITEM_H
#define PREVIEWITEM_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class PreviewItem : public QWidget {
    Q_OBJECT

public:
    explicit PreviewItem(QWidget* parent = nullptr);
    ~PreviewItem();

private:
    void initUI();

    QVBoxLayout* layout;
    QLabel* imageLabel;
    QLabel* textLabel;
};
#endif // PREVIEWITEM_H