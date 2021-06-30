#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include <QtDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Conectar objetos
    connect(ui->actionCalcular, SIGNAL(triggered()),
            this, SLOT(on_cmdCalc_clicked()));
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_cmdCalc_clicked()
{
    this->calcular();
}

void Principal::on_actionCalcular_triggered()
{
    this->on_cmdCalc_clicked();
}

void Principal::calcular()
{
    //Obtener el nombre
    QString nombre = ui->inNombre->text();
    //valida que el nombre no este vacio
    if(nombre.isEmpty())
    {
        QMessageBox::warning(this, "Salarios",
                             "No has proporcionado el nombre del obrero");
        return;
    }
    //Obtiene horas
    int horas = ui->inHoras->value();
    //Obtiene la jornada
    char jornada = '\0';
    if(ui->inMatutina->isChecked())
        jornada = 'M';
    else if(ui->inVespertina->isChecked())
        jornada = 'V';
    else if(ui->inNocturna->isChecked())
        jornada = 'N';
    CalculoSalario *s1 = new CalculoSalario(nombre, horas, jornada);
    s1->calcular();
    ui->outResultado->appendPlainText(s1->resultado());
    this->borrar();
}

void Principal::borrar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();
}

void Principal::nuevo()
{
    ui->outResultado->clear();
}

void Principal::on_actionNuevo_triggered()
{
    this->nuevo();
}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}

void Principal::on_actionGuardar_triggered()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();
    //Agregar al path absoluto del objeto del objeto, un nombre por defecto del archivo
    QString pathArchivo = directorio.absolutePath() + "/sin_nombre.txt";
    //abrir un cuadro de dialogo para seleccionar el nombre y ubicacion del archivo a guardar
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar archivo", pathArchivo, "Archivo de texto(*.txt)");

    //Crear el archivo a partir del nombre arrojado por el cuadro de dialogo
    QFile f(fileName);

    //Crear el objeto QTextstream (permite escribir sobre el archivo)
    QTextStream out(&f);
    //Intentar abrir el archivo ya sea para escribir(si no existe) o para agregar texto(si existe)
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QMessageBox::warning(this, "Salarios", "No se puede abrir el archivo");
        return;
    }
    //Guardar el contenido
    out << ui->outResultado->toPlainText();
    f.close();

    //mostrar mensage en la ventana
    ui->statusbar->showMessage("Archivo guardado en " + fileName, 3000);

}

void Principal::on_actionAbrir_triggered()
{
    QDir directorio = QDir::home();
    QString pathArchivo = directorio.absolutePath();
    QString file = QFileDialog::getOpenFileName(this, "Abrir", pathArchivo, "Archivo de texto(*.txt)");
    QFile f(file);
    QTextStream in(&f);
    QString informacion;
    if(!f.open(QIODevice::ReadOnly))
        QMessageBox::warning(this, "Salarios", "No se puede abrir el archivo");
    while(!in.atEnd()){
        informacion = informacion + in.readLine() + "\n";
    }
    f.close();
    ui->outResultado->appendPlainText(informacion);
}
