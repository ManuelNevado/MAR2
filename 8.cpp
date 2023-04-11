#include <iostream>
#include <stdlib>
#include <vector>
#include <string>


//Esto es un algoitmo de FLOYD de libro
//Seria muy util y facilitaria mucho las cosas trnasformar la lista de personas
//en un matriz de adyacencia
//
//Otra solucion que he visto es hacer un recorrido en anchura desde cada nodo, esto devuelve 
//el camino minimo entre un nodo y cualquiera de los siguientes, se mantiene un entero
//con el camino maximo global
//


void resuelveCaso(int P, int R){

    Matriz<std::string> relaciones(R,2,"");
    for(int i=0;i<R;i++){
        std::string s1, s2;
        std::cin>>s1>>s2;
        relaciones[i][0]=s1;
        relaciones[i][1]=s2;
    }
    
}


int main(){
    
    int P, R;
    while(std::cin>>P>>R)
        resuelveCaso(P, R);

    return 0;
}
