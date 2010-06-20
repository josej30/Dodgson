#include <limits.h>


int infinito = INT_MAX;
vector<int> resultado;
int cambios= -1;

vector<int> DFS_Init(vector< vector<int> > perfil, vector<Nodo> &suc, vector<string> cands, int costo_inicial, int costo_limit){
  cambios++;
  int costo_minimo = costo_inicial + heuristica(perfil);
  if (costo_minimo > costo_limit){
    resultado.at(0) = -1;
    resultado.at(1) = costo_minimo;
    return resultado;

   /* Verifico si de entrada hay un condorcet */
  vector<int> condor = condorcet(p,cands);
  if (condor.size()> 0){
    cout << "Dodgson winner: ";
    for (int cont=0;cont<condor.size();cont++)
      cout << cands[condor[cont]] << " ";
    cout << endl;
    resultado[0] = cambios;
    resultado[1] = costo_limit;
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


  int proximo_costo_limite = infinito;
  // Reviso cada uno de los sucesores */
  for (unsigned j = 0; j < l.size(); j++){
    nuevoCostoInicial = costo_inicial + 1;
    resultado_aux = DFS(nuevoCostoInicial,l[j],costo_limit); 
    if (resultados_aux != -1){
      resultados.at(0) = resultados_aux.at(0);
      resultados.at(1) = resultados_aux.at(1);
      return resultados;
    }

    proximo_costo_limite = min(proximo_costo_limite,resultados[1]);

    resultados.at(0) = -1;
    resultados.at(1) = resultados_aux.at(1);
    return resultados;

  }




DFS(perfil,l,0,cands);
}


