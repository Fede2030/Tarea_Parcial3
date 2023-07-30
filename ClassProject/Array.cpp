#include "Array.h"

#include <iostream>

// int myArray[5]

// POD = Plain Old Data, por ejemplo: int, float, bool, etc.
// NO-POD: objetos de clases y structs definidos por usuarios.

RawArray::RawArray(int in_Size): Size(in_Size)
{
	// Size = in_Size;
	// estoy pidiendo espacio en memoria igual a n ints, donde n = Size.
	InitialElement = new int[Size];

	// Internamente "new int[Size]" haría:
	// InitialElement = new int;
	// int* auxPosition = InitialElement;
	// for (int i = 0; i < Size; i++)
	// {
	// 	 auxPosition++;
	// 	 auxPosition = new int;
	// }
}

RawArray::~RawArray()
{
	std::cout << "entrada destructor de RawArray" << '\n';
	// Hay que liberar la memoria dinámica
	delete[] InitialElement;
	/*int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		int* toDelete = auxPosition;
		delete toDelete;
		auxPosition++;
	}*/
	std::cout << "salida destructor de RawArray" << '\n';
}

// Asignamos el mismo valor InitialValue a todas las posiciones de nuestro arreglo
void RawArray::Init(int InitialValue)
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = InitialValue;
		auxPosition++;
	}
}  // El return nos manda automáticamente hasta fuera del Scope de la función en que estés.
// al llegar acá, se manda llamar el destructor de TODAS las variables (estáticas) 
// que solo viven en ese scope.

void RawArray::Print()
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		std::cout<<*auxPosition << ", ";
		auxPosition++;
	}
	std::cout << '\n';
}


void RawArray::AddElement(int value)
{
	// Primero que nada, mantener una referencia a nuestros valores originales del arreglo que aumentará su tamaño
	// Si no mantenemos referencia a esos valores originales, no podríamos copiarlos al nuevo arreglo, ni liberar esa memoria.
	int* auxPointer = InitialElement;  // auxPointer ahora apunta a al primer elemento de [0, 1, 2]

	InitialElement = new int[Size + 1]; // esto nos va a dar [basura, basura, basura, basura]

	// Ahora, hay que copiar los elementos del arreglo antes de que se aumentara el tamaño, a las posiciones donde apunta InitialElement
	for (int i = 0; i < Size; i++)
	{
		InitialElement[i] = auxPointer[i];
	}
	// Después de esto ya tendríamos [0, 0, 0, basura]
	// AQUÍ TODAVÍA FALTA ALGO, ¿QUÉ ES?

	// 1) Debió haber impreso el 4to elemento que se agregó. CORREGIDO.
	// ¿por qué ahorita no lo imprimió? -> porque nos faltaba añadir ese +1 al Size de nuestro RawArray
	Size = Size + 1; // Size++;

	// 2) Nos falta tal cual agregar ese "value" pasado a la función, a nuestro RawArray
	InitialElement[Size - 1] = value; // Debe ir en la última posición del arreglo.

	// Todavía falta una cosa más!
	// Borrar la memoria dinámica que ya no nos es útil
	delete[] auxPointer; // Esto va a borrar el arreglo "original" (el de tamaño más chico) porque ya no es útil.
}

void RawArray::RemoveLastElement()
{
	int* auxPointer = InitialElement; // Una asignación, solo 1 operación

	Size = Size - 1;  // 1 operación
	InitialElement = new int[Size]; // 1 operación, PERO, tiene 'n' extra de memoria.

	// en este momento en que pedimos esta memoria, está usando Size + (Size-1) de memoria.
	// 1,000,000 + 999,999 = 1,999,999, casi Size*2 de memoria.

	// este ciclo for se ejecutará Size veces
	// como solo tiene 1 operación dentro, el total de este for será Size*x operaciones.
	for (int i = 0; i < Size; i++)
	{
		InitialElement[i] = auxPointer[i]; // 1 operación
	}

	// Podríamos decir que tiene una complejidad de Size operaciones, y 2*Size memoria

	delete[] auxPointer;
}


