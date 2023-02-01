#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
#include "EnterosInf.h"

/*
Para cada caso de prueba, primero se escribir ́a una l ́ınea con la m ́axima cantidad de oro que se 
puede recuperar. Despu ́es se escribir ́a otra l ́ınea con el n ́umero de cofres a recoger, 
seguida de una l ́ınea por cada uno de ellos con la informaci ́on de 
cada uno: profundidad y cantidad de oro. Los cofres deben presentarse en el mismo orden 
que aparecen en la entrada. Se garantiza que la soluci ́on  ́optima es  ́unica. Despu ́es de la 
salida de cada caso se escribir ́a ---.
 */

struct cofre{
    int p;
    int oro;
};

void sol(int T, int N, std::vector<cofre> const& cofres);

int main(){
    int T, N;
    while(std::cin>>T){
        std::cin>>N;
        std::vector<cofre> cofres;
        for(int i=0;i<N;i++){
            int p,oro;
            std::cin>>p>>oro;
            cofres.push_back({p,oro});
        }
        sol(T,N,cofres);
    }
}

void sol(int T, int N, std::vector<cofre> const& cofres){

    Matriz<int> matriz(N+1, T+1, 0);

    //Casos base
    for(int i=1;i<=N;i++)
        matriz[i][0] = 0;
    for(int i=1;i<=T;i++)
        matriz[0][i] = 0;

    matriz[0][0] = 0;

    //Caso recursivo
    for(int i=1;i<N+1;i++){
        for(int j=0;j<T+1;j++){
            if(j<3*cofres[i-1].p)
                matriz[i][j] = matriz[i-1][j];
            else
                matriz[i][j] = 
                    std::max(matriz[i-1][j], matriz[i-1][j-3*cofres[i-1].p] +cofres[i-1].oro);
        }
    }

    //reconstruccion

    int i = N;
    int j = T;
    std::vector<cofre> sol;
    int n_cofres=0;

    while(i>0 && j>0){
        if(matriz[i][j] != matriz[i-1][j]){
            sol.push_back(cofres[i-1]);
            j -= cofres[i-1].p*3;
            n_cofres++;
        }
        i--;
    }


    std::cout<<matriz[N][T]<<std::endl<<n_cofres<<std::endl;
    for(int i=n_cofres-1;i>=0;i--){
        std::cout<<sol[i].p<<' '<<sol[i].oro<<std::endl;
    }
    std::cout<<"---\n";
}
