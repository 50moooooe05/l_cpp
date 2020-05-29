#ifndef ACCEL_H
#define ACCEL_H
#include <vector>
#include <memory>
#include "ray.h"
#include "hit.h"
#include "sphere.h"

class Accel{
    public:
        std::vector<std::shared_ptr<Sphere>> spheres;

        Accel() {};

        void add(std::shared_ptr<Sphere> p){
            //Sphereのshared_ptrを末尾に追加する
            spheres.push_back(p);
        };

        bool intersect(const Ray& ray,Hit& hit) const {
            bool isHit = false;

            // hitの距離を大きな値で初期化しておく
            // double t ... 衝突点までの距離
            hit.t = 10000;

            //全ての物体に対して衝突計算をする
            Hit hit_each;

            for(auto p : spheres){
                if(p->intersect(ray,hit_each)){
                    isHit = true;
                    //衝突距離は短いものがあったらhitをそれで置き換える
                    if(hit_each.t < hit.t){
                        hit = hit_each;
                    }
                }
            }

            return isHit;
        };
};

#endif