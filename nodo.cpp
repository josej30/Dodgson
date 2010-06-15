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

/* Funcion para verificar que dos nodos sean iguales, 
   retorna -1 sino lo son, 0 en caso contrario */

int repetidos(Nodo x, Nodo y){
  // Si la matriz no es del mismo tamano ya descarto que sean iguales
  if (x.perfil.size() != y.perfil.size()){
    return -1;
  }
  else{
    for (unsigned i=0; i< x.perfil.size() ; i++) {    
      vector<int> z = x.perfil.back();
      vector<int> w = y.perfil.back();
      x.perfil.pop_back();
      y.perfil.pop_back();
      // Verifico que cada columna tenga el mismo tamano
      if  (z.size() != w.size())
	return -1;
      else{
	for ( unsigned i = 0; i < z.size(); i++ )
	  // Verifico que los elementos sean iguales
	  if (z[i] != w[i])
	    return -1;
	return 0;
      }
    }
  }
}
