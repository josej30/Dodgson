#include <iostream>
#include <vector>
#include "nodo.h"

using namespace std;

void Nodo::insertar(vector<int> c) {
  perfil.push_back(c);
}

void Nodo::mostrar(){
  for (unsigned i = 0; i <= perfil.size() ; i++) {    
    vector<int> z = perfil.back();
    perfil.pop_back();
    for ( unsigned j = 0; j < z.size(); j++ )
      cout << " " << z[j];
    cout << endl;
  }
  
}
