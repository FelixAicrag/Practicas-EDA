// Nombre del alumno Felix Garcia Ceballos
// Usuario del Juez C36


#include <iostream>
#include <iomanip>
#include <fstream>

#include "Queue.h"
#include "Stack.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elem;
	Queue <int> qu;
	Stack<int> st;

	cin >> elem;

	while (elem != 0) { 
		st.push(elem); 
		cin >> elem; 
	};

	while (!st.empty()) { 
		qu.push_back(st.top()); 
		st.pop();
	};
	


	if (!std::cin)
		return false;

	// escribir sol
	while (!qu.empty()){
		cout << qu.front() << " ";
		qu.pop_front();
	};
	cout << endl;
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	*/


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	*/
	return 0;
}