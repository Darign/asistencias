#include "agregaralumno.h"
#include "ui_agregaralumno.h"

AgregarAlumno::AgregarAlumno(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::AgregarAlumno)
{
    // ui->lineEditApellido->setText(apellido);
     //ui->lineEditNombres->setText(nombre);

    ui->setupUi(this);
    //qDebug()<<alumno;
}

AgregarAlumno::~AgregarAlumno()
{
    delete ui;
}

void AgregarAlumno::obtenerValores(QString &nombre, QString &apellido)
{
    nombre = ui->lineEditApellido->text();
    apellido = ui->lineEditNombres->text();


}

QString AgregarAlumno::getNombre()
{
    return ui->lineEditNombres->text();
}

QString AgregarAlumno::getApellido()
{
    return ui->lineEditApellido->text();
}




void AgregarAlumno::on_buttonBoxAgregarAlumno_accepted()
{

}
