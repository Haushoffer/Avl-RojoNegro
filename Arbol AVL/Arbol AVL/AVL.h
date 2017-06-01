#ifndef AVL_H
#define AVL_H
#include "Nodo.h"
#include <math.h>

template<class T>
class AVL
{
private:
	Nodo<T> *raizArbol;

public:
	AVL(void);
	~AVL(void);
	void rotarArbolDerechaSimple(Nodo<T> *&raiz);
	void rotarArbolDerechaCompuesta(Nodo<T> *&raiz);
	void rotarArbolIzquierdaSimple(Nodo<T> *&raiz);
	void rotarArbolIzquierdaCompuesta(Nodo<T> *&raiz);
	bool insertar(T elem, Nodo<T> *&raiz);
	Nodo<T> *buscarElemento(T elem, Nodo<T> *raiz);
	int altura(Nodo<T> *raiz);
	int contarNodos(Nodo<T> *raiz);
	Nodo<T> *Menor(Nodo<T> *raiz);
	Nodo<T> *Mayor(Nodo<T> *raiz);
	void mostrarPostOrder(Nodo<T> *raiz);
	void mostrarPreOrder(Nodo<T> *raiz);
	void mostrarInOrder(Nodo<T> *raiz);
	Nodo<T> *&getRaiz();
	bool AVL<T>::validarAVL(Nodo<T> *r);
};


template <class T>
AVL<T>::AVL(void)
{
	raizArbol = NULL;
}

template <class T>
void AVL<T>::rotarArbolDerechaSimple(Nodo<T> *&raiz)
{
	Nodo<T> *nuevaD;
	Nodo<T> *flot;
	flot  =  raiz->getIzq()->getDer();
	nuevaD  =  raiz;
	raiz  =  raiz->getIzq();
	raiz->setDer(nuevaD);
	
		nuevaD->setIzq(flot);
	
		
	raiz->cambiarFactor(0);
	nuevaD->cambiarFactor(0);
	if(nuevaD  ==  raizArbol)
		raizArbol  =  raiz;
}

template <class T>
void AVL<T>::rotarArbolDerechaCompuesta(Nodo<T> *&raiz)
{
	Nodo<T> *nuevaRaiz,*flotDer,*flotIzq;
	nuevaRaiz = raiz->getIzq()->getDer();
	
		flotDer = nuevaRaiz->getDer();
	
		flotIzq = nuevaRaiz->getIzq();
	nuevaRaiz->setDer(raiz);
	nuevaRaiz->setIzq(raiz->getIzq());
	(nuevaRaiz->getDer())->setIzq(flotDer);
	(nuevaRaiz->getIzq())->setDer(flotIzq);
	raiz = nuevaRaiz;
	
	if(raiz->getFactor() == 1)
	{
		raiz->getIzq()->cambiarFactor(0);
		raiz->getDer()->cambiarFactor(-1);
	}
	else
	{
		if(raiz->getFactor() == -1)
		{
			raiz->getDer()->cambiarFactor(0);
			raiz->getIzq()->cambiarFactor(1);
		}
		else
		{
			raiz->getIzq()->cambiarFactor(0);
			raiz->getDer()->cambiarFactor(0);
		}
	}
	raiz->cambiarFactor(0);
	if(raiz->getDer() == raizArbol)
		raizArbol = raiz;
}

template <class T>
void AVL<T>::rotarArbolIzquierdaSimple(Nodo<T> *&raiz)
{
	Nodo<T> *nuevaI;
	Nodo<T> *flot;
	flot = raiz->getDer()->getIzq();
	nuevaI = raiz;
	raiz = raiz->getDer();
	raiz->setIzq(nuevaI);
	
		nuevaI->setDer(flot);
	
		
	raiz->cambiarFactor(0);
	nuevaI->cambiarFactor(0);
	if(nuevaI == raizArbol)
		raizArbol = raiz;
}

template <class T>
void AVL<T>::rotarArbolIzquierdaCompuesta(Nodo<T> *&raiz)
{
	Nodo<T> *nuevaRaiz,*flotDer,*flotIzq;
	nuevaRaiz = raiz->getDer()->getIzq();
	
		flotDer = nuevaRaiz->getDer();
	
		flotIzq = nuevaRaiz->getIzq();
	nuevaRaiz->setIzq(raiz);
	nuevaRaiz->setDer(raiz->getDer());
	nuevaRaiz->getIzq()->setDer(flotIzq);
	nuevaRaiz->getDer()->setIzq(flotDer);
	raiz = nuevaRaiz;
	
	if(raiz->getFactor() == -1)
	{
		raiz->getIzq()->cambiarFactor(1);
		raiz->getDer()->cambiarFactor(0);
	}
	else
	{
		if(raiz->getFactor() == 1)
		{
			raiz->getDer()->cambiarFactor(-1);
			raiz->getIzq()->cambiarFactor(0);
		}
		else
		{
			raiz->getIzq()->cambiarFactor(0);
			raiz->getDer()->cambiarFactor(0);
		}
	}
	raiz->cambiarFactor(0);
	if(raiz->getIzq() == raizArbol)
		raizArbol = raiz;
}

template <class T>
bool AVL<T>::insertar(T elem, Nodo<T> *&raiz)
{
	if(raiz == NULL)
	{
		Nodo<T> *nodo = new Nodo<T>();
		nodo->setElem(elem);
		raiz = nodo;
		if(raizArbol == NULL)
			raizArbol = raiz;
		return true;
	}
	else
	{
		if(elem < raiz->getElem())
		{
			bool resp;
			if(insertar(elem, raiz->getIzq()) == true)
			{
				raiz->incrementarFactor();
				if(raiz->getFactor() == 0)
					return  false;
				else
				{
					if(raiz->getFactor() == 2)
					{
						if(raiz->getIzq()->getFactor() == 1)
							AVL<T>::rotarArbolDerechaSimple(raiz);
						else
							AVL<T>::rotarArbolDerechaCompuesta(raiz);
						return false;
					}
				}
				return true;
			}
		}
		else
		{
			if(elem > raiz->getElem())
			{
				bool resp;	
				if(insertar(elem, raiz->getDer()) == true)
				{
					raiz->decrementarFactor();
					if(raiz->getFactor() == 0)
						return false;
					else
					{
						if(raiz->getFactor() == -2)
						{
							if(raiz->getDer()->getFactor() == -1)
								AVL<T>::rotarArbolIzquierdaSimple(raiz);
							else
								AVL<T>::rotarArbolIzquierdaCompuesta(raiz);
							return false;
						}
					}
					return true;
				}
			}
		}
	}
	return false;
}

template <class T>
Nodo<T> *AVL<T>::buscarElemento(T elem,Nodo<T> *raiz)
{
	if(raiz == NULL)
		return raiz;
	else
	{
		int valor = raiz->getElem();
		if(valor == elem)
			return raiz;
		else
		{
			if(elem < valor)
				return buscarElemento(elem, raiz->getIzq());
			else
				return buscarElemento(elem, raiz->getDer());
		}
	}
}

template <class T>
int AVL<T>::altura(Nodo<T> *raiz)
{
	if(raiz == NULL)
		return 0;
	else
	{
		if(raiz->getIzq() == NULL && raiz->getDer() == NULL)
			return 1;
		else
		{
			int der = 1+altura(raiz->getDer());
			int izq = 1+altura(raiz->getIzq());
			if(izq>der)
				return izq;
			else
				return der;
		}
	}
}

template <class T>
int AVL<T>::contarNodos(Nodo<T> *raiz)
{
	if(raiz == NULL)
		return 0;
	else
	{
		if(raiz->getDer() == NULL && raiz->getIzq() == NULL)
			return 1;
		else
			return 1+contarNodos(raiz->getDer())+contarNodos(raiz->getIzq());
	}
}

template <class T>
Nodo<T> *AVL<T>::Menor(Nodo<T> *raiz)
{
	if(raiz == NULL)
		return raiz;
	else
	{
		if(raiz->getDer() == NULL && raiz->getIzq() == NULL)
			return raiz;
		else
			if(raiz->getIzq() !=  NULL)
				return Menor(raiz->getIzq());
			else
				return raiz;
	}
}

template <class T>
Nodo<T> *AVL<T>::Mayor(Nodo<T> *raiz)
{
	if(raiz == NULL)
		return raiz;
	else
	{
		if(raiz->getDer() == NULL && raiz->getIzq() == NULL)
			return raiz;
		else
		{
			if(raiz->getDer() !=  NULL)
				return Mayor(raiz->getDer());
			else
				return raiz;
		}
	}
}

template <class T>
void AVL<T>::mostrarPostOrder(Nodo<T> *r)
{
	if(r != NULL)
	{
		if(r->getDer() == NULL && r->getIzq() ==  NULL)
			r->mostrar();
		else
		{
			if(r->getIzq() != NULL)
				mostrarPostOrder(r->getIzq());
			if(r->getDer() != NULL)
				mostrarPostOrder(r->getDer());
			r->mostrar();
		}
	}
}

template <class T>
void AVL<T>::mostrarPreOrder(Nodo<T> *r)
{
	if(r != NULL)
	{
		if(r->getDer() == NULL && r->getIzq() ==  NULL)
			r->mostrar();
		else
		{
			r->mostrar();
			if(r->getIzq() != NULL)
				mostrarPreOrder(r->getIzq());
			if(r->getDer() != NULL)
				mostrarPreOrder(r->getDer());
		}
	}
}

template <class T>
void AVL<T>::mostrarInOrder(Nodo<T> *r)
{
	if(r != NULL)
	{
		if(r->getDer() == NULL && r->getIzq() ==  NULL)
			r->mostrar();
		else
		{
			if(r->getIzq() != NULL)
				mostrarInOrder(r->getIzq());
			r->mostrar();
			if(r->getDer() != NULL)
				mostrarInOrder(r->getDer());
		}
	}
}

template <class T>
bool AVL<T>::validarAVL(Nodo<T> *r)
{
	bool resp = true;
	if (r != NULL)
	{
		if (abs(altura(r->getIzq())- altura(r->getDer())  <=1))
		{
			return validarAVL(r->getIzq()) && validarAVL(r->getDer());
		}
		else
		{
			resp = false;
		}
	}
	else
	{
		return resp;
	}
}
template <class T>
Nodo<T> *&AVL<T>::getRaiz()
{
	return raizArbol;
}
template <class T>
AVL<T>::~AVL(void)
{
	delete raizArbol;
}

#endif