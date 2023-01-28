#ifndef FILEREADER_H
#define FILEREADER_H
#include <QJsonDocument>
#include <QString>

class filereader
{
public:
    static QJsonDocument readFile();
};

#endif // FILEREADER_H
