#include "userpokemon.h"

UserPokemon::UserPokemon()
{
    evasionStage = 0;
    speedStage = 0;
    accuracyStage = 0;
    level = 100;
    usedHP = 0;
}

void UserPokemon::pokemonSelect(QString what)
{
    m_poke = m_pokedex.find(what);
    for(int i=0; m_poke.stats.count()>i;i++){
        if (m_poke.stats[i].m_name == "attack"){
            stats.m_attack = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "hp"){
            stats.m_hp = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "defense"){
            stats.m_defence = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "special-attack"){
            stats.m_specialAttack = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "special-defense"){
            stats.m_specialDefense = m_poke.stats[i].m_value;
        }else if (m_poke.stats[i].m_name == "speed"){
            stats.m_speed = m_poke.stats[i].m_value;
        }
    }
    hp = m_calc.HP(level, stats.m_hp);
}

void UserPokemon::attack(int attackIndex)
{
     if (m_userMoves[attackIndex].m_damage_class == "special"){
        usedHP += m_calc.damage(stats.m_specialDefense, m_userMoves[attackIndex].m_power, stats.m_specialAttack, level);
     } else if (m_userMoves[attackIndex].m_damage_class == "physical"){
        usedHP += m_calc.damage(stats.m_defence, m_userMoves[attackIndex].m_power, stats.m_attack, level);
     } if (m_userMoves[attackIndex].m_damage_class == "status"){
         for (int i = 0; m_userMoves[attackIndex].m_stat_changes.length() > i; i++){
             if (m_userMoves[attackIndex].m_stat_changes[i].m_name == "speed")
             {

             }
             if (m_userMoves[attackIndex].m_stat_changes[i].m_name == "accuracy")
             {

             }
             if (m_userMoves[attackIndex].m_stat_changes[i].m_name == "evasion")
             {

             }
         }
     }
}
