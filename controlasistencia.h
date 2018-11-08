#ifndef CONTROLASISTENCIA_H
#define CONTROLASISTENCIA_H

#include <QMainWindow>

namespace Ui {
class ControlAsistencia;
}

class ControlAsistencia : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlAsistencia(QWidget *parent = 0);
    ~ControlAsistencia();

private:
    Ui::ControlAsistencia *ui;
};

#endif // CONTROLASISTENCIA_H
