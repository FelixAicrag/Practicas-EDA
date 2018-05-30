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


//Lee una lista de un tipo generico por teclado, con el centinela indicado por parametro.
template <class T>
List<T> getList_sentinel(T sentinel){

	List<T> list;
	T input;

	cin >> input;

	while (input != sentinel){
		list.push_back(input);
	
		cin >> input;
	}

	return list;
}





template <class T>
Arbin<T> reconstruirArbol(List<T>& postorden, List<T>& inorden){
	Arbin<T> hijoIz, hijoDr;
	List<T> hi_post, hi_in;


	if (postorden.empty()) return Arbin<T>();

	T raiz = postorden.back();

	postorden.pop_back();

	if (postorden.empty()) return Arbin<T>(raiz);

	while (inorden.front() != raiz) {
		hi_post.push_back(postorden.front());
		hi_in.push_back(inorden.front());

		postorden.pop_front();
		inorden.pop_front();
	}

	inorden.pop_front();

	hijoIz = reconstruirArbol(hi_post, hi_in);
	hijoDr = reconstruirArbol(postorden, inorden);

	return Arbin<T>(hijoIz, raiz, hijoDr);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso912() {
	// Leer los datos de entrada.

	List<int> postorden = getList_sentinel(-1);
	List<int> inorden = getList_sentinel(-1);


	if (inorden.empty() && postorden.empty())
		return false;

	Arbin<int> arbol = reconstruirArbol(postorden, inorden);

	List<int> *niveles = arbol.niveles();

	// Escribir solucion.
	cout << (*niveles);

	return true;

}

#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


	while (resuelveCaso912())
		;


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}