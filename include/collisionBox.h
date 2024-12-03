//
// Created by xiaofg on 24-11-27.
//


#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H
#include <vector>
#include <utility>

class collisionManager;

class collisionBox {
private:
    //bool enemy;
    int traits;
    std::pair<int, int> box;
    friend collisionManager;
public:
    collisionBox()=default;
    ~collisionBox()=default;
};

#endif //COLLISIONBOX_H
