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
#endif // STATUS_H
