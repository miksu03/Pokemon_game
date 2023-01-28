#include "calculations.h"
#include <QRandomGenerator>
#include <QtMath>

// kerro tämä modifikaatorilla oikean saamiseksi
int calculations::damage(double defense, double power, double attack, double level)
{
    double result = 0;
    auto randGen = QRandomGenerator::system();
    const double randomFactor = randGen->generateDouble() * 0.3 + 0.7; /* [0.7 .. 1.0[ */
    double criticalMultiplier = 1.0;
    if (randGen->generateDouble() <= 0.1)
    {
        criticalMultiplier = 1.5;
    }
    result = (2 * level) / 5;
    result = (result * power * (attack / defense) + 2) / 50;
    result = result * randomFactor * criticalMultiplier;

return qRound(result);
}

int calculations::HP(double level, double baseHP){
    double result = (31 + 2 * baseHP + 31/4)+10 + level;
    return qRound(result);
}

// kerro tämä modifikaatorilla oikean saamiseksi
int calculations::accuracy(int moveAccuracy, int accStage, int enemyAccStage){
    double result = 0;
    double final = 0;
    switch (accStage - enemyAccStage) {
    case -6:
            final = 0.333;
        break;
    case -5:
            final = 0.375;
        break;
    case -4:
            final = 0.43;
        break;
    case -3:
            final = 0.50;
        break;
    case -2:
            final = 0.60;
        break;
    case -1:
            final = 0.75;
        break;
    case 0:
            final = 1;
        break;
    case 1:
            final = 1.3333;
        break;
    case 2:
            final = 1.6667;
        break;
    case 3:
            final = 2;
        break;
    case 4:
            final = 2.3333;
        break;
    case 5:
            final = 2.6667;
        break;
    case 6:
            final = 3;
        break;
    default:
        if((accStage - enemyAccStage) < -6){
            final = 0.333;
        }
        else {
            final = 3;
        }
        break;
    }
    result = moveAccuracy * final;
    return qRound(result);
}
int speed (double level, double baseSpeed){
    int returnable = level * 2 * baseSpeed;
    returnable = returnable/100;
    return returnable + 5;
}
