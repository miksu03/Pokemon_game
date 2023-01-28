#ifndef SEARCHABLEPOKEMONLISTMODEL_H
#define SEARCHABLEPOKEMONLISTMODEL_H

#include <QSortFilterProxyModel>

#include "pokemonlistmodel.h"

class SearchablePokemonListModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString searchString READ searchString WRITE setSearchString NOTIFY searchStringChanged)
public:
    enum class Role {
        Name = PokemonListModel::Role::Name,
        Abilities = PokemonListModel::Role::Abilities,
        Moves = PokemonListModel::Role::Moves,
        Types = PokemonListModel::Role::Types,
        Stats = PokemonListModel::Role::Stats
    };
    Q_ENUM(Role);
    SearchablePokemonListModel();
    QString searchString() const;
    void setSearchString(QString newString);
signals:
    void searchStringChanged();
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
private:
    QString m_searchString;
    PokemonListModel m_sourceModel;
};

#endif // SEARCHABLEPOKEMONLISTMODEL_H
