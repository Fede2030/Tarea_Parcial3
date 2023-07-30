#pragma once

#ifndef LIST
#define LIST

#include <iostream>

template <typename T>
class ListNode
{
public:
	// Constructor
	ListNode(T in_data): data(in_data)
	{
		next = nullptr;
	}

	~ListNode()
	{
		// No necesita hacer nada explícitamente, pero lo pongo para dejar explicar que no necesita hacer nada.
	}

	T data;// Los datos
	ListNode<T>* next;// una referencia al nodo sigue de este nodo, dentro de la lista.
};



// List va a ser lista simplemente ligada
template <typename T>
class List
{
private:
	ListNode<T>* firstNode;  // checar si mejor usamos smart pointers de una vez.
	int size; // es opcional

	// Si el next de currentNode es == nullptr, quiere decir que currentNode es el último elemento de la lista.
public:
	List()
	{
		firstNode = nullptr;
		size = 0;
	}

	/*List(T dataArray[], int dataSize)
	{
	
	}*/

	~List()
	{
		// La lista es dueña de todos sus nodos, los nodos no son dueños de nadie.
		// por lo tanto, aquí sí tendríamos que borrar los nodos.
		// primero necesitamos los métodos de iteración para luego ahora sí poder borrar los nodos.
		// este while dice: mientras todavía haya nodos dentro de esta lista.
		while (firstNode != nullptr)
		{
			PopFront(); // quita el primer nodo.
		}
	}

	void PushBack(T element)
	{

		// aumentamos el size en 1
		size++;

		if (firstNode == nullptr)
		{
			firstNode = new ListNode<T>(element);  // usamos el constructor que recibe un valor T.
			return;
		}

		// añade element hasta el final de la lista.
		ListNode<T>* currentNode = firstNode;
		// Iteramos hasta encontrar el último de la lista
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		// Falta decirle a currentNode que su next es ahora un nuevo nodo que va a guardar a element.
		ListNode<T>* newNode = new ListNode<T>(element);  // usamos el constructor que recibe un valor T.

		// Ya que tenemos nuestro nuevo nodo, falta actualizar el next de currentNode, para que 
		// sepa que ya no es el último nodo de la lista.
		currentNode->next = newNode;

	}

	void PushBack(ListNode<T>* in_node)
	{
		// añade element hasta el final de la lista.
		ListNode<T>* currentNode = firstNode;
		// Iteramos hasta encontrar el último de la lista
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		// Aquí, por seguridad, es necesario
		in_node->next = nullptr;

		currentNode->next = in_node;
	}

	// Quita al primer elemento de la lista.
	void PopFront()
	{
		// Siempre checar que haya elementos antes de quitar elementos.
		if (firstNode == nullptr)
		{
			// entonces la lista está vacía.
			std::cout << "error, tratando de quitar elementos de una lista vacía" << '\n';
			return;  // nos salimos de la función.
		}

		// Hay que quitar a firstNode.
		// Primero hay que checar si hay otros nodos en la lista.
		if (firstNode->next != nullptr)
		{
			// Primero guardamos una referencia a quién sigue de firstNode
			ListNode<T>* auxNode = firstNode->next;
			// Después, borramos la memoria de first node.
			delete firstNode;
			// ajustamos quién es el nuevo firstNode.
			firstNode = auxNode;
		}
		else // si es el único elemento de la lista.
		{
			delete firstNode;
			firstNode = nullptr;
		}
		size--;
	}

	// Insertar en el índice index

	// Insertar el nodo x, después del nodo y pasado como parámetro
	void InsertAfter(ListNode<T>* toBeInserted, ListNode<T>* existingNode)
	{
		// checar si existingNode tiene un nodo next.
		if (existingNode->next != nullptr)
		{
			// si sí tiene, hay que ajustar los next correspondientes.
			// [c] = existingNode->next;
			toBeInserted->next = existingNode->next; // que el next de [b] apunte a [c]
			// hay que tener cuidado con estas reconexiones de next para no perder la referencia a nadie.
		}
		existingNode->next = toBeInserted;  // que el next de [a] apunte a [b]
	}

	//void InsertList(ListNode<T>* listToBeInserted, ListNode<T>* existingNode)
	//{
	//	// checar si existingNode tiene un nodo next.
	//	if (existingNode->next != nullptr)
	//	{
	//		// si sí tiene, hay que ajustar los next correspondientes.
	//		// [c] = existingNode->next;
	//		toBeInserted->next = existingNode->next; // que el next de [b] apunte a [c]
	//		// hay que tener cuidado con estas reconexiones de next para no perder la referencia a nadie.
	//	}
	//	existingNode->next = toBeInserted;  // que el next de [a] apunte a [b]
	//}

	// Borra a este elemento x de la lista.
	// MUY PROBABLEMENTE DEBERÍA SER PRIVADA
	void DeleteNode(ListNode<T>* x)
	{
		// forzosamente tenemos que usar Predecessor para saber quién va antes de x
		ListNode<T>* auxPredecessor = Predecessor(x);
		// hay que checar que no sea nulo
		if (auxPredecessor == nullptr)
		{
			// entonces es el primer nodo, solo tenemos que borrarlo y actualizar el first.
			ListNode<T>* auxPointer = firstNode;
			firstNode = firstNode->next;
			delete auxPointer;
			return;
		}
		
		// si no es el primer elemento. conectamos al predecesor de x, con el sucesor de x.
		auxPredecessor->next = x->next;
		// y ya podemos borrar x.
		delete x;
	}

	void DeleteByValue(T value)
	{
		ListNode<T>* toBeDeleted = GetByValue(T);
		if (toBeDeleted == nullptr)
			return;
		DeleteNode(toBeDeleted);
	}



	// Insertar por valor (si están ordenados)
	// a esta vamos a volver un poco después.
	// if(currentNode->data < newNode->data && currentNode->next->data >= newNode->data)


	// Función de búsqueda por valor T
	ListNode<T>* GetByValue(T value)
	{
		if (firstNode == nullptr)
		{
			std::cout << "error, la lista está vacía: " << '\n';
			return nullptr; // índice no válido, regresa nullptr por defecto.
		}

		ListNode<T>* auxPointer = firstNode;
		while (auxPointer != nullptr)
		{
			// Checamos si este nodo, tiene el value que nos dieron como entrada.
			if (auxPointer->data == value)
			{
				// entonces ya lo encontramos.
				return auxPointer; // regresamos una referencia a este nodo
			}
			// si todavía no encontramos al del value requerido, solo nos vamos al siguiente nodo.
			auxPointer = auxPointer->next;
		}

		std::cout << "error, no se encontró ningún nodo con value = " << value << '\n';
		return nullptr; // No encontrado, regresa nullptr por defecto.
	}


	// Función de "búsqueda" por índice i
	ListNode<T>* GetByIndex(int index)
	{
		if (firstNode == nullptr)  // checar que la lista no esté vacía
		{
			std::cout << "error, la lista está vacía: " << index << " pero size = " << size << '\n';
			return nullptr; // índice no válido, regresa nullptr por defecto.
		}
		if (index >= size)  // checar que el index sea válido
		{
			std::cout << "error, tratando de acceder a indice: " << index << " pero size = " << size << '\n';
			return nullptr; // índice no válido, regresa nullptr por defecto.
		}
		// no necesitamos 'else' porque el return de arriba los sacaría de la función.

		ListNode<T>* currentNode = firstNode;
		for (int i = 0; i < index; i++)
			currentNode = currentNode->next;

		return currentNode;
	}



	ListNode<T>* Successor(ListNode<T>* x)
	{
		return x.next;  // como X ya sabe qué nodo sigue de él, entonces lo regresamos.
	}

	ListNode<T>* Predecessor(ListNode<T>* x)
	{
		// tenemos que iterar desde el inicio de la lista, hasta encontrar un nodo 'y', cuyo next sea = x.
		ListNode<T>* currentNode = firstNode;
		// La primera parte del while es: si todavía no encontramos al predecesor
		// la segunda parte edl while es: si todavía hay elementos por checar en la lista.
		while(currentNode->next != nullptr)
		{
			if (currentNode->next == x)
			{
				return currentNode; 		// si sí encontramos al predecesor, pues lo regresamos
			}
			// si no se ha cumplido, este nodo no es el predecesor y nos tenemos que ir al siguiente.
			currentNode = currentNode->next;
		}
		return nullptr;
	}





};

#endif // LIST