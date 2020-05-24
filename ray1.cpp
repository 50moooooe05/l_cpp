#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory>
#include <string>

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
Vec2 operator*(const Vec2& left,const Vec2& right) {
    return Vec2(left.x * right.x, left.y * right.y);
}

class  Person{
   public:
   int age; 
   std::string name;

   Person(int _age, const std::string& _name) {
       age = _age;
       name = _name;
   };
};

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

    Vec2 v3 = v1 * v2;
    v3.print();

    return 0;

    //std::vector
    /*
    std::vector<Vec2> v; //int型のstd::vector

    v.push_back(Vec2(1,1)); //末尾に(1,1)を追加
    v.push_back(Vec2(2,2)); //末尾に(2,2)を追加
    v.push_back(Vec2(3,3)); //末尾に(3,3)を追加

    for(int i = 0; i < v.size(); i++){
        v[i].print();
    }
    printf("\n");

    return 0;
    */

    //スマートポインタ
    /*
    std::shared_ptr<Person> p = std::make_shared<Person>(Person(20,"Watson"));
    printf("%d\n",p->age);
    return 0;
    */

    /*ターミナルでやるときは
    clang++ -std=c++11 ray1.cpp
    C++11で使われ始めたかららしい
    */
}