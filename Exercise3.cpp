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

long fib(long n){
    long a = 1;
    long b = 0;
    for (int i=0;i<n;i++){
        long x = b;
        b += a;
        a = x;
    }
    return b;
}

int main(){
    long n;
    std::cout<<"Serie de Fibonacci"<<std::endl;
    std::cout<<"Ingresar numero:"<<std::endl;
    std::cin>>n;
    long fibr = fib_recursion(n);
    std::cout<<"f("<<n<<") recursivo = "<<fibr<<std::endl;
    long fibn = fib(n);
    std::cout<<"f("<<n<<") no recursivo = "<<fibn<<std::endl;
    
    return 0;
}