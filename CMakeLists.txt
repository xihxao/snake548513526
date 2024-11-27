cmake_minimum_required(VERSION 3.30)
project(snake548)

#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_FLAGS "-mconsole")
set(CMAKE_C_FLAGS "-mconsole")
# 强制编译为控制台应用程序，而非 GUI 应用程序
# 如果是 Windows 平台，可以设置一些特定的编译标志
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_SCL_SECURE_NO_WARNINGS")
endif()

# 自动收集 src 目录下的所有 .cpp 文件
file(GLOB SOURCES "src/*.cpp")

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)

# 设置包含目录
include_directories(
        ${CMAKE_SOURCE_DIR}/include  # 假设你的头文件在 include 目录下
        E:/cpplib_include/include
        E:/cpplib_include/spdlog-1.15.0/spdlog-1.15.0/include
        #E:/cpplib_include/SDL2_ttf-2.22.0/x86_64-w64-mingw32/include
        #E:/cpplib_include/SDL2-devel-2.30.9-mingw/SDL2-2.30.9/x86_64-w64-mingw32/include
        #E:/cpplib_include/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/x86_64-w64-mingw32/include
        #E:/cpplib_include/SDL2_mixer-devel-2.8.0-VC/SDL2_mixer-2.8.0/include
)

# 设置库目录
link_directories(
        E:/cpplib_include/SDL2_ttf-2.22.0/x86_64-w64-mingw32/lib
        E:/cpplib_include/SDL2-devel-2.30.9-mingw/SDL2-2.30.9/x86_64-w64-mingw32/lib
        E:/cpplib_include/SDL2-devel-2.30.9-mingw/SDL2-2.30.9/x86_64-w64-mingw32/lib/libSDL2.a
        E:/cpplib_include/SDL2-devel-2.30.9-mingw/SDL2-2.30.9/x86_64-w64-mingw32/lib/libSDL2main.a
        E:/cpplib_include/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/x86_64-w64-mingw32/lib
        E:/cpplib_include/SDL2_mixer-devel-2.8.0-mingw/SDL2_mixer-2.8.0/x86_64-w64-mingw32/lib
)


# 创建可执行文件
add_executable(snake548 WIN32 ${SOURCES}
        include/collisionLayer.h
        src/collisinLayer.cpp
        include/collisionBox.h
        include/collisionManager.h
        src/collisionBOX.cpp
        src/collisionBOX.h
        src/collisionManager.cpp)


# 链接所需的库
target_link_libraries(snake548
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_mixer
        SDL2_ttf
)


