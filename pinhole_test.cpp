#include <iostream>
#include <cmath>
#include <memory>
#include <random>
#include <algorithm>
#include "vec3.h"
#include "ray.h"
#include "image.h"
#include "camera.h"
#include "sphere.h"
#include "accel.h"

int main() {
    Image img(512,512);
    PinholeCamera cam(Vec3(0,0,0),Vec3(0,0,-1),1);

    Accel accel;
    accel.add(std::make_shared<Sphere>(Vec3(0,0,-3),1));
    accel.add(std::make_shared<Sphere>(Vec3(0,-10001,0),10000));

    Vec3 sunDir = normalize(Vec3(1,1,1));

    for(int k = 0; k < 100; k++){
        for(int i = 0; i < img.width; i++){
            for(int j = 0; j < img.height; j++){
                double u = (2.0 * (i + rnd()) - img.width) / img.width;
                double v = (2.0 * (j + rnd()) - img.height) / img.height;

                Vec3 col;
                Ray ray = cam.getRay(u,v);
                Hit hit;
                if(accel.intersect(ray,hit)){
                    Ray shadowRay(hit.hitPos + 0.001 * hit.hitNormal, sunDir);
                    Hit hit_temp;
                    if(!accel.intersect(shadowRay,hit_temp)){
                        col = std::max(dot(hit.hitNormal,sunDir),0.0) * Vec3(1,1,1);
                    }
                    else{
                        col = Vec3(0,0,0);
                    }
                }
                else{
                    col = Vec3(0,0,0);
                }
                img.setPixel(i,j,img.getPixel(i, j) + 1/100.0*col);
            }
        }
    }
    img.ppm_output();

    return 0;
}