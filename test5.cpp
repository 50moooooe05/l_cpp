#include <iostream>

void swap(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main() {
    /*
    int num = 0;
    int* i = &num; // ポインタ変数の宣言、初期化 
    *i = 3;
    std::cout << num << std::endl;
    */

    int m = 0;
    int n = 5;
    swap(&m, &n); //アドレス演算子をつけること!
    std::cout << m << std::endl;
    std::cout << n << std::endl;
}