#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

/*
 *  Esfuerzo de cortar un tablon es el dobre que su longitud
 *
 */

int coste(std::vector<int> v, int L, int inicio, int fin){
    if(fin == -1)
        fin = L;

    return 2*(fin - inicio);
}

void resuelveCaso(int N, int L){
    
    std::vector<int> v(N);

    for(int i=0;i<N;i++){
        int aux;
        std::cin>>aux;
        v[i] = aux;
    }


    //m[i][j] = minimo coste cortando desde 0 hasta j
    //con las marcas desde 0 hasta i
    Matriz<int> m(L,L);
    
    //el caso base es la diagonal principal
    for(int i=0;i<=N;i++){
        m[i][i] = coste(v,L,i,i);
    }
    
    //luego el resto de diagonales
    for(int d = 1; d<N; d++){
        for(int i = 0; i<N-d;i++){
            int j = i+d;
            int esfuerzo = coste(v,L,i,j);

            //k es el corte que se procesa
            for(int k=i+1; k<j;k++){
                int temp = m[i][k-1] + m[k+1][j] + esfuerzo;

                if(temp<m[i][j])//es mejor cortar por k
                    m[i][j]=temp;
            }

            m[i][j] = std::min(m[i][j], m[i][j-1]+esfuerzo);
            m[i][j] = std::min(m[i][j], m[i+1][j]+esfuerzo);
        }
    }

    std::cout<<m;


}

int main(){
    int L, N;
    std::cin>>L>>N;
    if(L != 0 && N != 0){
        resuelveCaso(N,L);

        std::cin>>L>>N;
    }
}
