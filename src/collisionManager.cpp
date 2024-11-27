//
// Created by xiaofg on 24-11-27.
//

#include "collisionManager.h"

bool collisionManager::HadCreated = false;
collisionManager* collisionManager::coll_manager=nullptr;

collisionManager* collisionManager::collisionManager_Init(){
    if (!HadCreated){
        HadCreated = true;
        collisionManager* coll_manager=new collisionManager();
    }
    return coll_manager;
}
