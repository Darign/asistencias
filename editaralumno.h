#ifndef EDITARALUMNO_H
#define EDITARALUMNO_H

#include <QDialog>
#include <QDebug>
#include <alumno.h>

namespace Ui {
class EditarAlumno;
}

class EditarAlumno : public QDialog
{
    Q_OBJECT

public:
    explicit EditarAlumno(QWidget *parent = 0);
    ~EditarAlumno();


    void setAlumno(Alumno alumno);
    Alumno getAlumno();

    void obtenerValores(QString &nombre,QString &apellido);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditarAlumno *ui;

    QString getNombre();
    QString getApellido();
    void setNombre(QString nombre);
    void setApellido(QString apellido);
    int id_alumno;
};

#endif // EDITARALUMNO_H
