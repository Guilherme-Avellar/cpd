#include <bits/stdc++.h>

using namespace std;

#define N 20

bool ordenado(int *v, int n);

int main(){

    srand(time(NULL));

    int v[N];

    cout << "\nesta ordenado?: " << ordenado(v, N) << endl;


    return 0;
}


bool ordenado(int *v, int n){
    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}