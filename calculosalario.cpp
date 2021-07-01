#include "calculosalario.h"

QString CalculoSalario::getJornada()
{
    QString str;
    switch(obrero->jornada())
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

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent)
{

}

CalculoSalario::CalculoSalario(Obrero &obrero)
{
    this->obrero = &obrero;
}

QString CalculoSalario::resultado()
{
    QString str;
    str = "Obrero " + obrero->nombre() + "\n";
    str += "Horas: " + QString::number(obrero->horas()) + "\n";
    str += "Jornada: " + getJornada() + "\n";
    str += "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n";
    str += "Descuento: $" + QString::number(m_descuento) + "\n";
    str += "Salario Neto: $" + QString::number(m_salarioNeto) + "\n\n";
    return str;
}

void CalculoSalario::calcular()
{
    float valorHora = 0;
    switch(obrero->jornada())
    {
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }

    m_salarioBruto = obrero->horas() * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO/100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

float CalculoSalario::salarioBruto() const
{
    return m_salarioBruto;
}

float CalculoSalario::descuento() const
{
    return m_descuento;
}

float CalculoSalario::salarioNeto() const
{
    return m_salarioNeto;
}
