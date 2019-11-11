#include <iostream>
#include <iomanip> 

int fill(int num,float **M);
int imprimir(int f,int c,float **M);
float **mul(int n1,int m1,int n2,int m2,float **M,float **N);
bool pruebaNil(int num,float **M);

int main()
{
    std::cout<<"Matrices"<<std::endl;
    int N;
    std::cout<<"Ingresar numero de filas y columnas:"<<std::endl;
    std::cin>>N;
    
    float **M = new float *[N];
    for (int i=0;i<N;++i){
        M[i] =new float[N];
    }
    float **R = new float *[N];
    for (int i=0;i<N;++i){
        R[i] =new float[N];
    }
    float **H = new float *[N];
    for (int i=0;i<N;++i){
        H[i] =new float[N];
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            H[i][j] = float(1)/float(i+j+1);
        }
    }
    
    std::cout<<"Matriz de Hilbert (H):"<<std::endl;
    imprimir(N,N,H);
    
    R = mul(N,N,N,N,H,H);
    std::cout<<"Multiplicación H*H:"<<std::endl;
    imprimir(N,N,R);
    
    fill(N,M);
    std::cout<<"Matriz nilpotente (N):"<<std::endl;
    imprimir(N,N,M);
    
    bool prueba;
    prueba = pruebaNil(N,M);
    if(prueba){
        std::cout<<"La matriz N es Nilpotente"<<std::endl;
    }
    else{
        std::cout<<"La matriz N NO es Nilpotente"<<std::endl;
    }

    return 0;
}

int fill(int num,float **M){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i==0 & j!=num-1){
                M[i][j] = 2;
            }
            else if(i==0 & j==num-1){
                M[i][j] = 1-num;
            }
            else if(j==num-1 & i!=0){
                M[i][j] = -num;
            }
            else if(j+1==i){
                M[i][j] = num+2;
            }
            else{
                M[i][j] = 1;
            }
        }
    }
    return 0;
}

int imprimir(int f,int c,float **M){
    std::cout<<std::setprecision(16);
    for (int i=0;i<f;i++){
        for (int j=0;j<c;j++) {
            std::cout<<std::scientific;
            std::cout<<M[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
    return 0;
}

float **mul(int n1,int m1,int n2,int m2,float **M,float **N){
    if(m1==n2){
        float **R = new float *[n1];
        for (int i=0;i<n1;++i){
            R[i] =new float[m2];
        }
        for(int i=0; i<n1; ++i){
            for(int j=0; j<m2; ++j){
                R[i][j] = 0;
            }
        }
        for(int i=0; i<n1; ++i){
            for(int j=0; j<m1; ++j){
                for(int z=0; z<m2; ++z){
                    R[i][j] += M[i][z] * N[z][j];
                }
            }
        }

        return R;
    }
    else{
        std::cout<<"No se puede realizar la multiplicación, m1!=n2"<<std::endl;
    }
}

bool pruebaNil(int num,float **M){
    bool prueba = false;
    float **R = new float *[num];
        for (int i=0;i<num;++i){
            R[i] =new float[num];
        }
    R = mul(num,num,num,num,M,M);
    for(int k=0;k<num;k++){
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(R[i][j]==0){
                    prueba = true;
                }
                else{
                    prueba = false;
                }
            }
        }
        R = mul(num,num,num,num,R,M);
    }
    
    return prueba;
}