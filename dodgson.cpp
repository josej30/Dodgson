#include "dodgson.h"

using namespace std;

int main () {
  int cont = 1;
  string line;
  ifstream entrada("entrada1.txt");
  vector<string> cand;
  int candidatos;

  if (entrada.is_open()) {
    while (! entrada.eof() ) {
      getline (entrada,line);
     
      if (cont == 2){     	

	string sub;
	stringstream ss(line);	
	ss >> sub;
	candidatos = atoi(sub.c_str());
	while (ss >> sub){
	  cand.push_back(sub);
	}
	
      }
      cont++;
    }
    entrada.close();
  }
  else cout << "No se pudo abrir el archivo\n"; 

  /********* 
  ********** Comprobacion de que se guardan bien las cosas 
  **********/

  cout << "Candidatos: " << candidatos << endl;

  cout << "Los candidatos son: ";
  for (int i=0;i<cand.size();i++){
    cout << cand[i] << " ";
  }
  cout << "" << endl;

  int c = bitscand(candidatos);
  cout << "necesarios: " << c << endl;

  /********** 
  ***********  Fin de Comprobacion 
  ***********/

  return 0;
}
