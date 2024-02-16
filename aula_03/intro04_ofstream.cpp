#include <bits/stdc++.h>

using namespace std;

int main() {
    //ifstream | ofstream | fstream
    ofstream arquivo;
    arquivo.open("saida.txt");//, ios::app);

    if(arquivo.is_open()) {
        for(int i = 1; i <= 1000; i++)
            arquivo << i << " " << i*i << endl;
        arquivo << endl;

        arquivo.close();
    }

    return 0;
}