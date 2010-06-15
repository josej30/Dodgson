#include <iostream>
#include <vector>

typedef std::vector<int> Pref;
typedef std::vector<Pref> MatPref;

using namespace std;

class Nodo {

public:

  MatPref perfil; /* Matriz que representa las preferencias */
  /* Metodos de la clase Nodo */
  void insertar(vector<int>); /* Inserta una preferencia a la matriz */ 
  void mostrar(); /* Muestra un preferencia*/
};

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

int main () {
  Nodo nodo;
  Nodo nodo1;
  vector <int> d, e;
  d.push_back(0);  d.push_back(8);  d.push_back(1);
  e.push_back(1); e.push_back(23); e.push_back(40);
  nodo.insertar(d);
  nodo.insertar(e);
  nodo.mostrar();
 
  nodo1.insertar(d);
  cout << "Son iguales: " << repetidos(nodo,nodo1) << endl;
  return 0;
}
