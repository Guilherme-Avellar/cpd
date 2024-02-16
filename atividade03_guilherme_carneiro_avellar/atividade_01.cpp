#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define N 100000


void exibir(short *v, int n);
void ordenacao(short *v, int tam);


int main(){

    srand(time(NULL));

    short v[N], v_temp[N];


    for(int i = 0; i < N; i++){
        v[i] = rand()%101;
    }


    fstream arquivo;
    arquivo.open("saida.txt", ios::out);


    float porcent = 0.25, temp;   //vai regular o tanto que o vetor temporario vai ter de tamanho e o tanto de vezes que ira testar o tempo
    temp = porcent;               //coloca-se em decimal a porcentagem

    for(int i = 0; temp <= 1; i++) {
        
        if(arquivo.is_open()) {

            for(int j = 0; j < N; j++) {
                v_temp[j] = v[j];
            }

            auto inicio = steady_clock::now();
            ordenacao(v_temp, (N * temp));                  // passa o tamanho reduzido pelo porcent
            auto fim = steady_clock::now();
            auto intervalo = fim - inicio;
            arquivo << "\nN = " << N * temp << endl;
            arquivo << duration_cast<seconds>(intervalo).count() << "s" << endl;
            arquivo << duration_cast<milliseconds>(intervalo).count() << "ms" << endl;
            arquivo << duration_cast<microseconds>(intervalo).count() << "us" << endl;
            arquivo << duration_cast<nanoseconds>(intervalo).count() << "ns" << endl;
            arquivo << duration<double>{intervalo}.count() << "s" << endl;

        } else {
            cout << "Problema na abertura do arquivo\n";
        }
        temp += porcent;                          //vai sempre adicionar a porcentagem
    }

    arquivo.close();

    return 0;
}


void exibir(short *v, int n) {
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
}


void ordenacao(short *v, int tam) {

    int i, j, chave;

    for(i = 1; i < tam; i++) {
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}
