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


using namespace std;

void BFS(vector< vector<int> > p, vector<Nodo> &m, int expand, vector<string> cands, int limite, bool all, vector<string> winners, string salida);

void BFSinit(vector< vector<int> > p, vector<Nodo> &l, vector<string> cands, bool all, string salida);


vector<int> DFS(int costo_inicial, vector <vector <int> > perfil, Nodo n, int costo_limit, int cambios, vector<Nodo> &suc, vector<string> cands, int num_cand);


vector<int>  IDA_estrella (vector <vector <int> > perfil, vector<string> cand, int num_cand);

