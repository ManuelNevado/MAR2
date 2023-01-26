#include <iostream>
#include "Matriz.h"
#include "EnterosInf.h"
#include <algorithm>
using namespace std;

struct cuerda{
    int longitud;
    int precio;
};

void print_vint(vector<int> v,int n){
    for(int i=0;i<n;i++)
        cout<<v[i]<<' ';
    cout<<'\n';
}
bool posible(vector<cuerda> cuerdas,int n, int l);
int matematico(vector<cuerda> cuerdas, int n, int l);
int economista(vector<cuerda> cuerdas,int n, int l);
EntInf ingeniero(vector<cuerda> cuerdas, int n, int l);


int main(){
    
    int n, l;
    while(cin>>n){
        cin>>l;
        vector<cuerda> cuerdas;
        for(int i=0;i<n;i++){
            int longitud, precio;
            cin>>longitud;
            cin>>precio;
            cuerdas.push_back({longitud,precio});
        }

        if(posible(cuerdas,n,l))
        cout<<"SI "<<matematico(cuerdas,n,l)<<' '<<ingeniero(cuerdas,n,l)<<endl;//<<' '<<economista(cuerdas,n,l)<<endl;
        else
            cout<<"NO\n";
    }


    return 0;
}

bool posible(vector<cuerda> cuerdas, int n, int l){
    //Un vector con n columnas para la longitud
    Matriz<bool> matriz(n+1, l+1);

    //Casos base
    matriz[0][0] = true; //hacer un cordel de longitud 0 con 0 cordeles es posible
    
    for(int i=1;i<=n;i++){
        matriz[i][0] = true; // hacer un cordel de longitud 0 con los cordeles desde 1 hasta
                               // n
    }

    for(int i=1;i<=l;i++){
        matriz[0][i] = false; // hacer un cordel de longitud i <- [1,l] con 0 cordeles no
                                // es posible
    }



    //Casos iterativos
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l;j++){
            if(cuerdas[i-1].longitud > j){//No se puede coger
                matriz[i][j] = matriz[i-1][j];
            }else{
                matriz[i][j] = matriz[i-1][j] || matriz[i-1][j-cuerdas[i-1].longitud];
            }
        }
    }

    //cout<<matriz;

    return matriz[n][l];
}

int matematico(vector<cuerda> cuerdas, int n, int l){
    vector<int> v(l+1,0);
    
    v[0] = 1;//Solo se puede hacer una cuerda de longitud 0 de 1 manera, con 0 cuerdas

    for(int i=0;i<n;i++){
        for(int j=l;j>=0;j--){
            int i_prev = j - cuerdas[i].longitud;
            v[j] += v[i_prev];
        }
    }

    //print_vint(v,l+1);
    return v[l];
}


EntInf ingeniero(vector<cuerda> cuerdas, int n, int l){

    vector<EntInf> v(l+1,Infinito);
    

    //Caso recursivo
    for(int i=0;i<n;i++){
        cout<<"i: "<<i<<"\nj: "<<l<<"\nhasta: "<<cuerdas[i].longitud<<endl;
        for(int j =l;l>=cuerdas[i].longitud;j--){
            int prev_index = j - cuerdas[i].longitud;
            cout<<"prev_index: "<<prev_index<<endl;
            v[j] = min(v[j],v[prev_index]+1);
        }
    }
    //cout<<matriz;
    return v[l];
}
