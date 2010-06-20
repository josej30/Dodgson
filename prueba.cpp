#include <math.h>
#include <iostream>
#include <vector>
#include "functions.h"





  


int defct(int x, int y, int n, Nodo nodo){

  int techo = ceil((n+1)/2.);
  int N_total = 0;
  int N_aux = 0;
  vector< vector <int> > aux = nodo.perfil;

  for (unsigned i = 0; i < nodo.perfil.size(); i++){
    vector <int> z = aux.back();
    aux.pop_back();
    N_aux = N(x,y,z);
    N_total =+ N_aux;
  }

  return max(0,techo - N_total);

}


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




int T(int x, vector <int> cand,int n, Nodo nodo){
  int suma = 0;
  int aux = 0;
  for (unsigned i = 0; i < cand.size(); i++){
    if (cand[i] != x){
      aux = defct(x,cand[i],n,nodo);
      suma = suma + aux;
    }
    
  }  

}

int T_prima(int x, vector<int> cand, int n, Nodo nodo, int m){
  
  int t = T(x,cand,n,nodo);
  return (t + log2(m)+ 1) /log2(m) + 3;


}

int main () {
  int n = 10;
  int x = 1;
  int y = 8;
  
  //vector<vector <int> > m;

  /*Nodo nodo2;
  
  vector <int> d, e, f,g,i;
  d.push_back(1);  d.push_back(0);  d.push_back(8);
  e.push_back(0); e.push_back(1); e.push_back(8);
  g.push_back(4);  g.push_back(2);  g.push_back(1);
  f.push_back(5);  f.push_back(1);  f.push_back(2);
  i.push_back(1);  i.push_back(2);  i.push_back(4);*/
  

 
  //nodo2.insertar(e);
  //  nodo.insertar(d);
  //nodo.insertar(g);
  
  // nodo.mostrar();


  
  //  cout << "defct " <<  defct(x,y,n,nodo2) << endl;*/

  return 0;
}


