#include <iostream>
#include <iomanip>

int main(){
    /*
    int n = 100;
    double B[n];
    for(int i = 0; i < n; i++){
        B[i] = (i + 1) * (i + 1);
        std::cout << B[i] << std::endl;
    }
    */

    //フィボナッチ数列
    /*
    int n;
    std::cin >> n;

    int fib[n+1];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-2] + fib[i-1];
    }
    std::cout << fib[n] << std::endl;
    */

    //例題1
    /*
    int sum = 0;
    for(int x = 0; x <= 10; x++){
        for(int y = 0; y <= x*x; y++){
            sum++;
        }
    }
    std::cout << sum << std::endl;
    */

    //例題2
    int n;
    int m;
    int l;
    std::cin >> n;
    std::cin >> m;
    std::cin >> l;

    double A[n][m];
    double B[m][l];
    double C[n][l];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> A[i][j];
        }
    }

     for(int i = 0; i < m; i++){
        for(int j = 0; j < l; j++){
            std::cin >> B[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){
            C[i][j] = 0;
            for(int k = 0; k < m ; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
            std::cout << std::setw(4) << C[i][j];
        }
        std::cout << std::endl;
    }
    
}