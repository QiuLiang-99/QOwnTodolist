#include <QApplication>
#include <QDebug>
#include <QDesktopServices>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
#include <QUrl>

QString getQueryParam(const QString& url, const QString& param) {
  QUrl        qurl(url);
  QString     query = qurl.query();
  QStringList pairs = QString(query).split('&');

  for (const QString& pair : pairs) {
    QStringList keyValue = pair.split('=');
    if (keyValue.size() == 2 && keyValue[0] == param) {
      return QUrl::fromPercentEncoding(keyValue[1].toUtf8());
    }
  }
  return QString();
}

void handleNetworkReply(QNetworkReply* reply) {
  if (reply->error() == QNetworkReply::NoError) {
    QByteArray jsonResponse = reply->readAll();
    qDebug() << "Received JSON response:" << jsonResponse;

    // 解析 JSON 数据
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonResponse);
    if (jsonDoc.isNull()) {
      qWarning() << "Failed to parse JSON.";
      return;
    }

    QJsonObject jsonObject = jsonDoc.object();
    QString     uid        = jsonObject.value("uid").toString(); // 提取 uid
    qDebug() << "User ID (uid) received:" << uid;
  } else {
    qWarning() << "Network error:" << reply->errorString();
  }
  reply->deleteLater();
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  // 1. 使用 QNetworkAccessManager 发送 API 请求
  QNetworkAccessManager* networkManager = new QNetworkAccessManager();
  QUrl apiUrl("https://www.huya.com/udb_web/checkLogin.php?callback_url=http://"
              "localhost:8080");

  // 发送请求
  QNetworkReply* reply = networkManager->get(QNetworkRequest(apiUrl));

  // 连接请求完成信号
  QObject::connect(reply, &QNetworkReply::finished, [reply]() {
    handleNetworkReply(reply);
  });

  // 2. 启动本地服务器，监听8080端口
  QTcpServer server;
  if (!server.listen(QHostAddress::LocalHost, 8080)) {
    qCritical() << "Unable to start the server:" << server.errorString();
    return 1; // 无法启动服务器
  }
  qDebug() << "Server started, listening on http://localhost:8080";

  // 3. 处理新的连接
  QObject::connect(&server, &QTcpServer::newConnection, [&]() {
    QTcpSocket* socket = server.nextPendingConnection();

    // 读取HTTP请求
    QObject::connect(socket, &QTcpSocket::readyRead, [socket]() {
      QByteArray requestData = socket->readAll();
      qDebug() << "Received data:" << requestData;

      // 解析数据（假设数据包含在GET请求的URL中）
      QString     request(requestData);
      QStringList requestLines = request.split("\r\n");
      QString     getLine      = requestLines.first();

      // 解析GET请求行，提取回调URL的参数
      QString urlPart          = getLine.split(" ").at(1);
      QString code             = getQueryParam(urlPart, "code");

      // 发送HTTP响应给浏览器
      QTextStream response(socket);
      response << "HTTP/1.1 200 OK\r\n";
      response << "Content-Type: text/html\r\n\r\n";
      response
          << "<h1>Authorization Successful</h1><p>You can close this page.</p>";
      response.flush();

      socket->disconnectFromHost();
    });

    QObject::connect(socket, &QTcpSocket::disconnected, socket,
                     &QTcpSocket::deleteLater);
  });

  return app.exec();
}
