#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory>

//三次元ベクトルを表すクラス
class Vec3 {
    public:
        double x;
        double y;
        double z;

    //コンストラクタ
    Vec3(double _x,double _y,double _z){
        x = _x;
        y = _y;
        z = _z;
    };

    //出力
    void print() const{
        printf("(%f,%f,%f)",x,y,z);
    };

    //長さを求める
    double length() const{
        return sqrt(std::pow(x,2) + std::pow(y,2) + std::pow(z,2));
    };
};

//演算子+をオーバーロード
Vec3 operator+(const Vec3& left,const Vec3& right) {
    return Vec3(left.x + right.x, left.y + right.y,left.z + right.z);
}

//演算子-をオーバーロード
Vec3 operator-(const Vec3& left,const Vec3& right) {
    return Vec3(left.x - right.x, left.y - right.y,left.z - right.z);
}

//演算子*をオーバーロード
Vec3 operator*(const Vec3& left,const Vec3& right) {
    return Vec3(left.x * right.x, left.y * right.y,left.z * right.z);
}

//スカラー倍
Vec3 operator*(const Vec3& v, double k) {
    return Vec3(k * v.x, k * v.y , k * v.z);
}

//演算子/をオーバーロード
Vec3 operator/(double k,const Vec3& v) {
    return Vec3(k / v.x, k / v.y, k / v.z);
}

Vec3 operator/(const Vec3& v,double k) {
    return Vec3(v.x / k, v.y /k, v.z / k);
}

double dot(const Vec3& v1, const Vec3& v2){ 
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

class Ray {
    public:
        Vec3 origin; //始点
        Vec3 direction; //方向

    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction){};
};

class Sphere{
    public:
        Vec3 center; //中心座標
        double radius; //半径

    Sphere(const Vec3& center, double radius): center(center), radius(radius){};

    //Rayとの衝突計算を行うメンバ関数
    bool intersect(const Ray& ray) const {
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

        return true;
    };
};

int main() {

}