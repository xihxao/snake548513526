#ifndef _SNAKEGAME_H
#define _SNAKEGAME_H 1
#include <array>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <thread>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

class Global_Game;

class Player{
private:
    const int traits;
    char direaction = 'w';
    std::vector<std::pair<int,int>> location {};
public:
    explicit Player(int);
    Player();
    ~Player();
    std::pair<int,int> getLocation(int);
    void move_ahead();
    void longth_increase();
    int kill(Global_Game&);
    void move_change(char);
};


class Global_Game{
private:
    std::array<int,1024>chessboard{0};
    auto Itera(int, int) -> decltype(chessboard.begin());
public:
    friend Player;
    void init(char[]);
    void pasue();
    template<class... Args>
    Player* Phy_Frame_Reflash(Args... args);
    void Graph_Reflash();
    void food_creat();
    void SoundPlay(const std::string& a)const;//yi bu
};

#endif