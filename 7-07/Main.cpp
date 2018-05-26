//Grupo C36
//Felix Garcia Ceballos
//Raul Diego Navarro

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include "Set.h"

using namespace std;

template<class T>
void getMaximos(Set<T> &miSet, const int k, T cent);

int main(){
	/**
	3) (Contestada en la funcion getMaximos().)
	4 a)
		Es posible reducir a O(1) la funcion removeMin()
		si guardamos los elementos de mayor a menor, 
		a cambio de empeorar el coste de removeMax().
	4 b)
        
		Una solucion posible para reducir el coste de ambas operaciones sin aumentar el de ninguna otra seria guardar en memoria tanto 
		la ultima posicion ocupada del array (fin) como la primera (ini). 
		De este modo el removeMin() se ejecutaria de forma analoga al removeMax().
		Como contrapartida, la operacion reallocate se ejecutaria mas veces de las estrictamente necesarias (ver figura), pero no afectaria al coste
		de la funcion. 
		                                            v fin
		---------------------------------------------
		|   |   |   |   |   |   |   | 1 | 2 | 3 | 4 |
		---------------------------------------------
		                            ^ ini

		Habria que cambiar las funciones isEmpty(), add(), contains(), reallocate() para que funcionen con ini/fin en lugar de con size.
	*/
	char caso;
	int k;
	string input;
	Set<int> miSetInt;
	Set<string> miSetStr;

	cin >> caso;
	while (cin){

		cin >> k;
		if (caso == 'N') { 
			getMaximos(miSetInt, k, -1); 
			cout << miSetInt << endl; 
			miSetInt.erase(); 
		}
		if (caso == 'P') { 
			getMaximos(miSetStr, k, string("FIN")); 
			cout << miSetStr << endl; 
			miSetStr.erase();
		}
	
		cin >> caso;
	}

	return 0;
}

template<class T>
void getMaximos(Set<T> &miSet, const int k, T cent){ 
	/**COSTE TOTAL:
	O(n*log(k)) donde n es el numero de elementos a comprobar.
	Suponiendo que k << n es mas eficiente que O(n*log(n))
	*/
	T var;
	cin >> var;
	while (var != cent){ //O(n) donde n = numero de variables a comprobar.
		if (miSet.getSize() < k) {
			miSet.add(var); //O(log(k)) por la busqueda binaria en miSet
		}
		else if (miSet.getMin() < var && !miSet.contains(var)){ //O(log(k)) por la busqueda binaria en miSet
			miSet.removeMin();
			miSet.add(var);
		}
		cin >> var;
	}
}