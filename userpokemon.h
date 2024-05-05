#ifndef USERPOKEMON_H
#define USERPOKEMON_H
#include <QDebug>
#include <QObject>
#include "pokedex.h"
#include "moves.h"
#include "calculations.h"
#include "abilities.h"
#include <QVariant>
#include <QMetaType>

class UserPokemon :  public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Move> m_userMovesGET READ m_userMovesGET NOTIFY m_userMovesChanged)
    Q_PROPERTY(int hp READ hpGET NOTIFY hpChanged)
    Q_PROPERTY(int maxHp READ maxHpGET NOTIFY pokemonChanged)
    Q_PROPERTY(QList<int> m_pp READ ppGET NOTIFY ppChanged)

public:
    UserPokemon();
    QList<Move> m_userMovesGET() const {return m_userMoves;};
    Q_INVOKABLE void pp_oneLover(int index){
        m_pp[index]--;
        emit ppChanged();
    }
    Q_INVOKABLE double speedTime(){
        return m_calc.attackTime(m_calc.defaultStatCalculation(100,m_baseStats.m_speed), m_baseStats.speedStage);
    }
    BetterStatus m_baseStats;
    int hp;
    int maxHp;
    QString pokemonName(){
        return m_poke.m_name;
    }

public slots:
    void pokemonSelect(QString what);
    void abilitySelect(QString what){
        m_ability = m_abilities.find(what); };
    void moveSelect(QString what){
        m_userMoves.append(m_moves.find(what));
        m_pp.append(m_moves.find(what).m_pp);
        emit m_userMovesChanged();
    };

private:
    //int ppGET(){return hp;}
    QList<int> m_pp;
    QList<int> ppGET() const {return m_pp;}
    int maxHpGET(){return maxHp;}
    int hpGET(){return hp;}

    Pokemon m_poke;
    Pokedex m_pokedex;
    QList<Move> m_userMoves;
    Moves m_moves;
    Calculations m_calc;
    Ability m_ability;
    Abilities m_abilities;

signals:
    void pokemonChanged();
    void hpChanged();
    void ppChanged();
    void m_userMovesChanged();
};

#endif // USERPOKEMON_H
