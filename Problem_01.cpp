#include <iostream>
#include "Matriz.h"
#include <algorithm>
using namespace std;

struct cuerda{
    int longitud;
    int precio;
};


bool posible(vector<cuerda> cuerdas,int n, int l);
int matematico(vector<cuerda> cuerdas, int n, int l);
int economista(vector<cuerda> cuerdas,int n, int l);
int ingeniero(vector<cuerda> cuerdas, int n, int l);


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
        cout<<"SI "<<matematico(cuerdas,n,l)<<'\n';//<<' '<<ingeniero(cuerdas,n,l)<<' '<<economista(cuerdas,n,l)<<endl;
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
    Matriz<int> matriz(n+1,l+1);

    //Casos base
    for(int i=1;i<=l;i++)
        matriz[0][i]=0;

    for(int i=0;i<=n;i++){
        matriz[i][0]=0;
    }

    matriz[0][0] = 1;

    //Casos recursivos
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l;j++){
            if(cuerdas[i-1].longitud > j){
                matriz[i][j] = matriz[i-1][j];
            }else{
                matriz[i][j] = matriz[i-1][j]+matriz[i][j-cuerdas[i-1].longitud];
            }
        }
    }

    cout<<matriz;
    return matriz[n][l];
}
