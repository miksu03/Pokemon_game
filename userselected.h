#ifndef USERSELECTED_H
#define USERSELECTED_H
#include <QString>
#include <QObject>

class UserSelected : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList mySelectedMoves READ mySelectedMoveGET)
    Q_PROPERTY(QString mySelectedAbility WRITE mySelectedAbilitySET READ mySelectedAbilityGET)
    Q_PROPERTY(QString mySelectedPokemon WRITE mySelectedPokemonSET READ mySelectedPokemonGET)
public:
    UserSelected(QObject *parent = nullptr);
    QStringList mySelectedMoveGET(){
        return mySelectedMoves;
    }
    QString mySelectedAbilityGET(){
        return mySelectedAbility;
    }
    QString mySelectedPokemonGET(){
        return mySelectedPokemon;
    }
    void mySelectedAbilitySET(QString what){
        mySelectedAbility = what;
    }
    void mySelectedPokemonSET(QString what){
        mySelectedPokemon = what;
    }
public slots:
    void mySelectedMoveIn(int index, QString what){
        mySelectedMoves[index] = what;
    }
private:
    QStringList mySelectedMoves{4};
    QString mySelectedAbility;
    QString mySelectedPokemon;
};

#endif // USERSELECTED_H
