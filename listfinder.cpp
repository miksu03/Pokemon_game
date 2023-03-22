#include "listfinder.h"

ListFinder::ListFinder(QObject *parent) : QObject(parent)
{
    myPokemon = "";
    myAbility = "";
    myMove = "";
}
void ListFinder::myPokemonFind(QString what){
    QString sendThis = "";
    const auto list = pokemonsInList.pokemonList();
    for(const auto& pokemon : list){
        if(pokemon.m_name == what){
            sendThis += "types: \n";
            for(const auto& types : pokemon.m_types){
                sendThis += types + "\n";
            }
            for(const auto& stats : pokemon.stats){
                sendThis += stats.m_name + ": " +  QString::number(stats.m_value) + "\n";
            }
        }
    }
    myPokemon = sendThis;
    emit myPokemonChanged();
}

void ListFinder::myMoveFind(QString what){
    QString sendThis = "";
    const auto list = movesInList.movesList();
    for(const auto& move : list){
        if(move.m_name == what){
            const auto& effect = move.m_effects;
            if (effect.m_description != "" && effect.m_description != nullptr){
                if (effect.m_description.contains("$effect_chance")){
                    QString replacebable = effect.m_description;
                    if(move.m_meta.m_ailment_chance != 0){
                        sendThis += "description: " + replacebable.replace("$effect_chance", QString::number(move.m_meta.m_ailment_chance)) + "\n";
                    }else if(move.m_meta.m_flinch_chance != 0){
                        sendThis += "description: " + replacebable.replace("$effect_chance", QString::number(move.m_meta.m_flinch_chance)) + "\n";
                    }else if(move.m_meta.m_stat_chance != 0){
                        sendThis += "description: " + replacebable.replace("$effect_chance", QString::number(move.m_meta.m_stat_chance)) + "\n";
                    }
                }else{
                    sendThis += "description: " +  effect.m_description + "\n";
                }
            }
            if (effect.m_short_description != "" && effect.m_short_description != nullptr){
                if (effect.m_short_description.contains("$effect_chance")){
                    QString replacebable = effect.m_short_description;
                    if(move.m_meta.m_ailment_chance != 0){
                        sendThis += "short description: " + replacebable.replace("$effect_chance", QString::number(move.m_meta.m_ailment_chance)) + "\n";
                    }else if(move.m_meta.m_flinch_chance != 0){
                        sendThis += "short description: " + replacebable.replace("$effect_chance", QString::number(move.m_meta.m_flinch_chance)) + "\n";
                    }else if(move.m_meta.m_stat_chance != 0){
                        sendThis += "short description: " + replacebable.replace("$effect_chance", QString::number(move.m_meta.m_stat_chance)) + "\n";
                    }
                }else{
                    sendThis += "short description: " +  effect.m_short_description + "\n";
                }
            }

            sendThis += "type: " + move.m_type + "\n";
            sendThis += "damage class: "+ move.m_damage_class + "\n";
            sendThis += "accuracy: "+  QString::number(move.m_accuracy) + "\n";
            sendThis += "power: "+ QString::number(move.m_power) + "\n";
            sendThis += "pp: "+ QString::number(move.m_pp) + "\n";
            sendThis += "priority: "+ QString::number(move.m_priority) + "\n";
            const auto& meta = move.m_meta;
                if (meta.m_ailment != "" && meta.m_ailment != nullptr){
                    sendThis += "ailment: " +  meta.m_ailment + "\n";
                }
                if (meta.m_category != "" && meta.m_category != nullptr){
                    sendThis += "category: " +  meta.m_category + "\n";
                }
                if (meta.m_drain != 0){
                    sendThis += "drain: " +  QString::number(meta.m_drain) + "\n";
                }
                if (meta.m_ailment_chance != 0){
                    sendThis += "ailment chance: " +  QString::number(meta.m_ailment_chance) + "\n";
                }
                if (meta.m_crit_rate != 0){
                    sendThis += "crit rate: " +  QString::number(meta.m_crit_rate) + "\n";
                }
                if (meta.m_flinch_chance != 0){
                    sendThis += "flinch chance: " +  QString::number(meta.m_flinch_chance) + "\n";
                }
                if (meta.m_healing != 0 ){
                    sendThis += "healing: " +  QString::number(meta.m_healing) + "\n";
                }
                if (meta.m_max_hits != -1 ){
                    sendThis += "max hits: " +  QString::number(meta.m_max_hits) + "\n";
                }
                if (meta.m_max_turns != -1 ){
                    sendThis += "max turns: " +  QString::number(meta.m_max_turns) + "\n";
                }
                if (meta.m_min_hits != -1 ){
                   sendThis += "min hits: " +  QString::number(meta.m_min_hits) + "\n";
                }
                if (meta.m_min_turns != -1 ){
                    sendThis += "min turns: " +  QString::number(meta.m_min_turns) + "\n";
                }
                if (meta.m_stat_chance != 0 ){
                    sendThis += "stat chance: " +  QString::number(meta.m_stat_chance) + "\n";
                }
                for (const auto& stat_changes : move.m_stat_changes) {
                     sendThis += "changes status of: " + stat_changes.m_name + ": " +  QString::number(stat_changes.m_value) + "\n";
                }
            }
        }
    myMove = sendThis;
    emit myMoveChanged();
}
void ListFinder::myAbilityFind(QString what){
    QString sendThis = "";
    const auto list = abilitiesInList.abilitiesList();
    for(const auto& ability : list){
        if(ability.m_name == what){
            sendThis += "description: " + ability.m_description + "\n";
            sendThis += "short description: " + ability.m_short_description + "\n";
            sendThis += "flavor text: " + ability.m_flavor_text + "\n";
        }
    }
    myAbility = sendThis;
    emit myAbilityChanged();
}
