#ifndef EDITARALUMNO_H
#define EDITARALUMNO_H

#include <QDialog>

namespace Ui {
class EditarAlumno;
}

class EditarAlumno : public QDialog
{
    Q_OBJECT

public:
    explicit EditarAlumno(QWidget *parent = 0);
    ~EditarAlumno();

private:
    Ui::EditarAlumno *ui;
};

#endif // EDITARALUMNO_H
