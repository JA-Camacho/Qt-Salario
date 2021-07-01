#include "calculosalario.h"

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent)
{

}

CalculoSalario::CalculoSalario(Obrero &obrero)
{
    this->obrero = &obrero;
}

QString CalculoSalario::resultado()
{
    return obrero->informacion()
            + "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n"
            + "Descuento: $" + QString::number(m_descuento) + "\n"
            + "Salario Neto: $" + QString::number(m_salarioNeto) + "\n\n";
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
