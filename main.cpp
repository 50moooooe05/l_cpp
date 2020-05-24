#include <algorithm>
#include <iostream>
#include <cmath>
#include "vec3.h"
#include "image.h"
#include "sphere.h"
#include "camera.h"

int main(){
    Image img(512,512);
    Camera cam(Vec3(0,0,-3), Vec3(0,0,1));

    Sphere sphere(Vec3(0,0,0),1.0);

    Vec3 lightDir = normalize(Vec3(1,1,-1)); //光源の方向

    for(int  i = 0; i < img.width; i++){
        for(int j = 0; j < img.height; j++){
            double u = (2.0 * i - img.width) / img.width;
            double v = (2.0 * j - img.height) / img.height;
            Ray ray = cam.getRay(u,v);
            
            Hit hit;
            if(sphere.intersect(ray,hit)){
                double I = std::max(dot(lightDir,hit.hitNormal),0.0);
                img.setPixel(i,j,I * Vec3(1,1,1));
            }else{
                img.setPixel(i,j,Vec3(0,0,0));
            }
        }
    }
    img.ppm_output();
    
}
