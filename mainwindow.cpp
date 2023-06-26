#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cliente.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QDataStream"
#include "acercadelprograma.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FiltracionDatos_v001)
{
    ui->setupUi(this);
    // Asignar punteros a los QLineEdit
    // Asignar punteros a los QLineEdit
    lineEditNombre = ui->lineEditNombre;
    lineEditCedula = ui->lineEditCedula;
    lineEditDireccion = ui->lineEditDireccion;
    lineEditTelefono = ui->lineEditTelefono;
    lineEditCiudad = ui->lineEditCiudad;
    lineEditCorreo = ui->lineEditCorreo;

    // Conectar el QPushButton a la función procesarDatos()
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::procesarDatos);
}
void MainWindow::procesarDatos()
{
    QString datos = ui->plainTextEdit->toPlainText(); // Obtener datos del QPlainTextEdit

    // Dividir la cadena en filas
    QStringList filas = datos.split("\n");

    // Verificar si hay al menos 6 filas de datos
    if (filas.size() >= 6) {
        Cliente cliente(filas[0].mid(filas[0].indexOf(": ") + 2),
                        filas[1].mid(filas[1].indexOf(": ") + 2),
                        filas[5].mid(filas[5].indexOf(": ") + 2));

        // Realizar las validaciones
        cliente.validarNombre();
        bool esCedulaValida = cliente.validarCedula();
        cliente.validarCorreo();

        // Mostrar información validada en los QLineEdit correspondientes
        lineEditNombre->setText(cliente.getNombre());
        lineEditCedula->setText(cliente.getCedula());
        lineEditDireccion->setText(filas[2].mid(filas[2].indexOf(": ") + 2));
        lineEditTelefono->setText(filas[3].mid(filas[3].indexOf(": ") + 2));
        lineEditCiudad->setText(filas[4].mid(filas[4].indexOf(": ") + 2));
        lineEditCorreo->setText(cliente.getCorreo());

        if (!esCedulaValida) {
            QMessageBox::warning(this, "Advertencia", "La cédula debe tener 10 dígitos");
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Guardar Archivo", QString(), "Archivos Binarios (*.bin)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            QDataStream out(&file);
            out << ui->plainTextEdit->toPlainText();
            file.close();
            QMessageBox::information(this, "Guardar Archivo", "Archivo guardado correctamente.");
        } else {
            QMessageBox::warning(this, "Guardar Archivo", "No se pudo abrir el archivo para escritura.");
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{

    QString filePath = QFileDialog::getOpenFileName(this, "Abrir Archivo", QString(), "Archivos Binarios (*.bin)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QDataStream in(&file);
            QString data;
            in >> data;
            file.close();
            ui->plainTextEdit->setPlainText(data);

            QMessageBox messageBox(this);
            messageBox.setWindowTitle("Abrir Archivo");
            messageBox.setText("Archivo abierto correctamente.");
            //por alguna razon si no pongo que la letra sea negra e mensaje salta con letras blancas ¿?
            messageBox.setStyleSheet("QLabel { color: black; }");
            messageBox.exec();
        } else {
            QMessageBox::warning(this, "Abrir Archivo", "No se pudo abrir el archivo para lectura.");
        }
    }
}
void MainWindow::on_actionAcerca_del_programa_triggered()
{
    AcercaDelPrograma ventana;
    ventana.exec();
}
void MainWindow::on_pushButton_clicked()
{
    //puesto sin querer y ahora no se como se borra sin crashear el codigo
}
