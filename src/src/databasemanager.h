#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantList>
#include <QSqlError>
#include <QCoreApplication>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();
    Q_INVOKABLE QVariantList getCharacters();
    Q_INVOKABLE QVariantList getEpisodes();
    Q_INVOKABLE QVariantList getEpisodesBySeason(int season);
    Q_INVOKABLE QVariantList getRelatedEpisodes(int characterId);
    Q_INVOKABLE QVariantList getRelatedCharacters(int episodeId);
    Q_INVOKABLE QVariantList getRandomCharacters(int limit);
    Q_INVOKABLE QVariantList getRandomEpisodes(int limit);
    Q_INVOKABLE QVariantList getDataByID(int id);

    Q_INVOKABLE QVariantList searchEpisodes(const QString &title);
    Q_INVOKABLE QVariantList searchCharacters(const QString &name);
    Q_INVOKABLE QVariantList searchAll(const QString &searchTerm);

    Q_INVOKABLE bool copyImage(const QString &sourcePath, const QString &targetDir, const QString &nameEn);
    // 为方便关系数据库的链接，addCharacter会返回当前新建值的id
    Q_INVOKABLE int addCharacter(const QString &nameEn, const QString &nameZh, const QString &breed, const QString &description, const QString &imagePath);
    Q_INVOKABLE int addEpisode(const QString &title, const QString &season, const QString &episode, const QString &description, const QString &imagePath);
    Q_INVOKABLE bool bindEpisodes(int characterId, const QVariantList &episodeIds);
    Q_INVOKABLE bool bindCharacters(int episodeId, const QVariantList &characterIds);

    Q_INVOKABLE bool deleteCharacter(int characterId);
    Q_INVOKABLE bool deleteEpisode(int episodeId);

    Q_INVOKABLE bool resetDatabase(); // 给QML的重置数据库函数

    Q_INVOKABLE void newDatabaseConnection(const QString& connectionName);

private:
    QSqlDatabase m_db;
    void initializeDatabase();
    const QString defaultDbFile = "/default_bluey_gallery.db"; // 默认数据库路径，用于重置
    const QString dbFile = "/bluey_gallery.db"; // 实际使用的数据库路径
    QString defaultDbPath = QCoreApplication::applicationDirPath() + defaultDbFile;
    QString dbPath = QCoreApplication::applicationDirPath() + dbFile;

signals:
};

#endif // DATABASEMANAGER_H
