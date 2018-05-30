//Felix Garcia Ceballos
//Raul Diego Navarro
//C36

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Arbin.h"
#include "Exceptions.h"
#include "PrintableList.h"
#include "Queue.h"

using namespace std;

template <class T>
Arbin<T> reconstruirArbol(List<T>& postorden, List<T>& inorden);


//Lee una arbol en preorden de un tipo generico por teclado, con el centinela indicado por parametro.
template <class T>
Arbin<T> getArbol(T sentinel){

	List<T> list;
	T input;

	cin >> input;

	if (input != sentinel){
		Arbin<T> hijoIz = getArbol(sentinel);
		Arbin<T> hijoDr = getArbol(sentinel);
			
		return Arbin<T>(hijoIz, input, hijoDr);
	}
	else return Arbin<T>();
}





template <class T>
bool esBusqueda(Arbin<T>& arbol){
	

	if (arbol.esVacio()) return true; //El arbol no existe. Esta ordenado.
	else{
		Arbin<T> hijoDr = arbol.hijoDr(), hijoIz = arbol.hijoIz();
		if (hijoDr.esVacio() && hijoIz.esVacio()) return true; //El arbol no tiene hijos. Esta ordenado.

		if (!hijoDr.esVacio() && !hijoIz.esVacio()) { //Tiene los dos hijos.
			if (hijoIz.raiz() < arbol.raiz() && arbol.raiz() < hijoDr.raiz() && esBusqueda(hijoIz) && esBusqueda(hijoDr)) return true;
			else return false;
		};

		if (!hijoIz.esVacio()) { //Solo tiene hijo izquierdo.
			if (hijoIz.raiz() < arbol.raiz() && esBusqueda(hijoIz)) return true; 
			else return false; }; 

		if (!hijoDr.esVacio()) { //Solo tiene hijo derecho.
			if (arbol.raiz() < hijoDr.raiz() && esBusqueda(hijoDr)) return true; 
			else return false; }; 
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso913() {
	// Leer los datos de entrada.

	Arbin<int> arbol = getArbol(-1);

	// Escribir solucion.
	if (esBusqueda(arbol)) cout << "SI" << endl;
	else cout << "NO" << endl;

	
}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 

	int numcasos;

	cin >> numcasos;
	for (int i = 0; i < numcasos; i++) { resuelveCaso913(); };

	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}