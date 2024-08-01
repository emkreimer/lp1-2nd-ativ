#ifndef NODE_H
#define NODE_H

template <typename T> struct Node {
    T content;
    Node* next;
    Node(T val) : content(val), next(nullptr) {}
};

#endif