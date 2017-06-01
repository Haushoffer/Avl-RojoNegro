#ifndef ABB_H
#define ABB_H

#include "Nodo.h"

template <class T>
class ABB
{
private:
	Nodo<T> *raizArbol;
public:
	ABB();
	~ABB();
	void insertarRojoNegro(T elem, Nodo<T> *&raiz);
	void insertar(T elem, Nodo<T> *&raiz);
	bool buscar(T elem, Nodo<T> *raiz);
	Nodo<T>* buscarNodo(T elem, Nodo<T> *raiz);
	int altura(Nodo<T> *raiz);
	int alturaCorta(Nodo<T> *raiz);
	int contarNodos(Nodo<T> *raiz);
	void rotarDerecha(Nodo<T> *&raiz);
	void rotarIzquierda(Nodo<T> *&raiz);
	Nodo<T> *menor(Nodo<T> *raiz);
	Nodo<T> *mayor(Nodo<T> *raiz);
	void mostrarNivel(int nivel, Nodo<T> *raiz, int altura = 0);
	void mostrarPorNiveles(Nodo<T> *raiz);
	void mostrarPostOrder(Nodo<T> *raiz);
	void mostrarPreOrder(Nodo<T> *raiz);
	void mostrarInOrder(Nodo<T> *raiz);
	bool cumpleRegla(Nodo<T> *raiz);


	Nodo<T>* getRaiz();
};
template <class T>
ABB<T>::~ABB()
{
	delete raizArbol;
}
template <class T>
ABB<T>::ABB()
{
	raizArbol = NULL;
}
template <class T>
void ABB<T>::rotarIzquierda(Nodo<T> *&raiz)
{
	Nodo<T> *nuevaRaiz = raiz->getDer();
	Nodo<T> *flotante;
	if (nuevaRaiz->getIzq() != NULL)
		flotante = nuevaRaiz->getIzq();
	else
		flotante = NULL;
	nuevaRaiz->setIzq(raiz);
	raiz->setDer(flotante);
	raiz = nuevaRaiz;
}
template <class T>
void ABB<T>::rotarDerecha(Nodo<T> *&raiz)
{
	Nodo<T> *nuevaRaiz = raiz->getIzq();
	Nodo<T> *flotante;
	if (nuevaRaiz->getDer() != NULL)
		flotante = nuevaRaiz->getDer();
	else
		flotante = NULL;
	nuevaRaiz->setDer(raiz);
	raiz->setIzq(flotante);
	raiz = nuevaRaiz;
}
template <class T>
void ABB<T>::insertarRojoNegro(T elem, Nodo<T> *&raiz)
{
	static bool paridad;
	static bool lado;
	static bool continuar;
	if (raiz == NULL)
	{
		Nodo<T> *nuevo = new Nodo<T>();
		nuevo->setElem(elem);
		nuevo->setColor(rojo);
		raiz = nuevo;
		paridad = par;
		continuar = true;
	}
	else
	{
		if (elem < raiz->getElem())
		{
			insertarRojoNegro(elem, raiz->getIzq());
			if (continuar)
			{
				if (paridad == par)
				{
					if (raiz->getColor() == negro)
						continuar = false;
					else
					{
						paridad = impar;
						lado = izquierdo;
					}
				}
				else
				{
					if (paridad == impar)
					{
						if (raiz->getDer() != NULL && raiz->getDer()->getColor() == rojo)
						{
							raiz->getDer()->setColor(negro);
							if (raiz->getIzq() != NULL)
								raiz->getIzq()->setColor(negro);
							raiz->setColor(rojo);
							paridad = par;
						}
						else
						{
							continuar = false;
							if (lado == derecho)
							{
								rotarIzquierda(raiz->getIzq());
							}
							raiz->getIzq()->setColor(negro);
							raiz->setColor(rojo);
							rotarDerecha(raiz);
						}
					}
				}
			}
		}
		else if (elem > raiz->getElem())
		{
			insertarRojoNegro(elem, raiz->getDer());
			if (continuar)
			{
				if (paridad == par)
				{
					if (raiz->getColor() == negro)
						continuar = false;
					else
					{
						paridad = impar;
						lado = derecho;
					}
				}
				else
				{
					if (paridad == impar)
					{
						if (raiz->getIzq() != NULL && raiz->getIzq()->getColor() == rojo)
						{
							raiz->getIzq()->setColor(negro);
							if (raiz->getDer() != NULL)
								raiz->getDer()->setColor(negro);
							raiz->setColor(rojo);
							paridad = par;
						}
						else
						{
							continuar = false;
							if (lado == izquierdo)
							{
								rotarDerecha(raiz->getDer());
							}
							raiz->getDer()->setColor(negro);
							raiz->setColor(rojo);
							rotarIzquierda(raiz);
						}
					}
				}
			}
		}
	}
}
template <class T>
void ABB<T>::insertar(T elem, Nodo<T> *&raiz)
{
	insertarRojoNegro(elem, raiz);
	raiz->setColor(negro);
}
template <class T>
bool ABB<T>::buscar(T elem, Nodo<T> *raiz)
{
	if (raiz == NULL)
		return false;
	else
	{
		if (raiz->getElem() == elem)
			return true;
		else
		{
			if (elem < raiz->getElem())
				return buscar(elem, raiz->getIzq());
			else
				return buscar(elem, raiz->getDer());
		}
	}
	return false;
}
template <class T>
Nodo<T>* ABB<T>::buscarNodo(T elem, Nodo<T> *raiz)
{
	if (raiz == NULL)
		return NULL;
	else
	{
		if (raiz->getElem() == elem)
			return raiz;
		else
		{
			if (elem < raiz->getElem())
				return buscarNodo(elem, raiz->getIzq());
			else
				return buscarNodo(elem, raiz->getDer());
		}
	}
	return false;
}
template <class T>
int ABB<T>::altura(Nodo<T> *raiz)
{
	if (raiz == NULL)
		return 0;
	else
	{
		if (raiz->getIzq() == NULL && raiz->getDer() == NULL)
			return 1;
		else
		{
			int der = altura(raiz->getDer());
			int izq = altura(raiz->getIzq());
			if (izq > der)
				return izq + 1;
			else
				return der + 1;
		}
	}
}
template <class T>
int ABB<T>::alturaCorta(Nodo<T> *raiz)
{
	if (raiz == NULL)
		return 0;
	else
	{
		if (raiz->getIzq() == NULL && raiz->getDer() == NULL)
			return 1;
		else
		{
			int der = alturaCorta(raiz->getDer());
			int izq = alturaCorta(raiz->getIzq());
			if (izq < der)
				return izq + 1;
			else
				return der + 1;
		}
	}
}
template <class T>
int ABB<T>::contarNodos(Nodo<T> *raiz)
{
	if (raiz == NULL)
		return 0;
	else
	{
		return 1 + contarNodos(raiz->getDer()) + contarNodos(raiz->getIzq());
	}
}
template <class T>
Nodo<T> *ABB<T>::menor(Nodo<T> *raiz)
{
	if (raiz == NULL)
		return raiz;
	else
	{
		if (raiz->getIzq() == NULL)
			return raiz;
		else
			return menor(raiz->getIzq());
	}
}
template <class T>
Nodo<T> *ABB<T>::mayor(Nodo<T> *raiz)
{
	if (raiz == NULL)
		return raiz;
	else
	{
		if (raiz->getDer() == NULL && raiz->getIzq() == NULL)
			return raiz;
		else
			return mayor(raiz->getDer());
	}
}
template <class T>
void ABB<T>::mostrarNivel(int nivel, Nodo<T> *raiz, int altura = 0)
{
	altura++;
	if (nivel == altura && raiz != NULL)	
		raiz->mostrar();
	else if (nivel == altura && raiz == NULL)
		cout << " ";	

	if (raiz != NULL)
	{
		mostrarNivel(nivel, raiz->getIzq(), altura);
		mostrarNivel(nivel, raiz->getDer(), altura);
	}
}
template <class T>
void ABB<T>::mostrarPorNiveles(Nodo<T> *raiz)
{
	int n = altura(raiz), x = 40, y = 0;
	for (int i = 1; i <= n; i++)
	{
		gotoxy(x, y);
		mostrarNivel(i, raiz);
		x -= 2;
		y++;
	}
}
template <class T>
void ABB<T>::mostrarPostOrder(Nodo<T> *raiz)
{
	if (raiz != NULL)
	{
		if (raiz->getDer() == NULL && raiz->getIzq() == NULL)
			raiz->mostrar();
		else
		{
			mostrarPostOrder(raiz->getIzq());
			mostrarPostOrder(raiz->getDer());
			raiz->mostrar();
		}
	}
}
template <class T>
void ABB<T>::mostrarPreOrder(Nodo<T> *raiz)
{
	if (raiz != NULL)
	{
		if (raiz->getDer() == NULL && raiz->getIzq() == NULL)
			raiz->mostrar();
		else
		{
			raiz->mostrar();
			mostrarPreOrder(raiz->getIzq());
			mostrarPreOrder(raiz->getDer());
		}
	}
}
template <class T>
void ABB<T>::mostrarInOrder(Nodo<T> *raiz)
{
	if (raiz != NULL)
	{
		if (raiz->getDer() == NULL && raiz->getIzq() == NULL)
			raiz->mostrar();
		else
		{
			mostrarInOrder(raiz->getIzq());
			raiz->mostrar();
			mostrarInOrder(raiz->getDer());
		}
	}
}
template <class T>
Nodo<T>* ABB<T>::getRaiz()
{
	return raizArbol;
}
template <class T>
bool  ABB<T>::cumpleRegla(Nodo<T> *raiz)
{
	if (raiz!=NULL)
	{
		if (altura(raiz) <= 2 * alturaCorta(raiz))
		{
			return (cumpleRegla(raiz->getDer()) && cumpleRegla(raiz->getIzq()));
		}
		else
		{
			return false;
		}
	
	}
	else
	{
		return true;
	}
}
#endif