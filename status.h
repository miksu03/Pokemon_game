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
    int m_hp;
    int m_defence;
    int m_specialAttack;
    int m_specialDefense;
    int m_speed;
};
#endif // STATUS_H
