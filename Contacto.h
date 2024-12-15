#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>

class Contacto {
private:
    std::string nombre;
    std::string edad;
    std::string genero;
    std::string ubicacion;
    std::string intereses;

public:
    // Constructores
    Contacto() : nombre(""), edad(""), genero(""), ubicacion(""), intereses("") {}
    Contacto(std::string nombre, std::string edad, std::string genero, std::string ubicacion, std::string intereses) : nombre(nombre), edad(edad), genero(genero), ubicacion(ubicacion), intereses(intereses) {}

    // Getters
    std::string getNombre() {return nombre;}
    std::string getEdad() {return edad;}
    std::string getGenero() {return genero;}
    std::string getUbicacion() {return ubicacion;}
    std::string getIntereses() {return intereses;}
};

#endif //CONTACTO_H
