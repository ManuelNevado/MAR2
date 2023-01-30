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
void reconstruir_sol(Matriz<EntInf> matriz, int puntos, int n, std::vector<int> v);

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

    //Casos base
    for(int i=0;i<=n;i++)
        matriz[i][0] = 0;

    for (int i=1;i<=puntos;i++)
        matriz[0][i] = Infinito;


    //Caso recursivo
    for(int i=1;i<=n;i++){
        for(int j=1;j<=puntos;j++){
            if(v[i-1] > j)
                matriz[i][j] = matriz[i-1][j];
            else
                matriz[i][j] = std::min(matriz[i-1][j],matriz[i][j-v[i]]+1);
        }
    }

    std::cout<< matriz;
    EntInf sol = matriz[n][puntos];
    if(sol != Infinito){
        std::cout<<sol<<":";
        reconstruir_sol(matriz,n,puntos,v);
    }else
        std::cout<<"Imposible\n";
    
}

EntInf max_elem(EntInf const& a, EntInf const& b){
    if(a==b)
        return b;
    else
        return std::max(a,b);
}

void reconstruir_sol(Matriz<EntInf> matriz, int n, int puntos, std::vector<int> v){

    std::vector<EntInf> sol;
    int i=n, j=puntos;

    while(j>0 && i>0){
        std::cout<<"Vector: \n";
        print_v(sol);
        std::cout<<"Current i,j: "<<i<<", "<<j<<std::endl;
        if(v[i-1] <= j){
            EntInf a = matriz[i-1][j];
            EntInf b = matriz[i][j-v[i-1]];
            EntInf max = max_elem(a,b);
            if(max == a)
                i--;
            else{
                sol.push_back(v[i-1]);
                j -= v[i-1];
            }
        }else
            i--;
    }
    
    print_v(sol);

}

