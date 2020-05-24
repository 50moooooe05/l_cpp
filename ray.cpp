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
    return k*v;
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

class Sphere{
    public:
        Vec3 center; //中心座標
        double radius; //半径

    Sphere(const Vec3& center, double radius): center(center), radius(radius){};

    //Rayとの衝突計算を行うメンバ関数
    bool intersect(const Ray& ray) const {

    };
};

class Ray {
    public:
        Vec3 start; //始点
        Vec3 direction; //方向

    Ray(const Vec3& start, const Vec3& direction) : start(start), direction(direction){};
};

int main() {
    /*
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared(Sphere(center, radius)));

    for(auto shape : shapes){
        if(shapes->intersect(ray)){
            printf("Hit\n");
        }
    }
    */

    Vec3 v1(1,1,sqrt(2));
    Vec3 v2(2,4,6);
    double d = dot(v1,v2);
    double l = v1.length();
    printf("%f\n",l);
}