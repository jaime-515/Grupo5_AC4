#ifndef USUARIO_H
#define USUARIO_H

#include "Contacto.h"
#include "LinkedList.h"

class Usuario {
private:
    std::string nombre;
    std::string edad;
    std::string genero;
    std::string ubicacion;
    std::string intereses;
    LinkedList<Contacto> contactos;

public:
    Usuario(std::string nombre, std::string edad, std::string genero, std::string ubicacion, std::string intereses)
        : nombre(nombre), edad(edad), genero(genero), ubicacion(ubicacion), intereses(intereses) {}

    std::string getNombre() const { return nombre; }
    std::string getEdad() const { return edad; }
    std::string getGenero() const { return genero; }
    std::string getUbicacion() const { return ubicacion; }
    std::string getIntereses() const { return intereses; }

    void agregar_contacto(Contacto* contacto) {
        contactos.insertar_datos_cola(*contacto);
    }

    void modificar_contacto(int pos, Contacto* contacto) {
        auto* aux = contactos.pos(pos);
        if (aux) {
            aux->data = *contacto;
        }
    }

    Contacto obtener_contacto(int pos) {
        auto* aux = contactos.pos(pos);
        if (aux) {
            return aux->data;
        }
        throw std::out_of_range("Invalid contact position");
    }

    void eliminar_contacto(int pos) {
        contactos.eliminar_dato(pos);
    }

    int getContactosSize() const {
        return contactos.get_size();
    }
};

#endif // USUARIO_H