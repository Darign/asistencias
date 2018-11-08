#ifndef GESTIONALUMNOS_H
#define GESTIONALUMNOS_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include "agregaralumno.h"
#include "editaralumno.h"

namespace Ui {
class GestionAlumnos;
}

class GestionAlumnos : public QWidget
{
    Q_OBJECT

public:
    explicit GestionAlumnos(QWidget *parent = 0);
    ~GestionAlumnos();

    void crearTablaAlumnos();

    void insertarAlumno(QString nombre, QString apellido);

    void mostrarDatos();

    void eliminarAlumno();

    int obtenerIdAlumno();

    void actualizarAlumno(int id, QString nombre, QString apellido);

    void obtenerCampo(QString &_apellido, QString &_nombres);

private slots:
    void on_pushButtonAgregar_clicked();

    void on_pushButtonEliminar_clicked();

    void on_pushButtonEditar_clicked();

    void on_pushButtonVolver_clicked();

private:
    Ui::GestionAlumnos *ui;
    AgregarAlumno *agregarAlumno;

    EditarAlumno *editarAlumno;
};

#endif // GESTIONALUMNOS_H
