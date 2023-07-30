#pragma once

#include <iostream>

template <typename T>
class Stack
{
private:
	// Las dejas como privadas para que no sea tan fácil para usuarios inexpertos modificarlas sin saber.
	T* InitialElement; // Tal cual los datos que estamos guardando en la Stack.
	int _size; // cuántos elementos puede tener antes de llenarse (overflow)
	int _top;  // cuántos elementos tiene ahorita

	bool _isDynamic;

public:
	Stack(int size, bool isDynamic=true) : _size(size), _isDynamic(isDynamic)
	{
		InitialElement = new T[_size];
		_top = 0;
	}

	~Stack()
	{
		std::cout << "entrada destructor de Stack" << '\n';
		delete[] InitialElement;
		std::cout << "salida destructor de Stack" << '\n';
	}


	// Función que añade un elemento hasta arriba de la pila
	void Push(T ElementToPush)
	{
		if (_size == _top)
		{
			if (_isDynamic == true)
			{
				// Pedir más memoria
				T* AuxPointer = new T[_size * 2];
				// dato cultural, el tamaño por defecto de las estructuras de datos es una potencia de 2, por ejemplo 128
				// Copiar lo de la vieja memoria a esta nueva memoria
				for (int i = 0; i < _size; i++)
				{
					AuxPointer[i] = InitialElement[i];
				}

				// borrar la memoria vieja
				delete[] InitialElement;
				// cambiar a dónde apunta InitialElement
				InitialElement = AuxPointer;
				_size = _size * 2; // _size *= 2; es lo mismo

				// lo podríamos añadir aquí, pero al pensar bien las ramificaciones de la ejecución, nos lo podemos ahorrar.
				// InitialElement[_top] = ElementToPush;
				// _top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)
			}
			else 
			{
				// esto sería un error de Overflow
				std::cout << "Error de Overflow" << '\n';
				return;
			}
		}

		// si no, lo metemos hasta el tope de la pila, y lo hacemos el nuevo top
		InitialElement[_top] = ElementToPush;
		_top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)

	}

	// Quita el elemento del tope de la Pila.
	void Pop()
	{
		if (IsEmpty())  // este de aquí no le importa si tu stack es dinámica o no, siempre es un error
		{
			// Error, underflow, que es: quieres quitar elementos donde no hay.
			std::cout << "Error de Underflow" << '\n';
			return;
		}

		// Comparar si vamos a un cuarto (1/4) de la capacidad de nuestra stack
		if (_isDynamic == true && _top <= _size / 4)
		{
			// Entonces hacemos un resize para no gastar memoria.

			// Pedir más memoria, pero más chica, solo la mitad de la capacidad actual
			// PENDIENTE, HACER EL REDONDEO PARA LOS NÚMEROS IMPARES
			T* AuxPointer = new T[_size / 2];

			// Copiar lo de la vieja memoria a esta nueva memoria
			// OJO: a´quí usamos _top en vez de _size para ahorrar operaciones.
			for (int i = 0; i < _top; i++)
			{
				AuxPointer[i] = InitialElement[i];
			}

			// borrar la memoria vieja
			delete[] InitialElement;
			// cambiar a dónde apunta InitialElement
			InitialElement = AuxPointer;
			_size = _size / 2; // _size /= 2; es lo mismo			
		}
		
		// Podríamos poner en 0 este elemento, pero no es necesario, porque el _top nos dice 
		// que ya no lo leamos o tomemos en cuenta, y cuando se añada algo nuevo, se sobreescribirá.
		// InitialElement[_top-1] = NULL; 
		_top--;
	}

	bool IsEmpty()
	{
		if (_top == 0)
		{
			return true;
		}
		// Aquí no puse el "else" porque con el return true; de arriba se saldría de la función.
		return false;
	}

	// Función que nos permite leer el elemento al tope de la Pila.
	T Top()
	{
		if (IsEmpty())
			return NULL;

		return InitialElement[_top - 1];
	}

	// Imprimir
	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			std::cout<< InitialElement[i] << ", ";
		}
		std::cout << '\n';

	}

	// Función Resize
};

