#include "userpokemon.h"

UserPokemon::UserPokemon()
{
    maxHp = 0;
    hp = 0;
    m_baseStats.evasionStage = 0;
    m_baseStats.speedStage = 0;
    m_baseStats.accuracyStage = 0;
    m_baseStats.level = 100;
    m_baseStats.specialAttackStage = 0;
    m_baseStats.specialDefenceStage = 0;
    m_baseStats.attackStage = 0;
    m_baseStats.defenceStage = 0;
}

void UserPokemon::pokemonSelect(QString what)
{
    m_poke = m_pokedex.find(what);
    for(int i=0; m_poke.stats.count()>i;i++){
        if (m_poke.stats[i].m_name == "attack"){
            m_baseStats.m_attack = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "hp"){
            m_baseStats.m_hp = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "defense"){
            m_baseStats.m_defence = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "special-attack"){
            m_baseStats.m_specialAttack = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "special-defense"){
            m_baseStats.m_specialDefense = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "speed"){
            m_baseStats.m_speed = m_poke.stats[i].m_value;
        }
        hp = m_calc.HP(m_baseStats.level, m_baseStats.m_hp);
        maxHp = hp;
        emit hpChanged();
        emit pokemonChanged();
    }
}
