#include "controlasistencia.h"
#include "ui_controlasistencia.h"

ControlAsistencia::ControlAsistencia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlAsistencia)
{
    ui->setupUi(this);
}

ControlAsistencia::~ControlAsistencia()
{
    delete ui;
}
