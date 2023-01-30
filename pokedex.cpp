#include "pokedex.h"
#include "filereader.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

Pokedex::Pokedex()
{
    QJsonDocument document = filereader::readFile();
    QJsonArray pokemonJson = document.object().value("pokedex").toArray();
    for (const auto& item : pokemonJson)
    {
        Pokemon currentPokemon;
        auto obj = item.toObject();
        currentPokemon.m_name = obj.value("name").toString();
        auto obj2 = obj.value("stats").toObject();
        Status stat2;
        stat2.m_name = "attack";
        stat2.m_value = obj2.value("attack").toInt();
        currentPokemon.stats.append(stat2);
        stat2.m_name = "hp";
        stat2.m_value = obj2.value("hp").toInt();
        currentPokemon.stats.append(stat2);
        stat2.m_name = "defense";
        stat2.m_value = obj2.value("defense").toInt();
        currentPokemon.stats.append(stat2);
        stat2.m_name = "special-attack";
        stat2.m_value = obj2.value("special-attack").toInt();
        currentPokemon.stats.append(stat2);
        stat2.m_name = "special-defense";
        stat2.m_value = obj2.value("special-defense").toInt();
        currentPokemon.stats.append(stat2);
        stat2.m_name = "speed";
        stat2.m_value = obj2.value("speed").toInt();
        currentPokemon.stats.append(stat2);
        for (const auto& type : obj.value("types").toArray()){
            currentPokemon.m_types.append(type.toString());
        }
        for (const auto& move : obj.value("moves").toArray()){
            currentPokemon.m_moves.append(move.toString());
        }
        for (const auto& ability : obj.value("abilities").toArray()){
            currentPokemon.m_abilities.append(ability.toString());
        }
        m_list << currentPokemon;
    }
}
const QList<Pokemon> &Pokedex::pokemonList()
{
    return m_list;
}

Pokemon Pokedex::find(QString what){
        QList<Pokemon> listopokemons = pokemonList();
        for (const auto& move : listopokemons){
            if (move.m_name == what){
                return move;
            }
        }
        Pokemon move;
        return move;
    }
