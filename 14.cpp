#include <iostream>
#include <queue>
#include <vector>

//Suma de tiempo de funcionarios minima

struct nodo{
    std::vector<int> tareas_para_cada_uno;
    std::vector<bool> tareas_asignadas;
    int k;  //indice de la iteracion
    int coste_real;
    int coste_estimado;
    bool operator<(nodo const& otro) const{return otro.coste_estimado < coste_estimado;}
};

int explora(int N, std::vector<std::vector<int>> const& matriz){

}

void resuelveCaso(int N){
    
    std::vector<std::vector<int>> matriz;

    for(int i=0; i<N; i++){
        std::vector<int> funcionario;
        for(int j=0;j<N;j++){
            int aux;
            std::cin>>aux;
            funcionario.push_back(aux);
        }
        matriz.push_back(funcionario);
    }
    
    std::cout<<explora(N, matriz)<<'\n';

}

int main(){

    int N;
    std::cin>>N;
    while(N>0){
        resuelveCaso(N);
        std::cin>>N;
    }
    return 0;
}
