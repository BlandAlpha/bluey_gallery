#include <QCoreApplication>
#include <QUrl>
#include "charactermodel.h"

CharacterModel::CharacterModel(QObject *parent) : QAbstractListModel(parent) {}

void CharacterModel::setCharacters(const QVariantList &characters) {
    beginResetModel();
    m_characters = characters;
    endResetModel();
}

int CharacterModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_characters.size();
}

QVariant CharacterModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_characters.size())
        return QVariant();

    const QVariantMap character = m_characters.at(index.row()).toMap();
    QString relativePath;
    QString absolutePath;

    switch (role) {
    case IdRole:
        return character["id"];
    case NameEnRole:
        return character["name_en"];
    case NameZhRole:
        return character["name_zh"];
    case BreedRole:
        return character["breed"];
    case DescriptionRole:
        return character["description"];
    case ImageRole:
        relativePath = character["image_path"].toString();
        absolutePath = QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + relativePath).toString();
        // qDebug()<< "Relative Path:" << relativePath;
        // qDebug()<< "Absolute Path:" << absolutePath;
        return absolutePath;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> CharacterModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameEnRole] = "name_en";
    roles[NameZhRole] = "name_zh";
    roles[BreedRole] = "breed";
    roles[DescriptionRole] = "description";
    roles[ImageRole] = "image_path";
    return roles;
}
