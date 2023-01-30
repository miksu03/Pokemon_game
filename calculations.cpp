#include "calculations.h"
#include <QRandomGenerator>
#include <QtMath>

// kerro tämä modifikaatorilla oikean saamiseksi
int Calculations::damage(double defense, double power, double attack, double level)
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

int Calculations::HP(double level, double baseHP){
    double result = (31 + 2 * baseHP + 31/4)+10 + level;
    return qRound(result);
}

// kerro tämä modifikaatorilla oikean saamiseksi
int Calculations::accuracy(int moveAccuracy, int accStage, int enemyEvasionStage){
    double result = 0;
    double evasion = accStageModifier(enemyEvasionStage * -1);
    result = moveAccuracy * accStageModifier(accStage) * evasion;
    return qRound(result);
}
double Calculations::accStageModifier(int stage){
    switch (stage) {
    case -6:
            return 0.333;
        break;
    case -5:
            return 0.375;
        break;
    case -4:
            return 0.43;
        break;
    case -3:
            return 0.50;
        break;
    case -2:
            return 0.60;
        break;
    case -1:
            return 0.75;
        break;
    case 0:
            return 1;
        break;
    case 1:
            return 1.3333;
        break;
    case 2:
            return 1.6667;
        break;
    case 3:
            return 2;
        break;
    case 4:
            return 2.3333;
        break;
    case 5:
            return 2.6667;
        break;
    case 6:
            return 3;
        break;
    default:
        if((stage) < -6){
            return 0.333;
        }
        else {
            return 3;
        }
        break;
    }
}

double Calculations::speedStageModifier(int stage){
    switch (stage) {
    case -6:
            return 0.25;
        break;
    case -5:
            return 0.28;
        break;
    case -4:
            return 0.33;
        break;
    case -3:
            return 0.40;
        break;
    case -2:
            return 0.50;
        break;
    case -1:
            return 0.66;
        break;
    case 0:
            return 1;
        break;
    case 1:
            return 1.5;
        break;
    case 2:
            return 2;
        break;
    case 3:
            return 2.5;
        break;
    case 4:
            return 3;
        break;
    case 5:
            return 3.5;
        break;
    case 6:
            return 4;
        break;
    default:
        if((stage) < -6){
            return 0.25;
        }
        else {
            return 4;
        }
        break;
    }
}

int Calculations::speed(double level, double baseSpeed, int speedStage){
    int returnable = level * 2 * baseSpeed;
    returnable = returnable/100;
    returnable += 5;
    return qRound(returnable * speedStageModifier(speedStage));
}
