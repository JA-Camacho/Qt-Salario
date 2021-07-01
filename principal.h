#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "calculosalario.h"
#include "acerca.h"
#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#define VERSION "1.1.0"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionSalir_triggered();
    void on_cmdCalc_clicked();
    void on_actionCalcular_triggered();
    void on_actionNuevo_triggered();
    void on_actionAcerca_de_triggered();
    void on_actionGuardar_triggered();
    void on_actionAbrir_triggered();

private:
    Ui::Principal *ui;
    void calcular();
    void borrar();
    void nuevo();
};
#endif // PRINCIPAL_H
