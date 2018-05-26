// Nombre de los alumnos
// Felix Garcia Ceballos, Raul Diego Navarro
// Usuario del Juez C36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Autoescuela.h"
#include "List.h"
#include "Exceptions.h"

using namespace std;

bool resolver(string input, Autoescuela &ae);

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	Autoescuela ae;
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

bool resolver(string input, Autoescuela &ae) {
	string alumno, profe;
	int nota;
	bool salir = false;

	 if (input != "FIN") {
		if (input == "alta") {
			cin >> alumno >> profe;
			ae.alta(alumno, profe);
		}
		if (input == "es_alumno") {
			cin >> alumno >> profe;
			if (ae.es_alumno(alumno, profe)) cout << alumno << " es alumno de " << profe << endl;
			else cout << alumno << " no es alumno de " << profe << endl;
		}
		if (input == "puntuacion") {
			cin >> alumno;
			try {
				nota = ae.puntuacion(alumno);
				cout << "Puntuacion de " << alumno << ": " << nota << endl;
			}
			catch (InvalidAccessException) {
				cout << "ERROR" << endl;
			}
		}
		if (input == "actualizar") {
			cin >> alumno >> nota;
			try {
				ae.actualizar(alumno, nota);
			}
			catch (InvalidAccessException) {
				cout << "ERROR" << endl;
			}
		}
		if (input == "examen") {
			cin >> profe >> nota;
			List<string> lista_examen = ae.examen(profe, nota);

			cout << "Alumnos de " << profe << " a examen:" << endl;

			while (!lista_examen.empty()) {
				cout << lista_examen.front() << endl;
				lista_examen.pop_front();
			}
		}

		if (input == "aprobar") {
			cin >> alumno;
			try {
				ae.aprobar(alumno);
			}
			catch (InvalidAccessException) {
				cout << "ERROR" << endl;
			}
		}
	 }
	 else {

		 cout << "------" << endl;
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