#pragma once

#include <iostream>
#include <stack>

template<typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    Node<T>* root;

    // Funci�n auxiliar para liberar la memoria de forma recursiva.
    void DestroyRecursive(Node<T>* node) {
        if (node) {
            DestroyRecursive(node->left);
            DestroyRecursive(node->right);
            delete node;
        }
    }

    // Funci�n auxiliar para insertar un nodo en el �rbol de forma recursiva.
    Node<T>* InsertRecursive(Node<T>* current, T value) {
        if (!current)
            return new Node<T>(value);

        if (value < current->data)
            current->left = InsertRecursive(current->left, value);
        else if (value > current->data)
            current->right = InsertRecursive(current->right, value);

        return current;
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        DestroyRecursive(root);
    }

    // Inserta un valor en el �rbol binario.
    void Insert(T value) {
        root = InsertRecursive(root, value);
    }

    // Obtiene el nodo predecesor (el que va antes de in_x, seg�n de data) en el �rbol.
    Node<T>* Predecessor(Node<T>* in_x) {
        // Implementaci�n de la funci�n Predecessor.
        // ...
    }

    // Versi�n iterativa (es decir, no recursiva) de la funci�n InOrder. Debe imprimir lo mismo.
    void InOrderIterative() {
        if (!root) return;

        std::stack<Node<T>*> s;
        Node<T>* current = root;

        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current->left;
            }
            else {
                current = s.top();
                s.pop();
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }

    // Versi�n iterativa (es decir, no recursiva) de la funci�n PreOrder. Debe imprimir lo mismo.
    void PreOrderIterative() {
        if (!root) return;

        std::stack<Node<T>*> s;
        s.push(root);

        while (!s.empty()) {
            Node<T>* current = s.top();
            s.pop();

            std::cout << current->data << " ";

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

    // Versi�n iterativa (es decir, no recursiva) de la funci�n PostOrder. Debe imprimir lo mismo.
    void PostOrderIterative() {
        if (!root) return;

        std::stack<Node<T>*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node<T>* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            Node<T>* current = s2.top();
            s2.pop();
            std::cout << current->data << " ";
        }
    }


};