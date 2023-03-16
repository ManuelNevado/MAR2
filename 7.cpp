#include <iostream>
#include <algorithm>
#include "Matriz.h"
#include <string>
#define MAX_LENGTH 1000
void comun(char* a, char* b);

int main(){
    std::string a_s, b_s;    
    char a[MAX_LENGTH],b[MAX_LENGTH];
    
    while(std::cin>>a_s){
        std::cin>>b_s;
        int i=0;
        for(auto it: a_s){
            a[i] = it;
            i++;
        }
        i=0;
        for(auto it: b_s){
            b[i] = it;
            i++;
        }
        
        comun(a, b);
    }
    return 0;
}

void comun(char* a, char* b){
    

}
