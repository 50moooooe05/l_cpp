#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

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
        double x1,y1,x2,y2;

        Circle(double _x1,double _y1,double _x2,double _y2){
            x1 = _x1;
            y1 = _y1;
            x2 = _x2;
            y2 = _y2;
        };

    double area() const{
        return (x2 - x1) * (y2 - y1) * M_PI;
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

int main(){
    Rectangle rect = Rectangle(1,1,2,2);
    Circle crl = Circle(1,1,2,2);
    Triangle trg = Triangle(1,1,2,2);
    // printf("%f\n",trg.area());
}

void printArea(const Rectangle& rect){
    printf("%f\n",rect.area());
}

//ポリモーフィズムから