#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertar_datos_cola(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    Node* pos(int index) const {
        if (index < 0 || index >= size) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void eliminar_dato(int index) {
        if (index < 0 || index >= size) return;
        Node* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            Node* prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
        size--;
    }

    int get_size() const {
        return size;
    }
};

#endif // LINKEDLIST_H