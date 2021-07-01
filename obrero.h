#ifndef OBRERO_H
#define OBRERO_H
#include <QObject>

class Obrero
{
private:
    int m_horas;      //Numeros de horas trabajadas
    QString m_nombre; //Nombre del Obrero
    char m_jornada;   //Jornada del Obrero
public:
    Obrero(QString nombre, int horas, char jornada);
    int horas() const;
    QString nombre() const;
    char jornada() const;
};

#endif // OBRERO_H
