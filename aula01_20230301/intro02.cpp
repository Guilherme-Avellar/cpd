#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// #define N 30 // => substituído por const

int busca_linear(int *v, int n, int k);

void exibir(int *v, int n);
void preencher(int *v, int n, int min, int max);

int main() {
    const int N = 100000;
    srand(time(NULL));

    int vetor[N]; // int vetor[] = {1,3,5,6,7,8,9,0};
    preencher(vetor, N, 10, 20);

    int histograma[30] = {0};
    for(int i = 0; i < N; i++)
        histograma[vetor[i]]++;

    //exibir(vetor, N);
    //cout << endl;

    for(int i = 0; i < 30; i++)
        cout << i << " ";
    cout << endl;
    exibir(histograma, 30);
    cout << endl;

    return 0;
}

int busca_linear(int *v, int n, int k) {
    for(int i = 0; i < n; i++)
        if(v[i] == k)
            return i;
    
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