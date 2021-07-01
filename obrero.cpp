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

Obrero::Obrero(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}
