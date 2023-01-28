#ifndef POKEMONLISTMODEL_H
#define POKEMONLISTMODEL_H

#include <QStandardItemModel>

#include "pokedex.h"

class PokemonListModel : public QStandardItemModel
{
    Q_OBJECT
public:
    PokemonListModel();
    enum Role {
        Name = Qt::ItemDataRole::DisplayRole,
        Abilities = Qt::ItemDataRole::UserRole,
        Moves,
        Types,
        Stats
    };
private:
    QScopedPointer<Pokedex> m_pokedex;
};

#endif // POKEMONLISTMODEL_H
