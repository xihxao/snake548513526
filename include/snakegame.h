#ifndef SNAKEGAME_H548513526
#define SNAKEGAME_H548513526 1
#include <array>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "Player.h"

class Global_Game{
private:
    //std::array<int,1024>chessboard{0};
    //auto Itera(int, int) -> decltype(chessboard.begin());
public:
    friend Player;
    void init(char[]);
    void pasue();
    //template<class... Args>
    //Player* Phy_Frame_Reflash(Args... args);
    Player Phy_Frame_Reflash();
    void Graph_Reflash(SDL_Renderer*);
    void food_creat();
};

#endif