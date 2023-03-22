#ifndef USERPOKEMON_H
#define USERPOKEMON_H
#include <QDebug>
#include <QObject>
#include "pokedex.h"
#include "moves.h"
#include "calculations.h"
#include "abilities.h"
//#include <QVariant>

class UserPokemon :  public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QVariant m_userMoves READ m_userMovesGET NOTIFY m_userMovesChanged)
    Q_PROPERTY(int hp READ hpGET /*NOTIFY hpChanged*/)
    Q_PROPERTY(QList<int> pp READ pp /*NOTIFY ppChanged*/)
public:
    UserPokemon();
    //QVariant m_userMovesGET() const {return m_userMoves;};
public slots:
    void pokemonSelect(QString what);
    void abilitySelect(QString what){
        m_ability = m_abilities.find(what); };
    void moveSelect(QString what){
        m_userMoves.append(m_moves.find(what));
        m_pp.append(m_moves.find(what).m_pp);
        emit m_userMovesChanged();
    };
    void attack(int attackIndex);
    QList<int> pp(){return m_pp;}
private:
    int hp;
    double usedHP;
    int speedStage;
    int evasionStage;
    int accuracyStage;
    int level;
    QList<int> m_pp;
    int hpGET(){return hp;}
    int ppGET(){return hp;}
    Pokemon m_poke;
    Pokedex m_pokedex;
    QList<Move> m_userMoves;
    Moves m_moves;
    Calculations m_calc;
    Ability m_ability;
    Abilities m_abilities;
    BetterStatus stats;
signals:
    void m_userMovesChanged();
};

#endif // USERPOKEMON_H
