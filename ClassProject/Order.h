#include <iostream>
#include <stack>

template<typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent; // Nuevo miembro que apunta al nodo padre

    Node(T value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    Node<T>* root;

    // Función auxiliar para liberar la memoria de forma recursiva.
    void DestroyRecursive(Node<T>* node) {
        if (node) {
            DestroyRecursive(node->left); // Liberar memoria de subárbol izquierdo recursivamente.
            DestroyRecursive(node->right); // Liberar memoria de subárbol derecho recursivamente.
            delete node; // Liberar el nodo actual.
        }
    }

    // Función auxiliar para insertar un nodo en el árbol de forma recursiva.
    Node<T>* InsertRecursive(Node<T>* current, Node<T>* parent, T value) {
        if (!current)
            return new Node<T>(value); // Creamos un nuevo nodo si alcanzamos un nodo nulo.

        // Actualizar el puntero parent del nuevo nodo.
        Node<T>* newNode = nullptr;
        if (value < current->data) {
            newNode = InsertRecursive(current->left, current, value); // Insertar en subárbol izquierdo recursivamente.
            current->left = newNode; // Establecer el puntero left del nodo actual.
        }
        else if (value > current->data) {
            newNode = InsertRecursive(current->right, current, value); // Insertar en subárbol derecho recursivamente.
            current->right = newNode; // Establecer el puntero right del nodo actual.
        }

        if (newNode)
            newNode->parent = current; // Establecer el puntero parent del nuevo nodo.

        return current;
    }

public:
    BinaryTree() : root(nullptr) {}

    // Destructor: libera la memoria de todos los nodos.
    ~BinaryTree() {
        DestroyRecursive(root);
    }

    // Inserta un valor en el árbol binario.
    void Insert(T value) {
        root = InsertRecursive(root, nullptr, value); // Llamada a la función auxiliar de inserción.
    }

    // Obtiene el nodo predecesor (el que va antes de in_x, según de data) en el árbol.
    Node<T>* Predecessor(Node<T>* in_x) {
        if (!in_x)
            return nullptr;

        // Si el nodo tiene un hijo izquierdo, el predecesor será el nodo más a la derecha de ese hijo.
        if (in_x->left) {
            Node<T>* temp = in_x->left;
            while (temp->right)
                temp = temp->right;
            return temp;
        }

        // Si no tiene hijo izquierdo, buscamos el ancestro más cercano cuyo hijo derecho sea el nodo actual.
        Node<T>* parent = in_x->parent;
        while (parent && in_x == parent->left) {
            in_x = parent;
            parent = parent->parent;
        }

        return parent;
    }

    // Versión iterativa (es decir, no recursiva) de la función InOrder. Debe imprimir lo mismo.
    void InOrderIterative() {
        if (!root) return;

        std::stack<Node<T>*> s;
        Node<T>* current = root;

        while (!s.empty() || current) {
            if (current) {
                s.push(current); // Apilamos el nodo actual y avanzamos hacia el hijo izquierdo.
                current = current->left;
            }
            else {
                current = s.top(); // Cuando no hay más hijos izquierdos, imprimimos el nodo actual y avanzamos al hijo derecho.
                s.pop();
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }

    // Versión iterativa (es decir, no recursiva) de la función PreOrder. Debe imprimir lo mismo.
    void PreOrderIterative() {
        if (!root) return;

        std::stack<Node<T>*> s;
        s.push(root);

        while (!s.empty()) {
            Node<T>* current = s.top(); // Sacamos el nodo de la cima de la pila.
            s.pop();

            std::cout << current->data << " "; // Imprimimos el valor del nodo actual.

            if (current->right) s.push(current->right); // Apilamos el hijo derecho antes que el izquierdo para mantener el orden correcto.
            if (current->left) s.push(current->left);
        }
    }

    // Versión iterativa (es decir, no recursiva) de la función PostOrder. Debe imprimir lo mismo.
    void PostOrderIterative() {
        if (!root) return;

        std::stack<Node<T>*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node<T>* current = s1.top(); // Sacamos el nodo de la cima de la primera pila.
            s1.pop();
            s2.push(current); // Luego, lo apilamos en la segunda pila.

            if (current->left) s1.push(current->left); // Apilamos el hijo izquierdo antes que el derecho.
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            Node<T>* current = s2.top(); // Sacamos el nodo de la cima de la segunda pila.
            s2.pop();
            std::cout << current->data << " "; // Imprimimos el valor del nodo actual.
        }
    }

    // Agregar este método en la clase BinaryTree
    // Obtiene el nodo raíz del árbol.
    Node<T>* GetRoot() const {
        return root;
    }
};


//Conultas de Paginas para dar referencia al codigo 
//InOrderIterative
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
//PreOrderIterative
//https://www.geeksforgeeks.org/iterative-preorder-traversal/
//PostOrderIterative
//https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/

//NOTA IMPORTANTE 

//NO PUDE TOMAR EL CODIGO Y IMPLEMENTARLO EN EL ARCHIVO BINARYTREE.H PORQUE EL CODIGO QUE MI EQUIPO CREO HACE MUCHO CONFLICTO CON EL CODIGO YA ESTABLECIDO DENTRO DE ESE ARCHIVO
//DANDO ASI ERRORES COMO DUPLICACION DE VARIABLES, FUNCIONES ETC Y SE NOS HIZO MAS SENCILLO Y MENOS MOLESTO CREAR UN NUEVO APARTADO DONDE SE PUSO Y CREO EL CODIGO MOSTRADO
//TRATAMOS DE TODO Y BUENO SE NOS ACABO EL TIEMPO ASI QUE ESE PUNTO SI TENDREMOS QUE DEJARLO ASI.




