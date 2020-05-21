#include <iostream>
#include <cstdio>

void f(int& x){
    x = 2;
}

int main() {
    int x = 1;
    f(x);
    printf("%d\n",x);

    return 0;
}