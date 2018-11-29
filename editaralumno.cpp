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


QString EditarAlumno::getNombre(){

    return ui->lineEditNombres->text();
}

QString EditarAlumno::getApellido(){

    return ui->lineEditApellido->text();
}

void EditarAlumno::setNombre(QString nombre){

    ui->lineEditNombres->setText(nombre);
}


void EditarAlumno::setApellido(QString apellido)
{
    ui->lineEditApellido->setText(apellido);
}

void EditarAlumno::setAlumno(Alumno alumno)
{

    setNombre(alumno.getNombres());
    setApellido(alumno.getApellido());
    id_alumno = alumno.getId();
}

Alumno EditarAlumno::getAlumno()
{
    Alumno aux;

    aux.setId(id_alumno);
    aux.setApellido(getApellido());
    aux.setNombres(getNombre());

    return aux;
}




void EditarAlumno::on_buttonBox_accepted()
{


}

