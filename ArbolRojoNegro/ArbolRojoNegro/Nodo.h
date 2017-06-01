#ifndef NODO_H
#define NODO_H


#include <fstream>
#include "Formato.h"
#define rojo true
#define negro false
#define par true
#define impar false
#define izquierdo true
#define derecho false

template <class T>
class Nodo
{
private:
	T elem;
	bool color;
	Nodo<T> *der;
	Nodo<T> *izq;
public:
	Nodo();
	void setElem(T ele);
	void setColor(bool color);
	bool getColor();
	void setDer(Nodo *der);
	void setIzq(Nodo *izq);
	Nodo<T>*& getDer();
	Nodo<T>*& getIzq();
	T getElem();
	void mostrar();
	~Nodo();
};
template <class T>
Nodo<T>::Nodo()
{
	der = NULL;
	izq = NULL;
	color = rojo;
}

template <class T>
void Nodo<T>::setElem(T ele)
{
	elem = ele;
}

template <class T>
void Nodo<T>::setColor(bool color)
{
	this->color = color;
}

template <class T>
bool Nodo<T>::getColor()
{
	return color;
}

template <class T>
void Nodo<T>::setDer(Nodo *der)
{
	this->der = der;
}

template <class T>
void Nodo<T>::setIzq(Nodo *izq)
{
	this->izq = izq;
}

template <class T>
T Nodo<T>::getElem()
{
	return elem;
}

template <class T>
Nodo<T>*& Nodo<T>::getDer()
{
	return der;
}

template <class T>
Nodo<T>*& Nodo<T>::getIzq()
{
	return izq;
}

template <class T>
void Nodo<T>::mostrar()
{
	if (color == rojo)
		textcolor(4);
	else
		textcolor(7);

	cout << elem << " ";
	textcolor(7);
}

template <class T>
Nodo<T>::~Nodo()
{
	delete der;
	delete izq;
}

#endif