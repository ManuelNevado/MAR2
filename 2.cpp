#include <iostream>
#include <vector>
#include "Matriz.h"
#include "EnterosInf.h"
#include <algorithm>

template <typename T>
void print_v(std::vector<T> sol){
    for(int i=0;i<sol.size();i++){
        std::cout<<" "<<sol[i];
    }
    std::cout<<std::endl;
}

EntInf max(EntInf const& a, EntInf const& b);
void sol(int puntos, int n, std::vector<int> v);
void reconstruir_sol(std::vector<EntInf> sol, int puntos, int n, std::vector<int> v);

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

    std::vector<EntInf> sol(puntos+1,Infinito);

    //Caso base
    sol[0] = 0;//El minimo numero de dardos para lograr la puntuacion 0 es 0
    
    //Caso recursivo
    for(int i = 1;i<=n;i++){
        for(int j = v[i-1]; j<=puntos;j++){
            sol[j] = std::min(sol[j], sol[j-v[i-1]]+1);
        }
    }

    
    if(sol[puntos] != Infinito){
        std::cout<<sol[puntos]<<":";
        reconstruir_sol(sol,n,puntos,v);
    }else
        std::cout<<"Imposible\n";
    
}

EntInf max_elem(EntInf const& a, EntInf const& b){
    if(a==b)
        return b;
    else
        return std::max(a,b);
}

void reconstruir_sol(std::vector<EntInf> sol, int n, int puntos, std::vector<int> v){
    

    std::vector<EntInf> puntuaciones;
    int j=puntos, i=n-1;

    while(j>0){
        if(v[i] <= j && sol[j] > sol[j - v[i]]){
            puntuaciones.push_back(v[i]);
            j-=v[i];
        }else
            i--;
    }

    print_v(puntuaciones);
}

