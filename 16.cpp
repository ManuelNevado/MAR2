#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <vector>

struct nodo{
    int k;
    std::vetor<int> productos;
    int coste_real;
    int coste_estimado;
    bool operator<(nodo const& otro){return otro.coste_estimado < coste_estimado;};
};

int estimar_coste(std::vector<std::vector<int>> matriz, nodo X){
    //TODO funcion cota inferior del posible resultadod el programa
    //
    return 0;
}

void recorrido(int supermercados, int productos, std::vector<std::vector<int>> matriz){
    std::priority_queue<nodo> q;
    
    nodo cabeza;
    cabeza.k=-1;
    cabeza.productos = std::vector<int>(productos,0);
    cabeza.coste_real = 0;
    cabeza.coste_estimado = estimar_coste(matriz,cabeza);
    
    q.push(cabeza);

    int min = INT_MAX;

    while(!q.empty() && q.top().coste_estimado < min){
        //TODO bucle principal
        auto X = q.top();
        q.pop();


    }

}


void resuelveCaso(){
    int supermercados, productos;
    std::cin>>supermercados>>productos;
    
    std::vector<std::vector<int>> matriz;

    for(int i=0;i<supermercados;i++){
        std::vector<int> v;
        for(int j=0;j<productos;j++){
            int precio;
            std::cin>>precio;
            v.push_back(precio);
        }
        matriz.push_back(v);
    }

    int sol = recorrido(supermercados, productos, matriz);

    if(sol>0)
        std::cout<<sol<<'\n';
    else
        std::cout<<"Sin solucion factible\n";
}


int main(){
    
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        resuelveCaso();
    }

    return 0;
}
