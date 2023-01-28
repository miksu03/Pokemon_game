#include "filereader.h"
#include <QFile>
#include <QDir>
QJsonDocument filereader::readFile()
{
    QFile file("C:/pokemon/pokemons.json");
    if(!file.open(QIODevice::ReadOnly)) {
        return QJsonDocument{};
    }
    QString inside = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(inside.toUtf8());
    file.close();
    return document;
}
