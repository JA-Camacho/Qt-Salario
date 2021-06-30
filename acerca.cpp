#include "acerca.h"
#include "ui_acerca.h"

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
    QString version = QString("Version: %1").arg(VERSION);
    ui->outVersion->setText(version);
}

Acerca::~Acerca()
{
    delete ui;
}

void Acerca::setVersion(const QString &value)
{
    version = value;
    ui->outVersion->setText("Version: " + value);
}
