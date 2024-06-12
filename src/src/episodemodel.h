#ifndef EPISODEMODEL_H
#define EPISODEMODEL_H

#include <QAbstractListModel>
#include <QVariantList>

class EpisodeModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum EpisodeRoles {
        IdRole = Qt::UserRole + 1,
        TitleRole,
        SeasonRole,
        EpisodeRole,
        DescriptionRole,
        ImageRole
    };

    explicit EpisodeModel(QObject *parent = nullptr);

    Q_INVOKABLE void setEpisodes(const QVariantList &episode);
    Q_INVOKABLE QVariantList getEpisodesBySeason(int season);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QVariantList m_episode;
};

#endif // EPISODEMODEL_H
