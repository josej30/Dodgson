#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include "functions.h"
#include "limits.h"


int infinito = INT_MAX;
int myints[] = {0,0};
vector<int> resultado (myints, myints + sizeof(myints) / sizeof(int) );
int cambios= -1;
int candidatos = 0; // Cantidad de candidatos

using namespace std;


/*
  Funcion Principal BFS:

  Entrada: 
  p, perfil original de preferencias
  &m, cola de Nodos para expandir
  expand, cantidad de nodos expandidos
*/
void BFS(vector< vector<int> > p, vector<Nodo> &m, int expand, vector<string> cands, int limite, bool all, vector<string> winners, string salida){

  Nodo nod = m[0];
  m.erase(m.begin());

  // Construyo la matriz correspondiente al estado utilizando las columnas que ya  
  // se han permutado junto a las columnas originales
  vector<vector <int> > modif;
  for (int i=0;i<p.size();i++){
    vector<int> alfa = p[i];
    for (int j=0;j<nod.perfil.size();j++){
      if (nod.perfil[j][0]==p[i][0]){
	alfa = nod.perfil[j];
      }
    }
    modif.push_back(alfa);
  }

  // Borro el primer entero de cada columna que representa la posicion
  // de la columna
  for (int i=0;i<modif.size();i++){
    modif[i].erase(modif[i].begin());
  }
  
  // Condicion de salida para el argumento -all
  if (all==true && limite != 1 && nod.perfil.size()==limite+1){
    cout << "Dodgson winner: ";
    for (int winc=0;winc<winners.size();winc++){
      cout << winners[winc] << " ";
    }
    cout << endl;
    cout << "Num cambios elementales: " << limite << endl;
    cout << "Nodos generados: " << m.size()+expand-1 << endl;
    cout << "Nodos expandidos: " << expand-1 << endl;
    return;
  }

  
  // Reviso si hay condorcet winner
  vector<int> condor = condorcet(modif,cands);
  if (condor.size()>0){

    if (all) {
      for (int cont=0;cont<condor.size();cont++)
	if (buscaCand(cands[condor[cont]],winners)==-1){
	  winners.push_back(cands[condor[cont]]);
	  string salidat = salida;
	  salidat.insert(0,"-");
	  salidat.insert(0,cands[condor[cont]]);
	  ofstream file;
	  char* charBuffer = new char[salidat.size()+1];
	  strcpy (charBuffer, salidat.c_str());
	  file.open(charBuffer);
	  for (int i=0;i<modif.size();i++){
	    file << "1 ";
	    for (int k=0;k<modif[i].size();k++){
	      file << cands[modif[i][k]] << " ";
	    }
	    file << endl;
	  }
	  file.close();
	}
      limite = nod.perfil.size();
    }

    else {
      cout << "Dodgson winner: ";
      for (int cont=0;cont<condor.size();cont++)
	cout << cands[condor[cont]] << " ";
      cout << endl;
      cout << "Num cambios elementales: " << nod.perfil.size() << endl;
      cout << "Nodos generados: " << m.size()+expand << endl;
      cout << "Nodos expandidos: " << expand << endl;
      
      string strsalida("vacio");
      if (strsalida.compare(salida)==0){      
	for (int i=0;i<modif.size();i++){
	  cout << "1 ";
	  for (int k=0;k<modif[i].size();k++){
	    cout << cands[modif[i][k]] << " ";
	  }
	  cout << endl;
	}
      }
      else {
	ofstream file;
	char* charBuffer = new char[salida.size()+1];
	strcpy (charBuffer, salida.c_str());
	file.open(charBuffer);
	for (int i=0;i<modif.size();i++){
	  file << "1 ";
	  for (int k=0;k<modif[i].size();k++){
	    file << cands[modif[i][k]] << " ";
	  }
	  file << endl;
	}
	file.close();
      }
      return;
    }
  }
  
  // Guardo las columnas que ya han sido permutadas
  vector<int> cols_perm;
  for (int j=0;j<nod.perfil.size();j++){
    cols_perm.push_back(nod.perfil[j][0]);
  }

  for (int k=0;k<p.size();k++){
    if (!existe(cols_perm,k)){
      vector<int> temp = p[k];

      for (int ii=1;ii<temp.size()-1;ii++){

	Nodo push;
	vector<vector <int> > prefs = nod.perfil;	
	vector<int> p2 = permuta(ii,ii+1,temp);

	prefs.push_back(p2);
	push.perfil = prefs;

	bool insertar = true;
	for (int t=0;t<m.size();t++){
	  if (repetidos(push,m[t]))
	    insertar = false;
	}	
	if (insertar)
	  m.push_back(push);
      }
    }    
  }
  BFS(p,m,expand+1,cands,limite,all,winners,salida);
}

void BFSinit(vector< vector<int> > p, vector<Nodo> &l, vector<string> cands, bool all, string salida){

  vector<int> condor = condorcet(p,cands);
  if (condor.size()>0){
    cout << "Num cambios elementales: 0" << endl;
    cout << "Nodos generados: 1" << endl;
    cout << "Nodos expandidos: 1" << endl;
    
    // Borro el primer entero de cada columna que representa la posicion
    // de la columna
    for (int i=0;i<p.size();i++){
      for (int k=0;k<p[i].size();k++){
	cout << cands[p[i][k]] << " ";
      }
      cout << endl;
    }
    return;
  }
  
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

  // Modifico la matriz colocandole el numero de la preferencia
  // al empezar cada columna
  for(int i=0;i<p.size();i++){
    vector<int>::iterator it;
    it = p[i].begin();
    it = p[i].insert(it,i);
  }

  vector<string> win;

  BFS(p,l,l.size(),cands,1,all,win,salida);
}


/* Funcion DFS que expande los nodos que prometan una mejor solucion,
   esta funcion es usada en la funcion IDA_estrella
   Entrada: int costo_inicial Costo inicial de expandir los nodos
            Nodo nodo Nodo actual que se va a expandir
	    int costo_limit Limite hasta el cual se va a expandir
	    int cambios Lleva la cuenta de los cambios elementales
	    vector<Nodo> suc  Vector que tiene los sucesores de un nodo
	    vector<string> cands Vector de candidatos
*/
 
vector<int> DFS(int costo_inicial, vector <vector <int> > perfil, Nodo n, int costo_limit, int cambios, vector<Nodo> &suc, vector<string> cands){

    cout << "costo_inicial:" << costo_inicial << ", costo_limit:"<< costo_limit << ",cambios" << cambios << endl; 
    cout << "entra" << endl;
   
    cambios++;
    int costo_minimo = costo_inicial + heuristica(n,candidatos, cands);
    if (costo_minimo > costo_limit){
      resultado.at(0) = -1; // Valor que indica que se paso el limite
      resultado.at(1) = costo_limit;
      return resultado;
    }
    
  /* Verifico si  hay un condorcet */
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
    
    
    //Se obtienen los nodos sucesores permutando los valores de los vectores */
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
      /*Se asume que el costo de ir de un nodo a otro es 1 */
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
      
      
    }
    
  }
 

vector<int>  IDA_estrella (vector <vector <int> > perfil, vector<string> cand){
  
  vector<int> res1 (myints, myints + sizeof(myints) / sizeof(int) );
  vector<Nodo> lista;
  Nodo aux;
  aux.perfil = perfil;
  float costo_limite = heuristica(aux,candidatos,cand);
  cout << costo_limite << endl;
  while(true){
    res1 = DFS(0,perfil,aux,costo_limite,-1,lista,cand);
    if (res1[0] != -1) 
      return resultado;
    if (res1[1] == infinito){
    	res1[0] = infinito;
    	return res1;
    }
  } 
  return res1;
  
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
    string strall("-all");
    Nodo aux;
    vector< int > res1;
    if (str1.compare(argv[1])==0){
      string salida="vacio";
      string strfinal("-final");
      for (int i=0;i<argc;i++){
	if (strfinal.compare(argv[i])==0){
	  salida = argv[i+1];
	}
      }
      bool all = false;
      for (int ar=0;ar<argc;ar++){
	if (strall.compare(argv[ar])==0){
	  all = true;
	}
      }
      if (all)
	BFSinit(perfil,fifo,c,true,salida);
      else
	BFSinit(perfil,fifo,c,false,salida);
    }
    else if (str2.compare(argv[1])== 0){
      //cout << "hola";
      res1 = IDA_estrella(perfil,c);
      //cout << res1[0] << endl;
      //cout << res1[1] << endl;
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
  
