#ifndef GESTIONALUMNOS_H
#define GESTIONALUMNOS_H

#include <QMainWindow>

namespace Ui {
class GestionAlumnos;
}

class GestionAlumnos : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionAlumnos(QWidget *parent = 0);
    ~GestionAlumnos();

private:
    Ui::GestionAlumnos *ui;
};

#endif // GESTIONALUMNOS_H
