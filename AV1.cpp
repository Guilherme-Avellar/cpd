#include <bits/stdc++.h>


using namespace std;

#define N 20

void preencher(int *v, int n, int min, int max);
void exibir(int *v, int ini, int fim);
bool ordenado(int *v, int n);
void quicksort(int *v, int esq, int dir);
void quicksortR(int *v, int esq, int dir);
int particionamento(int *v, int esq, int dir);
void troca(int *a, int *b);



int main(int argc, char *args[]){

    srand(time(NULL));

    int v[N];

    preencher(v, N, 0, N);
    cout << "\ndesordenado: ";
    exibir(v, 0, N);
    quicksort(v, 0, N-1);
    cout << "\nordenado: ";
    exibir(v, 0, N);
    cout << "\nesta ordenado?: " << ordenado(v, N) << endl;



    return 0; 
}




void preencher(int *v, int n, int min, int max){
        for(int i = 0; i < n; i++){
            v[i] = min + rand()%(max - min) + 1;
        }
}

void exibir(int *v, int ini, int fim){
    cout << "\n";
    for(int i = ini; i < fim; i++){
        cout << v[i] << " ";
    }
}

bool ordenado(int *v, int n){
    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

void quicksort(int *v, int esq, int dir){
    stack<int> pilha; pilha.push(esq); pilha.push(dir);
    int p;
    while(!pilha.empty()) {
        dir = pilha.top(); pilha.pop();
        esq = pilha.top(); pilha.pop();
        p = particionamento(v, esq, dir);
        if(p-1 > esq){
            pilha.push(esq);
            pilha.push(p-1);
        }
        if(p+1 < dir){
            pilha.push(p+1);
            pilha.push(dir);
        }
    }
}


void quicksortR(int *v, int esq, int dir){
    int p;
    if(esq < dir) {
        p = particionamento(v, esq, dir);
        quicksort(v, esq, p-1);
        quicksort(v, p+1, dir);
    }


}

int particionamento(int *v, int esq, int dir){
    int pivo = v[esq], pos = esq + 1;
    for(int atual = pos; atual <= dir; atual++){
        if(v[atual] < pivo) {
            troca(&v[atual], &v[pos]);
            pos++;
        }
    }
    troca(&v[esq], &v[pos-1]);
    return pos - 1;
}

void troca(int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

