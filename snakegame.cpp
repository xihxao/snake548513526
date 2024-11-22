#include "snakegame.h"
Player::Player(int a):traits(a){}
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

void Global_Game::SoundPlay(const std::string& a)const{
    //this->SoundPlay_flag=1;
    //code
    //SoundPlay_flag=0;
    std::cout<<"SoundPlay"<<std::endl;
}

void Global_Game::food_creat(){
    std::cout<<"food creat"<<std::endl;
}

void Global_Game::Graph_Reflash(){
    std::cout<<"Graph_Reflash"<<std::endl;
};

void Global_Game::Phgsicis_Frame_Reflash(){
    std::cout<<"Phgsicis"<<std::endl;
}

void Global_Game::global_Confirm(){
    std::cout<<"global_Confirm"<<std::endl;
}

