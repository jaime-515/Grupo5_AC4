#ifndef USUARIO_H
#define USUARIO_H

#include "Contacto.h"
#include "LinkedList.h"
#include <string>

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

    void agregarContacto(const Contacto& contacto) {
        contactos.insertar_datos_cola(contacto);
    }

    void modificarContacto(int pos, const Contacto& contacto) {
        auto* aux = contactos.pos(pos);
        if (aux) {
            aux->data = contacto;
        }
    }

    Contacto obtenerContacto(int pos) const {
        return contactos.pos(pos)->data;
    }

    void eliminarContacto(int pos) {
        contactos.quitar_entre_nodos(pos);
    }

    int getContactosSize() const {
        return contactos.get_size();
    }

    void mostrarContactos() const {
        for (int i = 0; i < contactos.get_size(); i++) {
            Contacto contacto = contactos.pos(i)->data;
            std::cout << "Contacto " << i + 1 << ": " << contacto.getNombre() << ", " << contacto.getEdad() << ", " << contacto.getGenero() << ", " << contacto.getUbicacion() << ", " << contacto.getIntereses() << std::endl;
        }
    }
};

#endif // USUARIO_H