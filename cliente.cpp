#include "cliente.h"
#include <QDebug>

Cliente::Cliente(const QString& nombre, const QString& cedula, const QString& correo) :
    m_nombre(nombre), m_cedula(cedula), m_correo(correo) {}

void Cliente::validarNombre() {
    // Verificar que la primera letra del nombre sea mayúscula
    if (!m_nombre.isEmpty() && m_nombre[0].isLower()) {
        // Convertir la primera letra a mayúscula
        m_nombre[0] = m_nombre[0].toUpper();
    }
}

bool Cliente::validarCedula() const {
    // Verificar que la cédula tenga exactamente 10 dígitos
    if (m_cedula.length() != 10) {
        qDebug() << "Advertencia: La cédula debe tener 10 dígitos";
        return false;
    }
    return true;
}

void Cliente::validarCorreo() {
    // Convertir todo el texto del correo a minúsculas
    m_correo = m_correo.toLower();
}

void Cliente::mostrarInformacion() const {
    qDebug() << "Nombre: " << m_nombre;
    qDebug() << "Cédula: " << m_cedula;
        qDebug() << "Correo: " << m_correo;
}
