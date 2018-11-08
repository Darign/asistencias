#ifndef CONTROLASISTENCIA_H
#define CONTROLASISTENCIA_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <alumno.h>

namespace Ui {
class ControlAsistencia;
}

class ControlAsistencia : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlAsistencia(QWidget *parent = 0);
    ~ControlAsistencia();

    void mostrarTabla();

private:
    Ui::ControlAsistencia *ui;

    std::vector<Alumno> listadoAlumnos;
    int contador;
};

#endif // CONTROLASISTENCIA_H
