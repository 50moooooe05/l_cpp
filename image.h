#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include "vec3.h"

class Image {
    public:
        int width; //横幅
        int height; //縦幅
        Vec3* data;

    //コンストラクタ
    Image(int _width, int _height){
        width = _width;
        height = _height;
        data = new Vec3[width*height];
    };

    //デストラクタ 使い終わったメモリを解放する
    ~Image() {
      delete[] data;
    };

    Vec3 getPixel(int i, int j) const{
        return data[width*i+j];
    };

    void setPixel(int i, int j, const Vec3& color){
        data[width*i+j] = color;
    }; 

    void ppm_output() const {
        std::ofstream file("output.ppm");
        file << "P3" << std::endl; 
        file << width << " " << height << " " << std::endl;
        file << "255" << std::endl;
  
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                Vec3 color = 255*this->getPixel(j,i);
                int r = (int)color.x;
                int g = (int)color.y;
                int b = (int)color.z;
                file << r << " " << g << " " << b << std::endl;
            }
        }
    };
};

#endif