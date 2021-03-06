#include "ida_estrella.h"

/* Variables Globales*/

int infinito = INT_MAX;
int myints[] = {0,0};
vector<int> resultado (myints, myints + sizeof(myints) / sizeof(int) );
int cambios= -1;


vector<int> DFS(int costo_inicial, vector <vector <int> > perfil, Nodo n, int costo_limit, int cambios, vector<Nodo> &suc, vector<string> cands, int num_cand){

    cout << "costo_inicial:" << costo_inicial << ", costo_limit:"<< costo_limit << ",cambios" << cambios << endl; 
    cout << "entra" << endl;
   
    cambios++;
    int costo_minimo = costo_inicial + heuristica(n,num_cand, cands);
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
      resultados_aux = DFS(nuevoCostoInicial,perfil, suc[j], costo_limit, cambios,suc,cands,num_cand);
       
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
 

vector<int>  IDA_estrella (vector <vector <int> > perfil, vector<string> cand, int num_cand){
  
  vector<int> res1 (myints, myints + sizeof(myints) / sizeof(int) );
  vector<Nodo> lista;
  Nodo aux;
  aux.perfil = perfil;
  float costo_limite = heuristica(aux,candidatos,cand);
  cout << costo_limite << endl;
  while(true){
    res1 = DFS(0,perfil,aux,costo_limite,-1,lista,cand, num_cand);
    if (res1[0] != -1) 
      return resultado;
    if (res1[1] == infinito){
    	res1[0] = infinito;
    	return res1;
    }
  } 
  return res1;
  
}
