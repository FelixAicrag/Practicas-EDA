// Nombre del alumno Felix Garcia Ceballos
// Usuario del Juez C36

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Arbin.h"
#include "Exceptions.h"
#include "List.h"
#include "Queue.h"

using namespace std;

template <class T>
Arbin<T> leerArbol(const T & repVacio);

int numero_navegables_aux(Arbin<int> rio, int& caudal);
int numero_navegables(Arbin<int> rio);

// funcion que lee el arbol
template <class T>
Arbin<T> leerArbol(const T & repVacio){
	T elem;

	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else{
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi, elem, hd);
	}
}

int numero_navegables(Arbin<int> rio){
	int caudalFinal, afluentes_navegables;
	afluentes_navegables = numero_navegables_aux(rio, caudalFinal);

	if (caudalFinal > 2) afluentes_navegables--;
	return afluentes_navegables;
}

int numero_navegables_aux(Arbin<int> rio, int& caudal) {
	int numaflu = 0, caudalDr, caudalIz;
	caudal = 0;

	Arbin<int> aflIz = rio.hijoIz();
	Arbin<int> aflDr = rio.hijoDr();

	if (aflIz.esVacio() && aflDr.esVacio()) { caudal = 1; }
	else if (aflIz.esVacio()) {
		numaflu = numero_navegables_aux(aflDr, caudalDr);
		caudal = caudalDr - rio.raiz();
	}
	else if (aflDr.esVacio()) {
		numaflu = numero_navegables_aux(aflIz, caudalIz);
		caudal = caudalIz - rio.raiz();
	}
	else {
		numaflu = numero_navegables_aux(aflDr, caudalDr) + numero_navegables_aux(aflIz, caudalIz);
		caudal = caudalIz + caudalDr - rio.raiz();
	}

	if (caudal > 2) numaflu++;
	if (caudal < 0) caudal = 0;
	return numaflu;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	Arbin<int> rio = leerArbol(-1);
	int numAfl = 0;

	numAfl = numero_navegables(rio);

	if (!std::cin)
		return false;

	// escribir sol
	cout << numAfl << endl;

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


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}