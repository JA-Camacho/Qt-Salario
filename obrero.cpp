#include "obrero.h"

int Obrero::horas() const
{
    return m_horas;
}

QString Obrero::nombre() const
{
    return m_nombre;
}

char Obrero::jornada() const
{
    return m_jornada;
}

QString Obrero::getJornada()
{
    QString str;
    switch(jornada())
    {
    case 'V':
        str = "Vespertina";
        break;
    case 'M':
        str = "Matutina";
        break;
    case 'N':
        str = "Nocturna";
        break;
    }
    return str;
}

QString Obrero::informacion()
{
    return "Obrero " + nombre() + "\n"
            + "Horas: " + QString::number(horas()) + "\n"
            + "Jornada: " + getJornada() + "\n";
}

Obrero::Obrero(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}
