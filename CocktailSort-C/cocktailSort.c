/*
Case#3
Topic: #pointers
Date: 09/03/2021, 9:00 pm 
Team size: two 
Students: 
-Sebastián Díaz Obando
-Sebatián Obando Paniagua
*/
#include <stdio.h>
#include <time.h>
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


#define SIZE          8192

void swap(int *x, int *y) {
    if(x == y)
        return;
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
void cocktailsort(int *a, size_t n) {
    while(1) {
        // junta dos loops similares en una
        char flag;
        int it, i;
        size_t start[2] = {1, n - 1},
               end[2] = {n, 0},
               inc[2] = {1, -1};
        for(it = 0; it < 2; ++it) {
            flag = 1;
            for(i = start[it]; i != end[it]; i += inc[it])
                if(a[i - 1] > a[i]) {
                    swap(a + i - 1, a + i);
                    flag = 0;
                }
            if(flag)
                return;
        }
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

void LlenarLista(int pLista[]){
	srand(time(NULL));
	for(int indice= 0; indice<100000; indice++){
		pLista[indice]=rand()%(3000001-0);
	}
}
 
int main(void) {
    
    //Inicia el contador de tiempo de ejecucion
    int tiempoInicial, tiempoFinal;
    tiempoInicial = clock();
    
    int a[100000];
    LlenarLista(a);
    int i;
    size_t n = sizeof(a)/sizeof(a[0]);
    cocktailsort(a,n);
    //Se finaliza el contador de tiempo
    tiempoFinal = clock();

    printf("\n  \nThe program took %ld milliseconds to execute in C \n", (tiempoFinal - tiempoInicial)*1000/CLOCKS_PER_SEC);
    int memoryUsed = mem_total();
    printf("The memory used was %d kilobytes \n",memoryUsed);
    
    return 0;
   
}
