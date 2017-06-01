#include "AVL.h"
#include <fstream>
#include "timer.h"
int main()
{
	AVL<int> arbol;
	int opcion = 1;
	int ele;
	Nodo<int> *raiz;
	Nodo<int> *resp;
	timer relojBuscar;
	timer relojInsertar;
	fstream archivo;
	archivo.open("numeros.txt");
	if (!archivo)
	{
		cout << "fin" << endl;
	}
	else
	{
		int aux;
		while (!archivo.eof())
		{
			relojInsertar.start();
			archivo >> aux;
			arbol.insertar(aux, arbol.getRaiz());
			relojInsertar.stop();
		}
		archivo.close();
	}

	while(opcion !=  13)
	{
		raiz = arbol.getRaiz();
		system("cls");
		cout << " Tiempo de Insertar 10mil " << relojInsertar << endl;
		cout << "1.  Insertar en elemento" << endl;
		cout << "2.  Buscar elemento" << endl;
		cout << "3.  Altura" << endl;
		cout << "4.  Contar nodos" << endl;
		cout << "5.  Menor" << endl;
		cout << "6.  Mayor" << endl;
		cout << "7.  Recorrer Pre Orden" << endl;
		cout << "8.  Recorrer Post Orden" << endl;
		cout << "9.  Recorrer In Orden" << endl;
		cout << "10. Mostrar Raiz" << endl;
		cout << "11. Validar" << endl;
		cout << "12. BuscarComparar" << endl;
		cout << "13. SALIR" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		switch(opcion)
		{
		case 1:
			cout << "elemento: ";
			cin >> ele;
			if(arbol.insertar(ele,raiz) == true)
				cout << "Elemento agregado";
			
			break;
		case 2:
			cout << "elemento: ";
			cin >> ele;
			if(arbol.buscarElemento(ele,raiz) != NULL)
				cout << "Elemento encontrado";
			else
				cout << "No se encontro elemento";
			break;
		case 3:
			cout << "La altura es: " << arbol.altura(raiz);
			break;
		case 4:
			cout << "El numero de nodos es: " << arbol.contarNodos(raiz);
			break;
		case 5:
			resp = arbol.Menor(raiz);
			if(resp == NULL)
				cout << "Arbol vacio";
			else
				resp->mostrar();
			break;
		case 6:
			resp = arbol.Mayor(raiz);
			if (resp == NULL)
				cout << "Arbol vacio";
			else
				resp->mostrar();
			break;
		case 7:
			arbol.mostrarPreOrder(raiz);
			break;
		case 8:
			arbol.mostrarPostOrder(raiz);
			break;
		case 9:
			arbol.mostrarInOrder(raiz);
			break;
		case 10:
			raiz->mostrar();
			break;
		case 11:
			if (arbol.validarAVL(raiz))
			{
				cout << "Es Valido" << endl;
			}
			else
			{
				cout << "No es Valido" << endl;
			}
			break;
		case 12:
			relojBuscar.start();
			int auxCont=1;
			do {
				arbol.buscarElemento(-1, raiz);
				auxCont++;
			} while (auxCont < 10000);
			relojBuscar.stop();
			cout << " Tiempo de Buscar -1 10mil Veces " << relojBuscar << endl;
			break;
		}
		_getch();
	}
	return 0;
		
}