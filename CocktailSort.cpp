// C++ Cocktail Sort
#include <bits/stdc++.h>
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
 
void MostrarLista(int plista[], int n)
{
    for (int indiceLista = 0; indiceLista < n; indiceLista++)
        cout<<plista[indiceLista]<<" ";
    cout<<endl;
}
 
int main()
{
    int lista[] = { 5, 1, 4, 2, 8, 0, 2 ,7,8,6,346,435,654,546,56,356,36,54};
    int n = sizeof(lista) / sizeof(lista[0]);
    CocktailSort(lista, n);
    cout<<"Resultado del algoritmo CocktailSort : "<<endl;
    MostrarLista(lista, n);
    return 0;
}
