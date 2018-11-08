#ifndef AGREGARALUMNO_H
#define AGREGARALUMNO_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class AgregarAlumno;
}

class AgregarAlumno : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarAlumno(QWidget *parent = 0);
    ~AgregarAlumno();


    void obtenerValores(QString &nombre,QString &apellido);

    QString getNombre();
    QString getApellido();


private slots:
    void on_buttonBoxAgregarAlumno_accepted();

private:

    Ui::AgregarAlumno *ui;
};

#endif // AGREGARALUMNO_H
