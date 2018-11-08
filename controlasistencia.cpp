#include "controlasistencia.h"
#include "ui_controlasistencia.h"

#include <QDebug>

ControlAsistencia::ControlAsistencia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlAsistencia)
{
    ui->setupUi(this);

    mostrarTabla();
}

ControlAsistencia::~ControlAsistencia()
{
    delete ui;
}

void ControlAsistencia::mostrarTabla()
{
    QString consulta;
    //|| ', ' || nombre //no se pudo concatenar

    consulta.append("SELECT alumnos.apellido,asistencias.fecha,asistencias.concepto "
                    "FROM alumnos "
                    "INNER JOIN asistencias ON asistencias.fk_alumno = alumnos.id and asistencias.fecha = '08-11-2018'"
                    );

    QSqlQuery query;
    query.prepare(consulta);

    int fila = 0;

    if(query.exec())
    {
        while(query.next()){

            //ALUMNO, APELLIDO + NOMBRES
            QTableWidgetItem *columna1 = new QTableWidgetItem(query.value(0).toByteArray().constData());
            //columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura

            //FECHA
            QTableWidgetItem *columna2= new QTableWidgetItem(query.value(1).toByteArray().constData());
            //columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura

            //ASISTENCIA
            QTableWidgetItem *columna3 = new QTableWidgetItem(query.value(2).toByteArray().constData());
            //columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura


            ui->tableWidgetAsistencia->insertRow(fila);
            //alumnos/apellido + nombres
            ui->tableWidgetAsistencia->setItem(fila,0,columna1);

            //fecha
            ui->tableWidgetAsistencia->setItem(fila,1,columna2);

            //asistencia
            ui->tableWidgetAsistencia->setItem(fila,2,columna3);

            fila++;
        }

        qDebug()<<"Se ha consultado correctamente";
    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << query.lastError();
    }
}



/*QString ControlAsistencia::getNombre()
{
    return ui->lineEditAlumno
}
*/
