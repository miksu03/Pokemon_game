#include "abilities.h"
#include "filereader.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

QList<Ability> Abilities::s_list;

Abilities::Abilities()
{
    if (s_list.empty())
    {
        QJsonDocument document = filereader::readFile();
        QJsonArray AbilityJson = document.object().value("abilities").toArray();
        for (const auto& item : AbilityJson)
        {
            Ability currentAbility;
            auto obj = item.toObject();
            currentAbility.m_name = obj.value("name").toString();
            currentAbility.m_description = obj.value("description").toString();
            currentAbility.m_flavor_text = obj.value("flavor_text").toString();
            currentAbility.m_short_description = obj.value("short_description").toString();
            if (currentAbility.m_short_description == "" &&
                currentAbility.m_flavor_text == "" &&
                currentAbility.m_description == "")
            {
                currentAbility.m_flavor_text = "No effect.";
            }
            auto value = obj.value("mikaelin_arvo");
            if (value.isNull() == false)
            {
                /* Aseta tässä arvo */
            }
            s_list << currentAbility;
        }
    }
}

QList<Ability> &Abilities::abilitiesList()
{
    return s_list;
}
Ability Abilities::find(QString what){
        QList<Ability> listofabilities = abilitiesList();
        for (const auto& move : listofabilities){
            if (move.m_name == what){
                return move;
            }
        }
        Ability move;
        return move;
    }
