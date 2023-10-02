#include <bits/stdc++.h>

using namespace std;

int main() {
    //ifstream | ofstream | fstream
    fstream arquivo;
    arquivo.open("saida.txt", ios::out | ios::app);

    string linha;

    if(arquivo.is_open()) {
        for(int i = 1; i <= 10; i++)
            arquivo << i << " " << i*i << endl;
        arquivo << endl;

        arquivo.close();
    } else {
        cout << "Problema na abertura do arquivo\n";
    }


    cout << "\nAlteracao feita pelo github\nisso funciona?\n";
    cout << "\nEssa linha foi alterada no local, não no site do git\n";

    return 0;
}