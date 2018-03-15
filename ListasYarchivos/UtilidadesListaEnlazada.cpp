#include "UtilidadesListaEnlazada.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;
bool UtilidadesListaEnlazada::vacio(node*&head) {
	if (head == NULL)
		return true;
	else
		return false;

}
void UtilidadesListaEnlazada::imp_lista(node *&current)
{
	if (vacio(current))
		cout << "Esta vacio" << endl;
	else {
		cout << "La lista contiene\n";
		while (current != NULL) {
			cout << (int)current->data << endl;
			current = current->next;
		}
	}

}
void UtilidadesListaEnlazada::guardar_lista(node *&current, char* nombre)
{
	ofstream ListasOut(nombre, ios::out);
	if (!ListasOut) {
		cout << "Error con el archivo" << endl;
		return;
	}

	while (current != NULL) {
		ListasOut << (int)current->data << ' ';
		current = current->next;
	}
	cout << " " << endl;
	ListasOut.close();

}
void UtilidadesListaEnlazada::OrdenarLista(node *&current, node *&tail)
{
	vector<int> numeros;
	while (current != NULL) {
		numeros.push_back(current->data);
		current = current->next;
	}
	int temp;
	for (int i = 0; i < numeros.size(); i++) {
		for (int j = 0; j < numeros.size() - 1; j++) {
			if (numeros[j] > numeros[j + 1]) {
				temp = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < numeros.size(); i++)
	{
		int numr;
		numr = numeros[i];
		agregarNodo(current, tail, numr);

	}

}
void UtilidadesListaEnlazada::CrearLista(node*&head, node*tail, int num)
{

	for (int i = 0; i < num; i++)
	{
		int numr;
		numr = rand() % num;
		agregarNodo(head, tail, numr);

	}

}
void UtilidadesListaEnlazada::agregarPrimero(node*&head, node*&tail, int num) {
	node*temp = new node;
	temp->data = num;
	temp->next = NULL;
	temp->prev = NULL;
	head = temp;
	tail = temp;

}
void UtilidadesListaEnlazada::agregarNodo(node*&head, node*&tail, int num) {
	if (vacio(head)) {
		agregarPrimero(head, tail, num);
	}
	else {
		node*temp = new node;
		temp->data = num;
		temp->next = NULL;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;

	}
}

int main() {
	node *head = NULL; //Cabeza
	node *tail = NULL;//Cola
	UtilidadesListaEnlazada u;
	char* nombre = new char;

	do
	{
		int opcion;
		int num = 0;
		cout << "1. Crear nueva lista" << endl;
		//cout << "2.Imprimir lista" << endl;
	//	cout << "3. Ordenar lista" << endl;
		cout << "2. Guardar lista" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:

			cout << "Cuantos nodos quiere agregar?" << endl;
			cin >> num;
			u.CrearLista(head, tail, num);

			break;
		
		case 2:
			cout << "Ingrese el nombre de su archivo de esta manera -> (nombre_de_su_archivo.dat)" << endl;
			cin >> nombre;
			u.OrdenarLista(head, tail);
			u.guardar_lista(head, nombre);
			break;

		}

	} while (true);

}