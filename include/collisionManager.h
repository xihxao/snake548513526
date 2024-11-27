//
// Created by xiaofg on 24-11-27.
//

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "collisionBox.h"
class collisionManager {
private:
    static bool HadCreated;
    static collisionManager* coll_manager;
    collisionManager()=default;
public:
    int collisionManager_Init();
    ~collisionManager()=default;
    int creat_collisionbox();
    int destroy_collisionbox();

};
#endif //COLLISIONMANAGER_H
