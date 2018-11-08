#ifndef DIALOGTOMARASISTENCIA_H
#define DIALOGTOMARASISTENCIA_H

#include <QMainWindow>
#include <dialogtomarasistencia.h>
#include <alumno.h>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>



namespace Ui {
class dialogTomarAsistencia;
}

class dialogTomarAsistencia : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialogTomarAsistencia(QWidget *parent = 0);
    ~dialogTomarAsistencia();

    void obtenerAlumnos();
    void guardarAsistencia();
    bool mostrarAlumno(int num);
    void asignarAsistencia(int num, int concepto);


private slots:
    void on_pushButtonPresente_clicked();

    void on_pushButtonAusente_clicked();

    void on_pushButtonJustificada_clicked();

    void on_pushButtonAtras_clicked();

    void on_pushButtonSalir_clicked();

private:
    Ui::dialogTomarAsistencia *ui;
    //dialogTomarAsistencia *tomarAsistencia;

    std::vector<Alumno> listadoAlumnos; //array que guarda objetos
    int contador;


};

#endif // DIALOGTOMARASISTENCIA_H
