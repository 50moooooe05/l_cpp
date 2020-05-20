#include <iostream>

/*
int main() {
    int p;
    std::cout << "整数を入力してください";
    std::cin >> p;
    if(p % 2 == 0){
        std::cout << "偶数ですね" << std::endl;
    }else{
        std::cout << "奇数ですね" << std::endl;
    }
    return 0;
}
*/

int main(){
    // std::cout << "Hello, World!" << std::endl;
    /*
    std::cout << 1 + 3 << std::endl; 
    std::cout << 2 - 3 << std::endl;
    std::cout << 1.4 * 2.5 << std::endl;
    std::cout << 3.0 / 2.0 << std::endl;
    std::cout << (1.3 + 2.4) * 2.0 << std::endl;
    */

    /*
    int a;
    std::cout << "a= ";
    std::cin >> a;
    std::cout << a*a << std::endl;
    */

    //例題
    //入力した2文字の実数a, bが a < b , a = b, a > b　のどれになるのか判定するプログラム

    int a;
    int b;

    std::cout << "a=";
    std::cin >> a;
    std::cout << "b=";
    std::cin >> b;

    if(a < b){
        std::cout << "a < b";
    }else if(a == b){
        std::cout << "a = b";
    }else if(a > b){
        std::cout << "a > b";
    }
}