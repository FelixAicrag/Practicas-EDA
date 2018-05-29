// Nombre del alumno Felix Garcia Ceballos
// Usuario del Juez C36


#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

#include "SetOfInts3.h"

using namespace std;

// función que resuelve el problema
Horas resolver(Horas hora, set<Horas> horario) {


}

class Horas {
private:
	int _tiempo;
public:
	istream& operator>>(istream& sIn, Horas& set) {
		int n;
		int d;
		sIn >> n;
		set.size = 0;
		if (sIn.fail()) return sIn;
		for (int i = 0; i < n; i++){
			sIn >> d;
			set.add(d);
		}
		return sIn;
	}

	ostream& operator<<(ostream& sOut, Horas& set) {
		sOut << "{";
		for (int i = 0; i < set.size - 1; i++)
			sOut << set.elems[i] << ",";
		if (set.size > 0) sOut << set.elems[set.size - 1];
		sOut << "}";
		return sOut;
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numtrenes, numhoras;
	Horas hora;
	set<Horas> horario;
	cin >> numtrenes >> numhoras;

	if (numtrenes < 1 && numhoras < 1)
		return false;

	for (int i = 0; i < numtrenes; i++){
		cin << hora;

	}
	for (int i = 0; i < numtrenes; i++){
		cin << hora;

	}


	Horas sol = resolver(hora, horario);

	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	//#ifndef DOMJUDGE
	//	std::ifstream in("datos.txt");
	//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	//#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	//#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//	std::cin.rdbuf(cinbuf);
	//	system("PAUSE");
	//#endif

	return 0;
}