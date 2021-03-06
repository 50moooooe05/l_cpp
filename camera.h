#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"
class Camera {
    public:
    Vec3 camPos; //カメラの位置
    Vec3 camForward; //カメラの前方向
    Vec3 camUp;
    Vec3 camRight;

    Camera(const Vec3& camPos,const Vec3& camForward) : camPos(camPos), camForward(camForward) {
        camRight = -1 * normalize(cross(camForward,Vec3(0,1,0)));
        camUp = normalize(cross(camForward,camRight));
    };

    Ray getRay(double u,double v) const{
        Vec3 pinhole = camPos + camForward;
        Vec3 sensorPos = camPos + u * camRight + v * camUp;
        return Ray(sensorPos,normalize(pinhole - sensorPos));
    };
};

class PinholeCamera : public Camera {
    public:
        double pinholeDist; 

        PinholeCamera(const Vec3& camPos,const Vec3& camForward,double pinholeDist) : Camera(camPos,camForward),pinholeDist(pinholeDist) {};
};

#endif

