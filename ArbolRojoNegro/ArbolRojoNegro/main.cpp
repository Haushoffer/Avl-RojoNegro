#include "ABB.h"
#include "timer.h"
ABB<int> tree;
Nodo<int>* raiz = tree.getRaiz();
int n = 10, aux;
timer relojBuscar;
timer relojInsertar;
void acciones(int opcion)
{
	switch (opcion)
	{
	case 1: cout << "Ingrese elemento: "; cin >> opcion; tree.insertar(opcion, raiz);  break;
	case 2: cout << "Ingrese elemento: "; cin >> opcion;  if (tree.buscar(opcion, raiz))
															cout << "El elemento existe en el arbol." << endl; 
														  else 
															cout << "El elemento no existe en el arbol."; 
												break;
	case 3: cout << "Altura del arbol: " << tree.altura(raiz); break;
	case 4: cout << "Cantidad de nodos: " << tree.contarNodos(raiz); break;
	case 5: if (tree.menor(raiz) == NULL)
			{ 
				cout << "No tiene menor." << endl; 
			}
			else
			{
				cout << "El menor es: ";
				tree.menor(raiz)->mostrar();
				cout << endl;
			} break;
	case 6: if (tree.mayor(raiz) == NULL)
			{
				cout << "No tiene mayor." << endl;
			}
			else
			{
				cout << "El mayor es: ";
				tree.mayor(raiz)->mostrar();
				cout << endl;
			} break;
	case 7:  tree.mostrarPorNiveles(raiz); break;
	case 8: tree.mostrarPreOrder(raiz); break;
	case 9: tree.mostrarInOrder(raiz); break;
	case 10: tree.mostrarPostOrder(raiz); break;
	case 11: cout << "Altura corta del arbol: " << tree.alturaCorta(raiz); break;
	case 12: cout << "La raiz es: "; raiz->mostrar(); break;
	case 13: cout << "Arbol: " << endl;
		if (tree.cumpleRegla(raiz))
		{
			cout << "Cumple regla" << endl;
		}
		else
		{
			cout << "No cumple regla" << endl;
		}
		break;
	case 14:
		relojBuscar.start();
		int auxCont = 1;
		do {
			tree.buscar(-1, raiz);
			auxCont++;
		} while (auxCont < 10000);
		relojBuscar.stop();
		cout << " Tiempo de Buscar -1 10mil Veces " << relojBuscar << endl;
		break;
	}
}

void menu()
{
	
	int opcion = 0;
	while (opcion!=15)
	{
		cout << "1.  Insertar" << endl;
		cout << "2.  Buscar" << endl;
		cout << "3.  Altura" << endl;
		cout << "4.  Contar Nodos" << endl;
		cout << "5.  Menor" << endl;
		cout << "6.  Mayor" << endl;
		cout << "7.  Mostrar por niveles" << endl;
		cout << "8. Mostrar PreOrder" << endl;
		cout << "9. Mostrar InOrder" << endl;
		cout << "10. Mostrar PostOrder" << endl;
		cout << "11. Altura Corta" << endl;
		cout << "12. Mostrar raiz" << endl;
		cout << "13. Validar Regla de Arbol RN" << endl;
		cout << "14 BuscarComparar" << endl;
		cout << "15 Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		acciones(opcion);
		cin.get();
		cin.ignore();
		system("cls");
	}
}

int main()
{
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
			tree.insertar(aux, raiz);
			relojInsertar.stop();
		}
		archivo.close();
	}
	cout << " Tiempo de insertar 10mil " << relojInsertar << " " << endl;
	menu();
	return 0;
}
