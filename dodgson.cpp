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

int BFS(vector<int> cols, vector<Nodo> &m, int limite){

  /*  vector<int>::iterator it;
  int tam = m.size();
  for (int i=0; i<tam ; i++) {
    vector<int> z = m.back();
    m.pop_back();
    // Busco las columnas que no haya expandido previamente
    if (existe(cols,i)==0){
      //      for ( it=z.begin() ; it < z.end(); it++ )
      cout << i << endl;
    }

    }*/
  return 0;
  
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
  vector< vector<int> > fifo;

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

  /*********
  ********** Comprobacion de que se guardan bien las cosas
  **********/

  /*

  cout << "Candidatos: " << candidatos << endl;

  cout << "Los candidatos son: ";
  for (int i=0;i<candidatos;i++){
  }

  */

  vector< vector<int> > zzz = perfil;

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


  /* int con = condorcet(zzz,c);
  if (con>=0)
    cout << c[con] << " es un Condorcet Winner!" << endl;
  */
  
  vector<int> a;
  a.push_back(8);

  vector<Nodo> nodeishon;

  int asd = BFS(a,nodeishon,0);

  /*  vector<int>::iterator it;
  for ( it=b.begin() ; it < b.end(); it++ )
    cout << " " << *it;
    cout << endl;*/

  /**********
  *********** Fin de Comprobacion
  ***********/

  return 0;
}

