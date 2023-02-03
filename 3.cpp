#include <iostream>
#include <algorithm>
#include <vector>
#include "Matriz.h"

int max3(int a, int b, int c){
    return std::max(a,std::max(b,c));
}


void resuelve(int n){
    int suma, col;


    Matriz<int> datos(n,n);
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            int aux;
            std::cin>>aux;
            datos[i][j] = aux;
        }
    }


    Matriz<int> matriz_sol(n,n,0);
    suma =0;
    col = n;

    //Caso base
    for(int j=0;j<n;j++)
        matriz_sol[0][j] = datos[0][j]; //Maxima suma por cada columna hasta la profundida 0
    
    //Caso recursivo
    for(int i=1;i<n;i++){
        matriz_sol[i][0] = datos[i][0] + std::max(matriz_sol[i-1][0],matriz_sol[i-1][1]); 
        matriz_sol[i][n-1] = datos[i][n-1] + std::max(matriz_sol[i-1][n-1], matriz_sol[i-1][n-2]);

        for(int j=1;j<n-1;j++){
            matriz_sol[i][j] = datos[i][j] + max3(matriz_sol[i-1][j-1],matriz_sol[i-1][j],matriz_sol[i-1][j+1]);
        }
    }
    //el valor maximo de la ultima fila
    for(int j=0;j<n;j++){
        if(matriz_sol[n-1][j] > suma){
            suma = matriz_sol[n-1][j];
            col = j;
        }
    }

    std::cout<<suma<<' '<<col+1<<std::endl;

}


int main(){
    
    int n;
    while(std::cin>>n){
        resuelve(n);
    }


    return 0;
}
