#include <QCoreApplication>
#include <QUrl>
#include "episodemodel.h"

EpisodeModel::EpisodeModel(QObject *parent) : QAbstractListModel(parent) {}

void EpisodeModel::setEpisodes(const QVariantList &episode) {
    beginResetModel();
    m_episode = episode;
    endResetModel();
}

QVariantList EpisodeModel::getEpisodesBySeason(int season) {
    QVariantList episodesBySeason;

    if (m_episode.isEmpty()) {
        qWarning() << "Episodes list is empty. Call setEpisodes() first.";
        return episodesBySeason;
    }

    // 从整个剧集列表中筛选出特定季度的剧集数据
    for (const QVariant &episode : m_episode) {
        QVariantMap episodeMap = episode.toMap();
        if (episodeMap["season"].toInt() == season) {
            episodesBySeason.append(episodeMap);
        }
    }
    qDebug() << "Season" << season <<"get:" << episodesBySeason;
    return episodesBySeason;
}


int EpisodeModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_episode.size();
}

QVariant EpisodeModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_episode.size())
        return QVariant();

    const QVariantMap episode = m_episode.at(index.row()).toMap();
    QString relativePath;
    QString absolutePath;

    switch (role) {
    case IdRole:
        return episode["id"];
    case SeasonRole:
        return episode["season"];
    case EpisodeRole:
        return episode["episode"];
    case TitleRole:
        return episode["title"];
    case DescriptionRole:
        return episode["description"];
    case ImageRole:
        relativePath = episode["image_path"].toString();
        absolutePath = QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + relativePath).toString();
        // qDebug() << "abs path:" << absolutePath;
        return absolutePath;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> EpisodeModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[SeasonRole] = "season";
    roles[EpisodeRole] = "episode";
    roles[TitleRole] = "title";
    roles[DescriptionRole] = "description";
    roles[ImageRole] = "image_path";
    return roles;
}
