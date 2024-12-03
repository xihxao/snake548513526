//
// Created by xiaofg on 24-11-27.
//

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <memory>

#include "collisionBox.h"
#include <unordered_map>
#include <unordered_set>

collisionManager* collisionManager_Init();

class collisionManager {
private:
    static bool HadCreated;
    static collisionManager* coll_manager;
    std::unordered_set<std::pair<int,int>> Has_Used;
    std::unordered_map<int,std::vector<std::pair<int,int>>&> boxes;//记得销毁
    //int amounts_of_traits =0;
    collisionManager();
    collisionManager(collisionManager const&)=delete;
    collisionManager& operator=(collisionManager const&)=delete;
public:
    friend collisionManager* collisionManager_Init();
    ~collisionManager();
    //int creat_collisionbox(int,int,int);
    int creat_collisionbox(int,int,int,int);
    int destroy_collisionbox(int);
    void collisionDetection();/////////////////////////////
    bool collisionDetection(int,int);
    bool collisionHasUsed(int,int);
    int boxesSize()const;
};
#endif //COLLISIONMANAGER_H
