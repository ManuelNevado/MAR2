#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
#include <string>


struct Sol{
    int n;
    std::string new_s;
};

void solucion(std::string s);
int aibofobia(std::string const& s, Matriz<int> &matriz, int i, int j);
void reconstruirSol(std::string const& s, Matriz<int> const& matriz, std::string & new_s, int i, int j);

int main(){
    std::string s;
    while(std::cin>>s){
        solucion(s);
    }
}


void solucion(std::string s){
    Sol sol = {0,""};
    Matriz<int> matriz(s.size(),s.size(),-1); //-1 significa que no se ha inicializado
    
    sol.n = aibofobia(s,matriz,0,s.size()-1);

    reconstruirSol(s,matriz, sol.new_s,0,s.size()-1);

    std::cout<<sol.n<<' '<<sol.new_s<<std::endl;
/*
    if(sol.n != sol.new_s.size() - s.size())
        fprintf(stderr, "Error en la longitud de la palabra");
*/
}


void reconstruirSol(std::string const& s, Matriz<int> const& matriz, std::string & new_s, int i, int j){
    if(i<=j){
        if(i==j)
            new_s.push_back(s[i]);
        
        else if(s[i] == s[j]){
            new_s.push_back(s[i]);
            reconstruirSol(s, matriz,new_s,i+1,j-1);
            new_s.push_back(s[j]);
        
        }else if(matriz[i][j] == matriz[i+1][j] +1){
            new_s.push_back(s[i]);
            reconstruirSol(s,matriz,new_s,i+1,j);
            new_s.push_back(s[i]);

        }else{
            new_s.push_back(s[j]);
            reconstruirSol(s,matriz,new_s,i,j-1);
            new_s.push_back(s[j]);
        }
    }
}

int aibofobia(std::string const& s, Matriz<int> & matriz, int i, int j){
    int &res = matriz[i][j];

    if(res == -1){
        if(i==j || i>j)
            res = 0;
        else if (s[i] == s[j])
            res = aibofobia(s, matriz, i+1, j-1);
        else
            res = std::min(aibofobia(s,matriz,i+1,j), aibofobia(s,matriz,i,j-1)) +1;
    }

    return res;
}

