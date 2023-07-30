// ClassProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// En C++ solo se usan los archivos de código que se referencien en el main a través del include.
#include <iostream>
// i input
// o output
// stream

#include "Array.h"
#include "TArray.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "List.h"
#include "DList.h"
#include "Order.h"
// #include "../include/Array.h"
// #include "Triage.h"



#define MY_NULL 0
// #define TV NVIDIA

// #if TV == NVIDIA
// hacen esto porque es tv nvidia

// #elif TV == AMD
// hacer esto porque es tv AMD-.

// A diferencia de Java, no es necesaria una clase para ejecutar código.
// El código inicia a partir de la función "main"

// Ya no es recomendado a menos que realmente vayas a usar mucho del namespace
// using namespace std;

// Definición:
// Generalmente se lleva a cabo en los archivos .cpp (c plus plus, o archivos de fuente)
int myFunction()
{
    return 0;
}


class myClass 
{
public:
    myClass()
    {
        x = 0;
        y = 0;
    }

    int x;
    int y;
};

class Triangle
{
public:
    Triangle()
    {
        Base = 0.0f;
        Height = 0.0f;
    }

    Triangle(float in_base, float in_height)
    {
        Base = in_base;
        Height = in_height;
    }

    float Base;
    float Height;

    float GetArea()
    {
        return Base * Height / 2.0f;
    }

    friend bool operator < (Triangle a, Triangle b)
    {
        return a.GetArea() < b.GetArea();
    }

    friend bool operator > (Triangle a, Triangle b)
    {
        return a.GetArea() > b.GetArea();
        // return b < a;
    }



};

void ClassesBeforeMay24()
{
    // Declaración
    int myDeclaration;
    // SCOPE
    // Generalmente en los archivos .h (header)
    // Inicialización:
    myDeclaration = 0;

    Triangle example = Triangle(2.0f, 5.0f);
    // example.Base = 2.0f;
    // example.Height = 5.0f;
    std::cout << example.GetArea() << '\n';

    char nullChar = NULL;
    int nullInt = NULL;
    bool nullBool = MY_NULL; // bool nullBool = 0;

    int x = 0;

    if (x == NULL)
    {
        std::cout << "sí entré" << '\n';
    }

    //if (x == 0)

    char nullCharPtr = NULL;
    char* nullptrCharPtr = nullptr;

    int BigArray[500][500] = { 0 };

    // int newInt = new int;  // este no es posible
    int myIntInstance = 4;
    int* newInt = &myIntInstance;
    *newInt = 5;
    std::cout << *newInt << '\n';
    // delete newInt;
    // std::cout << *newInt << '\n';

    int* Copion1 = newInt, * Copion2 = newInt;

    *newInt = 6;

    int* BigArrayPtr = new int[20000000];

    for (int i = 0; i < 100; i++)
    {
        delete[] BigArrayPtr;
        BigArrayPtr = new int[200000000];

    }
    int myInt = 5;

    // int j; // No está inicializado, no nos deja usarlo el compilador, traería basura.
    // c de console y out de salida: salida a consola
    // std::cout << i << '\n';
    // std::cout << j << '\n';

    int myArray[5] = { 0, 11, 22, 337, 45 };

    for (int i = 0; i < 5; i++)
    {
        std::cout << myArray[i] << '\n';
    }

    std::cout << &myInt << '\n';

    int* myAddress = &myInt;

    std::cout << "Dirección de memoria a que apunta MyAddress: " << myAddress << '\n';
    std::cout << "Valor de la variable a la que apunta MyAddress: " << *myAddress << '\n';

    std::cout << &myAddress << '\n';

    int** myAddressAddress = &myAddress;

    // myArray[iésimo] ~ *

    // myTable[][] ~ []* ~ **

    // c de consola, in de entrada: entrada a consola (cin)

    int* myArrayPtr = &myArray[0];

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Dirección de memoria de myArray[" << i << "] : " << myArrayPtr << '\n';

        std::cout << "Valor del objeto de myArray[" << i << "] : " << *myArrayPtr << '\n';

        ++myArrayPtr;
        ++myArrayPtr;
    }
}


// función por valor
// se genera una copia en una dirección de memoria distinta a la de la variable pasada a la función
int PlusOne(int a)
{
    a = a + 1;
    return a;
}

// función por referencia 
// es tal cual a la variable que pases, no a una copia
int PlusOneRef(int &a)
{
    a = a + 1;
    return a;
}

void ParametrosPorValorYPorReferencia()
{
    int myInt = 0;

    int PlusOneResult = PlusOne(myInt);

    std::cout << "myInt: " << myInt << '\n';  // 0

    std::cout << "PlusOneResult: " << PlusOneResult << '\n';  // 1

    int PlusOneRefResult = PlusOneRef(myInt);

    std::cout << "myInt: " << myInt << '\n'; // 1

    std::cout << "PlusOneRefResult: " << PlusOneRefResult << '\n'; // 1

    PlusOneRefResult = PlusOneRef(myInt);

    std::cout << "myInt: " << myInt << '\n';  // 2

    std::cout << "PlusOneRefResult: " << PlusOneRefResult << '\n'; // 2


    PlusOneResult = PlusOne(myInt);

    std::cout << "myInt: " << myInt << '\n';  // 2

    std::cout << "PlusOneResult: " << PlusOneResult << '\n';  // 3
}

//template <typename T1, typename T2>
//int Suma(T1 x, T2 b)
//{
//    
//}



// Nótese que el tipo de retorno es "int", pues devuelve un entero que representa el código
// de cómo terminó el programa, siendo 0 un término exitoso.
// En Java, main es de tipo "void", pues no retorna ningún valor.
int main()
{
    //TArray<float> myTArray = TArray<float>(10);
    //myTArray.Init(12.7f);
    //myTArray.Print();

    //int myInt = 5 + 8.3;


    RawArray test = RawArray(3);

    // Si ya pedimos los 5 ints de memoria dinámica, hay que asignarles un valor
    test.Init(0); // como el valor por defecto es 0, todos los ints serán 0.

    // comprobar que se les asignó el valor.
    test.Print();

    // Nosotros tenemos [0, 0, 0]

    test.AddElement(3);

    // Después del addElement, nuestro arreglo se debería ver así [0, 0, 0, 3]
    test.Print();

    // char myChar = 'a';
    // RawArray OtherArray = RawArray(5);
    // test.AddElement(OtherArray);

    ///* // si Size fuera 1000, no está tan descabellado.,
    //// pero 1000*1000 son 1000000...
    //// Size iteraciones, con Size operaciones cada una, por lo tanto, Size*Size operaciones.
    //for (int i = 0; i < test.Size; i++)
    //{
    //    test.RemoveLastElement(); // Size operaciones
    //}
    //test.~RawArray(); // lo haría en una llamada a delete*/


    // 1000
    // copiamos 999
    // copiamos 988
    // 997
    //..,
    // 1
    // 1000 + 1 = 1001
    // 999 + 2 = 1001
    // 998 + 3 = 1001
    // 1000/2
    // 1001 * 500 = 500500
    // n(n+1)/2 -> n^2 + n / 2, 
    // se dice que tiene una complejidad Big 0 de n^2 (de operaciones)
    // 100 -> 100^2
    // 1000000 -> 1000000^2


    //test.RemoveLastElement();
    //test.RemoveLastElement();
    //test.Print();

    //// Remove // size operaciones
    //// add // size operaciones
    //// remove // size operaciones
    //// remove // ...
    //// add
    //// ...

    Stack<char> MyStack = Stack<char>(3);
    // Stack<char> MyStack = Stack<char>(3, false);

    // Inicia vacía
    MyStack.Pop();

    // metemos elementos
    MyStack.Push('a');
    MyStack.Push('b');
    MyStack.Push('c');
    MyStack.Push('d');  // este va a causar un error de Overflow, porque solo pedimos 3 de Size.
    MyStack.Push('e');
    // MyStack. = 100;
    MyStack.Push('f');

    MyStack.Print();


    std::cout << "El tope de la Stack es: " << MyStack.Top() << '\n';




    // PRUEBAS DE QUEUE.
    Queue<char> MyQueue = Queue<char>(6);
    MyQueue.Enqueue('a');
    MyQueue.Enqueue('b');
    MyQueue.Enqueue('c');
    MyQueue.Enqueue('d');
    MyQueue.Enqueue('e');
    MyQueue.Enqueue('f');



    if (MyQueue.Full() == true)
    {
        std::cout << "la Queue está llena." << '\n';
    }

    //MyQueue.Enqueue('g');  // aquí va a entrar a incrementar el tamaoñl de la Queue.

    // Después, quitamos un elemento, y metemos otro nuevo, para probar la otra condición de Full()
    MyQueue.Dequeue();
    MyQueue.Print();

    MyQueue.Enqueue('g');
    MyQueue.Enqueue('h');

    if (MyQueue.Full() == true)
    {
        std::cout << "la Queue está llena de nuevo." << '\n';
    }


    MyQueue.Print();


    // CÓDIGO PARA PROBAR LA CLASE DEQUE.




    //

    List<char> myList = List<char>();
    myList.PushBack('a');
    myList.GetByValue('a');

    myList.PopFront();


    // Código para probar la Clase de Lista doblemente ligada

    DList<char> myDList = DList<char>();
    myDList.PushBack('a');
    myDList.PushFront('b');

    myDList.Print();

    myDList.PopBack();
    myDList.PopFront();

    myDList.PopFront();

    myDList.PushBack('c');
    myDList.PushBack('d');
    myDList.PushBack('e');

    myDList.DeleteByValue('d');

    myDList.Print();


    // DListNode

/*    BinaryTree<int> myBT = BinaryTree<int>();
    myBT.Insert(5);
    myBT.Insert(3);
    myBT.Insert(8);
    myBT.Insert(2);
    myBT.Insert(4);
    myBT.Insert(7);
    myBT.Insert(9);
 
    myBT.InOrder(myBT.GetRoot());
    myBT.PreOrder(myBT.GetRoot());
    */


    //// Hay que liberar memoria del RawArray
    //// test.~RawArray();


 


 
        BinaryTree<int> tree;
        tree.Insert(5);
        tree.Insert(3);
        tree.Insert(7);
        tree.Insert(2);
        tree.Insert(4);
        tree.Insert(6);
        tree.Insert(8);

        Node<int>* root = tree.GetRoot(); // Obtener el nodo raíz

        std::cout << "InOrder: ";
        tree.InOrderIterative();
        std::cout << std::endl;

        std::cout << "PreOrder: ";
        tree.PreOrderIterative();
        std::cout << std::endl;

        std::cout << "PostOrder: ";
        tree.PostOrderIterative();
        std::cout << std::endl;

        // Encontrar el predecesor del nodo con valor 7
        Node<int>* node7 = root->right->left;
        Node<int>* predecessor7 = tree.Predecessor(node7);
        if (predecessor7)
            std::cout << "Predecesor de 7: " << predecessor7->data << std::endl;
        else
            std::cout << "7 no tiene predecesor" << std::endl;

        return 0;
    }



// Anteriormente, se cerraba la consola en cuenta terminaba de ejecutarse la aplicación.
    // Ahora ya no, lo cual es bastante útil.

    // Si bien ya no es indispensable, es buena práctica poner este return 0,
    // que indica que el programa finalizó con el código 0 (correcto).




// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
