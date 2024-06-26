#include "pathhelper.h"

PathHelper::PathHelper(QObject *parent) : QObject(parent)
{
}

QString PathHelper::getAbsolutePath(const QString &relativePath)
{
    QString absolutePath = QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + relativePath).toString();
    return absolutePath;
}
