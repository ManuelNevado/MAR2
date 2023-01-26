#include <iostream>
#include <vector>
#include "Matriz.h"
#include "EntrerosInf"
#include <algorithm>

void sol(int puntos, int n, std::vector<int> v);

int main(){
    int puntos, n;
    while(std::cin>>puntos){
        std::cin>>n;
        std::vector<int> v(n);
        for(int i=0;i<n;i++)
            std::cin>>v[i];
        sol(puntos,n,v);
    }
}


void sol(int puntos, int n, std::vector<int> v){
    // Es igual que las monedas
    Matriz<EntInf> matriz(n+1, puntos+1, Infinito);
}

