#pragma once

#include <iostream>



template <typename T>
class TArray
{
public:
	TArray(int in_Size) : Size(in_Size)
	{
		// Size = in_Size;
		// estoy pidiendo espacio en memoria igual a n ints, donde n = Size.
		InitialElement = new T[Size];
	}

	~TArray()
	{
		std::cout << "entrada destructor de TArray" << '\n';
		// Hay que liberar la memoria dinámica
		delete[] InitialElement;
		std::cout << "salida destructor de TArray" << '\n';
	}

	void Init(T InitialValue = 0)
	{
		T* auxPosition = InitialElement;
		for (int i = 0; i < Size; i++)
		{
			*auxPosition = InitialValue;
			auxPosition++;
		}
	}

	void Print()
	{
		T* auxPosition = InitialElement;
		for (int i = 0; i < Size; i++)
		{
			std::cout << *auxPosition << ", ";
			auxPosition++;
		}
		std::cout << '\n';
	}

	// puntero a la primera dirección de los N enteros continuos en memoria
	T* InitialElement;  // es decir, es el elemento '0' de un Array[0]
	// int* auxPosition = InitialElement;
	// InitialElement++;  // nos mueve 4 bytes en memoria
	// si auxPosition está apuntando a x1, y luego hacemos auxPosition++
	// al hacer auxPosition++ una vez más nos llevaría al tercer elemento

	int Size;

};