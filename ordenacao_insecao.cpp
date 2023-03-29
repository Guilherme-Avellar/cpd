#include <bits/stdc++.h>

using namespace std;


void ordenacao(int *v, int tam);

int main(){
    int tam = 10;
    int v[tam];

    for(int i = 9; i >= 0; i--){
        v[9 - i] = i;
    }
    cout << endl;
    ordenacao(v, tam);

    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    cout << endl;
    return 0;
}

void ordenacao(int *v, int tam){
    int i, j, chave;

    for(i = 1; i < tam; i++){
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j -= 1;
        }
        v[j + 1] = chave;
    }

}
