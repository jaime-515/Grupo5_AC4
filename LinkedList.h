//
// Created by jaime on 12/12/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
protected:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;
};

#endif //LINKEDLIST_H
