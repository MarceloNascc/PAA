#include <stdlib.h>
#include <stdio.h>

//TROCA POSIÇÃO
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//CONQUISTA
int ParticionarRand(int lista[], int ini, int fim){
    int pivo = ini + rand() % (fim - ini); //PIVO RANDÔMICO
    swap(&lista[pivo], &lista[fim-1]);

    int i, j;
    for(i = ini - 1, j = ini; j < fim-1; j++){
        if(lista[j] < lista[fim-1]){
            i++;
            swap(&lista[i], &lista[j]);
        }
    }

    swap(&lista[++i], &lista[fim-1]);

    return i;
}

//DIVISÃO
void QuickSort(int lista[], int ini, int fim){
    if((fim - ini) <= 1){
        return;
    }

    int pivo = ParticionarRand(lista, ini, fim);

    QuickSort(lista, ini, pivo);
    QuickSort(lista, pivo + 1, fim);
}

//TESTE
int main (){
    int n;
    printf("Tamanho: ");
    scanf("%d", &n);

    printf("Lista: ");
    int lista[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &lista[i]);
    }

    srand(6);
    QuickSort(lista, 0, n);

    for(int i = 0; i < n; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}
