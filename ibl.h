#ifndef IBF_H
#define IBF_H
#include <cmath>
#include "ray.h"

class IBL {
    public:
        int width;
        int height;
        float* ibl_data; //HDR画像データ

        IBL(const std::string& filename){
            int n;
            ibl_data = stbi_loadf(filename.c_str(),&width,&height,&n,0);
        };

        ~IBL{
            stbi_image_free(ibl_data);
        };

    RGB getcolor(const Ray& ray) const {
        double phi = std::atan2(ray.direction.z,ray.direction.x);
        if(phi < 0) phi += 2*M_PI;
        float theta = std::acos(ray.direction.y);

        double u = phi/(2*M_PI);
        double v = theta/M_PI;

        int w = (int)(u * width);
        int h = (int)(v * height);
        int adr = 3*w + 3*width*h;
        return RGB(ibl_data[adr],ibl_data[adr+1],ibl_data[adr+2]);
    };

};