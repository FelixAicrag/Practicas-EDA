//Felix Garcia Ceballos
//Raul Diego Navarro
//C36

#include <iostream>
#include <fstream>
#include "List.h"
#include <cstdlib>

using namespace std;

template <class T>
void mostrarLista(List<T>* l){
	typename List<T>::ConstIterator it = l->cbegin();
	if (it != l->cend()){
		cout << it.elem();
		it.next();
	}
	while (it != l->cend()){
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}

int main(){
	int numCasos;
	int n;
	int pringao;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		List<int>* q = new List<int>();
		cin >> n;
		while (n != -1){
			q->push_back(n);
			cin >> n;
		}

		cin >> pringao;
		List<int>* colegas = new List<int>();
		cin >> n;
		while (n != -1){
			colegas->push_back(n);
			cin >> n;
		}

		mostrarLista(q);
		q->jump(pringao, *colegas);
		mostrarLista(q);
		delete q;
		delete colegas;
	}
}