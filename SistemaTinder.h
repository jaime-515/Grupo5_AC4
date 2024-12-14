//
// Created by jaime on 12/12/2024.
//

#ifndef SISTEMATINDER_H
#define SISTEMATINDER_H

#include "Usuario.h"
#include "LinkedList.h"

class SistemaTinder {
private:
    LinkedList<Usuario> usuarios;

public:
    SistemaTinder() {
        //Inicializar con 3 usuarios y 5 contactos cada uno
        Usuario usuario1("Luis", "24", "Masculino", "Toledo", "Programar");
        Usuario usuario2("Ana", "22", "Femenino", "Madrid", "Leer");
        Usuario usuario3("Pedro", "26", "Masculino", "Barcelona", "Cocinar");

        //Contactos de usuario1
        Contacto contacto1("Maria", "23", "Femenino", "Toledo", "Programar");
        Contacto contacto2("Juan", "25", "Masculino", "Toledo", "Programar");
        Contacto contacto3("Sara", "24", "Femenino", "Toledo", "Programar");
        Contacto contacto4("Carlos", "23", "Masculino", "Toledo", "Programar");
        Contacto contacto5("Laura", "22", "Femenino", "Toledo", "Programar");

        //Contactos de usuario2
        Contacto contacto6("Miguel", "24", "Masculino", "Madrid", "Leer");
        Contacto contacto7("Elena", "23", "Femenino", "Madrid", "Leer");
        Contacto contacto8("Pablo", "25", "Masculino", "Madrid", "Leer");
        Contacto contacto9("Carmen", "24", "Femenino", "Madrid", "Leer");
        Contacto contacto10("Javier", "23", "Masculino", "Madrid", "Leer");

        //Contactos de usuario3
        Contacto contacto11("Isabel", "26", "Femenino", "Barcelona", "Cocinar");
        Contacto contacto12("Antonio", "25", "Masculino", "Barcelona", "Cocinar");
        Contacto contacto13("Rosa", "24", "Femenino", "Barcelona", "Cocinar");
        Contacto contacto14("Manuel", "23", "Masculino", "Barcelona", "Cocinar");
        Contacto contacto15("Sergio", "22", "Masculino", "Barcelona", "Cocinar");

        //Agregar contactos a los usuarios
        usuario1.agregar_contacto(&contacto1);
        usuario1.agregar_contacto(&contacto2);
        usuario1.agregar_contacto(&contacto3);
        usuario1.agregar_contacto(&contacto4);
        usuario1.agregar_contacto(&contacto5);

        usuario2.agregar_contacto(&contacto6);
        usuario2.agregar_contacto(&contacto7);
        usuario2.agregar_contacto(&contacto8);
        usuario2.agregar_contacto(&contacto9);
        usuario2.agregar_contacto(&contacto10);

        usuario3.agregar_contacto(&contacto11);
        usuario3.agregar_contacto(&contacto12);
        usuario3.agregar_contacto(&contacto13);
        usuario3.agregar_contacto(&contacto14);
        usuario3.agregar_contacto(&contacto15);

        // Agregar usuarios a la lista de usuarios
        usuarios.insertar_datos_cola(usuario1);
        usuarios.insertar_datos_cola(usuario2);
        usuarios.insertar_datos_cola(usuario3);
    }

    Usuario& obtener_usuario(int pos) {
        return usuarios.pos(pos)->data;
    }

    void importar_contactos(int origen, int destino) {
        Usuario& usuarioOrigen = obtener_usuario(origen);
        Usuario& usuarioDestino = obtener_usuario(destino);

        for (int i = 0; i < usuarioOrigen.getContactosSize(); i++) {
            Contacto contacto = usuarioOrigen.obtener_contacto(i);
            if (!esDuplicado(usuarioDestino, contacto)) {
                usuarioDestino.agregar_contacto(&contacto);
            }
        }
    }

    bool esDuplicado(Usuario& usuario, Contacto& contacto) {
        for (int i = 0; i < usuario.getContactosSize(); i++) {
            Contacto c = usuario.obtener_contacto(i);
            if (c.getNombre() == contacto.getNombre() && c.getEdad() == contacto.getEdad() &&
                c.getGenero() == contacto.getGenero() && c.getUbicacion() == contacto.getUbicacion() &&
                c.getIntereses() == contacto.getIntereses()) {
                return true;
                }
        }
        return false;
    }
};
#endif //SISTEMATINDER_H
