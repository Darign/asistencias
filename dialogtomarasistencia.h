#ifndef DIALOGTOMARASISTENCIA_H
#define DIALOGTOMARASISTENCIA_H

#include <QMainWindow>

namespace Ui {
class dialogTomarAsistencia;
}

class dialogTomarAsistencia : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialogTomarAsistencia(QWidget *parent = 0);
    ~dialogTomarAsistencia();

private:
    Ui::dialogTomarAsistencia *ui;
};

#endif // DIALOGTOMARASISTENCIA_H
