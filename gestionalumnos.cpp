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

void GestionAlumnos::insertarAlumno(Alumno alumno)
{
    QString consulta;

    //editado con objeto alumno + nombre + apellido
    consulta.append("INSERT INTO alumnos(apellido,nombres)"
                    "VALUES("

                    "'"+ alumno.getNombres() +"',"

                    "'"+ alumno.getApellido() +"'"
                    ");"
                    );

    QSqlQuery insertar;
    insertar.prepare(consulta);

    if (insertar.exec())
    {
        qDebug()<<"Se agregó correctamente";       

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

    //limpia la tabla
    ui->tableWidgetDatos->setRowCount(0);

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

    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();   

    int id_alumno = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();

    return id_alumno;

}

Alumno GestionAlumnos::obtenerAlumnoSeleccionado()
{
    Alumno alumno;
    //índice seleccionado de la tabla
    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();

    QString _nombres = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),2).data().toString();
    QString _apellido = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),1).data().toString();
    int _id = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),0).data().value<int>();

    alumno.setNombres(_nombres);
    alumno.setApellido(_apellido);
    alumno.setId(_id);

    return alumno;
}


void GestionAlumnos::actualizarAlumno(Alumno alumno)
{
    QString consulta;

    consulta.append("UPDATE alumnos "
                    "SET apellido ='" + alumno.getApellido() + "',nombres = '" + alumno.getNombres() +"'"
                    " WHERE id = " + QString::number(alumno.getId()));

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

    //índice seleccionado de la tabla
    QModelIndex indice = ui->tableWidgetDatos->selectionModel()->currentIndex();

    _nombres = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),2).data().toString();
    _apellido = indice.sibling(ui->tableWidgetDatos->selectionModel()->currentIndex().row(),1).data().toString();

}

void GestionAlumnos::on_pushButtonAgregar_clicked()
{
    agregarAlumno = new AgregarAlumno(this); //Crea un diálogo

    Alumno alumno;

    if(agregarAlumno->exec()){//se ejecuta después de cerrar la ventana


        alumno.setNombres(agregarAlumno->getNombre());
        alumno.setApellido(agregarAlumno->getApellido());

        insertarAlumno(alumno);

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

    Alumno alumno;

    alumno = obtenerAlumnoSeleccionado();


    qDebug() << "el id seleccionado es: " <<alumno.getId();

    //diálogo editar alumno
    editarAlumno = new EditarAlumno(this);

    //llena los campos de la ventana con los datos de la tabla
    editarAlumno->setAlumno(alumno);


    //si la ventana retorna verdadero
    if (editarAlumno->exec()){

        alumno = editarAlumno->getAlumno();

        qDebug() << "el id seleccionado es: " <<alumno.getId();
        qDebug() << "el nombre seleccionado es: " <<alumno.getNombres();

        actualizarAlumno(alumno);

        mostrarDatos();

    }

}

void GestionAlumnos::on_pushButtonVolver_clicked()
{
    this->close();
}
