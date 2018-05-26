// Nombre de los alumnos
// Felix Garcia Ceballos, Raul Diego Navarro
// Usuario del Juez C36

#include "HashMap.h"
#include "TreeMap.h"
#include "List.h"



class Autoescuela {


private:

	struct infoAlumno {
		int nota;
		string profesor;
	};

	class infoProfe {
	public:
		TreeMap<string, int> info; //Valor no se usa. (No funcionaba el campus asi que no he podido sacar el treeSet)
	};

	HashMap<string, infoAlumno> _alumnos; //Todos los alumnos, cada uno con su profesor y su nota.
	HashMap<string, infoProfe> _profes; //Todos los profesores, cada uno con un treeset de todos los alumnos.

public:

	Autoescuela() : _profes() {

	}

	//O(1) en promedio.
	void alta(string alu, string prof) {

		if (!_alumnos.contains(alu)) { //O(1)
			infoAlumno nuevo;
			nuevo.nota = 0;
			nuevo.profesor = prof;

			_alumnos.insert(alu, nuevo); //O(1)
			_profes[prof].info.insert(alu, 0); //O(1)
		} 
		else {
			string profe_viejo = _alumnos[alu].profesor; //O(1)
			_profes[profe_viejo].info.erase(alu); //O(1)

			_alumnos[alu].profesor = prof; //O(1)
			_profes[prof].info.insert(alu, 0); //O(1)
		
		}
	};

	//O(1) en promedio.
	bool es_alumno(string alu, string prof) {
		return (_alumnos[alu].profesor == prof);
	};

	//O(1) en promedio.
	int puntuacion(string alu){	
		if (!_alumnos.contains(alu)) throw InvalidAccessException("El alumno A no esta matriculado.");
		else return _alumnos[alu].nota;
	};

	//O(1) en promedio. 
	void actualizar(string alu, int nota) {
		if (!_alumnos.contains(alu)) throw InvalidAccessException("El alumno A no esta matriculado.");
		else _alumnos[alu].nota += nota;
	};

	//O(n), siendo n el numero de alumnos del profesor.
	List<string> examen(string prof, int nota) {
		List<string> outList;

		TreeMap<string, int> :: ConstIterator cit = _profes[prof].info.cbegin();

		while (cit != _profes[prof].info.cend()){
			if (_alumnos[cit.key()].nota >= nota) outList.push_back(cit.key());
			cit.next();
		}

		return outList;
	}

	//O(1) en promedio.
	void aprobar(string alu) {
		if (!_alumnos.contains(alu)) throw InvalidAccessException("El alumno A no esta matriculado."); //O(1)
		else {
			string profe = _alumnos[alu].profesor; //O(1)
			_profes[profe].info.erase(alu); //O(1)
			_alumnos.erase(alu); //O(1)
		}
	};
};