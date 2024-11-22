#ifndef _SNAKEGAME_H
#define _SNAKEGAME_H 1
#include <array>
#include <string>
#include <stdexcept>
#include <iostream>
#include <thread>
#include <chrono>
#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>

class Global_Game;

class Player{
private:
    int traits;
public:
    Player(int);
    Player();
    ~Player();
    int kill(Global_Game&);
    void move_change(char);
};


class Global_Game{
private:
    std::array<int,930>chessboard{0};
    bool SoundPlay_flag{0};
public:
    friend Player;
    void init(char[]);
    void pasue();
    void Phgsicis_Frame_Reflash();
    void Graph_Reflash();
    void global_Confirm();
    void food_creat();
    void SoundPlay(const std::string& a)const;//yi bu
};

#endif