#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class Cliente
{
public:
    Cliente(const QString& nombre, const QString& cedula, const QString& correo);

    void validarNombre();
    bool validarCedula() const;
    void validarCorreo();
    void mostrarInformacion() const;

    // Getter para acceder a los datos validados
    QString getNombre() const { return m_nombre; }
    QString getCedula() const { return m_cedula; }
    QString getCorreo() const { return m_correo; }

private:
    QString m_nombre;
    QString m_cedula;
    QString m_correo;
};

#endif // CLIENTE_H

