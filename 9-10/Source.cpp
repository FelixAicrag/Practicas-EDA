//Felix Garcia Ceballos
//Raul Diego Navarro
//C36

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Arbin.h"
#include "Exceptions.h"
#include "List.h"
#include "Queue.h"

using namespace std;

template <class T>
Arbin<T> leerArbol9_10(T tipo);

int nodos_singulares(Arbin<int> arbol);
int nodos_singulares_aux(Arbin<int> arbol, int& solucion, int valorHeredado);

//Lee el arbol conforme al formato del ejercicio 9-10 - Nodos singulares.
template <class T>
Arbin<T> leerArbol9_10(T tipo){
	T elem;
	char aux;
	Arbin<T> output;

	cin >> aux;

	switch (aux) {
	case ('#') : //Es un arbol vacio.
		output = Arbin<T>();
		break;
	case ('[') : //Es un nodo hoja.
		cin >> elem;
		output = Arbin<T>(elem);
		cin >> aux;
		break;
	case ('(') : //Es un nodo no-hoja.
		Arbin<T> hi;
		Arbin<T> hd;
		
		hi = leerArbol9_10(tipo);
		cin >> elem;
		hd = leerArbol9_10(tipo);
		output = Arbin<T>(hi, elem, hd);
		cin >> aux;
		break;
	}

	return output;
}

/*
Calcula cuantos nodos del arbol tienen hijos que sumen exactamente lo mismo que todos sus padres.
COSTE EN TIEMPO: Lineal en N, siendo N el numero de elementos del arbol.
Esto se debe a que cada nodo se llama una sola vez, y la solucion se realiza mediante una variable global
que se incrementa sin necesidad de volver a recorrer los hijos.
*/
int nodos_singulares(Arbin<int> arbol){
	int solucion = 0;
	nodos_singulares_aux(arbol, solucion, 0);
	return solucion;
}

int nodos_singulares_aux(Arbin<int> arbol, int& solucion, int valorHeredado) {
	int output = 0;
	
	if (!arbol.esVacio()) {
		int demesne = arbol.raiz() + valorHeredado;
		int valorHijos = nodos_singulares_aux(arbol.hijoIz(), solucion, demesne) + nodos_singulares_aux(arbol.hijoDr(), solucion, demesne);

		if (valorHijos == valorHeredado) solucion++;

		output = valorHijos + arbol.raiz();
	}

	return output;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// Leer los datos de entrada.

	Arbin<int> arbol = leerArbol9_10(0);
	int numsing = nodos_singulares(arbol);

	if (!std::cin)
		return false;

	// Escribir solucion.
	cout << numsing << endl;

	return true;

}

#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}