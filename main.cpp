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
#include <chrono>
#include <thread>
#include <stdexcept>
#include <SDL.h>
#include <SDL_timer.h>
#ifdef _WIN32
    #include <conio.h>
#elif defined(_WIN64)
    #include <conio.h>
#elif defined(__linux__)
    #include <termios.h>
#else
    throw "unexcept_OS"
#endif

#include "snakegame.h"
const std::string PATH_MUSIC("/home/sduser/exercise/music/a.mp3");
//extern std::array<int,930>chessboard{0};


int main(int argc,char* argv[])
{
    using namespace std;
    Global_Game global_game{};
    char input_char{'w'};

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
    Player player1{};
    Player player2{};
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    spdlog::info("SDL Init");
   
    // 创建窗口
    SDL_Window* win = nullptr;
    win = SDL_CreateWindow("SNAKE_GAME", 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       1000, 1000, 0);
    if (!win) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1; // 创建窗口失败
    }
    spdlog::info("Window Creat!");

    // 创建渲染器
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1; // 创建渲染器失败
    }
    spdlog::info("Render Creat!");
    // 游戏循环和基本控制
    while(1){
        //if (SoundPlay_flag==0)
          global_game.SoundPlay(PATH_MUSIC);
        if (input_char==' ')
          global_game.pasue();
        player1.move_change(input_char);
        global_game.Phgsicis_Frame_Reflash();
        global_game.global_Confirm();
        global_game.food_creat();
        global_game.Graph_Reflash();
        //SDL_Delay(1000);
        this_thread::sleep_for(chrono::seconds(2));
        }
    }

    // 延迟 3 秒以便看到窗口
    SDL_Delay(10000);

    // 释放资源
    SDL_DestroyRenderer(rend);  // 销毁渲染器
    spdlog::info("Render Destory!");
    SDL_DestroyWindow(win);     // 销毁窗口
    spdlog::info("Window Destory!");

    // 安全地关闭 SDL
    SDL_Quit();
    return 0;
}
//input
//SDL2
//timesleep
//#include <SDL.h>
//#include <SDL_main.h> // only include this one in the source file with main()!
//
//int main(int argc, char* argv[])
//{
//    const int WIDTH = 640;
//    const int HEIGHT = 480;
//    SDL_Window* window = NULL;
//    SDL_Renderer* renderer = NULL;
//
//    SDL_Init(SDL_INIT_VIDEO);
//    window = SDL_CreateWindow("Hello SDL", WIDTH, HEIGHT, 0);
//    renderer = SDL_CreateRenderer(window, NULL);
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
//}