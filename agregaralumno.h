#ifndef AGREGARALUMNO_H
#define AGREGARALUMNO_H

#include <QDialog>

namespace Ui {
class AgregarAlumno;
}

class AgregarAlumno : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarAlumno(QWidget *parent = 0);
    ~AgregarAlumno();

private:
    Ui::AgregarAlumno *ui;
};

#endif // AGREGARALUMNO_H
