#include <random>
#include <spdlog/spdlog.h>
#include "snakegame.h"
#include "player.h"
#include "collisionManager.h"

extern collisionManager* COLL_MANAGER;

void Global_Game::init(char PATH[]){
    if (PATH==NULL) {
        return;
    }
    else {
        load PATH;
    }
}
void Global_Game::pasue(){
    //std::this_thread::sleep_for(std::chrono::milliseconds(15));
    SDL_Delay(20);
    std::cin.ignore();
    std::cin.clear();
    char a{'a'};
    while(a!=' '){
        std::cin>>a;
    }
}

//auto Global_Game::Itera(int a, int b)->decltype(chessboard.begin()) {
//    return chessboard.begin() + (a * 32 + b);
//}

void Global_Game::food_creat(){
    int a,b;
    do {
        a=rand()%30;
        b=rand()%30;
        //auto temp = Itera(a + 1, b + 1);
    }while (COLL_MANAGER->collisionHasUsed(a,b));
        COLL_MANAGER->creat_collisionbox(a,b,666,0);

    spdlog::info("food creat");
}

void Global_Game::Graph_Reflash(SDL_Renderer* rend){
    SDL_Rect rect={0,0,930,930};
    SDL_SetRenderDrawColor(rend,255,255,255,255);
    SDL_RenderFillRect(rend,&rect);
    rect.w=30;rect.h=30;
    for (int i=0; i<4;i++) {
        COLL_MANAGER->boxes.find(i);
        SDL_SetRenderDrawColor(rend,255-32*i+32,32*i-32,32*i-32,255);
        for (int j=0; j<4;j++) {
            rect.w=30;rect.h=30;
            SDL_RenderFillRect(rend,&rect);
        }
    }


    spdlog::info("Graph Reflash");
};

/*template <class... Args>
Player* Global_Game::Phy_Frame_Reflash(Args... args){
    (..., args.move_ahead());
    (..., args.getLocation(0));
    spdlog::info("Physicis Reflash");
    return nullptr;
}*/
Player Global_Game::Phy_Frame_Reflash() {
    COLL_MANAGER->collisionDetection();
    spdlog::info("Phy_Frame_Reflash");
    return if_win();
}

//template Player* Global_Game::Phy_Frame_Reflash<Player>(Player, Player);
