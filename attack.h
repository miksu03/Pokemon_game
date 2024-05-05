#ifndef ATTACK_H
#define ATTACK_H

#include <QJsonObject>
#include "moves.h"
#include "userpokemon.h"
#include "calculations.h"

class Sentable
{
public:
    bool hit;
    bool statchange;
    int turns;
    int damage;
    int gainable;
    bool flinched;
    Move attack;
    UserPokemon* attacker;
    QJsonObject toJson();
};

class Attack
{
public:
    Sentable attackTo(Move attack, UserPokemon* attacker, UserPokemon* defender);
    void attackFrom(Sentable sended, UserPokemon* defender);
    Attack();
private:
    QList<QString> modifications;
    Calculations m_calc;
    void statChnger(QList<Status> changes, UserPokemon* targeted);
};

#endif // ATTACK_H

