#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

template <class T>
class Nodo
{
private:
	T elemento;
	Nodo<T> *ramaDer;
	Nodo<T> *ramaIzq;
	int factor;
public:
	Nodo(void);
	~Nodo(void);
	void setElem(T ele);
	void setDer(Nodo<T> *Der);
	void setIzq(Nodo<T> *Izq);
	void cambiarFactor(int nuevo);
	void incrementarFactor();
	void decrementarFactor();
	int getFactor();
	T getElem();
	Nodo<T> *&getDer();
	Nodo<T> *&getIzq();
	void mostrar();
};

template <class T>
Nodo<T>::Nodo(void)
{
	ramaDer=NULL;
	ramaIzq=NULL;
	factor=0;
}

template <class T>
Nodo<T>::~Nodo(void)
{
	delete ramaDer;
	delete ramaIzq;
}

template <class T>
void Nodo<T>::setElem(T ele)
{
	elemento=ele;
}

template <class T>
void Nodo<T>::setDer(Nodo<T> *der)
{
	ramaDer=der;
}

template <class T>
void Nodo<T>::setIzq(Nodo<T> *izq)
{
	ramaIzq=izq;
}

template <class T>
void Nodo<T>::cambiarFactor(int nuevo)
{
	factor=nuevo;
}

template <class T>
void Nodo<T>::incrementarFactor()
{
	factor=factor+1;
}

template <class T>
void Nodo<T>::decrementarFactor()
{
	factor = factor -1;
}

template <class T>
int Nodo<T>::getFactor()
{
	return factor;
}

template <class T>
T Nodo<T>::getElem()
{
	return elemento;
}

template <class T>
Nodo<T> *&Nodo<T>::getDer()
{
	return ramaDer;
}

template <class T>
Nodo<T> *&Nodo<T>::getIzq()
{
	return ramaIzq;
}

template <class T>
void Nodo<T>::mostrar()
{
	cout << elemento << " ";
	//cout << "F:" << factor <<" ";
}

