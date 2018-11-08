#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //este código se ejecuta cuando se inicializa la aplicación
    //qDebug()<<"Se inició bien...";

    QString nombre;
    nombre.append("baseDatos.qlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db. setDatabaseName("baseDatos.qlite");

    if (db.open()) {qDebug()<<"Se ha conectado a la base de datos";
    }
    else
    {
     qDebug()<<"ERROR, no se ha podido conectar";
    }

    crearTablaAlumnos();

    crearTablaAsistencias();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearTablaAsistencias()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS asistencias("
                    "id_asistencia INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "fecha DATE NOT NULL,"
                    "fk_alumno INT(3) NOT NULL,"
                    "concepto INT(1)"
                    ");"
                    );

    QSqlQuery crear;
    crear.prepare(consulta);

    if (crear.exec())
        {
        qDebug()<<"Se creó correctamente";
        }else
        {
        qDebug()<<"ERROR, no se ha creado correctamente";
    }
}

void MainWindow::crearTablaAlumnos()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS alumnos("
                    "id INTEGER(3) PRIMARY KEY AUTOINCREMENT,"
                    "apellido VARCHAR(50),"
                    "nombres VARCHAR (100)"
                    ");"
                    );

    QSqlQuery crear;
    crear.prepare(consulta);

    if (crear.exec())
        {
        qDebug()<<"Se creó correctamente";
        }else
        {
        qDebug()<<"ERROR, no se ha creado correctamente";
    }
}

void MainWindow::on_pushButtonGestionar_clicked()
{
    gestionAlumnos = new GestionAlumnos(this);
    gestionAlumnos->show();
}

void MainWindow::on_pushButtonAsistencia_clicked()
{
    tomarAsistencia = new dialogTomarAsistencia(this);
    tomarAsistencia->show();

}



void MainWindow::on_pushButtonVerAsistencia_clicked()
{
    controlAsistencia = new ControlAsistencia(this);
    controlAsistencia->show();
}
