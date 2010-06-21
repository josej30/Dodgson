#include "nodo.h"

using namespace std;

/*Nodo::Nodo(vector< vector <int> > p){
	perfil = p;	
}*/


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


/*int repetidos(Nodo x, Nodo y){
  
  MatPref n1 = x.perfil;
  MatPref n2 = y.perfil;
  int j;

  // Veo si el tamano de ambos nodos es igual
  if (n1.size() != n2.size())
    return 0;
  else{
    // Fijo la ultima columna del nodo 1.
    for (unsigned i = x.perfil.size() - 1; i >= 1; i--){
      vector<int> pref_n1 = n1.at(i);
      j = 0;
      // Itero sobre las columnas del nodo 2 en busca de una columna igual.
      while (j < n2.size()){
	vector<int> pref_n2 = n2.at(j);
	// Verifico que la matriz este compuesta de las mismas columnas.
	if (pref_n1[0] != pref_n2[0]) 
	  j++;
	else{
	  //Itero sobre los elementos de las columnas
	  for (unsigned k = 1; k < pref_n2.size(); k++ ){
	    //Si hay algun elemento diferente concluyo que son diferentes
	    if (pref_n1[k] != pref_n2[k]){
	      return 0;
	    }	   
	  }
	  // Voy eliminando columnas hasta quedar con una sola (caso base)
	  if (n1.size() >=1  and n2.size() >= 1){
	    n1.erase(n1.begin() + i);
	    n2.erase(n2.begin() + j);
	    j = y.perfil.size();
	  }

	}
      }
      /* Corroboro que luego de iterar sobre el nodo 2 se haya eliminado una columna
	 lo que indica que hubo al menos una coincidencia */
  /*    if (n1.size() == x.perfil.size()) 
	return 0;	                
    
    }
    /* Caso base, me quedan dos columnas las cuales voy a comparar*/
    /*if (n1.size() == 1 and n2.size() == 1){
      vector <int> pref_n1 = n1.at(0);
      vector <int> pref_n2 = n2.at(0);
      if (pref_n1[0] == pref_n2[0]){
	for (unsigned k = 1; k < pref_n2.size(); k++ ){
	  if (pref_n1[k] != pref_n2[k])
	    return 0;
	}
	return 1;
      }
      else
	return 0;
    }
      
  }
}*/




/*
int main () {
 Nodo nodo;
  Nodo nodo1;
  vector <int> d, e, f,g,i;
  d.push_back(1);  d.push_back(0);  d.push_back(8);
  e.push_back(0); e.push_back(1); e.push_back(8);
  g.push_back(4);  g.push_back(2);  g.push_back(1);
  f.push_back(5);  f.push_back(1);  f.push_back(2);
  i.push_back(1);  i.push_back(2);  i.push_back(4);


 
  nodo.insertar(e);
  nodo.insertar(d);
  //nodo.insertar(f);
  nodo.insertar(g);
  
  //nodo1.insertar(f);
  nodo1.insertar(i);
  nodo1.insertar(d);
  nodo1.insertar(e);
  
  
  nodo.mostrar();
  nodo1.mostrar();
  cout << "Son iguales: " << repetidos(nodo,nodo1) << endl;
  return 0;
  }
*/

