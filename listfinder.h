#ifndef LISTFINDER_H
#define LISTFINDER_H
#include <QObject>
#include "pokedex.h"
#include "moves.h"
#include "abilities.h"

class ListFinder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myPokemon READ myPokemonGET NOTIFY myPokemonChanged)
    Q_PROPERTY(QString myMove READ myMoveGET NOTIFY myMoveChanged)
    Q_PROPERTY(QString myAbility READ myAbilityGET NOTIFY myAbilityChanged)

public:
    ListFinder(QObject *parent = nullptr);
    QString myPokemon;
    QString myMove;
    QString myAbility;
    QString myPokemonGET(){
        return myPokemon;
    }
    QString myAbilityGET(){
        return myAbility;
    }
    QString myMoveGET(){
        return myMove;
    }

public slots:
    void myPokemonFind(QString what);
    void myMoveFind(QString what);
    void myAbilityFind(QString what);

private:
    Pokedex pokemonsInList;
    Abilities abilitiesInList;
    Moves movesInList;
signals:
    void myPokemonChanged();
    void myMoveChanged();
    void myAbilityChanged();
};

#endif // LISTFINDER_H
