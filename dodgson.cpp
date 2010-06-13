#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
using namespace std;


/* Funcion que busca un string en un arreglo y devuelve 
   su posicion. Devuelve -1 si no lo encuentra. */
int buscaCand(string b,vector<string> v){
  for (int i=0;i<v.size();i++){
    if (v[i] == b)
      return i;
  }
  return -1;
}

int main () {
  int cont = 1; // Contador de las lineas del archivo
  string line; // String que contiene la linea leida
  ifstream entrada("entrada1.txt"); // Stream contenedor del archivo de entrada
  int candidatos; // Cantidad de candidatos
  int offset = 0;
  int cand_por_int = 0; // Candidatos que se guardan en un entero
  int tpref = 0; // Tamano en bytes de las preferencias  
  vector<string> c; // Vector que contiene a los candidatos y funciona como una tabla de hash

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
  ifstream entrada2("entrada1.txt"); // Stream contenedor del archivo de entrada
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
	  cout << sub << " " << cont << " ";
	}
	cout << endl;

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

  cout << "Candidatos: " << candidatos << endl;

  cout << "Los candidatos son: ";
  for (int i=0;i<candidatos;i++){
    cout << c[i] << " ";
  }
  cout << "" << endl;

  cout << endl << "Pruebas misticas de almacenamiento" << endl;
  int bit = 10;
  cout << bit << endl;
  bit = bit << 9;
  cout << bit << endl;
  bit = bit | 11;
  cout << bit << endl;
  bit = bit << 9;
  cout << bit << endl;
  bit = bit | 100;
  cout << bit << endl;
  
  cout << endl << "Matriz de preferencias: " << endl;
  vector<int>::iterator it;
  int tam = perfil.size();
  for (unsigned i=0; i<tam ; i++) {    
    vector<int> z = perfil.back();
    perfil.pop_back();
    for ( it=z.begin() ; it < z.end(); it++ )
      cout << " " << c[*it];
    cout << endl;  
  }

  /********** 
  ***********  Fin de Comprobacion 
  ***********/

  return 0;
}
