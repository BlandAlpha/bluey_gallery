#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariantMap>
#include <QStandardPaths>
#include <QFile>
#include <QDebug>
#include <QFileInfo>

DatabaseManager::DatabaseManager(QObject *parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        qWarning() << "Error: Unable to connect to database!" << m_db.lastError().text();;
    } else {
        qDebug() << "Success: Database Opened:" << m_db.databaseName();
    }
}

DatabaseManager::~DatabaseManager() {
    m_db.close();
}

void DatabaseManager::resetDatabase() {
    m_db.close();
    QFile::remove(dbPath); // 删除当前数据库文件
    initializeDatabase();  // 重新初始化数据库
    m_db.open();
}

void DatabaseManager::initializeDatabase() {
    // 检查实际数据库文件是否存在，如果不存在则复制默认数据库文件
    if (!QFile::exists(dbPath)) {
        if (QFile::copy(defaultDbPath, dbPath)) {
            QFile::setPermissions(dbPath, QFile::WriteOwner | QFile::ReadOwner);
            qDebug() << "Default database copied to" << dbPath;
        } else {
            qDebug() << "Failed to copy default database!";
        }
    } else {
        qDebug() << "Database already exists at" << dbPath;
    }
}

QVariantList DatabaseManager::getCharacters() {
    QVariantList characters;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return characters;
    }

    QSqlQuery query(m_db);
    if (!query.exec("SELECT * FROM Characters;")) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return characters;
    }

    qDebug() << "Getting Characters...";
    while (query.next()) {
        QVariantMap character;
        character["id"] = query.value("ID");
        character["name_en"] = query.value("Name_en");
        character["name_zh"] = query.value("Name_zh");
        character["breed"] = query.value("Breed");
        character["description"] = query.value("Description");
        character["image_path"] = query.value("ImagePath");
        characters.append(character);
        qDebug() << "Now getting:" << character["name_en"];
    }
    qDebug() << "---Characters Done---";
    return characters;
}

QVariantList DatabaseManager::getEpisodes() {
    QVariantList episodes;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return episodes;
    }

    QSqlQuery query(m_db);
    if (!query.exec("SELECT * FROM Episodes;")) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return episodes;
    }

    qDebug() << "Getting Episodes...";
    while (query.next()) {
        QVariantMap episode;
        episode["id"] = query.value("ID");
        episode["season"] = query.value("Season");
        episode["episode"] = query.value("Episode");
        episode["title"] = query.value("Title");
        episode["description"] = query.value("Description");
        episode["image_path"] = query.value("ImagePath");
        episodes.append(episode);
        qDebug() << "Now getting:" << episode["title"];
    }
    qDebug() << "---Episodes Done---";
    return episodes;
}

QVariantList DatabaseManager::getEpisodesBySeason(int season) {
    QVariantList episodes;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return episodes;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Episodes WHERE season = :season");
    query.bindValue(":season", season);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return episodes;
    }

    qDebug() << "Getting Season" << season;
    while (query.next()) {
        QVariantMap episode;
        episode["id"] = query.value("ID");
        episode["season"] = query.value("Season");
        episode["episode"] = query.value("Episode");
        episode["title"] = query.value("Title");
        episode["description"] = query.value("Description");
        episode["image_path"] = query.value("ImagePath");
        episodes.append(episode);
        qDebug() << "Now getting:" << episode["title"];
    }
    qDebug() << "---Episodes Done---";
    return episodes;
}

