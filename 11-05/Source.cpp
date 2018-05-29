// Nombre de los alumnos
// Felix Garcia Ceballos, Raul Diego Navarro
// Usuario del Juez C36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "IPud.h"
#include "List.h"
#include "Exceptions.h"

using namespace std;

bool resolver(string input, IPud &ae);

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	IPud ae;
	string input;
	bool salir = false;


	 do {
		 // leer los datos de la entrada

		 cin >> input;

		 if (!std::cin)
			 return false;

		 // escribir sol

		salir = resolver(input, ae);

	 } while (!salir);

	return true;

}

bool resolver(string input, IPud &ipud) {
	string s, a;
	int d, n;
	bool salir = false;

	 if (input != "FIN") {
		if (input == "addSong") {
			cin >> s >> a >> d;
			try {
				ipud.addSong(s, a, d);
			}
			catch (InvalidAccessException) {
				cout << "ERROR " << input << endl;
			}
		}
		if (input == "addToPlaylist") {
			cin >> s;
			try {
				ipud.addToPlaylist(s);
			}
			catch (InvalidAccessException) {
				cout << "ERROR " << input << endl;
			}
		}
		if (input == "current") {
			try {
				ipud.current();
				//cout << currentSong << endl;
			}
			catch (InvalidAccessException) {
				cout << "ERROR " << input << endl;
			}
		}
		if (input == "play") {
			string sonando = ipud.play();

			if (sonando == "") cout << "No hay canciones en la lista" << endl;
			else cout << "Sonando " << sonando << endl;

		}
		if (input == "totalTime") {
			cout << "Tiempo total " << ipud.totalTime() << endl;
		}
		if (input == "recent") {
			cin >> n;
			List<string> listaRecientes = ipud.recent(n);
			if (listaRecientes.empty()) cout << "No hay canciones recientes" << endl;
			else {
				cout << "Las " << listaRecientes.size() << " mas recientes" << endl;
				while (!listaRecientes.empty()) {
					cout << "    " << listaRecientes.front() << endl;
					listaRecientes.pop_front();
				}
			}
		}
		if (input == "deleteSong") {
			cin >> s;
			ipud.deleteSong(s);
		}
	 }
	 else {

		 cout << "----" << endl;
		 salir = true;
	 }

	 return salir;
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