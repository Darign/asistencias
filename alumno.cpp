#include "alumno.h"

QString Alumno::getNombres()
{
    return nombres;
}

QString Alumno::getApellido()
{
    return apellido;
}

int Alumno::getConcepto()
{
    return concepto;
}

int Alumno::getId()
{
    return id;
}

void Alumno::setNombres(QString _nombres)
{
    nombres = _nombres;
}

void Alumno::setApellido(QString _apellido)
{
    apellido = _apellido;
}

void Alumno::setConcepto(int _concepto)
{
    concepto = _concepto;
}

void Alumno::setId(int _id)
{
    id = _id;
}

Alumno::Alumno()
{

}
