#include <math.h>
#include <string>
#include <vector>
#include <iostream>

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
int condorIndiv(int x,vector< vector<int> > p,vector<string> c){

  int tot[250];
  for (int r=0;r<250;r++)
    tot[r]=0;
  vector<int>::iterator it;
  int tam = p.size();
  for (unsigned i=0; i<tam ; i++) {    
    vector<int> z = p.back();
    p.pop_back();
    for (int j=0; j<c.size(); j++){
      tot[j] = tot[j] + N(x,j,z);
    }
  }
  for (int k=0; k<c.size(); k++){
    if (tot[k] < tam/2)
      return 0;
  }
  return 1;

}


/* Funcion que dado un perfil, revisa si tiene Condorcet
   Winner. Retorna el ganador. Si no hay retorna -1.
*/
int condorcet(vector< vector<int> > p, vector<string> c){
  for (int i=0;i<c.size();i++)
    if (condorIndiv(i,p,c))
      return i;
  return -1;
}
