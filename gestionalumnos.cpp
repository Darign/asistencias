#include "gestionalumnos.h"
#include "ui_gestionalumnos.h"
#include "alumno.h"

#include <QDebug>

GestionAlumnos::GestionAlumnos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionAlumnos)
{
    ui->setupUi(this);

    mostrarDatos();


}

GestionAlumnos::~GestionAlumnos()
{
    delete ui;
}

void GestionAlumnos::insertarAlumno(QString nombre, QString apellido)
{
    QString consulta;

    consulta.append("INSERT INTO alumnos(apellido,nombres)"
                    "VALUES("

                    "'"+ nombre +"',"

                    "'"+ apellido +"'"
                    ");"
                    );

    QSqlQuery insertar;
    insertar.prepare(consulta);

    if (insertar.exec())
    {
        qDebug()<<"Se agregó correctamente";

       // ui->lineEditApellido->setText("");
        //ui->lineEditNombres->setText("");

        qDebug()<<"el número de fila es: " << ui->tableWidgetDatos->selectionModel()->currentIndex().row(); //está devolviendo -1
        qDebug()<<"alumno es; " << ui->tableWidgetDatos->selectionModel()->currentIndex().sibling(
                  ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data(); //está devolviendo QVariant(Invalid)

    }else{
        qDebug()<<"ERROR, no se ha agregado correctamente";
        qDebug()<<"ERROR!"<< insertar.lastError();
    }
}

void GestionAlumnos::mostrarDatos()
{
    QString consulta;
    consulta.append("SELECT * FROM alumnos");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    if(consultar.exec())
    {
        qDebug()<<"Se ha consultado correctamente";
    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << consultar.lastError();
    }

    int fila = 0;

    //ui->tableWidgetDatos->setRowCount(0);

    while(consultar.next()){

        QTableWidgetItem *columna1 = new QTableWidgetItem(consultar.value(0).toByteArray().constData());
        columna1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura

        QTableWidgetItem *columna2= new QTableWidgetItem(consultar.value(1).toByteArray().constData());
        columna2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura

        QTableWidgetItem *columna3 = new QTableWidgetItem(consultar.value(2).toByteArray().constData());
        columna3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//activa la celda en modo solo lectura


        ui->tableWidgetDatos->insertRow(fila);
        ui->tableWidgetDatos->setItem(fila,0,columna1);
                                      //new QTableWidgetItem(consultar.value(0).toByteArray().constData()));

        ui->tableWidgetDatos->setItem(fila,1,columna2);
                                      //new QTableWidgetItem(consultar.value(1).toByteArray().constData()));

        ui->tableWidgetDatos->setItem(fila,2,columna3);
                                      //new QTableWidgetItem(consultar.value(2).toByteArray().constData()));
        fila++;
    }
}



void GestionAlumnos::eliminarAlumno()
{

    int id_alumno = obtenerIdAlumno();
    qDebug()<<"El id del alumno seleccionado es: " << id_alumno;
    QString consulta;

    consulta.append("DELETE FROM alumnos WHERE id = " + QString::number(id_alumno));

    QSqlQuery eliminar;
    eliminar.prepare(consulta);

    if(eliminar.exec()){
        qDebug()<<"Se ha eliminado correctamente.";
        QMessageBox::information(this,tr("Mensaje"),tr("Se ha eliminado correctamente."));

    } else {
        qDebug()<<"No se ha podido eliminar.";
        qDebug()<<"Se ha producido un ERROR" << eliminar.lastError();

    }    
}

int GestionAlumnos::obtenerIdAlumno()
{
    /*qDebug()<<"alumno es; " << ui->tableWidgetDatos->selectionModel()->currentIndex().sibling(
              ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();*/

    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();

    //int num_fila = indice.row();
    //qDebug()<<"el número de fila es: " << num_fila;

    int id_alumno = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();

    //qDebug()<<"el id de alumno es; " << id_alumno;

    return id_alumno;


}


void GestionAlumnos::actualizarAlumno(int id, QString nombre, QString apellido)
{
    QString consulta;

    consulta.append("UPDATE alumnos "
                    "SET apellido ='" + apellido + "',nombres = '" + nombre +"'"
                    " WHERE id = " + QString::number(id));

    QSqlQuery actualizar;
    actualizar.prepare(consulta);

    if(actualizar.exec()){
        qDebug()<<"Se ha actualizado correctamente.";
        QMessageBox::information(this,tr("Mensaje"),tr("Se ha actualizado correctamente."));

    } else {
        qDebug()<<"No se ha podido actualizar.";
        qDebug()<<"Se ha producido un ERROR" << actualizar.lastError();

    }

}

void GestionAlumnos::obtenerCampo(QString &_apellido, QString &_nombres)
{

    //int id_alumno = obtenerIdAlumno();

    //índice seleccionado de la tabla
    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();


    _nombres = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),2).data().toString();
    _apellido = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),1).data().toString();



     /*qDebug()<<"Imprime el nombre y apellido:" << _nombres + _apellido;
*/


/*

    qDebug()<<"alumno es; " << ui->tableWidgetDatos->selectionModel()->currentIndex().sibling(
              ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();



    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();

    int num_fila = indice.row();

    int campo = ;
    qDebug()<<"el número de fila es: " << num_fila;

    int id_alumno = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();

    qDebug()<<"el id de alumno es; " << id_alumno;

    return campo;*/

}

void GestionAlumnos::on_pushButtonAgregar_clicked()
{
    agregarAlumno = new AgregarAlumno(this); //Crea un diálogo

    if(agregarAlumno->exec()){//se ejecuta después de cerrar la ventana

        QString nombre, apellido;

        //agregarAlumno->obtenerValores(nombre, apellido);


        nombre = agregarAlumno->getNombre();
        apellido = agregarAlumno->getApellido();



        insertarAlumno(nombre, apellido);

        mostrarDatos();
    }

  //  agregarAlumno->show();
}

void GestionAlumnos::on_pushButtonEliminar_clicked()
{
    eliminarAlumno();
    mostrarDatos();
}

void GestionAlumnos::on_pushButtonEditar_clicked()
{
    QString nombres, apellido;
    int id;

    obtenerCampo(apellido, nombres);

    id = obtenerIdAlumno();

    qDebug() << "el id seleccionado es: " <<id;

    //agregarAlumno = new AgregarAlumno(apellido,nombres,this);

    //agregarAlumno->exec();

    editarAlumno = new EditarAlumno(this);

    editarAlumno->setNombre(nombres);
    editarAlumno->setApellido(apellido);

    if (editarAlumno->exec()){

        QString nombre, apellido;

        nombre = editarAlumno->getNombre();
        apellido = editarAlumno->getApellido();

        actualizarAlumno(id, nombre, apellido);

        mostrarDatos();

    }

}
