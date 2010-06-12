/* Funcion que dado un entero, retorna el numero maximo
   de bits que se necesitan para guardarlo. 
   Devuelve -1 si se pasa de 256
*/
int bitsCand(int can){
  int exp[9] = {1,2,4,8,16,32,64,128,256};
  for (int i=0;i<9;i++){
    if (can<=exp[i])
      return exp[i];
  }
  return -1;
}
