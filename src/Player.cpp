//
// Created by xiaofg on 24-11-29.
//

#include "Player.h"
#include "snakegame.h"

Player::Player(int a):traits(a),location({}) {}
Player::Player():traits(0){};
Player::~Player()=default;
int Player::kill(Global_Game& a){
    return 0;
};

void Player::move_change(char a){
    switch (a)
    {
        case 'w':
            std::cout<<'w'<<std::endl;
        break;
        case 'a':
            std::cout<<'a'<<std::endl;
        break;
        case 's':
            std::cout<<'s'<<std::endl;
        break;
        case 'd':
            std::cout<<'d'<<std::endl;
        break;
        default:
            break;
    }
}

void Player::move_ahead() {
    std::cout<<"move ahead"<<std::endl;
}

std::pair<int, int> Player::getLocation(int a) {
    return std::pair<int,int>{1,1};
}

