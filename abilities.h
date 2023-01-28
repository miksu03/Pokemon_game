#ifndef ABILITIES_H
#define ABILITIES_H
#include <QString>
#include <QList>

class Ability
{
public:
    QString m_name;
    QString m_description;
    QString m_flavor_text;
    QString m_short_description;
};
class Abilities
{
public:
    Abilities();
    QList<Ability>& abilitiesList();
private:
    static QList<Ability> s_list;
};

#endif // ABILITIES_H
