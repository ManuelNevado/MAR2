#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
#include "EnterosInf.h"

void resuelve_caso(int n, int pmax, int pmin){
    
    //Recoleccion de datos
    std::vector<int> potencia(n);
    std::vector<int> coste(n);
    for(int i=0;i<n;i++)
        std::cin>>potencia[i];
    for(int i=0;i<n;i++)
        std::cin>>coste[i];
    


    //Creacion de la matriz
    Matriz<EntInf> m(n+1, pmax+1);

    //Caso Base
    for(int i=1;i<=pmax;i++)
        m[0][i] = Infinito; //Se requieren infinito dinero para llegar a la ptencia 1<=i<=pmax 
    for(int i=1;i<=n;i++)
        m[i][0] = 0;

    m[0][0] = 0;

    //Caso recursivo
    for(int i=1;i<=n;i++){
        for(int j=1;j<=pmax;j++){
            if(potencia[i-1] >j)
                m[i][j]=m[i-1][j];
            else{
                m[i][j] = std::min(m[i-1][j], m[i][j-potencia[i-1]]+coste[i-1]);
            }
        }
    }
    //Sacar el minimo de entre pmin y pmax
    EntInf min = Infinito;
    int index_min = pmin;
    for(int j =pmin;j<=pmax;j++){
        if(m[n][j]<min){
            min = m[n][j];
            index_min = j;
        }
    }
    
    if(min == Infinito)
        std::cout<<"IMPOSIBLE\n";
    else{
        //reconstruimos desde index_min
        int sol_i = n;
        int sol_j = index_min;
        int sol=0;
        while(sol_i >0 && sol_j>0){
           // std::cout<<"sol_i: "<<sol_i<<"\nsol_j: "<<sol_j<<std::endl;
            if(m[sol_i][sol_j] == m[sol_i][sol_j-potencia[sol_i-1]] +coste[sol_i-1]){
                sol+=potencia[sol_i-1];
                sol_j -=potencia[sol_i-1];
            }else{
                sol_i--;
            }
        }
        std::cout<<min<<' '<<sol<<'\n';
    }
    //std::cout<<m;

}

int main(){
    int n, pmax, pmin;
    while(std::cin>>n>>pmax>>pmin){
        resuelve_caso(n,pmax,pmin);
    }
}
