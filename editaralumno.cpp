#include "editaralumno.h"
#include "ui_editaralumno.h"

EditarAlumno::EditarAlumno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditarAlumno)
{
    ui->setupUi(this);
}

EditarAlumno::~EditarAlumno()
{
    delete ui;
}
