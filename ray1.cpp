#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

/*
int main(){
    const int x = 1;
    x = 2;
    return 0;
}
*/

//クラス
/*
class Player{
    public:
        int health;
        int life;

        //体力１００、残機３で初期化する
        Player(){
            health = 100;
            life = 3;
        };
        //クラスが破棄されるときに呼ばれる
        ~Player() {};

        //弾に当たったときにダメージを計算する
        void getDamage(){
            health -= 10;

            //体力が0になったら
            if(health <= 0){
                life--;
                health = 100;
            }
        };

        void print(){
            printf("%d %d\n",health,life);
        }
};

int main(){
    //Playerを作る。コンストラクタが呼ばれる。
    Player ply = Player();

    //Playerの体力と残機を出力
    ply.print();

    //ダメージを与える
    ply.getDamage();

    //もう一回Playerの体力と残機を出力
    ply.print();
}
*/

//継承
class Figure{
    public:
        virtual double area() const = 0; //具体的な定義を書くことはできない
};

class Rectangle : public Figure {
    public:
        double x1, y1, x2, y2;

        Rectangle(double _x1,double _y1,double _x2,double _y2) {
            x1 = _x1;
            y1 = _y1;
            x2 = _x2;
            y2 = _y2;
        };
    
    double area() const{
        return (x2 - x1) * (y2 - y1);
    };
};

class Circle : public Figure{
    public:
        double x1,y,x2;

        Circle(double _x1,double _y,double _x2){
            x1 = _x1;
            y = _y;
            x2 = _x2;
        };

    double area() const{
        return  (x2+x1)*M_PI;
    };
};

class Triangle : public Figure{
    public:
        double x1,y1,x2,y2;

        Triangle(double _x1,double _y1,double _x2,double _y2){
            x1 = _x1;
            y1 = _y1;
            x2 = _x2;
            y2 = _y2;
        };

    double area() const{
        return (x1 - x2) * (y1 - y2) / 2;
    };
};

void printArea(const Figure& fig){
    printf("%f\n",fig.area());
}

/*
int main(){
    Rectangle rect(1,1,2,2);
    Circle circle(1,1,1);
    Triangle trg(1,1,2,2);
    
    printArea(rect);
    printArea(circle);
    printArea(trg);
}
*/

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

Vec2 operator+(const Vec2& left,const Vec2& right){
    return Vec2(left.x + right.x, left.y + right.y);
}

Vec2 operator-(const Vec2& left,const Vec2& right){
    return Vec2(left.x - right.x, left.y - right.y);
}

Vec2 operator*(const Vec2& left,const Vec2& right){
    return Vec2(left.x * right.x, left.y * right.y);
}

/*
int main(){
    Vec2 v1(1,1);
    Vec2 v2(2,2);

    Vec2 v3 = v1 + v2;
    v3.print();

    Vec2 v4 = v1 - v2;
    v4.print();

    Vec2 v5 = v1 * v2;
    v5.print();

    return 0;
}
*/

//STLから
int main(){

}