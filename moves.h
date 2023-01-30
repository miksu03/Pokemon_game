#ifndef MOVES_H
#define MOVES_H
#include <QList>
#include "status.h"

class Meta
{
public:
    int m_stat_chance;
    int m_ailment_chance;
    QString m_ailment;
    QString m_category;
    int m_crit_rate;
    int m_drain;
    int m_flinch_chance;
    int m_healing;
    int m_max_hits;
    int m_max_turns;
    int m_min_hits;
    int m_min_turns;
};
class Effect
{
public:
    QString m_description;
    QString m_short_description;
};
class Move
{
public:
    int m_accuracy;
    int m_priority;
    int m_pp;
    QString m_name;
    QString m_type;
    int m_power;
    Meta m_meta;
    Effect m_effects;
    QString m_damage_class;
    QList<Status> m_stat_changes;
};

class Moves
{
public:
    Moves();
    QList<Move>& movesList();
    Move find(QString what);
private:
    static QList<Move> s_list;
    //std::optional<int> value;
};
#endif // MOVES_H
