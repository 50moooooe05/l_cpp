#ifndef RAY_H
#define RAY_H

class Ray {
    public:
        Vec3 origin; //始点
        Vec3 direction; //方向

    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction){};
};

#endif