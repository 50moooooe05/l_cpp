#ifndef VEC3_H
#define VEC3_H

//三次元ベクトルを表すクラス
class Vec3 {
    public:
        double x;
        double y;
        double z;

    Vec3() {
        x = y = z = 0;
    };

    //コンストラクタ
    Vec3(double _x,double _y,double _z){
        x = _x;
        y = _y;
        z = _z;
    };

    //出力
    void print() const{
        printf("(%f,%f,%f)\n",x,y,z);
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

Vec3 operator-( const {
    return Vec3(-x,-y,-z);
})

//演算子*をオーバーロード
Vec3 operator*(const Vec3& left,const Vec3& right) {
    return Vec3(left.x * right.x, left.y * right.y,left.z * right.z);
}

//スカラー倍
Vec3 operator*(double k,const Vec3& v) {
    return Vec3(k * v.x, k * v.y , k * v.z);
}

Vec3 operator*(const Vec3& v,double k) {
    return k * v;
}

//演算子/をオーバーロード
Vec3 operator/(double k,const Vec3& v) {
    return Vec3(k / v.x, k / v.y, k / v.z);
}

Vec3 operator/(const Vec3& v,double k) {
    return Vec3(v.x / k, v.y /k, v.z / k);
}

Vec3 operator+=(const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3 operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3 operator*=(const Vec3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vec3 operator/=(const Vec3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

double dot(const Vec3& v1, const Vec3& v2){ 
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3 cross(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

Vec3 normalize(const Vec3& v) {
    return v/v.length();
}

Vec3 reflect(const Vec3& d, const Vec3& n) {
    return Vec3(d - 2*dot(d,n)*n);
}

//ベクトルnのみから正規直交基底を生成してくれる関数
void orthonormalBasis(const Vec3& n, Vec3& x, Vec3& z) {
    if(n.x > 0.9) x = Vec3(0,1,0);
    else x = Vec3(1,0,0);
    x = x - dot(x,n)*n;
    x = normalize(x);
    z = cross(n,x);
}

Vec3 worldToLocal(const Vec3& v,const Vec3& s,const Vec3& t,const Vec3& n){
    return Vec3(dot(v,s),dot(v,t),dot(v,n));
};

Vec3 localToWorld(const Vec3& v,const Vec3& s,const Vec3& t,const Vec3& n){
    Vec3 a = Vec3(s.x,n.x,t.x);
    Vec3 b = Vec3(s.y,n.y,t.y);
    Vec3 c = Vec3(s.z,n.z,t.z);
    return Vec3(dot(v,a),dot(v,b),dot(v,c));
}


#endif