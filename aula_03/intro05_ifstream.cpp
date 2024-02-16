#include <bits/stdc++.h>

using namespace std;

int main() {
    //ifstream | ofstream | fstream
    ifstream entrada;
    entrada.open("saida.txt");

    string linha;

    if(entrada.is_open()) { // retorna true se estiver aberto e false caso contrário
        /*
        // Leitura de duas linhas:
        getline(entrada, linha);    // primeira linha
        cout << linha << endl;
        getline(entrada, linha);    // segunda linha
        cout << linha << endl;
        */
        while(getline(entrada, linha))  // leitura de todas as linhas do arquivo
            cout << linha << endl;

        entrada.close();
    } else {
        cout << "Problema na abertura do arquivo\n";
    }

    return 0;
}