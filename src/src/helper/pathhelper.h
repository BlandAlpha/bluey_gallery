#ifndef PATHHELPER_H
#define PATHHELPER_H

#include <QObject>
#include <QCoreApplication>
#include <QUrl>

class PathHelper : public QObject
{
    Q_OBJECT

public:
    explicit PathHelper(QObject *parent = nullptr);

    Q_INVOKABLE QString getAbsolutePath(const QString &relativePath);

};

#endif // PATHHELPER_H
