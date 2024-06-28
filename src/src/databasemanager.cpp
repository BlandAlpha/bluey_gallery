#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariantMap>
#include <QStandardPaths>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

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

bool DatabaseManager::resetDatabase() {
    m_db.close();
    QFile::remove(dbPath); // 删除当前数据库文件
    initializeDatabase();  // 重新初始化数据库
    m_db.open();
    return true;
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
        QSqlQuery query(m_db);
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
        QSqlQuery query(m_db);
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
        character["title"] = query.value("Name_zh");
        characters.append(character);
        qDebug() << character["title"] << "searched!";
    }

    return characters;
}

QVariantList DatabaseManager::searchAll(const QString &searchTerm) {
    QVariantList results;

    if (!m_db.isOpen()) {
        // 不和其他查询混合，删除会 Database is not open!
        newDatabaseConnection("mainSearch");
        if (!m_db.isOpen()) {
            qDebug() << "Database is not open!";
        }
        return results;
    }

    // Search Episodes
    QSqlQuery episodeQuery(m_db);
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
    QSqlQuery characterQuery(m_db);
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

bool DatabaseManager::copyImage(const QString &sourcePath, const QString &targetDir, const QString &nameEn) {
    // 去掉 file:/// 前缀
    QString cleanSourcePath = sourcePath;
    if (sourcePath.startsWith("file:///")) {
        cleanSourcePath = sourcePath.mid(8);
    }

    // 设置目标路径并包含新的文件名
    QString newFileName = nameEn + "." + QFileInfo(cleanSourcePath).suffix();
    QString newImagePath = QDir::currentPath() + targetDir + "/" + newFileName;

    // 确保目标目录存在
    QDir dir(targetDir);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    // 检查目标文件是否已存在，如果存在则删除
    if (QFile::exists(newImagePath)) {
        QFile::remove(newImagePath);
    }

    // 复制文件到新路径
    bool success = QFile::copy(cleanSourcePath, newImagePath);
    if (!success) {
        qWarning() << "Error: Unable to copy image from" << cleanSourcePath << "to" << newImagePath;
        return false;
    }

    qDebug() << "Copying to new path:" << newImagePath;

    return true;
}

int DatabaseManager::addCharacter(const QString &nameEn, const QString &nameZh, const QString &breed, const QString &description, const QString &imagePath) {
    if (!m_db.isOpen()) {
        qWarning() << "Error: Unable to open database!";
        return -1;
    }

    // 获取当前最大角色ID
    QSqlQuery maxIdQuery(m_db);
    maxIdQuery.prepare("SELECT MAX(ID) FROM Characters");
    if (!maxIdQuery.exec() || !maxIdQuery.next()) {
        qWarning() << "Error: Failed to retrieve max ID" << maxIdQuery.lastError().text();
        return -1;
    }

    int newId = 1001; // 初始值为1001
    QVariant maxIdValue = maxIdQuery.value(0);
    if (maxIdValue.isValid()) {
        int maxId = maxIdValue.toInt();
        newId = maxId + 1;
    }

    // 插入新角色记录
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Characters (ID, Name_zh, Name_en, Breed, Description, ImagePath) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(newId);
    query.addBindValue(nameZh);
    query.addBindValue(nameEn);
    query.addBindValue(breed);
    query.addBindValue(description);
    query.addBindValue(imagePath);

    if (!query.exec()) {
        qDebug() << "Add character query execution failed:" << query.lastError().text();
        return -1;
    }

    return newId;
}

int DatabaseManager::addEpisode(const QString &title, const QString &season, const QString &episode, const QString &description, const QString &imagePath) {
    if (!m_db.isOpen()) {
        qWarning() << "Error: Unable to open database!";
        return -1;
    }

    int newId = 2000 + season.toInt() * 100 + episode.toInt();
    qDebug() << "Episode new ID:" << newId;

    // 插入新角色记录
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Episodes (ID, Season, Episode, Title, Description, ImagePath) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(newId);
    query.addBindValue(season.toInt());
    query.addBindValue(episode.toInt());
    query.addBindValue(title);
    query.addBindValue(description);
    query.addBindValue(imagePath);

    if (!query.exec()) {
        qDebug() << "Add episode query execution failed:" << query.lastError().text();
        return -1;
    }

    return newId;
}

bool DatabaseManager::bindEpisodes(int characterId, const QVariantList &episodeIds) {
    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    QSqlQuery query(m_db);
    bool success = true;

    // 开始数据库事务
    if (!m_db.transaction()) {
        qDebug() << "Failed to start transaction:" << m_db.lastError().text();
        return false;
    }

    // 插入每个剧集与角色的关联，foreach循环很适合在List中遍历
    foreach (const QVariant &episodeIdVariant, episodeIds) {
        int episodeId = episodeIdVariant.toInt();

        query.prepare("INSERT INTO EpisodesCharacters (CharactersID, EpisodesID) VALUES (?, ?)");
        query.addBindValue(characterId);
        query.addBindValue(episodeId);

        if (!query.exec()) {
            qDebug() << "Failed to bind episode" << episodeId << "to character" << characterId << ":" << query.lastError().text();
            success = false;
            break;
        }
        qDebug() << "Now Binding episode" << episodeId << "to character" << characterId;
    }

    // 提交或回滚事务
    if (success && !m_db.commit()) {
        qDebug() << "Failed to commit transaction:" << m_db.lastError().text();
        success = false;
        m_db.rollback();
    }

    return success;
}

bool DatabaseManager::bindCharacters(int episodeId, const QVariantList &characterIds) {
    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    QSqlQuery query(m_db);
    bool success = true;

    // 开始数据库事务
    if (!m_db.transaction()) {
        qDebug() << "Failed to start transaction:" << m_db.lastError().text();
        return false;
    }

    // 插入每个剧集与角色的关联，foreach循环很适合在List中遍历
    foreach (const QVariant &characterIdVariant, characterIds) {
        int characterId = characterIdVariant.toInt();
        qDebug() << "Current episode ID:" << episodeId;

        query.prepare("INSERT INTO EpisodesCharacters (CharactersID, EpisodesID) VALUES (?, ?)");
        query.addBindValue(characterId);
        query.addBindValue(episodeId);

        if (!query.exec()) {
            qDebug() << "Failed to bind character" << characterId << "to episode" << episodeId << ":" << query.lastError().text();
            success = false;
            break;
        }
        qDebug() << "Now Binding character" << characterId << "to episode" << episodeId;
    }

    // 提交或回滚事务
    if (success && !m_db.commit()) {
        qDebug() << "Failed to commit transaction:" << m_db.lastError().text();
        success = false;
        m_db.rollback();
    }

    return success;
}

bool DatabaseManager::deleteCharacter(int characterId) {
    newDatabaseConnection("deleteCharacter");

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    QSqlQuery query;

    // 开始事务
    if (!m_db.transaction()) {
        qDebug() << "Failed to start transaction:" << m_db.lastError().text();
        return false;
    }

    // 删除 EpisodesCharacters 表中相关的行
    qDebug() << "Now Deleting From EpisodesCharacters";
    query.prepare("DELETE FROM EpisodesCharacters WHERE CharactersID = ?");
    query.addBindValue(characterId);

    if (!query.exec()) {
        qDebug() << "Failed to delete from EpisodesCharacters:" << query.lastError().text();
        m_db.rollback(); // 发生错误时回滚事务
        return false;
    }

    // 删除 Characters 表中相关的行
    qDebug() << "Now Deleting From Characters";
    query.prepare("DELETE FROM Characters WHERE ID = ?");
    query.addBindValue(characterId);

    if (!query.exec()) {
        qDebug() << "Failed to delete from Characters:" << query.lastError().text();
        m_db.rollback(); // 发生错误时回滚事务
        return false;
    }

    // 提交事务
    if (!m_db.commit()) {
        qDebug() << "Failed to commit transaction:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "Character and related episodes deleted successfully!";

    return true;
}

bool DatabaseManager::deleteEpisode(int episodeId) {
    newDatabaseConnection("deleteEpisode");

    if (!m_db.isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    QSqlQuery query;

    // 开始事务
    if (!m_db.transaction()) {
        qDebug() << "Failed to start transaction:" << m_db.lastError().text();
        return false;
    }

    // 删除 EpisodesCharacters 表中相关的行
    query.prepare("DELETE FROM EpisodesCharacters WHERE EpisodeID = ?");
    query.addBindValue(episodeId);

    if (!query.exec()) {
        qDebug() << "Failed to delete from EpisodesCharacters:" << query.lastError().text();
        m_db.rollback(); // 发生错误时回滚事务
        return false;
    }

    // 删除 Episodes 表中相关的行
    query.prepare("DELETE FROM Episodes WHERE ID = ?");
    query.addBindValue(episodeId);

    if (!query.exec()) {
        qDebug() << "Failed to delete from Episodes:" << query.lastError().text();
        m_db.rollback(); // 发生错误时回滚事务
        return false;
    }

    // 提交事务
    if (!m_db.commit()) {
        qDebug() << "Failed to commit transaction:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "Episode and related characters deleted successfully!";
    return true;
}
