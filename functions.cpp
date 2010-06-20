#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include "functions.h"

using namespace std;

/* Funcion que dado un entero, retorna el numero maximo
   de bits que se necesitan para guardarlo. 
   Devuelve -1 si se pasa de 256
*/
int bitsCand(int can){
  int exp[9] = {1,2,4,8,16,32,64,128,256};
  for (int i=0;i<9;i++){
    if (can<=exp[i])
      return (i);
  }
  return -1;
}


/* Funcion que busca un string en un vector y devuelve 
   su posicion. Devuelve -1 si no lo encuentra. */
int buscaCand(string b,vector<string> v){
  for (int i=0;i<v.size();i++){
    if (v[i] == b)
      return i;
  }
  return -1;
}

/* Funcion que dada una preferencia de un votante, devuelve
   1 si el mismo prefiere a x sobre y, 0 si es lo contrario
*/
int N(int x,int y,vector<int> v){
  int posx, posy;
  for (int i=0;i<v.size();i++){
    if (v[i] == x)
      posx = i;
    else if (v[i] == y)
      posy = i;
  }
  if (posx < posy)
    return 1;
  else
    return 0;
}


/* Funcion que revisa si x es un Condorcet winner 
   Es decir, que para todo x!=y N(x,y) > n/2
*/
bool condorIndiv(int x,vector< vector<int> > p,vector<string> c){

  int tot[250];
  for (int r=0;r<250;r++)
    tot[r]=0;
  for (int i=0; i<p.size(); i++) {
    for (int j=0; j<c.size(); j++){
      tot[j] = tot[j] + N(x,j,p[i]);
    }
  }
  for (int k=0; k<c.size(); k++){
    if (k!=x){
      if (tot[k] <= p.size()/2){
	return false;
      }
    }
  }
  return true;
}


/* Funcion que dado un perfil, revisa si tiene Condorcet
   Winner. Retorna el ganador. Si no hay retorna -1.
*/
vector<int> condorcet(vector< vector<int> > p, vector<string> c){
  vector <int> res;
  for (int i=0;i<c.size();i++)
    if (condorIndiv(i,p,c))
      res.push_back(i);
  return res;
}

/* Funcion que revisa si existe un entero en un vector
*/
bool existe(vector<int> a, int b){
  for (unsigned i=0; i<a.size() ; i++) {
    if (a[i] == b){
      return true;
    }
    return false;
  }
}

/* Funcion que permuta un vector */
vector<int> permuta(int a, int b, vector<int> v){
  int temp = v[a];
  v[a]=v[b];
  v[b]=temp;
  return v;
}

/* Funcion que modifica una matriz de preferencias
   de acuerdo a un vector dado */
void sust(vector<Nodo> v, vector<vector <int> > &pref){

  for (int i=0;i<v.size();i++){
    for (int j=0;j<v[i].perfil.size();j++){
      for (int k=0;i<v[i].perfil[j].size();k++){
	cout << v[i].perfil[j][k] << endl;
      }
    }
  }
}


/* Funcion para verificar que dos nodos sean iguales, 
   retorna -1 sino lo son, 0 en caso contrario */
bool repetidos(Nodo x, Nodo y){
  // Si la matriz no es del mismo tamano ya descarto que sean iguales
  if (x.perfil.size() != y.perfil.size()){
    return false;
  }
  else{
    for (unsigned i=0; i< x.perfil.size() ; i++) {    
      vector<int> z = x.perfil.back();
      vector<int> w = y.perfil.back();
      x.perfil.pop_back();
      y.perfil.pop_back();
      // Verifico que cada columna tenga el mismo tamano
      if  (z.size() != w.size())
	return false;
      else{
	for ( unsigned i = 0; i < z.size(); i++ )
	  // Verifico que los elementos sean iguales
	  if (z[i] != w[i])
	    return false;
	return true;
      }
    }
  }
}
