//Felix Garcia Ceballos
//Raul Diego Navarro
//C36

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void diferenciasDiccionario(map <string, int> const& map1, map <string, int> const& map2, vector <string> & vector1, vector <string> & vector2, vector <string> & vector3);
void resuelveCaso();


int main() {
	int n;
	cin >> n;
	char c;
	cin.get(c);
	for (int i = 0; i < n; ++i)
		resuelveCaso();
	return 0;
}

void resuelveCaso() {
	string aux1, aux2, clave;
	int valor;
	stringstream auxStream;
	map <string, int> map1, map2;
	vector <string> vector1;
	vector <string> vector2;
	vector <string> vector3;

	getline(cin, aux1);
	auxStream << aux1;

	while (auxStream >> clave >> valor) {
		map1.insert({ clave, valor });
	}
	getline(cin, aux2);
	auxStream.clear();
	auxStream << aux2;
	while (auxStream >> clave >> valor) {
		map2.insert({ clave, valor });
	}

	diferenciasDiccionario(map1, map2, vector1, vector2, vector3);
	if (vector1.size() == 0 && vector2.size() == 0 && vector3.size() == 0) cout << "Sin cambios\n";
	else {
		if (vector1.size() > 0) {
			cout << "+ ";
			for (int i = 0; i < vector1.size(); ++i) {
				cout << vector1[i];
				if (i < vector1.size()) cout << " ";
			}
			cout << '\n';
		}

		if (vector2.size() > 0) {
			cout << "- ";
			for (int i = 0; i < vector2.size(); ++i) {
				cout << vector2[i];
				if (i < vector2.size()) cout << " ";
			}
			cout << '\n';
		}

		if (vector3.size() > 0) {
			cout << "* ";
			for (int i = 0; i < vector3.size(); ++i) {
				cout << vector3[i];
				if (i < vector3.size()) cout << " ";
			}
			cout << '\n';
		}
	}
	cout << "----\n";
}

void diferenciasDiccionario(map <string, int> const& map1, map <string, int> const& map2, vector <string> & vector1, vector <string> & vector2, vector <string> & vector3) {

	auto auto1 = map1.begin();
	auto auto2 = map2.begin();

	while (auto1 != map1.end() || auto2 != map2.end()) {
		if (auto1 == map1.end()) {
			vector1.push_back(auto2->first);
			auto2++;
		}
		else if (auto2 == map2.end()) {
			vector2.push_back(auto1->first);
			auto1++;
		}
		else {
			if (auto1->first == auto2->first && auto1->second != auto2->second) {
				vector3.push_back(auto1->first);
				auto1++;
				auto2++;
			}
			else if (auto1->first > auto2->first) {
				vector1.push_back(auto2->first);
				auto2++;
			}
			else if (auto1->first < auto2->first) {
				vector2.push_back(auto1->first);
				auto1++;
			}
			else {
				auto1++;
				auto2++;
			}
		}
	}
}