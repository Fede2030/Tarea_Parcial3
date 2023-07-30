#pragma once

#include <iostream>

template <typename T>
class Queue
{
private:
	// Variables que tiene que tener:
	// Donde vamos a guardar los datos.
	T* InitialElement;
	int _head;
	int _tail;
	int _size; // cuanta memoria está pedida actualmente.
	int _currentElements;  // Nos indica cuántos elementos hay actualmente dentro de la Queue.

	bool _isDynamic;

public:
	Queue(int size, bool Dynamic=true): _size(size), _isDynamic(Dynamic)
	{
		// pedimos _size bloques de memoria, cada uno de tamaño igual al tipo T del template.
		InitialElement = new T[_size];
		// Tenemos que inicializar los valores de _head y _tail, y ambos inician en 0.
		_head = 0;
		_tail = 0;
		_currentElements = 0;  // porque iniciamos con una Queue vacía.
	}

	~Queue()
	{
		delete[] InitialElement;  // liberamos la memoria pedida para nuestro arreglo de tipo T.
	}

	// Añade el elemento "element" en la posición Tail de la Queue, e incrementa el valor de Tail en 1.
	void Enqueue(T element)
	{
		if (Full() == true)
		{
			if (_isDynamic == true)
			{
				// Pedir más memoria
				T* AuxPointer = new T[_size * 2];
				// dato cultural, el tamaño por defecto de las estructuras de datos es una potencia de 2, por ejemplo 128
				// Copiar lo de la vieja memoria a esta nueva memoria
				for (int i = 0; i < _currentElements; i++)
				{
					AuxPointer[i] = InitialElement[(i + _head) % _size];
				}

				// borrar la memoria vieja
				delete[] InitialElement;
				// cambiar a dónde apunta InitialElement
				InitialElement = AuxPointer;
				_size = _size * 2; // _size *= 2; es lo mismo

				// Necesitamos también actualizar los valores de head y tail.
				_head = 0;
				_tail = _currentElements;  // también podría haber sido _tail = _size, pero antes del size*2.

				// lo podríamos añadir aquí, pero al pensar bien las ramificaciones de la ejecución, nos lo podemos ahorrar.
				// InitialElement[_top] = ElementToPush;
				// _top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)
			}
			// 
			std::cout << "Queue llena" << '\n';
		}

		// Poner element en donde Tail nos diga.
		InitialElement[_tail] = element;
		if (_tail == _size - 1)
		{
			// Hay que ciclar el valor de tail
			_tail = 0;
		}
		else
		{
			_tail++;
		}

		_currentElements++;

		// PRIMERO, checamos si lo tenemos que ciclar
		// if (_tail == _size)
		// 	_tail = 0;


		//_tail++;
		// Y después aumentamos Tail en 1
		// _tail++;
		//_tail = _tail % _size;
	}

	// Quita el elemento de la posición Head de la Queue, e incrementa el valor de Head en 1.
	void Dequeue()
	{
		// Antes de quitar elementos, hay que checar que sí hay al menos un elemento por quitar.
		// IMPORTANTE.
		if (Empty())
		{
			std::cout << "ERROR, tratando de quitar elementos de la Queue, pero no hay. Underflow." << '\n';
			return;  // salimos de la función para evitar modificar otra cosa.
		}

		// InitialElement[_head] = NULL;  // OPCIONAL
		_head++;
		// Primero ciclamos el valor de head
		_head = _head % _size;
 
		// Incrementamos Head en 1
		_currentElements--;

		if (_isDynamic == true)
		{
			// checar cuántos elementos quedan
			if (_currentElements <= _size / 4)
			{
				// entonces reducimos la memoria que ocupa esta Queue.

				// Pedimos nueva memoria
				T* AuxPointer = new T[_size / 2];

				// copiamos de lo viejo a lo nuevo
				for (int i = 0; i < _currentElements; i++)
				{
					AuxPointer[i] = InitialElement[(i + _head) % _size];
				}

				// borramos lo viejo
				delete[] InitialElement;
				InitialElement = AuxPointer;
				_size = _size / 2;

				// actualizamos head y tail.
				_head = 0;
				_tail = _currentElements;

			}
		}


	}

	// Regresa el valor del elemento en el índice Head de la Queue
	T Front()
	{
		return NULL; // Retorna un valor NULL por defecto
	}

	// Regresa el valor del elemento en el índice Tail de la Queue
	T Back()
	{
		return NULL; // Retorna un valor NULL por defecto
	}

	bool Empty()
	{
		// if (_head == _tail)
		// 	return true;

		if (_currentElements == 0)
			return true;  // si no hay elementos, quiere decir que está vacía la Queue.

		return false;
	}

	bool Full()
	{
		// Si le caben _size elementos, y actualmente tiene dentro _size elementos, entonces está llena.
		if (_size == _currentElements)
			return true;

		// if (_head == (_tail ) || (_head == 0 && _tail == _size-1))
		//	return true;

		return false;
	}

	// Imprimir // No es exactamente igual que la de Stack ni la de RawArray.
	void Print()
	{
		// Cuántas veces debería imprimir letras? _currentElements;
		for (int i = 0; i < _currentElements; i++)
		{
			std::cout << InitialElement[(i + _head) % _size] << ", ";
		}
		std::cout << '\n';
	}


};

