#include "episodemodel.h"

EpisodeModel::EpisodeModel(QObject *parent) : QAbstractListModel(parent) {}

void EpisodeModel::setEpisodes(const QVariantList &episode) {
    beginResetModel();
    m_episode = episode;
    endResetModel();
}

int EpisodeModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_episode.size();
}

QVariant EpisodeModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_episode.size())
        return QVariant();

    const QVariantMap episode = m_episode.at(index.row()).toMap();
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
        return episode["image"];
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
    roles[ImageRole] = "image";
    return roles;
}
