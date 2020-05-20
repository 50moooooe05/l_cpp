#include <iostream>

int main() {
    /*
    int x = 0;
    for(int i = 1; i <= 100; i++){
        x += i;
    }
    std::cout << x << std::endl;
    */

    //例題
    //1〜100までの７の倍数の総和と1〜100までの７の倍数でない整数の総和の差を求めるプログラム

    int x = 0;
    int y = 0;

    for(int i = 1; i <= 100; i++){
        if(i % 7 == 0){
            x += i;
            continue;
        }else{
            y += i;
        }
    }
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}