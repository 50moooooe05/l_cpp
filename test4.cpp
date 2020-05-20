#include <iostream>

int sum(int m, int n);
void product(int m,int n);
int fibo(int n);

int main() {
    /*
    int a;
    int b;
    int c;
    std::cin >> a;
    std::cin >> b;
    c = sum(a,b); //関数を使う
    std::cout << c << std::endl;
    */
    
    /*
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    product(a,b);
    */

    int n = 10;
    std::cout << fibo(10) << std::endl;
}

int sum(int m, int n) { //関数定義
    return m + n; //引数を足した値が戻り値となる。
}

void product (int m, int n) {
    std::cout << m*n << std::endl;  //処理だけで、戻り値がない
} 

int fibo(int n){
    int fib[n+1];
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] +fib[i-2];
    }

    return fib[n];
}