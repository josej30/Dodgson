#include <iostream>
#include <vector>
#include<math.h> 

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
  MatPref perfil_aux = perfil;
  int tam = perfil.size();
  for (unsigned i = 0; i < tam ; i++) {    
     vector<int> z = perfil_aux.back();
     perfil_aux.pop_back();
     for ( unsigned j = 0; j < z.size(); j++ )
       cout << " " << z[j];
     cout << endl;
   }
  cout<< endl;
}

/* Funcion para verificar que dos nodos sean iguales, 
   retorna 1 sino lo son, 0 en caso contrario */

/*int repetidos(Nodo x, Nodo y){
  int checkSum1, checkSum2, checkTot1 = 0, checkTot2 = 0;
  int tam = y.perfil.size();
  // Si la matriz no es del mismo tamano ya descarto que sean iguales
  if (x.perfil.size() != y.perfil.size()){
    return 0;
  }
  else{
    for (unsigned i = 0; i< tam ; i++) {    
      vector<int> z = x.perfil.back();
      vector<int> w = y.perfil.back();
      x.perfil.pop_back();
      y.perfil.pop_back();
      
      // Verifico que cada columna tenga el mismo tamano
      if  (z.size() != w.size())
	return 0;
      else{
	checkSum1 = 0;
	checkSum2 = 0;
	for ( unsigned j = 0; j < z.size(); j++ ){
       
	  checkSum1 += pow(z[j],j);
	  checkSum2 += pow(w[j],j);
	}

	checkTot1 = checkTot1 + checkSum1;
	checkTot2 = checkTot2 + checkSum2;

      }
    }
    // Verifico que los elementos sean iguales
    if (checkTot1 != checkTot2)
      return 0;
    return 1;
  }
}*/


int repetidos(Nodo x, Nodo y){
  MatPref perfil_aux1 = x.perfil;
  MatPref perfil_aux2 = y.perfil;
  //bool igual = true;
  if (x.perfil.size() != y.perfil.size()){
    return 0;
  }
  else {
    int tam = x.perfil.size();
    for (unsigned k = 0; k < tam; k++){
      vector<int> z = x.perfil.at(k);
      for (unsigned i = 0; i < tam ; i++) {    
	vector<int> w = y.perfil.at(i);
	cout << " i " << i;
	cout << " k " << k;

	cout << " wp " << w[0];	 
	cout << " zp " << z[0];
	if (z[0] == w[0]){
	  perfil_aux1.erase (perfil_aux1.begin()+k);
	  perfil_aux2.erase (perfil_aux2.begin()+k);
	  for ( unsigned j = 1; j < z.size(); j++ ){



	    if  (z[j] != w[j]) 
	      return 0;
	  }
	}
      }
    }
    if (perfil_aux1.size() == 0 and perfil_aux2.size() == 0)
      return 1;
    else
      return 0;
    
  }
}

int main () {
  Nodo nodo;
  Nodo nodo1;
  vector <int> d, e, f,g,i;
  d.push_back(1);  d.push_back(0);  d.push_back(8);
  e.push_back(0); e.push_back(1); e.push_back(8);
  g.push_back(2);  g.push_back(2);  g.push_back(1);
  f.push_back(5);  f.push_back(1);  f.push_back(2);
  i.push_back(1);  i.push_back(2);  i.push_back(4);


 
  nodo.insertar(e);
  nodo.insertar(d);
  //nodo.insertar(f);
  nodo.insertar(g);
  
  nodo1.insertar(f);
  //nodo1.insertar(i);
  nodo1.insertar(d);
  nodo1.insertar(e);
  
  cout << "Son iguales: " << repetidos(nodo,nodo1) << endl;
  nodo.mostrar();
  nodo1.mostrar();
  return 0;
}
