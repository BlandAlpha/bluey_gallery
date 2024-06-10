#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include <QAbstractListModel>
#include <QVariantList>

class CharacterModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum CharacterRoles {
        IdRole = Qt::UserRole + 1,
        NameEnRole,
        NameZhRole,
        BreedRole,
        DescriptionRole,
        ImageRole
    };

    explicit CharacterModel(QObject *parent = nullptr);

    Q_INVOKABLE void setCharacters(const QVariantList &characters);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QVariantList m_characters;
};

#endif // CHARACTERMODEL_H
