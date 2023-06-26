#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class FiltracionDatos_v001; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::FiltracionDatos_v001 *ui;
    QLineEdit* lineEditNombre;
    QLineEdit* lineEditCedula;
    QLineEdit* lineEditDireccion;
    QLineEdit* lineEditTelefono;
    QLineEdit* lineEditCiudad;
    QLineEdit* lineEditCorreo;

private slots:
    void procesarDatos();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_actionAcerca_del_programa_triggered();
};

#endif // MAINWINDOW_H
