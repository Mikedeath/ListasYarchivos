#pragma once

struct node {
	int data;
	node*next;
	node*prev;
};

class UtilidadesListaEnlazada {

public:

	static void OrdenarLista(node*&,node *&tail);
	static void CrearLista(node*&head, node*tail, int num);
	static void	agregarPrimero(node*&, node*&, int );
	static void agregarNodo(node*&, node*&, int);
	static bool vacio(node*&);
	static void imp_lista(node *&);
	static void guardar_lista(node*&,char*);


};