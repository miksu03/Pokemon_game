#ifndef CALCULATIONS_H
#define CALCULATIONS_H


class calculations
{
public:
    int damage(double defence, double power, double attack, double level);
    int HP(double level, double baseHP);
    int accuracy(int moveAccuracy, int accStage, int enemyAccStage);
    int speed (double level, double baseSpeed);
};

#endif // CALCULATIONS_H
