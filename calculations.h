#ifndef CALCULATIONS_H
#define CALCULATIONS_H


class Calculations
{
public:
    int damage(double defence, double power, double attack, double level);
    int HP(double level, double baseHP);
    int accuracy(int moveAccuracy, int accStage, int enemyEvasionStage);
    int speed (double level, double baseSpeed, int speedStage);
private:
    double accStageModifier(int stage);
    double speedStageModifier(int stage);
};

#endif // CALCULATIONS_H
