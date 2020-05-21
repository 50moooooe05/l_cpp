#include <iostream>
#include <cmath>
#include <cstdio>

//抽象クラス
class Figure {
    public:
        virtual double area() = 0;
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

        double area(){
            return (x2-x1)*(y2-y1);
        };
};

//円クラス
class Circle : public Figure {
    public:
        double x1,y1,x2,y2;

    Circle(double _x1,double _y1,double _x2,double _y2){
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    };

    double area(){
        int r = sqrt(std::pow(x1-x2,2)+std::pow(y1-y2,2));
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

        double area(){
            return (x2-x1)*(y2-y1)/2;
        };
};

int main() {
    Rectangle rect = Rectangle(1,1,2,2);
    Circle circle = Circle(1,1,2,2);
    Triangle tri = Triangle(1,1,2,2);
    // printf("%f\n",rect.area());
    // printf("%f\n",circle.area());
    printf("%f\n",tri.area());
}