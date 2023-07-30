#pragma once

#ifndef DLIST
#define DLIST

#include <iostream>


template <typename T>
class DListNode
{
public:
	DListNode(T in_data) : data(in_data)
	{
		prev = nullptr;
		next = nullptr;
	}

	~DListNode()
	{
		// No tiene que hacer nada.
	}

	T data;
	// Recordatorio: tienen que ser punteros, no instancias de la clase,
	// sino, el compilador se cicla tratando de definir qué es un DListNode.
	DListNode<T>* prev;
	DListNode<T>* next;
};



template <typename T>
class DList
{
private:
	DListNode<T>* sentinel; // es el primer y último nodo, el nodo centinela.

public:
	DList()
	{
		// Tenemos que crear el nodo centinela.
		sentinel = new DListNode<T>(NULL);
		// aquí todas las menciones de nullptr se deben de cambiar por sentinel.
		sentinel->next = sentinel;
		sentinel->prev = sentinel;
	}

	~DList()
	{
		// borramos todos menos el centinela.
		while (Empty() == false)
		{
			PopFront();
		}

		/*DListNode<T>* auxNode = sentinel->next;
		DListNode<T>* auxNodeDelete = nullptr;
		while (auxNode != sentinel)
		{
			auxNodeDelete = auxNode;
			auxNode = auxNode->next;
			delete auxNodeDelete;
		}*/

		// el nodo sentinela únicamente se borra cuando se destruye la lista.
		delete sentinel;
	}

	void PushBack(T element)
	{
		// hacemos un nuevo nodo que va a contener a element.
		DListNode<T>* newNode = new DListNode<T>(element);

		// El next de este nuevo nodo, tiene que ser el nodo centinela
		newNode->next = sentinel;

		// Que el prev del nuevo nodo apunte al nodo que antes era el último
		newNode->prev = sentinel->prev;

		// que el nodo que antes era el último ahora su next apunte al nuevo nodo
		// sentinel->prev es el nodo que antes era el último
		sentinel->prev->next = newNode;

		// El prev del centinela tiene que ser este nuevo nodo.
		sentinel->prev = newNode;
	}

	void PushFront(T element)
	{
		InsertNodeAfter(element, sentinel);
	}

	void PopFront()
	{
		if (Empty())
		{
			// entonces la lista está vacía
			return;
		}

		// hay que quitar ese nodo y reconectar los prev y los next necesarios.

		// "el que estamos quitando" es "sentinel->next".
		DListNode<T>* toBeDeleted = sentinel->next;

		toBeDeleted->next->prev = sentinel;

		// esta debe ser la última asignación.
		// el next del centinela apunta al next del que estamos quitando
		sentinel->next = toBeDeleted->next;

		delete toBeDeleted;
	}

	void PopBack()
	{
		if (Empty())
		{
			// entonces la lista está vacía
			return;
		}

		// quitar el nodo y reconectar
		DListNode<T>* toBeDeleted = sentinel->prev;

		toBeDeleted->prev->next = sentinel;

		sentinel->prev = toBeDeleted->prev;

		delete toBeDeleted;
	}

	bool Empty()
	{
		if (sentinel->next == sentinel)
		{
			// entonces la lista está vacía
			return true;
		}
		return false;
	}

	// Inserta un nodo con el valor X (valueToInsert) después del nodo Y (priorNode)
	void InsertNodeAfter(T valueToInsert, DListNode<T>* priorNode)
	{
		DListNode<T>* newNode = new DListNode<T>(valueToInsert);

		newNode->prev = priorNode;

		newNode->next = priorNode->next;

		// priorNode->next sería el nodo "Z", porque va después del nodo "Y"
		priorNode->next->prev = newNode;

		priorNode->next = newNode;
	}

	DListNode<T>* GetByValue(T value)
	{
		sentinel->data = value;  // lo guardamos aquí mismo para no guardar más memoria

		DListNode<T>* auxNode = sentinel->next;
		while (auxNode->data != value)
		{
			auxNode = auxNode->next;
		}

		// restablecemos el data de sentinel a NULL para mejor debug 
		// es decir, para que sea obvio que es el centinela.
		sentinel->data = NULL;

		// tenemos que checar el porqué terminó
		if (auxNode == sentinel)
		{
			// entonces no encontró un nodo en la lista con data = value.
			// std::cout << "no se encontró un nodo con valor: " << value << '\n';
			return nullptr;
		}

		// si sí lo encontró, regresamos el nodo al que apunte auxNode.
		return auxNode;

	}

	void DeleteNode(DListNode<T>* toBeDeleted)
	{
		// hay que recvonectar esos dos faltantes
		toBeDeleted->prev->next = toBeDeleted->next;
		toBeDeleted->next->prev = toBeDeleted->prev;
		delete toBeDeleted;
	}

	void DeleteByValue(T value)
	{
		DListNode<T>* toBeDeleted = GetByValue(value);
		// checar que está ese nodo con valor T
		if (toBeDeleted != nullptr)
		{
			DeleteNode(toBeDeleted);
		}
	}

	void Print()
	{
		DListNode<T>* auxNode = sentinel->next;
		while (auxNode != sentinel)
		{
			std::cout << auxNode->data << ", ";
			auxNode = auxNode->next;
		}
		std::cout << '\n';
	}

	//string operator <<
	//{
	//	std::string 
	//	DListNode<T>* auxNode = sentinel->next;
	//	while (auxNode != sentinel)
	//	{
	//		std::cout << auxNode->data << ", ";
	//		auxNode = auxNode->next;
	//	}
	//	std::cout << '\n';

	//}

};

#endif DLIST