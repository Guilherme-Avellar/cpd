#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busca_linear(short *v, int n, short k);
int busca_linear_ord(short *v, int n, short k);
int busca_binaria(short *v, int n, short k);
void exibir(short *v, int n);
void preencher(short *v, int n, short min, short max);

const int N = 1000000;
int main() {
    srand(time(NULL));

    short vetor[N];
    preencher(vetor, N, 10, 20);
    
    auto inicio = steady_clock::now();
    int idx = busca_linear(vetor, N, 21); 
    auto fim = steady_clock::now();
    auto intervalo = fim - inicio;
    cout << duration_cast<seconds>(intervalo).count() << "s" << endl;
    cout << duration_cast<milliseconds>(intervalo).count() << "ms" << endl;
    cout << duration_cast<microseconds>(intervalo).count() << "us" << endl;
    cout << duration_cast<nanoseconds>(intervalo).count() << "ns" << endl;
    cout << duration<double>{intervalo}.count() << "s" << endl;

    return 0;
}

int busca_linear(short *v, int n, short k) {
    for(int i = 0; i < n; i++)
        if(v[i] == k)
            return i;
    
    return -1;
}

int busca_linear_ord(short *v, int n, short k) {
    for(int i = 0; i < n && v[i] <= k; i++) {
        if(v[i] == k)
            return i;
    }
    
    return -1;
}

int busca_binaria(short *v, int n, short k) {
    int esq = 0, dir = n, meio;

    while(esq <= dir) {
        meio = (esq + dir)/2;
        if(v[meio] == k)
            return meio;
        else if(k > v[meio])
            esq = meio + 1;
        else
            dir = meio - 1;
    }

    return -1;
}

void exibir(short *v, int n) {
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
}

void preencher(short *v, int n, short min, short max) {
    for(int i = 0; i < n; i++)
        v[i] = min + rand()%(max - min + 1);
}