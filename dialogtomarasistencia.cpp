#include "dialogtomarasistencia.h"
#include "ui_dialogtomarasistencia.h"



dialogTomarAsistencia::dialogTomarAsistencia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialogTomarAsistencia)
{      
    ui->setupUi(this);

    contador = 0; //se inicializa el contador
    obtenerAlumnos();
    mostrarAlumno(contador);

    QDateTime qdatetime;
    qdatetime = QDateTime::currentDateTime();
    QString fecha_actual = qdatetime.toString("dd-MM-yyyy");
    ui->lineEditFecha->setText(fecha_actual);

}

dialogTomarAsistencia::~dialogTomarAsistencia()
{
    delete ui;
}


void dialogTomarAsistencia::obtenerAlumnos()
{
    QString consulta;
    consulta.append("SELECT * FROM alumnos");
    QSqlQuery query;
    query.prepare(consulta);

    if(query.exec())
    {
        qDebug()<<"Se ha consultado correctamente";

        while(query.next()){

            Alumno alumno_aux;

            alumno_aux.setId( query.value(0).toInt() );
            alumno_aux.setApellido( query.value(1).toString() );
            alumno_aux.setNombres( query.value(2).toString() );
            alumno_aux.setConcepto(0);

            listadoAlumnos.push_back(alumno_aux);

        }

    }else{
        qDebug()<<"No se ha podido realizar la consulta";
        qDebug()<<"ERROR" << query.lastError();
    }

}

void dialogTomarAsistencia::guardarAsistencia()
{
    QMessageBox mensaje;

    mensaje.setText("Guardar asistencias");
    mensaje.setInformativeText("¿Desea guardar?");
    //no funcionaron las opciones
    mensaje.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Discard);
    mensaje.setStandardButtons(QMessageBox::Save);

    int resultado = mensaje.exec();

    if (resultado == QMessageBox::Save) {

        qDebug() << "SE GUARDÓ CORRECTAMENTE LA ASISTENCIA";

        QString fecha_actual = ui->lineEditFecha->text();

        for (int i = 0; i < listadoAlumnos.size();i++){
            Alumno aux = listadoAlumnos[i];
            QString consulta;
            consulta.append("INSERT INTO asistencias(fk_alumno, fecha,concepto) "
                             "VALUES("
                            + QString::number(aux.getId()) +
                            ",'" + fecha_actual + "',"
                            + QString::number(aux.getConcepto()) +
                            ");"
                            );

            QSqlQuery insertar;
            insertar.prepare(consulta);

            if (insertar.exec())
            {
                qDebug()<<"Se agregó correctamente el alumno";


            }else{
                qDebug()<<"ERROR, no se ha agregado correctamente alumno";
                qDebug()<<"ERROR!"<< insertar.lastError();
            }
        }


    } else {
        qDebug() << "SE CANCELÓ";

    }




}

bool dialogTomarAsistencia::mostrarAlumno(int num)
{
    if (num>=listadoAlumnos.size()) {

        return false;
    }
    else {

        Alumno aux = listadoAlumnos[num];

        ui->lineEditAlumno->setText(aux.getApellido()+" "+aux.getNombres());
        return true;
    }
}

void dialogTomarAsistencia::asignarAsistencia(int num, int concepto)
{
    Alumno aux = listadoAlumnos[num];
    aux.setConcepto(concepto);
}

void dialogTomarAsistencia::on_pushButtonPresente_clicked()
{
    asignarAsistencia(contador,1);
    contador++;
    //si el contador es mayor al número de alumnos devuelve falso
    if (mostrarAlumno(contador)==false){
        guardarAsistencia();
    }
}

void dialogTomarAsistencia::on_pushButtonAusente_clicked()
{

    asignarAsistencia(contador,0);
    contador++;

    //si el contador es mayor al número de alumnos devuelve falso
    if (mostrarAlumno(contador)==false){
        guardarAsistencia();
    }
}

void dialogTomarAsistencia::on_pushButtonJustificada_clicked()
{
    asignarAsistencia(contador,2);
    contador++;
    //si el contador es mayor al número de alumnos devuelve falso
    if (mostrarAlumno(contador)==false){
        guardarAsistencia();
    }
}

void dialogTomarAsistencia::on_pushButtonAtras_clicked()
{
    if (contador >0) {
        contador --;
        mostrarAlumno(contador);
    }
}
