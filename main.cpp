#include <iostream>
#include "SistemaTinder.h"

void mostrarMenuPrincipal();
void gestionarPerfil(SistemaTinder& sistema, int usuarioIndex);
void gestionarContactos(SistemaTinder& sistema, int usuarioIndex);
void importarContactos(SistemaTinder& sistema);

int main() {
    SistemaTinder sistema;
    int opcion;
    int usuarioIndex;

    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el indice del usuario (0-2): ";
                std::cin >> usuarioIndex;
                if (usuarioIndex < 0 || usuarioIndex >= sistema.getUsuariosSize()) {
                    std::cout << "Indice de usuario no valido. Intente de nuevo." << std::endl;
                } else {
                    gestionarPerfil(sistema, usuarioIndex);
                }
                break;
            case 2:
                std::cout << "Ingrese el indice del usuario (0-2): ";
                std::cin >> usuarioIndex;
                if (usuarioIndex < 0 || usuarioIndex >= sistema.getUsuariosSize()) {
                    std::cout << "Indice de usuario no valido. Intente de nuevo." << std::endl;
                } else {
                    gestionarContactos(sistema, usuarioIndex);
                }
                break;
            case 3:
                importarContactos(sistema);
                break;
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
    std::cout << "======================" << std::endl;
    std::cout << "     Menu Principal   " << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "1. Gestionar Perfil" << std::endl;
    std::cout << "2. Gestionar Contactos" << std::endl;
    std::cout << "3. Importar Contactos" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

void gestionarPerfil(SistemaTinder& sistema, int usuarioIndex) {
    int opcion;

    std::cout << "======================" << std::endl;
    std::cout << "   Gestion de Perfil  " << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "1. Ver Perfil" << std::endl;
    std::cout << "2. Modificar Perfil" << std::endl;
    std::cout << "0. Volver al Menu Principal" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
        case 1: {
            Usuario& usuario = sistema.obtenerUsuario(usuarioIndex);
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

            Usuario& usuario = sistema.obtenerUsuario(usuarioIndex);
            usuario = Usuario(nombre, edad, genero, ubicacion, intereses);
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void gestionarContactos(SistemaTinder& sistema, int usuarioIndex) {
    int opcion;
    do {
        std::cout << "======================" << std::endl;
        std::cout << "  Gestion de Contactos" << std::endl;
        std::cout << "======================" << std::endl;
        std::cout << "1. Agregar Contacto" << std::endl;
        std::cout << "2. Modificar Contacto" << std::endl;
        std::cout << "3. Buscar Contacto" << std::endl;
        std::cout << "4. Eliminar Contacto" << std::endl;
        std::cout << "5. Mostrar Contactos" << std::endl;
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
                sistema.obtenerUsuario(usuarioIndex).agregarContacto(nuevoContacto);
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
                sistema.obtenerUsuario(usuarioIndex).modificarContacto(pos, nuevoContacto);
                break;
            }
            case 3: {
                std::string nombre;
                std::cout << "Ingrese el nombre del contacto a buscar: ";
                std::cin >> nombre;
                Usuario& usuario = sistema.obtenerUsuario(usuarioIndex);
                bool encontrado = false;
                for (int i = 0; i < usuario.getContactosSize(); i++) {
                    Contacto contacto = usuario.obtenerContacto(i);
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
                sistema.obtenerUsuario(usuarioIndex).eliminarContacto(pos);
                break;
            }
            case 5: {
                Usuario& usuario = sistema.obtenerUsuario(usuarioIndex);
                usuario.mostrarContactos();
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 0);
}

void importarContactos(SistemaTinder& sistema) {
    int origen, destino;
    std::cout << "Ingrese el indice del usuario origen (0-2): ";
    std::cin >> origen;
    std::cout << "Ingrese el indice del usuario destino (0-2): ";
    std::cin >> destino;

    if (origen < 0 || origen >= sistema.getUsuariosSize() || destino < 0 || destino >= sistema.getUsuariosSize()) {
        std::cout << "Indices de usuario no validos. Intente de nuevo." << std::endl;
    } else {
        sistema.importarContactos(origen, destino);
        std::cout << "Contactos importados exitosamente." << std::endl;
    }
}