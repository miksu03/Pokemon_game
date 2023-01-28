#include "pokemonlistmodel.h"

PokemonListModel::PokemonListModel()
    : QStandardItemModel{nullptr}
{
    QHash<int, QByteArray> rolelist;
    rolelist.insert(Role::Abilities, "abilities");
    rolelist.insert(Role::Moves, "moves");
    rolelist.insert(Role::Name, "name");
    rolelist.insert(Role::Types, "types");
    rolelist.insert(Role::Stats, "stats");
    setItemRoleNames(rolelist);
    m_pokedex.reset(new Pokedex{});
    const auto list = m_pokedex->pokemonList();
    for (const auto& pokemon : list)
    {
        QStandardItem* newListItem = new QStandardItem;
        newListItem->setData(pokemon.m_abilities, Role::Abilities);
        newListItem->setData(pokemon.m_moves, Role::Moves);
        newListItem->setData(pokemon.m_name, Role::Name);
        newListItem->setData(pokemon.m_types, Role::Types);
        /* TODO: QList<Status> stats; */
        appendRow(newListItem);
    }
}
