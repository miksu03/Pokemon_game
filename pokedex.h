#ifndef POKEDEX_H
#define POKEDEX_H
#include <QList>
#include "status.h"

class Pokemon
{
public:
    QList<QString> m_abilities;
    QList<QString> m_moves;
    QString m_name;
    QList<QString> m_types;
    QList<Status> stats;
};

class Pokedex
{
public:
    Pokedex();
    const QList<Pokemon>& pokemonList();
private:
    QList<Pokemon> m_list;
};

#endif // POKEDEX_H
