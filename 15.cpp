#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

struct nodo{
    int k;                      //maquina que se esta procesando
    std::vector<bool> caminos;  //caminos que se han barrido
    int coste_real;             //valor de la solucion parcial
    int coste_estimado;         //valor de la mejor solucion estimada
    bool operator>(nodo const& otro) const{return otro.coste_estimado>coste_estimado;}
};  

void print_caminos(std::vector<bool> const& v){
    for(auto it : v){
        if(it)
            std::cout<<'x';
        else
            std::cout<<'_';
        std::cout<<' ';
    }
    std::cout<<'\n';
}
void report_nodo(nodo const& X){
    std::cout<<"Nodo{\n";
    std::cout<<"\tk: "<<X.k<<'\n';
    std::cout<<"\tcaminos: ";
    print_caminos(X.caminos);
    std::cout<<"\tcoste_estimado: "<<X.coste_estimado<<'\n';
    std::cout<<"}\n";
}


bool es_solucion(nodo const& X, int n){return X.k == n-1;}

int min(std::vector<int> const& v){
    int min = 0;
    for(auto it: v)
        if(it>min)
            min=it;
    return min;
}

int estimar_coste(int n, int m, std::vector<std::vector<int>> const& matriz, nodo const& X){
    int por_calcular = 0;
    for(int i=0;i<n;i++)
        if(!X.caminos[i])
            por_calcular += min(matriz[i]);
    return X.coste_real+por_calcular;
}

int recorrido(int n, int m, std::vector<int> const& carros, std::vector<int> const& caminos, std::vector<std::vector<int>> const& matriz){
    

    //creamos la variable minima y la cola de prioridad
    int min = 0;
    std::priority_queue<nodo> q;
    nodo sol_mejor;
    
    //std::cout<<"Iniciando Cabeza...\n";
    //Iniciamos el nodo
    nodo er_cabesa;
    er_cabesa.k=-1;
    er_cabesa.caminos = std::vector<bool> (m, false);
    er_cabesa.coste_real = 0;
    er_cabesa.coste_estimado = estimar_coste(n,m,matriz,er_cabesa);
    //std::cout<<"Cabeza iniciada\n";
    
    //Apilamos la cabeza
    q.push(er_cabesa);

    //Empezamos el bucle
    while(!q.empty() && q.top().coste_estimado > min){

        nodo Y = q.top();
        q.pop();

        for(int i=0;i<m;i++){
            nodo X = Y;
            X.k++;
            if(!X.caminos[i] && carros[X.k] <= caminos[i]){
                report_nodo(X);
                X.caminos[i] = true;
                X.coste_real += matriz[X.k][i];
                X.coste_estimado = estimar_coste(n,m,matriz,X);
                
                if(es_solucion(X,n) && X.coste_real < min){
                    min = X.coste_real;
                    sol_mejor = X;
                }else if(X.coste_estimado > max){
                    q.push(X);
                }
            }

        }
    }

    return min;
}


void resuelveCaso(int n, int m){

    std::vector<int> carros(n);
    std::vector<int> caminos(m);
    std::vector<std::vector<int>> matriz;

    for(int i=0;i<n;i++){
        int aux;
        std::cin>>aux;
        carros[i] = aux;
    }
    for(int i=0;i<m;i++){
        int aux;
        std::cin>>aux;
        caminos[i] =aux;
    }

    for(int i=0;i<n;i++){
        std::vector<int> fila;
        for (int j=0;j<m;j++){
            int aux;
            std::cin>>aux;
            fila.push_back(aux);
        }
        matriz.push_back(fila);
    }

    std::cout<<recorrido(n, m, carros, caminos,  matriz)<<'\n';

}

int main(){
    int c;
    std::cin>>c;
    for(int i=0;i<c;i++){
        int n, m;
        std::cin>>n>>m;
        resuelveCaso(n,m);
    }

    return 0;
}
