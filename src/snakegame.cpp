#include <random>
#include <spdlog/spdlog.h>
#include "snakegame.h"
Player::Player(int a):traits(a),location({}) {}
Player::Player():traits(0){};
Player::~Player(){}
int Player::kill(Global_Game& a){
    for(int i=0;i<930;i++){
        if(a.chessboard[i]>0&&a.chessboard[i]%traits==0){
            a.chessboard[i]=0;
        }
    }
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



void Global_Game::init(char a[]){
    for (int i = 0; i < 930; i++)
    {
        if (i%30==0)
        {
            chessboard[i]=-65535;
            std::cout<<std::endl;
        }
        std::cout<<chessboard[i];
    }
}
void Global_Game::pasue(){
    std::this_thread::sleep_for(std::chrono::milliseconds(15));
    std::cin.ignore();
    std::cin.clear();
    char a{'a'};
    while(a!=' '){
        std::cin>>a;
    }
}

auto Global_Game::Itera(int a, int b)->decltype(chessboard.begin()) {
    return chessboard.begin() + (a * 32 + b);
}

void Global_Game::SoundPlay(const std::string& a)const{
    //this->SoundPlay_flag=1;
    //code
    //SoundPlay_flag=0;
    std::cout<<"SoundPlay"<<std::endl;
}

void Global_Game::food_creat(){
    int a=rand()%30;
    int b=rand()%30;
    //auto temp = Itera(a + 1, b + 1);
    *(Itera(a + 1, b + 1)) = -666;
    spdlog::info("food creat");
}

void Global_Game::Graph_Reflash(){

    std::cout<<"Graph_Reflash"<<std::endl;
};

template <class... Args>
Player* Global_Game::Phy_Frame_Reflash(Args... args){
    (..., args.move_ahead());
    (..., args.getLocation(0));
    spdlog::info("Physicis Reflash");
    return nullptr;
}
template Player* Global_Game::Phy_Frame_Reflash<Player>(Player, Player);
