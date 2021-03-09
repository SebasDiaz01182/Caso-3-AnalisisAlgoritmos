// C++ Cocktail Sort
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;


void CocktailSort(int pLista[], int n){
    bool cambio = true;
    int primerIndice = 0;
    int ultimoIndice = n - 1;
 
    while (cambio) {

        cambio = false;
 
        for (int i = primerIndice; i < ultimoIndice; ++i) 
        {
            if (pLista[i] > pLista[i + 1]) {
                swap(pLista[i], pLista[i + 1]);
                cambio = true;
            }
        }

        if (!cambio)
            break;
 
        cambio = false;
        --ultimoIndice;
        
        for (int i = ultimoIndice - 1; i >= primerIndice; --i) 
        {
            if (pLista[i] > pLista[i + 1]) {
                swap(pLista[i], pLista[i + 1]);
                cambio = true;
            }
        }
        ++primerIndice;
    }
}


void LlenarLista(int pLista[]){
	srand(time(NULL));
	for(int indice= 0; indice<100000; indice++){
		pLista[indice]=rand()%(3000001-0);
	}
}
 
int main(){
	int tiempoInicial, tiempoFinal;
	tiempoInicial = clock();
    int lista[100000];
    LlenarLista(lista);
    int n = sizeof(lista) / sizeof(lista[0]);
    CocktailSort(lista, n);
    tiempoFinal = clock();
    cout<<"Algoritmo CocktailSort realizado con exito "<<endl;
    printf("El tiempo  es de %d milisegundos\n", tiempoFinal - tiempoInicial);
    return 0;
}
