#include <iostream>
#include <fstream>
#include <cmath>
#include "image.h"

int main(){
    Image img(512,512);

    int cx = 256;
    int cy = 256;
    int r = 100;

    for(int  i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
            int dx = i - cx;
            int dy = j - cy;
            if(dx*dx+dy*dy < r*r){
                img.setPixel(i,j, Vec3(255,255,255));
            }else{
                img.setPixel(i,j, Vec3(0,0,0));
            }
        }
    }
    img.ppm_output();
    
}
