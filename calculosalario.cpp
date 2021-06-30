#include "calculosalario.h"

QString CalculoSalario::getJornada()
{
    QString str;
    switch(m_jornada)
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

CalculoSalario::CalculoSalario(QString nombre, int horas, char jornada)
{
    this->m_nombre = nombre;
    this->m_horas = horas;
    this->m_jornada = jornada;
}

QString CalculoSalario::resultado()
{
    QString str;
    str = "Obrero " + m_nombre + "\n";
    str += "Horas: " + QString::number(m_horas) + "\n";
    str += "Jornada: " + getJornada() + "\n";
    str += "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n";
    str += "Descuento: $" + QString::number(m_descuento) + "\n";
    str += "Salario Neto: $" + QString::number(m_salarioNeto) + "\n\n";
    return str;
}

void CalculoSalario::calcular()
{
    float valorHora = 0;
    switch(m_jornada)
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

    m_salarioBruto = m_horas * valorHora;
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
