#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include <omp.h>
#include "vec3.h"
#include "ray.h"
#include "image.h"
#include "sphere.h"
#include "camera.h"
#include "accel.h"

std::random_device dev_rnd;
std::mt19937 mt(dev_rnd()); //std::mt19937...メルセンヌ・ツイスタによる擬似乱数生成器
std::uniform_real_distribution<> dist(0,1);
//0から1までの一様分布に従う乱数が得られる
inline double rnd() {
    return dist(mt);
};

/*
Vec3 randomDir() {
    double theta = M_PI*rnd();
    double phi = 2*M_PI*rnd();

    double x = std::cos(phi) * std::sin(theta);
    double y = std::cos(theta);
    double z = std::sin(phi) * std::sin(theta);

    return Vec3(x,y,z);
}
*/

//ランダムな方向
Vec3 randomHemisphere(const Vec3& n){
    double u = rnd();
    double v = rnd();

    double y = u;
    double x = std::sqrt(1 - u * u) * std::cos(2 * M_PI * v);
    double z = std::sqrt(1 - u * u) * std::sin(2 * M_PI * v);

    Vec3 xv,zv;
    orthonormalBasis(n,xv,zv);

    return x*xv + y*n + z*zv;
}

Accel accel;

Vec3 getcolor(const Ray& ray,int depth = 0){
    if(depth > 100) return Vec3(0,0,0);
    
    Hit hit;
    if(accel.intersect(ray,hit)){
        //Diffuse
        if(hit.hitSphere->material == 0){
            Ray nextRay(hit.hitPos + 0.001 * hit.hitNormal,randomHemisphere(hit.hitNormal));
            double cos_term = std::max(dot(nextRay.direction,hit.hitNormal),0.0);
            return 2*M_PI * hit.hitSphere -> color/M_PI * cos_term * getcolor(nextRay,depth + 1);
        }
        //Mirror
        else if(hit.hitSphere->material == 1){
            //反射した先で陰影計算
            Ray nextRay(hit.hitPos + 0.001*hit.hitNormal,reflect(ray.direction,hit.hitNormal));
            return getcolor(nextRay,depth + 1);
        }
        else{
            return Vec3(0,0,0);
        }
    }
    else{
        return Vec3(1,1,1);
    }
}

int main(){
    Image img(512,512);
    Camera cam(Vec3(0,0,-3), Vec3(0,0,1));

    // accel.add(std::make_shared<Sphere>(Vec3(rnd(),rnd(),rnd()),0.5,Vec3(rnd(),rnd(),rnd()),0));
    accel.add(std::make_shared<Sphere>(Vec3(rnd(),rnd(),rnd()),rnd(),Vec3(rnd(),rnd(),rnd()),0));
    accel.add(std::make_shared<Sphere>(Vec3(0,-10001,0), 10000, Vec3(rnd(),rnd(),rnd()),0));

#pragma omp parallel for schedule(dynamic,1)
    for(int k = 0; k < 100; k++){
        for(int  i = 0; i < img.width; i++){
            for(int j = 0; j < img.height; j++){
                double u = (2.0 * (i + rnd()) - img.width) / img.width;
                double v = (2.0 * (j + rnd()) - img.height) / img.height;
                Ray ray = cam.getRay(u,v);
                
                Vec3 color = getcolor(ray);

                img.setPixel(i,j,img.getPixel(i,j) + 1/100.0 * color); //平均をとる
            }
        }
    }
    img.gamma_correction();
    img.ppm_output();
}
