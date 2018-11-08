#include "agregaralumno.h"
#include "ui_agregaralumno.h"

AgregarAlumno::AgregarAlumno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarAlumno)
{
    ui->setupUi(this);
}

AgregarAlumno::~AgregarAlumno()
{
    delete ui;
}
