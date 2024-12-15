#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdio>

template <typename T>
class LinkedList {
protected:
    class Node {
    public:
        T data;
        Node *next;

        Node(T data) : data(data), next(nullptr) {}
        Node(T data, Node *next) : data(data), next(next) {}
    };
private:
    Node* first;
    Node* last;
    int size;

public:
    LinkedList() : first(nullptr), last(nullptr), size(0) {}

    int get_size() const {return size;}

    void insertar_datos_cabeza(T dato) {
        Node* newNode = new Node(dato);
        if (es_vacio_ptr()) {
            last = newNode;
        }
        newNode->next = first;
        first = newNode;
        size++;
    }

    void insertar_datos_cola(T dato) {
        Node* newNode = new Node(dato);
        if (es_vacio_count()) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        size++;
    }

    void insertar_datos_entre_nodos(T dato, int pos) {
        if (pos < size) {
            if (pos == 0) {insertar_datos_cabeza(dato);}
            else if (pos == size - 1) {insertar_datos_cola(dato);}
            else {
                Node* newNode = new Node(dato);
                Node* aux = first;
                for (int i = 1; i < pos - 1; i++) {
                    aux = aux->next;
                }
                newNode->next = aux->next;
                aux->next = newNode;
                size++;
            }
        } else {
            printf("Posicion no valida\n");
        }
    }

    // Método para insertar en el centro de la lista
    void insertar_datos_en_centro(T data) {
        Node* newNode = new Node(data);
        if (es_vacio_count()) {
            first = newNode;
            last = newNode;
        } else {
            Node* aux = first;
            int pos = size / 2;
            if (pos == 0) {
                newNode->next = first;
                first = newNode;
            } else {
                for (int i = 1; i < pos; i++) {
                    aux = aux->next;
                }
                newNode->next = aux->next;
                aux->next = newNode;
            }
        }
        size++;
    }

    T quitar_cabeza() {
        T dato;
        if (!es_vacio_ptr()) {
            Node* aux = first;
            first = first->next;
            size--;
            dato = aux->data;
            delete aux;
        }
        return dato;
    }

    T quitar_cola() {
        T dato;
        if (!es_vacio_ptr()) {
            Node* aux = first;
            while (aux->next != last) {
                aux = aux->next;
            }
            dato = last->data;
            delete last;
            last = aux;
            size--;
        }
        return dato;
    }

    T quitar_entre_nodos(int pos) {
        T dato;
        if (pos < size) {
            if (pos == 0) {dato = quitar_cabeza();}
            else if (pos == size - 1) {dato = quitar_cola();}
            else {
                Node* aux = first;
                for (int i = 1; i < pos - 1; i++) {
                    aux = aux->next;
                }
                dato = aux->next->data;
                Node* aux2 = aux->next->next;
                delete aux->next;
                aux->next = aux2;
                size--;
            }
        } else {
            printf("Posicion no valida\n");
        }
        return dato;
    }

    Node* pos(int pos) const {
        Node* aux;
        if (pos < size) {
            aux = first;
            if (pos == 0) {}
            else if (pos == size - 1) {aux = last;}
            else {
                for (int i = 1; i < pos; i++) {
                    aux = aux->next;
                }
            }
        }
        return aux;
    }


    void toString() const {
        Node* temp = first;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool es_vacio_ptr() const {return first == nullptr;}

    bool es_vacio_count() const {return size == 0;}

    void liberar_memoria() {
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

};

#endif // LINKEDLIST_H