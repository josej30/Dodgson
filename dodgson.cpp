#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "functions.h"
#include "nodo.h"

using namespace std;

void BFS(vector<Nodo> &m, int limite){
  // Ciclo hiper cochino para mostrar los nodos almacenados en la lista
  /*  for (int i=0;i<m.size();i++){
    cout << "muestro " << endl;
    for (int j=0;j<m[i].perfil.size();j++){
      for (int k=0;k<m[i].perfil[j].size();k++){
	cout << m[i].perfil[j][k] << " ";
      }
    }
    cout << endl;
    }*/
}

void BFSinit(vector< vector<int> > p, vector<Nodo> &l){
  int tam = p.size();
  for (int i=0; i<tam ; i++) {
    vector<int> p1 = p[i];
    for (int j=0;j<p1.size()-1;j++){
      vector<int> p2 = permuta(j,j+1,p1);

      vector<int>::iterator it;
      it = p2.begin();
      it = p2.insert(it,i);

      Nodo ins;
      ins.insertar(p2);
      l.push_back(ins);
    }
  }
  BFS(l,0);
}

int main (int argc, char *argv[]) {

  if (argc < 3){
    printf("USO: ./dodgson {-ida|-bfs} [-all] [-final <archivo_salida>] <archivo_entrada>\n");
    exit(-1);
  }

  string archivoin = argv[argc-1];
  int cont = 1; // Contador de las lineas del archivo
  string line; // String que contiene la linea leida
  ifstream entrada(archivoin.c_str()); // Stream contenedor del archivo de entrada
  int candidatos; // Cantidad de candidatos
  int offset = 0;
  int cand_por_int = 0; // Candidatos que se guardan en un entero
  int tpref = 0; // Tamano en bytes de las preferencias
  vector<string> c; // Vector que contiene a los candidatos y funciona como una tabla de hash
  vector<Nodo> fifo;

  if (entrada.is_open()) {
    while (! entrada.eof() ) {
      getline (entrada,line);
     
      if (cont == 2){

string sub;
stringstream ss(line);
ss >> sub;

// Se lee el numero de candidatos y se hacen calculos de
// almacenamiento para guardarlos eficientemente
candidatos = atoi(sub.c_str());
offset = bitsCand(candidatos);
cand_por_int = 32/offset;
float temp = (float)candidatos/(float)cand_por_int;
tpref = (int)ceil(temp);
break;
      }
      cont++;
    }
    entrada.close();
  }
  else cout << "No se pudo abrir el archivo\n";

  vector< vector<int> > perfil; // Matriz que representa el perfil inicial

  cont = 1;
  ifstream entrada2(archivoin.c_str()); // Stream contenedor del archivo de entrada
  if (entrada2.is_open()) {
    while (! entrada2.eof() ) {
      getline (entrada2,line);
      
      if (cont == 2){
	string sub;
	stringstream ss(line);
	ss >> sub;
	
	while (ss >> sub){
	  c.push_back(sub);
	}
      }
      else if (cont > 3){
	string sub;
	stringstream ss(line);
	ss >> sub;
	int vot = atoi(sub.c_str());
	
	vector<int> a;
	while (ss >> sub){
	  a.push_back(buscaCand(sub,c));
	}
	
	while (vot > 0){
	  perfil.push_back(a);
	  vot--;
	}
      }
      cont++;
    }
    entrada2.close();
  }
  else cout << "No se pudo abrir el archivo\n";
  
  // Aplicacion de algoritmos
  
  string str1("-bfs");
  if (str1.compare(argv[1])==0){
    BFSinit(perfil,fifo);
  }

  /* Este codigo imprime toda la matriz de preferencias (perfil) */

  /*cout << endl << "Matriz de preferencias: " << endl;
  vector<int>::iterator it;
  int tam = perfil.size();
  for (unsigned i=0; i<tam ; i++) {
    vector<int> z = perfil.back();
    perfil.pop_back();
    for ( it=z.begin() ; it < z.end(); it++ )
      cout << " " << c[*it];
    cout << endl;
  }*/
  
  /*  vector<int>::iterator it;
  for ( it=b.begin() ; it < b.end(); it++ )
    cout << " " << *it;
    cout << endl;*/

  /**********
  *********** Fin de Comprobacion
  ***********/

  return 0;
}

