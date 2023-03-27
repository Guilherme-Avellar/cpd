#include <bits/stdc++.h>

using namespace std;

int busca_linear(int *v, int n, int k, int *soma); // adicionei mais um parametro como ponteiro para somar o peso
int busca_linear_ord(int *v, int n, int k, int *soma);
int busca_binaria(int *v, int n, int k, int *soma);

void exibir(int *v, int n);
void preencher(int *v, int n, int min, int max);

int main() {
    const int N = 100;
    srand(time(NULL));

    int vetor[N];
    preencher(vetor, N, 10, 20);
    exibir(vetor, N);
    cout << endl;

    sort(vetor, vetor+N); // sort(&(vetor[0]), &(vetor[N]));
    exibir(vetor, N);
    cout << endl;

    int soma_l = 0, soma_l_o = 0, soma_bi = 0;

    busca_binaria(vetor, N, 100, &soma_bi);
    busca_linear(vetor, N, 100, &soma_l);
    busca_linear_ord(vetor, N, 100, &soma_l_o);

    cout << "\nsoma linear: "<< soma_l << "\nsoma linear ordinaria: " << soma_l_o << "\nsoma binaria: " << soma_bi << "\n\n\n";
    
    return 0;
}

int busca_linear(int *v, int n, int k, int *soma){
    *soma++;
    for(int i = 0; i < n; i++){
        *soma += 2;
        if(v[i] == k){
            *soma++;
            return i;
        }
    }
    return -1;
}

int busca_linear_ord(int *v, int n, int k, int *soma) {
    *soma += 1;
    for(int i = 0; i < n && v[i] <= k; i++){
        *soma += 4;
        if(v[i] == k){
            return i;
            *soma += 1;
        }
    }
    
    return -1;
}

int busca_binaria(int *v, int n, int k, int *soma) {
    int esq = 0, dir = n, meio;

    while(esq <= dir) {
        meio = (esq + dir)/2;

        *soma += 4;
        if(v[meio] == k){
            return meio;
            *soma++;
        }
        else if(k > v[meio]){
            esq = meio + 1;
            *soma += 3;
        }
        else{
            dir = meio - 1;
            *soma += 2;
        }
    }

    return -1;
}

void exibir(int *v, int n) {
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
}

void preencher(int *v, int n, int min, int max) {
    for(int i = 0; i < n; i++)
        v[i] = min + rand()%(max - min + 1);
}