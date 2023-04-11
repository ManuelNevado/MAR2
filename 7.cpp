#include <iostream>
#include <algorithm>
#include "Matriz.h"
#include <string>
#define MAX_LENGTH 1000

void reconstruir_sol(std::string const& a, std::string const& b, int a_size, int b_size, Matriz<int> const& m, std::string & comun);
int subsecuencia(std::string const& a, std::string const& b, int a_size, int b_size, Matriz<int> &m);
void resuelveCaso(std::string a, std::string b);

int main(){

    std::string a, b;
    while(std::cin>>a>>b)
        resuelveCaso(a,b);

    return 0;
}


void resuelveCaso(std::string a, std::string b){
    int a_size=a.size(), b_size=b.size();  
    Matriz<int> m(a_size+1, b_size+1, -1);
    
    int sol = subsecuencia(a, b, a_size, b_size, m);

    std::string comun;
    if (sol != 0){
        reconstruir_sol(a, b, a_size, b_size, m, comun);
        std::cout<<comun<<'\n';
    }else
        std::cout<<'\n';
}

int subsecuencia(std::string const& a, std::string const& b, int i, int j, Matriz<int> &m){
    
    int &res = m[i][j];
    if(res==-1){
        if(i==0 || j==0)
            res = 0;
        else if(a[i-1] == b[j-1])
            res = subsecuencia(a,b,i-1,j-1,m)+1;
        else
            res = std::max( subsecuencia(a,b,i-1,j,m), subsecuencia(a,b,i,j-1,m));
    }

    return res;
}

void reconstruir_sol(std::string const& a, std::string const& b, int i, int j, Matriz<int> const& m, std::string & sol){
    if(i != 0 && j != 0){
        if (a[i-1] == b[j-1]){
            reconstruir_sol(a,b,i-1,j-1, m,sol);
            sol.push_back(a[i-1]);
        }else if(m[i][j] == m[i][j-1])
            reconstruir_sol(a, b, i, j-1, m, sol);
        else
            reconstruir_sol(a, b, i-1,j, m, sol);
    }
}
