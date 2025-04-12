#ifndef PREVIEWWINDOWMODEL_H
#define PREVIEWWINDOWMODEL_H

#include <QObject>
#include <QUrl>

class PreviewWindowModel : public QObject {
    Q_OBJECT

  public:
    explicit PreviewWindowModel(QObject* parent = nullptr);
    ~PreviewWindowModel() override;

    // signals:
    //   void previewUpdated(const QString& url);

    // public slots:
    //   void updatePreview(const QString& url);

  private:
    QUrl currentUrl;
};

#endif // PREVIEWWINDOWMODEL_H