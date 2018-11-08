#ifndef ALUMNO_H
#define ALUMNO_H
#include <QString>

class Alumno
{
public:
    QString getNombres();
    QString getApellido();
    int getConcepto();
    int getId();

    void setNombres(QString _nombres);
    void setApellido(QString _apellido);
    void setConcepto(int _concepto);
    void setId(int _id);

    Alumno();

private:
    int id;
    QString nombres;
    QString apellido;
    int concepto;

};

#endif // ALUMNO_H
