//
// Created by xiaofg on 24-11-27.
//

#include <vector>
#include <utility>
#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H
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
