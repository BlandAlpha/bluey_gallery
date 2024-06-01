#pragma once

#include <QObject>
#include <QtQml/qqml.h>
#include <QTranslator>
#include "../singleton.h"
#include "../stdafx.h"

class TranslateHelper : public QObject {
Q_OBJECT
Q_PROPERTY_AUTO(QString, current)
Q_PROPERTY_READONLY_AUTO(QStringList, languages)
private:
    [[maybe_unused]] explicit TranslateHelper(QObject *parent = nullptr);

public:
SINGLETON(TranslateHelper)

    ~TranslateHelper() override;

    void init(QQmlEngine *engine);

private:
    QQmlEngine *_engine = nullptr;
    QTranslator *_translator = nullptr;
};
