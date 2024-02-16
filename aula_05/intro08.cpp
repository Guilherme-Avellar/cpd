#include <bits/stdc++.h>

// https://c-for-dummies.com/blog/?p=5270
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[m"

//#define PRINT

using namespace std;

int main(int argc, char* args[]) {
    /* Ver todos os argumentos de programa
    for(int i = 0; i < argc; i++)
        cout << args[i] << endl;*/
    
    if(argc >= 3)
        cout << atoi(args[1]) + atoi(args[2]) << endl;

    // g++ intro08.cpp -DPRINT -A => define PRINT e A para o programa
    #ifdef PRINT
        cout << "entrou aqui" << endl;
    #endif

    #ifdef A
        cout << "a tambem entrou aqui" << endl;
    #endif

    cout << RED << 10 << endl;
    cout << RESET;
    cout << 10 << endl;
    cout << GREEN << 10 << endl;

    return 0;
}