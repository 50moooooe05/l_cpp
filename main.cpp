#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include "vec3.h"
#include "ray.h"
#include "hit.h"
#include "image.h"
#include "sphere.h"
#include "camera.h"
#include "accel.h"

std::random_device dev_rnd;
std::mt19937 mt(dev_rnd()); //std::mt19937...メルセンヌ・ツイスタによる擬似乱数生成器
std::uniform_real_distribution<> dist(0,1);
//0から1までの一様分布に従う乱数が得られる
double rnd() {
    return dist(mt);
}

Vec3 randomDir() {
    double theta = M_PI*rnd();
    double phi = 2*M_PI*rnd();

    double x = std::cos(phi) * std::sin(theta);
    double y = std::cos(theta);
    double z = std::sin(phi) * std::sin(theta);

    return Vec3(x,y,z);
}

int main(){
    Image img(512,512);
    Camera cam(Vec3(0,0,-3), Vec3(0,0,1));

    Accel accel;
    accel.add(std::make_shared<Sphere>(Sphere(Vec3(0,0,0),1.0)));
    accel.add(std::make_shared<Sphere>(Sphere(Vec3(0,-10001,0),10000)));

    for(int k = 0; k < 100; k++){
        for(int  i = 0; i < img.width; i++){
            for(int j = 0; j < img.height; j++){
                double u = (2.0 * (i + rnd()) - img.width) / img.width;
                double v = (2.0 * (j + rnd()) - img.height) / img.height;
                Ray ray = cam.getRay(u,v);
                
                Vec3 color;
                Hit hit;
                if(accel.intersect(ray,hit)){
                    Vec3 lightDir = randomDir();
                    Ray shadowRay = Ray(hit.hitPos+0.001*hit.hitNormal,lightDir);
                    Hit hit_shadow;
                    if(!accel.intersect(shadowRay,hit_shadow)){
                        color = Vec3(1,1,1);
                    }else{
                        color = Vec3(0,0,0);
                    }
                }else{
                    color = Vec3(1,1,1);
                }

                img.setPixel(i,j,img.getPixel(i,j) + 1/100.0 * color); //平均をとる
            }
        }
    }
    img.ppm_output();
    
}
