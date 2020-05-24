#include <iostream>
#include <cmath>
#include "vec3.h"
#include "image.h"
#include "sphere.h"
#include "camera.h"

int main(){
    Image img(512,512);
    Camera cam(Vec3(0,0,-3), Vec3(0,0,1));

    for(int  i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
            double u = (2.0 * i - img.width) / img.width;
            double v = (2.0 * j - img.height) / img.height;
            Ray ray = cam.getRay(u,v);
            img.setPixel(i,j,(ray.direction + Vec3(1,1,1))/2.0);
        }
    }
    img.ppm_output();
    
}
