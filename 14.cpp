#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
//Suma de tiempo de funcionarios minima

struct nodo{
    //std::vector<int> tareas_para_cada_uno;
    std::vector<bool> tareas_asignadas;
    int k;  //indice de la iteracion
    int coste_real;
    int coste_estimado;
    bool operator<(nodo const& otro) const{return otro.coste_estimado < coste_estimado;}
};

void report_queue(nodo const& Y){
    std::cout<<"Nodo{"<<'\n'<<'\t'<<"k: "<<Y.k<<"\n\tcoste_real: "<<Y.coste_real<<"\n\tcoste_estimado: "<<Y.coste_estimado<<"\n}\n";
}

bool es_solucion(nodo const& n, int N){return n.k == N-1;}

int minimo(std::vector<int> const& v){
    int min = INT_MAX;
    for (auto it : v){
        if (it <min)
            min = it;
    }
    return min;
}

int coste_estimado(nodo const& n, std::vector<std::vector<int>> const& matriz, int N){
    int min_posible = 0;
    for(int i=0; i<N;i++){
        if(!n.tareas_asignadas[i]){ //hace la mejor suma posible para los (n-k) ministros que no han sido computados
            min_posible += minimo(matriz[i]);
        }
    }
    
    return n.coste_real + min_posible;
}

nodo inicia_cabeza(int N, std::vector<std::vector<int>> const& matriz){
    nodo er_cabesa;

    //er_cabesa.tareas_para_cada_uno = std::vector<int>(N, -1);
    er_cabesa.k = -1;    //Ningun ministro
    er_cabesa.tareas_asignadas = std::vector<bool>(N, false);
    er_cabesa.coste_real = 0;
    er_cabesa.coste_estimado = coste_estimado(er_cabesa, matriz, N);
    
    return er_cabesa;
}

int explora(int N, std::vector<std::vector<int>> const& matriz){
    
    std::priority_queue<nodo> q;
    std::vector<int> suma_minima;
    nodo cabesa = inicia_cabeza(N, matriz);
    int min = INT_MAX;

    q.push(cabesa);

    while(!q.empty() && q.top().coste_estimado < min){
        
        //popeamos el primer elemento del monticulo
        auto X = q.top();
        q.pop();
        //report_queue(X); //Esta funcion es para debuguear
        //generamos todos los hijos
        for(int i=0;i<N;i++){
            nodo Y = X;
            if(!Y.tareas_asignadas[i]){
                Y.k++;                                              //aumentamos la k, avanzamos de ministro
                Y.tareas_asignadas[i] = true;                       //si la tarea i no ha sido asignada se asigna
                Y.coste_real += matriz[Y.k][i];                     //se suma el coste de esa tarea
                Y.coste_estimado = coste_estimado(Y, matriz, N);    //se estima el nuevo nodo
                
                if(es_solucion(Y, N)){              //Si es solucion comprobamos si mejora el minimo anterior
                    //std::cout<<"NODO SOLUCION: ";
                    //report_queue(Y);
                    if(Y.coste_real < min)
                        min = Y.coste_real;
                }
                else if(Y.coste_estimado < min){//Si no es solucion y la estimacion es mejor que lo que ya tenemos, apilamos en el heap
                        q.push(Y);
                }
            }
        }
    }
    

    return min;
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
