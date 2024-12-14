#include <iostream>
#include "SistemaTinder.h"

void mostrarMenuPrincipal();
void gestionarPerfil(SistemaTinder& sistema);
void gestionarContactos(SistemaTinder& sistema, int usuarioIndex);

int main() {
    SistemaTinder sistema;
    int opcion;

    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarPerfil(sistema);
                break;
            case 2: {
                int usuarioIndex;
                std::cout << "Ingrese el indice del usuario (0-2): ";
                std::cin >> usuarioIndex;
                gestionarContactos(sistema, usuarioIndex);
                break;
            }
            case 0:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 0);

    return 0;
}

void mostrarMenuPrincipal() {
    std::cout << "Menu Principal" << std::endl;
    std::cout << "1. Gestionar Perfil" << std::endl;
    std::cout << "2. Gestionar Contactos" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

void gestionarPerfil(SistemaTinder& sistema) {
    int opcion;
    int usuarioIndex;
    std::cout << "Ingrese el indice del usuario (0-2): ";
    std::cin >> usuarioIndex;

    std::cout << "Gestion de Perfil" << std::endl;
    std::cout << "1. Ver Perfil" << std::endl;
    std::cout << "2. Modificar Perfil" << std::endl;
    std::cout << "0. Volver al Menu Principal" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
        case 1: {
            Usuario& usuario = sistema.obtener_usuario(usuarioIndex);
            std::cout << "Nombre: " << usuario.getNombre() << std::endl;
            std::cout << "Edad: " << usuario.getEdad() << std::endl;
            std::cout << "Genero: " << usuario.getGenero() << std::endl;
            std::cout << "Ubicacion: " << usuario.getUbicacion() << std::endl;
            std::cout << "Intereses: " << usuario.getIntereses() << std::endl;
            break;
        }
        case 2: {
            std::string nombre, edad, genero, ubicacion, intereses;
            std::cout << "Ingrese nuevo nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese nueva edad: ";
            std::cin >> edad;
            std::cout << "Ingrese nuevo genero: ";
            std::cin >> genero;
            std::cout << "Ingrese nueva ubicacion: ";
            std::cin >> ubicacion;
            std::cout << "Ingrese nuevos intereses: ";
            std::cin >> intereses;

            Usuario& usuario = sistema.obtener_usuario(usuarioIndex);
            usuario = Usuario(nombre, edad, genero, ubicacion, intereses);
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void gestionarContactos(SistemaTinder& sistema, int usuarioIndex) {
    int opcion;
    do {
        std::cout << "Gestion de Contactos" << std::endl;
        std::cout << "1. Agregar Contacto" << std::endl;
        std::cout << "2. Modificar Contacto" << std::endl;
        std::cout << "3. Buscar Contacto" << std::endl;
        std::cout << "4. Eliminar Contacto" << std::endl;
        std::cout << "0. Volver al Menu Principal" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, edad, genero, ubicacion, intereses;
                std::cout << "Ingrese nombre: ";
                std::cin >> nombre;
                std::cout << "Ingrese edad: ";
                std::cin >> edad;
                std::cout << "Ingrese genero: ";
                std::cin >> genero;
                std::cout << "Ingrese ubicacion: ";
                std::cin >> ubicacion;
                std::cout << "Ingrese intereses: ";
                std::cin >> intereses;
                Contacto nuevoContacto(nombre, edad, genero, ubicacion, intereses);
                sistema.obtener_usuario(usuarioIndex).agregar_contacto(&nuevoContacto);
                break;
            }
            case 2: {
                int pos;
                std::string nombre, edad, genero, ubicacion, intereses;
                std::cout << "Ingrese la posicion del contacto a modificar: ";
                std::cin >> pos;
                std::cout << "Ingrese nuevo nombre: ";
                std::cin >> nombre;
                std::cout << "Ingrese nueva edad: ";
                std::cin >> edad;
                std::cout << "Ingrese nuevo genero: ";
                std::cin >> genero;
                std::cout << "Ingrese nueva ubicacion: ";
                std::cin >> ubicacion;
                std::cout << "Ingrese nuevos intereses: ";
                std::cin >> intereses;
                Contacto nuevoContacto(nombre, edad, genero, ubicacion, intereses);
                sistema.obtener_usuario(usuarioIndex).modificar_contacto(pos, &nuevoContacto);
                break;
            }
            case 3: {
                std::string nombre;
                std::cout << "Ingrese el nombre del contacto a buscar: ";
                std::cin >> nombre;
                Usuario& usuario = sistema.obtener_usuario(usuarioIndex);
                bool encontrado = false;
                for (int i = 0; i < usuario.getContactosSize(); i++) {
                    Contacto contacto = usuario.obtener_contacto(i);
                    if (contacto.getNombre() == nombre) {
                        std::cout << "Contacto encontrado: " << contacto.getNombre() << ", " << contacto.getEdad() << ", " << contacto.getGenero() << ", " << contacto.getUbicacion() << ", " << contacto.getIntereses() << std::endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Contacto no encontrado." << std::endl;
                }
                break;
            }
            case 4: {
                int pos;
                std::cout << "Ingrese la posicion del contacto a eliminar: ";
                std::cin >> pos;
                sistema.obtener_usuario(usuarioIndex).eliminar_contacto(pos);
                break;
            }
            case 0:
                return;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 0);
}