#include "attack.h"
#include "qjsonarray.h"
#include <QRandomGenerator>
#include <QtMath>
#include <QDebug>

Sentable Attack::attackTo(Move attackedMove, UserPokemon *attacker, UserPokemon *defender)
{
    auto randGen = QRandomGenerator::system();
    Sentable table;
    table.damage = 0;
    table.gainable = 0;
    table.attack = attackedMove;
    table.statchange = false;
    table.flinched = false;
    int attack = m_calc.defaultStatCalculation(attacker->m_baseStats.level,
                                               attacker->m_baseStats.m_attack,
                                               attacker->m_baseStats.attackStage);
    int defence = m_calc.defaultStatCalculation(defender->m_baseStats.level,
                                                defender->m_baseStats.m_defence,
                                                defender->m_baseStats.defenceStage);
    int sattack = m_calc.defaultStatCalculation(attacker->m_baseStats.level,
                                                attacker->m_baseStats.m_specialAttack,
                                                attacker->m_baseStats.specialAttackStage);
    int sdefence = m_calc.defaultStatCalculation(defender->m_baseStats.level,
                                                 defender->m_baseStats.m_specialDefense,
                                                 defender->m_baseStats.specialDefenceStage);
    //TODO:
    if (attackedMove.m_meta.m_category != "ohko"){
        if (m_calc.accuracy(attackedMove.m_accuracy, attacker->m_baseStats.accuracyStage,
        defender->m_baseStats.evasionStage) >= randGen->bounded(100))
        {
            table.hit = true;
            if (attackedMove.m_damage_class == "special"){
                if(attackedMove.m_meta.m_max_hits != -1 && attackedMove.m_meta.m_min_hits != -1){
                    table.damage = m_calc.damage(sdefence, attackedMove.m_power, sattack, attacker->m_baseStats.level);
                    defender->hp -= table.damage;
                }else {
                    int hits = randGen->bounded(attackedMove.m_meta.m_min_hits, attackedMove.m_meta.m_max_hits);
                    for (int i = 0; i <= hits; i++){
                        table.damage += m_calc.damage(sdefence, attackedMove.m_power, sattack, attacker->m_baseStats.level);
                    }
                    defender->hp -= table.damage;
                }
            } else if (attackedMove.m_damage_class == "physical"){
                if(attackedMove.m_meta.m_max_hits != -1 && attackedMove.m_meta.m_min_hits != -1){
                    table.damage = m_calc.damage(defence, attackedMove.m_power, attack, attacker->m_baseStats.level);
                    defender->hp -= table.damage;
                }else {
                    int hits = randGen->bounded(attackedMove.m_meta.m_min_hits, attackedMove.m_meta.m_max_hits);
                    for (int i = 0; i <= hits; i++){
                        table.damage += m_calc.damage(defence, attackedMove.m_power, attack, attacker->m_baseStats.level);
                    }
                    defender->hp -= table.damage;
                }
            } else if (attackedMove.m_damage_class == "status"){
                table.damage=0;
            }
            if (attackedMove.m_meta.m_category == "damage+lower"){
                if (attackedMove.m_meta.m_stat_chance > randGen->bounded(100) || attackedMove.m_meta.m_stat_chance == 0){
                    table.statchange = true;
                    statChnger(attackedMove.m_stat_changes, defender);
                }
            }else if (attackedMove.m_meta.m_category == "damage+ailment"){
                //TODO: ailments
            }else if (attackedMove.m_meta.m_category == "damage+raise"){
                if (attackedMove.m_meta.m_stat_chance >= randGen->bounded(100) || attackedMove.m_meta.m_stat_chance == 0){
                    table.statchange = true;
                    statChnger(attackedMove.m_stat_changes, attacker);
                }
            }else if (attackedMove.m_meta.m_category == "damage+heal"){
                table.gainable = table.damage * (attackedMove.m_meta.m_drain / 100);
                if (attacker->hp + table.gainable >= attacker->maxHp){
                    table.gainable = attacker->maxHp - attacker->hp;
                    attacker->hp = attacker->maxHp;
                }else {
                    attacker->hp += table.gainable;
                }
            }else if (attackedMove.m_meta.m_category == "ailment"){
                //TODO: ailments
            }else if (attackedMove.m_meta.m_category == "net-good-stats"){
                if (attackedMove.m_accuracy == 0){
                    if (attackedMove.m_meta.m_stat_chance >= randGen->bounded(100) || attackedMove.m_meta.m_stat_chance == 0){
                        table.statchange = true;
                        statChnger(attackedMove.m_stat_changes, attacker);
                    }
                }else{
                    if (attackedMove.m_meta.m_stat_chance > randGen->bounded(100) || attackedMove.m_meta.m_stat_chance == 0){
                        table.statchange = true;
                        statChnger(attackedMove.m_stat_changes, defender);
                    }
                }
            }else if (attackedMove.m_meta.m_category == "unique"){
                //TODO: uniques
            }else if (attackedMove.m_meta.m_category == "field-effect"){
                //TODO: effects
            }else if (attackedMove.m_meta.m_category == "whole-field-effect"){
                //TODO: field effects
            }if (attackedMove.m_meta.m_category == "swagger"){
                if (attackedMove.m_meta.m_stat_chance > randGen->bounded(100) || attackedMove.m_meta.m_stat_chance == 0){
                    table.statchange = true;
                    statChnger(attackedMove.m_stat_changes, defender);
                }
                //TODO: ailments
            }
            if (attackedMove.m_meta.m_flinch_chance <= randGen->bounded(100)){
                table.flinched = true;
            }
            if (attackedMove.m_meta.m_healing != 0){
                table.gainable += attacker->maxHp * (attackedMove.m_meta.m_healing / 100);
                if (attacker->hp + table.gainable >= attacker->maxHp){
                    table.gainable = attacker->maxHp - attacker->hp;
                    attacker->hp = attacker->maxHp;
                }else {
                    attacker->hp += table.gainable;
                }
            }
        }else{table.hit = false;}
    }else{
        if (attackedMove.m_accuracy >= randGen->bounded(100))
        {
            table.hit = true;
            table.damage = defender->maxHp;
            defender->hp = table.damage;
        }
    }
    return table;
}

void Attack::attackFrom(Sentable sended, UserPokemon *defender)
{
    int attack = m_calc.defaultStatCalculation(sended.attacker->m_baseStats.level,
                                               sended.attacker->m_baseStats.m_attack,
                                               sended.attacker->m_baseStats.attackStage);
    int defence = m_calc.defaultStatCalculation(defender->m_baseStats.level,
                                                defender->m_baseStats.m_defence,
                                                defender->m_baseStats.defenceStage);
    int sattack = m_calc.defaultStatCalculation(sended.attacker->m_baseStats.level,
                                               sended.attacker->m_baseStats.m_specialAttack,
                                               sended.attacker->m_baseStats.specialAttackStage);
    int sdefence = m_calc.defaultStatCalculation(defender->m_baseStats.level,
                                                defender->m_baseStats.m_specialDefense,
                                                defender->m_baseStats.specialDefenceStage);
    if(sended.attack.m_type == "physical"){
        if (m_calc.maxDamage(defence, sended.attack.m_power, attack, sended.attacker->m_baseStats.level) < sended.damage){return;}
    }else if(sended.attack.m_type == "special"){
        if (m_calc.maxDamage(sdefence, sended.attack.m_power, sattack, sended.attacker->m_baseStats.level) < sended.damage){return;}
    }
    if (sended.attack.m_meta.m_category != "ohko"){
        if (sended.hit)
        {
            defender->hp -= sended.damage;
            if (sended.attack.m_meta.m_category == "damage+lower"){
                if (sended.statchange){
                    statChnger(sended.attack.m_stat_changes, defender);
                }
            }else if (sended.attack.m_meta.m_category == "damage+ailment"){
                //TODO: ailments
            }else if (sended.attack.m_meta.m_category == "damage+raise"){
                if (sended.statchange){
                    statChnger(sended.attack.m_stat_changes, sended.attacker);
                }
            }else if (sended.attack.m_meta.m_category == "damage+heal"){
                sended.attacker->hp += sended.gainable;
            }
        }else if (sended.attack.m_meta.m_category == "ailment"){
            //TODO: ailments
        }else if (sended.attack.m_meta.m_category == "net-good-stats"){
            if (sended.attack.m_accuracy == 0){
                if (sended.statchange){
                    statChnger(sended.attack.m_stat_changes, sended.attacker);
                }
            }else{
                if (sended.statchange){
                    statChnger(sended.attack.m_stat_changes, defender);
                }
            }
        }else if (sended.attack.m_meta.m_category == "unique"){
            //TODO: uniques
        }else if (sended.attack.m_meta.m_category == "field-effect"){
            //TODO: effects
        }else if (sended.attack.m_meta.m_category == "whole-field-effect"){
            //TODO: field effects
        }if (sended.attack.m_meta.m_category == "swagger"){
            if (sended.statchange){
                statChnger(sended.attack.m_stat_changes, defender);
            }
            //TODO: ailments
        }
        if (sended.attack.m_meta.m_healing != 0){
            sended.attacker->hp += sended.gainable;
        }
    }else{
        if (sended.hit)
        {
            defender->hp = sended.damage;
        }
    }
}

Attack::Attack() {
    modifications.append("accuracy");
    modifications.append("evasion");
    modifications.append("speed");
    modifications.append("attack");
    modifications.append("defense");
    modifications.append("special-defense");
    modifications.append("special-attack");
}

void Attack::statChnger(QList<Status> changes, UserPokemon* targeted)
{
    for (const auto& item : changes)
    {
        switch (modifications.indexOf(item.m_name)) {
        case 0:
            targeted->m_baseStats.accuracyStage += item.m_value;
            break;
        case 1:
            targeted->m_baseStats.evasionStage += item.m_value;
            break;
        case 2:
            targeted->m_baseStats.speedStage += item.m_value;
            break;
        case 3:
            targeted->m_baseStats.attackStage += item.m_value;
            break;
        case 4:
            targeted->m_baseStats.defenceStage += item.m_value;
            break;
        case 5:
            targeted->m_baseStats.m_specialDefense += item.m_value;
            break;
        case 6:
            targeted->m_baseStats.m_specialAttack += item.m_value;
            break;
        default:
            qDebug() << "you forgot: " << item.m_name;
            break;
        }
    }
}

QJsonObject Sentable::toJson()
{
    QJsonObject obj;
    if (attacker != nullptr) {
        obj["attacker"] = attacker->pokemonName();
        obj["attack"] = attack.m_name;
        obj["hit"] = hit;
        obj["statchange"] = statchange;
        obj["turns"] = turns;
        obj["damage"] = damage;
        obj["gainable"] = gainable;
        obj["flinched"] = flinched;
        return obj;
    }else{
        return obj;
    }
}
