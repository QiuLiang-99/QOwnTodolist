#include "previewitem.h"

PreviewItem::PreviewItem(QWidget* parent) : QWidget(parent) {
    initUI();
}

void PreviewItem::initUI() {
    layout = new QVBoxLayout(this);
    imageLabel = new QLabel(this);
    textLabel = new QLabel(this);

    layout->addWidget(imageLabel);
    layout->addWidget(textLabel);

    setLayout(layout);
}

