#include <bits/stdc++.h>

void ordenacao_selecao(int *v, int tam);

#define N 100

using namespace std;


int main(){

    srand(time(NULL));
    
    int i, v[N];

    for(i = 0; i < N; i++){
        v[i] = rand()%101;
    }

    for(i = 0; i < 5; i++){
        ordenacao_selecao(v, i + 10);
    }

    

    return 0;
}

void ordenacao_selecao(int *v, int tam){
    int i, j, menor, aux, v_temp[tam];

    fstream arquivo;
    arquivo.open("ordena_vetor.txt", ios::out | ios::app);


    for(i = 0; i <= tam - 2 ; i++){
        menor = i;
        for(j = i+1; j <= tam - 1; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        v_temp[i] = v[menor];
    }

    if(arquivo.is_open()) {
        for(int i = 0; i < tam; i++)
            arquivo << v_temp[i] << " ";
        arquivo << "\n\n";

        arquivo.close();
    } else {
        cout << "Problema na abertura do arquivo\n";
    }

}
