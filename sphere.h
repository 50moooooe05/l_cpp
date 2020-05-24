#ifndef SPHERE_H
#define SPHERE_H
#include "vec3.h"
#include "ray.h"
#include "hit.h"

class Sphere{
    public:
        Vec3 center; //中心座標
        double radius; //半径

    Sphere(const Vec3& center, double radius): center(center), radius(radius){};

    //Rayとの衝突計算を行うメンバ関数
    bool intersect(const Ray& ray,Hit& hit) const {
        double d_norm = ray.direction.length();
        double oc_norm = (ray.origin - center).length();

        double a = std::pow(d_norm,2);
        double b = 2 * dot(ray.direction,ray.origin - center);
        double c = std::pow(oc_norm,2) - std::pow(radius,2);
        double D = std::pow(b,2) - 4 * a * c; //判定式
        if(D < 0) return false; //D<0のとき、実数解は存在しない

        //解の候補
        double t1 = (-b + std::sqrt(D)) / (2*a);
        double t2 = (-b - std::sqrt(D)) / (2*a);

        //衝突距離
        //直線の方向を前側としたときに、直線の始点より後側で衝突した場合もfalse
        double t = t1;
        if(t < 0){ 
            t = t2;
            if(t < 0) return false;
        }

        hit.t = t;
        hit.hitPos = ray.origin + t * ray.direction;
        hit.hitNormal = normalize(hit.hitPos - center);

        return true;
    };
};

#endif