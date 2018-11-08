#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//consultas y requerimientos
#include <QtSql/QSqlError>//permite reconocer errores
//#include <QMessageBox>
#include <gestionalumnos.h>
#include <controlasistencia.h>
#include <dialogtomarasistencia.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void crearTablaAlumnos();

    void crearTablaAsistencias();

private slots:

    void on_pushButtonGestionar_clicked();

    void on_pushButtonAsistencia_clicked();

    void on_pushButtonVerAsistencia_clicked();

private:
    Ui::MainWindow *ui;
    GestionAlumnos *gestionAlumnos;
    ControlAsistencia *controlAsistencia;
    dialogTomarAsistencia *tomarAsistencia;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
