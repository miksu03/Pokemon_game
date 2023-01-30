#include "moves.h"
#include "filereader.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

QList<Move> Moves::s_list;

Moves::Moves()
{
    QJsonDocument document = filereader::readFile();
    QJsonArray movesJson = document.object().value("moves").toArray();
    for (const auto& item : movesJson)
    {
        Move currentMove;
        auto obj = item.toObject();
        currentMove.m_name = obj.value("name").toString();
        currentMove.m_accuracy = obj.value("accuracy").toInt();
        currentMove.m_power = obj.value("power").toInt();
        currentMove.m_pp = obj.value("pp").toInt();
        currentMove.m_priority = obj.value("priority").toInt();
        currentMove.m_damage_class = obj.value("damage_class").toString();
        currentMove.m_type = obj.value("type").toString();
        auto statChanges = obj.value("stat_changes").toObject();
        for (QJsonObject::Iterator iter = statChanges.begin() ; iter != statChanges.end() ; iter++)
        {currentMove.m_stat_changes << Status{iter.key(), iter.value().toInt()};}
        auto effect = obj.value("effect").toObject();
        currentMove.m_effects.m_description = effect.value("description").toString();
        currentMove.m_effects.m_short_description = effect.value("short_description").toString();
        auto meta = obj.value("meta").toObject();
        currentMove.m_meta.m_drain = meta.value("drain").toInt();
        currentMove.m_meta.m_ailment_chance = meta.value("ailment_chance").toInt();
        currentMove.m_meta.m_crit_rate = meta.value("crit_rate").toInt();
        currentMove.m_meta.m_flinch_chance = meta.value("flinch_chance").toInt();
        currentMove.m_meta.m_healing = meta.value("healing").toInt();
        currentMove.m_meta.m_category = meta.value("category").toObject().value("name").toString();
        currentMove.m_meta.m_ailment = meta.value("ailment").toObject().value("name").toString();
        currentMove.m_meta.m_stat_chance = meta.value("stat_chance").toInt();
        if(meta.value("max_hits").isNull())
        {currentMove.m_meta.m_max_hits = -1;}
        else{currentMove.m_meta.m_max_hits = meta.value("max_hits").toInt();}
        if(meta.value("max_turns").isNull())
        {currentMove.m_meta.m_max_turns = -1;}
        else{currentMove.m_meta.m_max_turns = meta.value("max_turns").toInt();}
        if(meta.value("min_hits").isNull())
        {currentMove.m_meta.m_min_hits = -1;}
        else{currentMove.m_meta.m_min_hits = meta.value("min_hits").toInt();}
        if(meta.value("min_turns").isNull())
        {currentMove.m_meta.m_min_turns = -1;}
        else{currentMove.m_meta.m_min_turns = meta.value("min_turns").toInt();}
        s_list << currentMove;
    }
}

QList<Move> &Moves::movesList()
{
    return s_list;
}

Move Moves::find(QString what)
{
    QList<Move> listofmoves = movesList();
    for (const auto& move : listofmoves){
        if (move.m_name == what){
            return move;
        }
    }
    Move move;
    return move;
}
