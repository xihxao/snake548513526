//
// Created by xiaofg on 24-11-29.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <array>
#include <string>
#include <utility>
#include <stdexcept>
#include <iostream>
class Global_Game;

Player if_win();

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
    friend Player if_win();////if sb win ;return winner Player
    //////////////////////////else return nullptr
};

#endif //PLAYER_H
