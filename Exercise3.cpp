#include <iostream>

long fib_recursion(long n){
    long n_fibonacci = 0;
    if (n == 0){
        n_fibonacci = 0;
    }
    else if (n == 1){
        n_fibonacci = 1;
    }
    else{
        n_fibonacci = fib_recursion(n-1)+fib_recursion(n-2);  
    }
    return n_fibonacci;
}

int main(){
    long n;
    std::cout<<"Serie de Fibonacci"<<std::endl;
    std::cout<<"Ingresar numero:"<<std::endl;
    std::cin>>n;
    long fibr = fib_recursion(n);
    std::cout<<"f("<<n<<") recursivo = "<<fibr<<std::endl;
    
    return 0;
}