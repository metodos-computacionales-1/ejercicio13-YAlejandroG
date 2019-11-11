#include <iostream>

int getMaxInt(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

double getMaxDouble(double a,double b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    std::cout<<"Hallar maximo"<<std::endl;
    int a,b;
    std::cout<<"Ingresar primer entero:"<<std::endl;
    std::cin>>a;
    std::cout<<"Ingresar segundo entero:"<<std::endl;
    std::cin>>b;
    int maxint = getMaxInt(a,b);
    std::cout<<"Maximo entre "<<a<<" y "<<b<<": "<<maxint<<std::endl;
    
    double c,d;
    std::cout<<"Ingresar primer double:"<<std::endl;
    std::cin>>c;
    std::cout<<"Ingresar segundo double:"<<std::endl;
    std::cin>>d;
    double maxDouble = getMaxDouble(c,d);
    std::cout<<"Maximo entre "<<c<<" y "<<d<<": "<<maxDouble<<std::endl;
    
    return 0;
}