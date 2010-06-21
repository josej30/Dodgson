#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include "limits.h"
#include "functions.h"

using namespace std;

vector<int> DFS(int costo_inicial, vector <vector <int> > perfil, Nodo n, int costo_limit, int cambios, vector<Nodo> &suc, vector<string> cands, int num_cand);
vector<int>  IDA_estrella (vector <vector <int> > perfil, vector<string> cand, int num_cand);
