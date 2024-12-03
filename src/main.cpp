/////////////////////////////////////////////////////////
/*
author:
version:0.0.1
date:2024 十一月/17
role:
throw:
invalid_argument"too more argument for  fn main"
invalid_argument"error argument for  fn main"
UnkownError
other_description:
*/
/////////////////////////////////////////////////////////

//#include <iconv.h>
#include <spdlog/spdlog.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <filesystem> 
#ifdef _WIN32
    #include <conio.h>
#elif defined(_WIN64)
    #include <conio.h>
#elif defined(__linux__)
    #include <termios.h>
#else
    throw "unexcept_OS"
#endif

#include <collisionManager.h>

#include "snakegame.h"
//extern std::array<int,1024>chessboard{0};


int main(int argc,char* argv[])
{try{
    using namespace std;
    Global_Game global_game{};
    char input_char{'w'};
    Player player1{};
    Player player2{};
    filesystem::path MusicPath {"res/Aice room - Aoharu.mp3"};
    MusicPath= filesystem::canonical(MusicPath);
    SDL_Window* win = nullptr;
    SDL_Renderer* rend=nullptr;
    Mix_Music* music = nullptr;
    Player* winner = nullptr;

    if (argc>2) cerr<<("too more argument for  fn main");
    try{
    if (argc==2){
        global_game.init(argv[1]);
    }
    }
    catch(const runtime_error& error){
        if(error.what()==string("error argument for  fn main")){
            cerr<<("error argument for  fn main");
        }
        else{
            cerr<<("UnkownError");
        }
    }
    //xian cheng 1-n

    if (SDL_Init(SDL_INIT_TIMER) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    spdlog::info("SDL Init Successfully");

    const collisionManager* COLL_MANAGER=collisionManager_Init();

    // 创建窗口
    win = SDL_CreateWindow("SNAKE_GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       930, 930, 0);
    if (!win) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1; // 创建窗口失败
    }
    spdlog::info("Window Creat!");

    // 创建渲染器
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1; // 创建渲染器失败
    }
    spdlog::info("Render Creat!");
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,1,4096)==EOF){
        cerr<<"MIXER Init Fail";
        spdlog::warn("MIXER Init Failed!");
        return 1;
        }
    music = Mix_LoadMUS(const_cast<char*>(MusicPath.string().c_str()));
    spdlog::info("MIXER Init Successfully");



    //游戏循环和基本控制
    while(true){
        SDL_Delay(2000);


        if (music == nullptr) {
            spdlog::warn("Failed to load music: {}{}", Mix_GetError(), const_cast<char*>(MusicPath.string().c_str()));
            throw;
        }
        if(Mix_PlayingMusic() == 0 && Mix_PausedMusic() == 0) {
            if (Mix_PlayMusic(music, -1) == -1) {
                spdlog::warn("Error playing music: {}", Mix_GetError());
                throw;
            }
        }

        Mix_VolumeMusic(MIX_MAX_VOLUME);  // 设置最大音量
        if (input_char==' ')
          global_game.pasue();
        player1.move_change(input_char);
        winner=&global_game.Phy_Frame_Reflash(player1,player2);
        if (winner!=nullptr) {
            cout/*<<winner->traits*/<<" win"<<endl;
            break;
        }
        global_game.food_creat();
        global_game.Graph_Reflash(rend);
        //this_thread::sleep_for(chrono::seconds(2));
    }

    // 释放资源
    SDL_DestroyRenderer(rend);  // 销毁渲染器
    spdlog::info("Render Destroy!");
    SDL_DestroyWindow(win);     // 销毁窗口
    spdlog::info("Window Destroy!");
    Mix_FreeMusic(music);
    spdlog::info("MIXEr Destroy!");

    // 安全地关闭 SDL
    SDL_Quit();
    return 0;
}
catch(std::exception& e){
    spdlog::warn(e.what());
    std::cerr<<std::filesystem::current_path();
    return 1;
}
}
//input
//SDL2
//timesleep