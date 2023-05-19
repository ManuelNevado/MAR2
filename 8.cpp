#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Matriz.h"
//Esto es un algoitmo de FLOYD de libro
//Seria muy util y facilitaria mucho las cosas trnasformar la lista de personas
//en un matriz de adyacencia
//
//Otra solucion que he visto es hacer un recorrido en anchura desde cada nodo, esto devuelve 
//el camino minimo entre un nodo y cualquiera de los siguientes, se mantiene un entero
//con el camino maximo global



void resuelveCaso(int P, int R){
    
    Matriz<int> grafo(P,R,0);
    std::unordered_map<std::string,int> mapa_nombres;
    int n = 0;

    for(int i=0;i<R;i++){
        std::string nombre1, nombre2;
        std::cin>>nombre1>>nombre2;
        
        int indice1, indice2;
        if(mapa_nombres.find(nombre1) == mapa_nombres.end()){
            mapa_nombres[nombre1] = n;
            indice1 = n;
            n++;
        }else{
            indice1 = mapa_nombres[nombre1];
        }if(mapa_nombres.find(nombre2) == mapa_nombres.end()){
            mapa_nombres[nombre2] = n;
            indice2 = n;
            n++;
        }else{
            indice2 = mapa_nombres[nombre2];
        }


        //Creo la conexion con los indices
        grafo[indice1][indice2] = 1; 

    }
    
    std::cout<<grafo<<std::endl;

}


int main(){
    
    int P, R;
    while(std::cin>>P>>R)
        resuelveCaso(P, R);

    return 0;
}
