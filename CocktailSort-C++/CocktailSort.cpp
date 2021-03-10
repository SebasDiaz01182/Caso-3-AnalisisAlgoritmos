/*
Case#3
Topic: #pointers
Date: 09/03/2021, 9:00 pm 
Team size: two 
Students: 
-Sebastián Díaz Obando
-Sebatián Obando Paniagua
*/
// C++ Cocktail Sort
#include <bits/stdc++.h>
#include<stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctime>

#define SIZE          8192
using namespace std;

//La funcion cocktailSort es un ordenamiento para listas, la funcion ordena enteros del menor al mayor valor
void CocktailSort(int pLista[], int n){
    bool cambio = true;
    int primerIndice = 0;
    int ultimoIndice = n - 1;
 
    while (cambio) {

        cambio = false;
        
        //Se analiza la posicion y se evalua el valor si es mayor que su predecesor se realiza el cambio de orden, sino se continua ejecutando
        for (int i = primerIndice; i < ultimoIndice; ++i) {
            if (pLista[i] > pLista[i + 1]) {
                swap(pLista[i], pLista[i + 1]);
                cambio = true;
            }
        }

        if (!cambio)
            break;
 
        cambio = false;
        --ultimoIndice;
        
        //En esta parte del algoritmo se analiza si el valor que antecede a la posicion actual es mayor si es así se realiza el cambio de orden 
        for (int i = ultimoIndice - 1; i >= primerIndice; --i) {
            if (pLista[i] > pLista[i + 1]) {
                swap(pLista[i], pLista[i + 1]);
                cambio = true;
            }
        }
        ++primerIndice;
    }
}

int mem_total ()
{
  char a[SIZE], *p, *q;
  int data, stack;
  int n, v, fd;
  pid_t pid= getpid();

  p = a;
  sprintf (p, "/proc/%d/status", pid);
  fd = open (p, O_RDONLY);
  if (fd < 0)
    return -1;
  do
    n = read (fd, p, SIZE);
  while ((n < 0) && (errno == EINTR));
  if (n < 0)
    return -2;
  do
    v = close (fd);
  while ((v < 0) && (errno == EINTR));
  if (v < 0)
    return -3;
  data = stack = 0;
  q = strstr (p, "VmData:");
  if (q != NULL)
    {
      sscanf (q, "%*s %d", &data);
      q = strstr (q, "VmStk:");
      if (q != NULL)
    sscanf (q, "%*s %d\n", &stack);
    }
  return (data + stack);
}  


//Esta funcion cambia cada posicion del arreglo por un numero al azar entre 0 a 3.000.000 
void LlenarLista(int pLista[]){
	srand(time(NULL));
	for(int indice= 0; indice<100000; indice++){
		pLista[indice]=rand()%(3000001-0);
	}
}
 
int main(){
	//Inicia el contador de tiempo de ejecucion
	int tiempoInicial, tiempoFinal;
	tiempoInicial = clock();
	
	//Se instancia el arreglo
    int lista[100000];
    LlenarLista(lista);
    int n = sizeof(lista) / sizeof(lista[0]);
    
    //Se llama la funcion que realiza el ordenamiento
    CocktailSort(lista, n);
    
    //Se finaliza el contador de tiempo
    tiempoFinal = clock();
    
    cout<<"Algoritmo CocktailSort realizado con exito "<<endl;
    cout<<"El tiempo  es de "<<(tiempoFinal - tiempoInicial)*1000/CLOCKS_PER_SEC <<" milisegundos"<<endl;
    //--------------------------------------------------------------------------
    int cantidadMemoria = mem_total() ;
	//-------------------------------------------------------------------------
	cout<<"La memoria utilizada por el ordenamiento es:"<<cantidadMemoria<<" kilobytes."<<endl;
    return 0;
}
