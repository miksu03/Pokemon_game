#ifndef USERSELECTED_H
#define USERSELECTED_H
#include <QDebug>
#include <QString>
#include <QObject>

class UserSelected : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList mySelectedMoves READ mySelectedMoveGET NOTIFY mySelectedMoveChanged)
    Q_PROPERTY(QString mySelectedAbility WRITE mySelectedAbilitySET READ mySelectedAbilityGET NOTIFY mySelectedAbilityChanged)
    Q_PROPERTY(QString mySelectedPokemon WRITE mySelectedPokemonSET READ mySelectedPokemonGET NOTIFY mySelectedPokemonChanged )
public:
    UserSelected(QObject *parent = nullptr);
    QStringList mySelectedMoveGET(){
        QStringList returnable;
        for(const QString& currentMove : mySelectedMoves){
            if(currentMove!="")
                returnable.append(currentMove);
        }
        return returnable;
    }
    QString mySelectedAbilityGET(){
        return mySelectedAbility;
    }
    QString mySelectedPokemonGET(){
        return mySelectedPokemon;
    }
    void mySelectedAbilitySET(QString what){
        mySelectedAbility = what;
        emit mySelectedAbilityChanged();
    }
    void mySelectedPokemonSET(QString what){
        mySelectedPokemon = what;
        emit mySelectedPokemonChanged();
    }
public slots:
    void mySelectedMoveIn(int index, QString what){
            mySelectedMoves[index] = what;
            emit mySelectedMoveChanged();
    }
signals:
    void mySelectedMoveChanged();
    void mySelectedAbilityChanged();
    void mySelectedPokemonChanged();

private:
    QStringList mySelectedMoves{4};
    QString mySelectedAbility;
    QString mySelectedPokemon;
};

#endif // USERSELECTED_H
