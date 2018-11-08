#include "dialogtomarasistencia.h"
#include "ui_dialogtomarasistencia.h"

dialogTomarAsistencia::dialogTomarAsistencia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialogTomarAsistencia)
{
    ui->setupUi(this);
}

dialogTomarAsistencia::~dialogTomarAsistencia()
{
    delete ui;
}
