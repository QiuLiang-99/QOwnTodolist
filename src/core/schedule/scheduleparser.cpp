#include "scheduleparser.h"
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

ScheduleParser::ScheduleParser() {
}

ScheduleParser::~ScheduleParser() {
}

void ScheduleParser::selectFile() {
    QString filter = "JSON Files (*.json)";
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select JSON File", "", filter);
    if (!fileName.isEmpty()) {
        parse(fileName);
    }
}



void ScheduleParser::parse(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << path;
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(fileData);
    if (document.isNull() || !document.isObject()) {
        qWarning() << "Invalid JSON document";
        return;
    }

    QJsonObject jsonObject = document.object();
    if (!jsonObject.contains("kbList") || !jsonObject["kbList"].isArray()) {
        qWarning() << "JSON does not contain kbList array";
        return;
    }

    QJsonArray kbList = jsonObject["kbList"].toArray();
    for (const QJsonValue& value : kbList) {
        if (value.isObject()) {
            QJsonObject kbObject = value.toObject();
            auto sometosave=analyzeCourse(kbObject);
            //todo: save sometosave to database
        }
    }
}

course ScheduleParser::analyzeCourse(const QJsonObject& courseObject) {
    course c;
    c.courseName = courseObject["name"].toString();
    //todo
    return c;
}