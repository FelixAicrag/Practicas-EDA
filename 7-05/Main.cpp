//C36
//Felix Garcia Ceballos
//Raul Diego Navarro


#include <iostream>
#include <iomanip>
#include <fstream>




#include "SetOfInts3.h"


using namespace std;


int main(){
	SetOfInts3 set1, set2;

	cin >> set1 >> set2;

	while (cin){
		cout << (set1 == set2) << endl;
		cin >> set1 >> set2;
	}
}