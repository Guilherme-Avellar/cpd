#include <bits/stdc++.h>

using namespace std;

void exibir(int *v, int n);
void heapify(int *v, int n, int idx);
void heapsort(int *v, int n);
void maxheap(int *v, int n);
bool ordem(int *v, int n);
void preencher(int *v, int n);
void trocar(int *a, int *b);

int main(int argc, char* args[]) {
    if(argc <= 1)
        return 0;
    
    int N = atoi(args[1]);
    int v[N];
    
    preencher(v, N);
    exibir(v, N);

    heapsort(v, N);
    exibir(v, N);

    cout << "Ordenado? " << (ordem(v, N) ? "Sim" : "Nao") << endl;

    return 0;
}

void exibir(int *v, int n) {
}

void heapify(int *v, int n, int idx) {
    int esq, dir;
    int maior = idx;
    bool troca = true;
    while(troca) {
        troca = false;
        esq = 2*maior + 1;
        dir = 2*maior + 2;
        if(esq < n && v[maior] < v[esq])
            maior = esq;
        if(dir < n && v[maior] < v[dir])
            maior = dir;
        if(maior != idx) {
            trocar(&v[maior], &v[idx]);
            troca = true;
            idx = maior;
        }
    }
}

void heapsort(int *v, int n) {
    int maior, esq, dir, idx, N = n;
    maxheap(v, n);
    while(n > 0) {
        trocar(&v[0], &v[n-1]);
        n--;
        heapify(v, n, 0);
    }
}

void maxheap(int *v, int n) {
    int idx, esq, dir, maior;

    for(int idx = n/2-1; idx >= 0; idx--)
        heapify(v, n, idx);
}

bool ordem(int *v, int n) {
    return false;
}

void preencher(int *v, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        v[i] = 1 + rand()%100;
}

void trocar(int *a, int *b) {

}
