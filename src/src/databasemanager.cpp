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

void DatabaseManager::newDatabaseConnection(const QString& connectionName) {
    if (QSqlDatabase::contains(connectionName)) {
        m_db = QSqlDatabase::database(connectionName);
    } else {
        m_db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        m_db.setDatabaseName(dbPath);

        if (!m_db.open()) {
            qWarning() << "Error: Unable to connect to database!" << m_db.lastError().text();
        } else {
            qDebug() << "Success: Database Opened:" << m_db.databaseName();
        }
    }
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
        qDebug() << "getCharacters:: Query execution failed:" << query.lastError().text();
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
    }
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
        qDebug() << "getEpisodes:: Query execution failed:" << query.lastError().text();
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
    }
    // qDebug() << "---Episodes Done---";
    return episodes;
}

QVariantList DatabaseManager::getRelatedEpisodes(int characterId) {
    QVariantList episodes;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return episodes;
    }

    QSqlQuery query;
    query.prepare("SELECT "
                  "Episodes.ID AS EpisodeID, "
                  "Episodes.Season AS Season, "
                  "Episodes.Episode AS Episode, "
                  "Episodes.Title AS Title, "
                  "Episodes.Description AS Description, "
                  "Episodes.ImagePath AS ImagePath "
                  "FROM Episodes "
                  "JOIN EpisodesCharacters ON Episodes.ID = EpisodesCharacters.EpisodesID "
                  "WHERE EpisodesCharacters.CharactersID = :characterId "
                  "ORDER BY Episodes.ID ASC");
    query.bindValue(":characterId", characterId);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return episodes;
    }

    qDebug() << "Getting episodes for Character ID:" << characterId;
    while (query.next()) {
        QVariantMap episode;
        episode["id"] = query.value("EpisodeID");
        episode["season"] = query.value("Season");
        episode["episode"] = query.value("Episode");
        episode["title"] = query.value("Title");
        episode["description"] = query.value("Description");
        episode["image_path"] = query.value("ImagePath");
        episodes.append(episode);
        // qDebug() << "Now getting:" << episode["title"];
    }
    // qDebug() << "---Related Episodes Done---";
    return episodes;
}

QVariantList DatabaseManager::getRelatedCharacters(int episodeId) {
    QVariantList characters;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return characters;
    }

    QSqlQuery query;
    query.prepare("SELECT "
                  "Characters.ID AS CharacterID, "
                  "Characters.Name_en AS Name_en, "
                  "Characters.Name_zh AS Name_zh, "
                  "Characters.Breed AS Breed, "
                  "Characters.Description AS Description, "
                  "Characters.ImagePath AS ImagePath "
                  "FROM Characters "
                  "JOIN EpisodesCharacters ON Characters.ID = EpisodesCharacters.CharactersID "
                  "WHERE EpisodesCharacters.EpisodesID = :episodeId "
                  "ORDER BY Characters.ID ASC");
    query.bindValue(":episodeId", episodeId);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return characters;
    }

    qDebug() << "Getting Characters...";
    while (query.next()) {
        QVariantMap character;
        character["id"] = query.value("CharacterID");
        character["name_en"] = query.value("Name_en");
        character["name_zh"] = query.value("Name_zh");
        character["breed"] = query.value("Breed");
        character["description"] = query.value("Description");
        character["image_path"] = query.value("ImagePath");
        characters.append(character);
    }
    return characters;
}

// Random Function

QVariantList DatabaseManager::getRandomCharacters(int limit) {
    QVariantList characters;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return characters;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Characters ORDER BY RANDOM() LIMIT :limit");
    query.bindValue(":limit", limit);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return characters;
    }

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

    return characters;
}

QVariantList DatabaseManager::getRandomEpisodes(int limit) {
    QVariantList episodes;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return episodes;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Episodes ORDER BY RANDOM() LIMIT :limit");
    query.bindValue(":limit", limit);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return episodes;
    }

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

    return episodes;
}

QVariantList DatabaseManager::getDataByID(int id) {
    QVariantList data;
    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return data;
    }

    if (id < 2000) {
        // Character
        QSqlQuery query;
        query.prepare("SELECT * FROM Characters WHERE ID = ?");
        query.addBindValue(id);
        if (!query.exec()) {
            qDebug() << "Character query execution failed:" << query.lastError().text();
            return data;
        }

        while (query.next()) {
            QVariantMap character;
            character["id"] = query.value("ID");
            character["name_en"] = query.value("Name_en");
            character["name_zh"] = query.value("Name_zh");
            character["breed"] = query.value("Breed");
            character["description"] = query.value("Description");
            character["image_path"] = query.value("ImagePath");
            qDebug() << "ID getting:" << character["name_zh"];
            data.append(character);
        }
        return data;
    } else if (id > 2000) {
        // Episode
        QSqlQuery query;
        query.prepare("SELECT * FROM Episodes WHERE ID = ?");
        query.addBindValue(id);
        if (!query.exec()) {
            qDebug() << "Episodes query execution failed:" << query.lastError().text();
            return data;
        }

        while (query.next()) {
            QVariantMap episode;
            episode["id"] = query.value("ID");
            episode["season"] = query.value("Season");
            episode["episode"] = query.value("Episode");
            episode["title"] = query.value("Title");
            episode["description"] = query.value("Description");
            episode["image_path"] = query.value("ImagePath");
            qDebug() << "ID getting:" << episode["title"];
            data.append(episode);
        }
        return data;
    } else {
        qDebug() << "ID not supported!";
        return data;
    }
}


QVariantList DatabaseManager::searchEpisodes(const QString &title) {
    QVariantList episodes;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return episodes;
    }

    QSqlQuery query;
    query.prepare("SELECT ID, Title FROM Episodes WHERE Title LIKE ?");
    query.addBindValue("%" + title + "%");

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return episodes;
    }

    while (query.next()) {
        QVariantMap episode;
        episode["id"] = query.value("ID");
        episode["title"] = query.value("Title");
        episodes.append(episode);
        qDebug() << episode["title"] << "searched!";
    }

    return episodes;
}

QVariantList DatabaseManager::searchCharacters(const QString &name) {
    QVariantList characters;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return characters;
    }

    QSqlQuery query;
    query.prepare("SELECT ID, Name_zh FROM Characters WHERE Name_zh LIKE ?");
    query.addBindValue("%" + name + "%");

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return characters;
    }

    while (query.next()) {
        QVariantMap character;
        character["id"] = query.value("ID");
        character["name_zh"] = query.value("Name_zh");
        characters.append(character);
        qDebug() << character["name_zh"] << "searched!";
    }

    return characters;
}

QVariantList DatabaseManager::searchAll(const QString &searchTerm) {
    newDatabaseConnection("mainSearch");
    QVariantList results;

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return results;
    }

    // Search Episodes
    QSqlQuery episodeQuery;
    episodeQuery.prepare("SELECT ID, Title FROM Episodes WHERE Title LIKE ?");
    episodeQuery.addBindValue("%" + searchTerm + "%");

    if (!episodeQuery.exec()) {
        qDebug() << "Episode query execution failed:" << episodeQuery.lastError().text();
        return results;
    }

    while (episodeQuery.next()) {
        QVariantMap episode;
        episode["id"] = episodeQuery.value("ID");
        episode["title"] = episodeQuery.value("Title");
        results.append(episode);
        qDebug() << episode["title"] << "searched in Episodes!";
    }

    // Search Characters
    QSqlQuery characterQuery;
    characterQuery.prepare("SELECT ID, Name_zh FROM Characters WHERE Name_zh LIKE ? OR Name_en LIKE ?");
    characterQuery.addBindValue("%" + searchTerm + "%");
    characterQuery.addBindValue("%" + searchTerm + "%");

    if (!characterQuery.exec()) {
        qDebug() << "Character query execution failed:" << characterQuery.lastError().text();
        return results;
    }

    while (characterQuery.next()) {
        QVariantMap character;
        character["id"] = characterQuery.value("ID");
        character["title"] = characterQuery.value("Name_zh");
        results.append(character);
        qDebug() << character["title"] << "searched in Characters!";
    }

    return results;
}
