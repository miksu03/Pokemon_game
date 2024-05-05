#ifndef STATUS_H
#define STATUS_H
#include <QString>

class Status
{
public:
    Status() = default;
    Status(const QString& name, int value);
    QString m_name;
    int m_value;
};

class BetterStatus{
public:
    int m_attack;
    int attackStage;
    int m_hp;
    int m_defence;
    int defenceStage;
    int m_specialAttack;
    int specialAttackStage;
    int m_specialDefense;
    int specialDefenceStage;
    int m_speed;
    int speedStage;
    int evasionStage;
    int accuracyStage;
    int level;
};
#endif // STATUS_H
