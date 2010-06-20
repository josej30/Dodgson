#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "functions.h"
#include "limits.h"


int infinito = INT_MAX;
int myints[] = {0,0};
vector<int> resultado (myints, myints + sizeof(myints) / sizeof(int) );



int cambios= -1;

using namespace std;

/*
Funcion Principal BFS:

Entrada: 
p, perfil original de preferencias
&m, cola de Nodos para expandir
limit, limite al que llega BFS al encontrar el primer condorcet
*/
void BFS(vector< vector<int> > p, vector<Nodo> &m, int limite, vector<string> cands){

  Nodo nod = m[0];
  m.erase(m.begin());

  cout << "profundidad=" << nod.perfil.size() << endl;
  cout << "nodos expandidos=" << limite << endl;
  cout << "nodos generados=" << m.size()+limite << endl;

  vector<vector <int> > modif;
  for (int i=0;i<p.size();i++){
    vector<int> alfa = p[i];
    for (int j=0;j<nod.perfil.size();j++){
      if (nod.perfil[j][0]==p[i][0])
	alfa = nod.perfil[j];
    }
    modif.push_back(alfa);
  }

  for (int i=0;i<modif.size();i++){
    modif[i].erase(modif[i].begin());
    for (int k=0;k<modif[i].size();k++){
      cout << modif[i][k] << " ";
    }
    cout << endl;
  }
  
    
  vector<int> condor = condorcet(modif,cands);
  if (condor.size()>0){
    cout << "Dodgson winner: ";
    for (int cont=0;cont<condor.size();cont++)
      cout << cands[condor[cont]] << " ";
    cout << endl;
    return;
  }
    
  vector<int> cols_perm;
  for (int j=0;j<nod.perfil.size();j++){
    cols_perm.push_back(nod.perfil[j][0]);
  }

  Nodo push;
  vector<vector <int> > prefs = nod.perfil;

  for (int k=0;k<p.size();k++){
    if (!existe(cols_perm,k)){
      vector<int> temp = p[k];

      int pos = temp[0];
      temp.erase(temp.begin());
      for (int ii=0;ii<temp.size()-1;ii++){
	vector<int> p2 = permuta(ii,ii+1,temp);
	vector<int>::iterator it;
	it = p2.begin();
	it = p2.insert(it,pos);	

	prefs.push_back(p2);
      }
    }

    push.perfil = prefs;
    
    bool insertar = true;
    for (int cont=0;cont<m.size();cont++){
      if (repetidos(push,m[cont]))
	insertar = false;
    }
    
    if (insertar)
      m.push_back(push);
    
  }


  // Ciclo hiper cochino para mostrar los nodos almacenados en la lista

  /*  for (int i=0;i<m.size();i++){
    cout << "Nodo" << endl;
    for (int j=0;j<m[i].perfil.size();j++){
      for (int k=0;k<m[i].perfil[j].size();k++){
	cout << m[i].perfil[j][k] << " ";
      }
      cout << endl;
    }
    }*/

  BFS(p,m,limite+1,cands);


}

void BFSinit(vector< vector<int> > p, vector<Nodo> &l, vector<string> cands){

  vector<int> condor = condorcet(p,cands);
  if (condor.size()>0){
    cout << "Dodgson winner: ";
    for (int cont=0;cont<condor.size();cont++)
      cout << cands[condor[cont]] << " ";
    cout << endl;
    return;
  }
  
  int tam = p.size();
  for (int i=0; i<tam ; i++) {
    vector<int> p1 = p[i];
    for (int j=0;j<p1.size()-1;j++){
      vector<int> p2 = permuta(j,j+1,p1);

      vector<int>::iterator it;
      it = p2.begin();
      it = p2.insert(it,j);	

      Nodo ins;
      ins.insertar(p2);
      l.push_back(ins);
    }
  }

  // Modifico la matriz colocandole el numero de la preferencia
  // al empezar cada columna
  for(int i=0;i<p.size();i++){
    vector<int>::iterator it;
    it = p[i].begin();
    it = p[i].insert(it,i);
  }

  BFS(p,l,0,cands);
}

/* Funcion DFS que expande los nodos que prometan una mejor solucion
   Entrada: int costo_inicial Costo inicial de expandir los nodos
            Nodo nodo Nodo actual que se va a expandir
	    int costo_limit Limite hasta el cual se va a expandir
	    int cambios Lleva la cuenta de los cambios elementales
	    vector<Nodo> suc  Vector que tiene los sucesores de un nodo
	    vector<string> cands Vector de candidatos
*/
vector<int> DFS(int costo_inicial, vector <vector <int> > perfil, Nodo n, int costo_limit, int cambios, vector<Nodo> &suc, vector<string> cands){

    cout << "start_cost:" << costo_inicial << ", cost_limit:"<< costo_limit << ",cambios" << cambios << endl; 
    cout << "entra" << endl;
    cambios++;
    int costo_minimo = costo_inicial + 1; //heuristica(perfil);
    if (costo_minimo > costo_limit){
      resultado.at(0) = -1;
      resultado.at(1) = costo_minimo;
      return resultado;
    }
    
  /* Verifico si de entrada hay un condorcet */
    vector<int> condor = condorcet(perfil,cands);
    if (condor.size()> 0){
      cout << "Dodgson winner: ";
      for (int cont=0;cont<condor.size();cont++)
	cout << cands[condor[cont]] << " ";
      cout << endl;
      resultado.at(0) = cambios;
      resultado.at(1) = costo_limit;
      return resultado;
    }
    
    
    int tam = perfil.size();
    for (int i=0; i<tam ; i++) {
      vector<int> p1 = perfil[i];
      for (int j=0;j<p1.size()-1;j++){
	vector<int> p2 = permuta(j,j+1,p1);
	vector<int>::iterator it;
	it = p2.begin();
	it = p2.insert(it,j);	
      
	Nodo ins;
	ins.insertar(p2);
	suc.push_back(ins);
      }
    }
    
    // Modifico la matriz colocandole el numero de la preferencia
    // al empezar cada columna
    for(int i=0;i<perfil.size();i++){
      vector<int>::iterator it;
      it = perfil[i].begin();
      it = perfil[i].insert(it,i);
    }
    
    
    vector<int> resultados_aux;
    int proximo_costo_limite = infinito;
    
    // Reviso cada uno de los sucesores */
    for (unsigned j = 0; j < suc.size(); j++){
      int nuevoCostoInicial = costo_inicial + 1;
      resultados_aux = DFS(nuevoCostoInicial,perfil, suc[j], costo_limit, cambios,suc,cands);
      
      if (resultados_aux.at(0) != -1){
	resultado.at(0) = resultados_aux.at(0);
	resultado.at(1) = resultados_aux.at(1);
	return resultado;
      }
      
      proximo_costo_limite = min(proximo_costo_limite,resultado[1]);
      
      resultado.at(0) = -1;
      resultado.at(1) = resultados_aux.at(1);
      return resultado;
      
      
      
      //  DFS(perfil,suc,0,cands);
    }
    
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
    string str2("-ida");
    Nodo aux;
    vector< int > res1;
    if (str1.compare(argv[1])==0){    
      BFSinit(perfil,fifo,c);
    }
    else if (str2.compare(argv[1])== 0){
      //  cout << "hola";
      res1 = DFS(0,perfil, aux,100,-1,fifo,c);
      cout << res1[0] << endl;
      cout << res1[1] << endl;
    }
    
    /* Este codigo imprime toda la matriz de preferencias (perfil) */

    /*  cout << endl << "Matriz de preferencias: " << endl;
	vector<int>::iterator it;
	int tam = perfil.size();
	for (unsigned i=0; i<tam ; i++) {
	vector<int> z = perfil.back();
	perfil.pop_back();
	for ( it=z.begin() ; it < z.end(); it++ )
	cout << " " << c[*it];
	cout << endl;
	}*/
    
    
    /* vector<int>::iterator it;
       for ( it=b.begin() ; it < b.end(); it++ )
       cout << " " << *it;
       cout << endl;*/
    
    /**********
    *********** Fin de Comprobacion
    ***********/
    
    return 0;
  }
  
