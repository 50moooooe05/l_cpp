#ifndef RANDOM_H
#define RANDOM_H

std::random_device dev_rnd;
std::mt19937 mt(dev_rnd()); //std::mt19937...メルセンヌ・ツイスタによる擬似乱数生成器
std::uniform_real_distribution<> dist(0,1);
//0から1までの一様分布に従う乱数が得られる
inline double rnd() {
    return dist(mt);
};

#endif