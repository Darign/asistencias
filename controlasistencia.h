#ifndef CONTROLASISTENCIA_H
#define CONTROLASISTENCIA_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <alumno.h>
//#include <mainwindow.h>



namespace Ui {
class ControlAsistencia;
}

class ControlAsistencia : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlAsistencia(QWidget *parent = 0);
    ~ControlAsistencia();

    void mostrarTabla(QString _filtro_fecha);

private slots:
    void on_pushButtonConsultar_clicked();

    void on_pushButtonAtras_clicked();

private:
    Ui::ControlAsistencia *ui;

    std::vector<Alumno> listadoAlumnos;
    int contador;
    QString filtro_fecha;
};

#endif // CONTROLASISTENCIA_H
