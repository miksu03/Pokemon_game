#ifndef CALCULATIONS_H
#define CALCULATIONS_H


class Calculations
{
public:
    int damage(double defenceStat, double powerOfMove, double attackStat, double level);
    int maxDamage(double defenceStat, double powerOfMove, double attackStat, double level);
    int HP(double level, double baseHP);
    int accuracy(int moveAccuracy, int accStage, int enemyEvasionStage);
    int defaultStatCalculation (double level, double baseSpeed, int speedStage);
    int defaultStatCalculation (double level, double baseSpeed);
    double attackTime(int speedStat, int speedStage);
private:
    double accStageModifier(int stage);
    double speedStageModifier(int stage);
};

#endif // CALCULATIONS_H
