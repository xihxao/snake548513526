//
// Created by xiaofg on 24-11-27.
//

#include "collisionManager.h"
#include <vector>////////////////////////


collisionManager::collisionManager():Has_Used({}),boxes({}){}
collisionManager::~collisionManager() {
    for(auto & i : boxes) {
        i.second.clear();
        i.second.shrink_to_fit();
    }
    Has_Used.clear();
    Has_Used.rehash(1);
}



bool collisionManager::HadCreated = false;
collisionManager* collisionManager::coll_manager=nullptr;


collisionManager* collisionManager_Init(){
    if (!collisionManager::HadCreated){
        collisionManager::HadCreated = true;
        collisionManager::coll_manager=new collisionManager();
    }
    return collisionManager::coll_manager;
}

bool collisionManager::collisionDetection(int trait1,int trait2){
  bool res=true;
  auto a=boxes.find(trait1);
    auto b=boxes.find(trait2);
    if (a==boxes.end()||b==boxes.end()){
        throw "box not found";
    }
    else{
        for (auto i=b->second.begin();i!=b->second.end();i++){
            res=res||(*a->second.begin()==*i);////提前返回？？？
        }
    }
}
/*int collisionManager::creat_collisionbox(int x,int y,int trait){
    if (Has_Used.find(std::pair<int,int>(x,y))!=Has_Used.end()){
        player1kill;
        player2trytokill;
    }
    else{
        auto a=boxes.find(trait);
        if (a!=boxes.end()){
            a->second.push_back(std::pair<int,int>(x,y));
        }
        else {
            std::vector<std::pair<int,int>>* temp=new std::vector<std::pair<int,int>>;
            boxes.insert({trait,*temp});
        }
        Has_Used.emplace(std::pair<int,int>(x,y));
    }
}*/
int collisionManager::creat_collisionbox(int x,int y,int trait,int offset=0){
    if (Has_Used.contains(std::pair<int,int>(x,y))){
        playerkill;
        playertrytokill;
    }
    else{
        auto a=boxes.find(trait);
        if (a!=boxes.end()){
            a->second.insert((a->second.begin()+offset),std::pair<int,int>(x,y));
        }
        else {
            auto* temp=new std::vector<std::pair<int,int>>;
            temp->emplace_back(x,y);
            boxes.insert({trait,*temp});
        }
        Has_Used.emplace(x,y);
    }
    return 0;
}

int collisionManager::boxesSize()const {
    return boxes.size();
}
