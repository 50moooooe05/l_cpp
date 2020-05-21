#include <iostream>
#include <cmath>
#include <cstdio>

//抽象クラス
class Figure {
    public:
        virtual double area() const = 0;
};

//矩形
class Rectangle : public Figure {
    public:
        double x1,y1,x2,y2;

        Rectangle(double _x1,double _y1,double _x2,double _y2){
            x1 = _x1;
            y1 = _y1;
            x2 = _x2;
            y2 = _y2;
        };

        double area() const{
            return (x2-x1)*(y2-y1);
        };
};

//円クラス
class Circle : public Figure {
    public:
        double x1,y1,x2;

    Circle(double _x1,double _y1,double _x2){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
    };

    double area() const{
        double r = sqrt(x2 + x1);
        return (r * r * M_PI);
    };
}; 

//三角形クラス
class Triangle : public Figure {
    public:
        double x1,y1,x2,y2;

        Triangle(double _x1,double _y1,double _x2,double _y2){
            x1 = _x1;
            y1 = _y1;
            x2 = _x2;
            y2 = _y2;
        };

        double area() const{
            return (x2-x1)*(y2-y1)/2;
        };
};

void printArea(const Figure& fig) {
  printf("%f\n", fig.area());
}

//二次元ベクトルを表すクラス
class Vec2 {
    public:
        double x;
        double y;

    //コンストラクタ
    Vec2(double _x,double _y){
        x = _x;
        y = _y;
    };

    //出力
    void print() const{
        printf("(%f,%f)",x,y);
    };
};

//演算子+をオーバーロード
Vec2 operator+(const Vec2& left,const Vec2& right) {
    return Vec2(left.x + right.x, left.y + right.y);
}

//演算子-をオーバーロード
Vec2 operator-(const Vec2& left,const Vec2& right) {
    return Vec2(left.x - right.x, left.y - right.y);
}

//演算子*をオーバーロード
Vec2 *operator(const Vec2& left,const Vec2& right) {
    return Vec2(left.x * right.x, left.y * right.y);
}

int main() {
    /*
    Rectangle rect(1,1,2,2);
    Circle circle(1,1,1);
    
    printArea(rect);
    printArea(circle);

    return 0;
    */

    Vec2 v1(1,1);
    Vec2 v2(2,2);

    Vec3 v3 = v1 + v2;
    v3.print();

    return 0; 
}