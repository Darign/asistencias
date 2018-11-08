#include "gestionalumnos.h"
#include "ui_gestionalumnos.h"

GestionAlumnos::GestionAlumnos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionAlumnos)
{
    ui->setupUi(this);
}

GestionAlumnos::~GestionAlumnos()
{
    delete ui;
}
