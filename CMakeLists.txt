cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")

project(MeuJogoRaylib VERSION 1.0 LANGUAGES CXX)

# 1. Define o padrão do C++ (C++20 é uma ótima escolha para jogos)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Coleta automaticamente todos os arquivos fontes .cpp da pasta src/
file(GLOB SOURCES "src/*.cpp")

# 3. Define o executável com os fontes encontrados
add_executable(${PROJECT_NAME} ${SOURCES})

# 4. Inclui a pasta de headers (onde ficam seus arquivos .h ou .hpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# ==============================================================================
# 5. GERENCIAMENTO MANUAL DA RAYLIB
# ==============================================================================

# 1. Diz ao CMake onde encontrar o "raylib.h"
target_include_directories(${PROJECT_NAME} PRIVATE "C:/raylib-1/include")

# 2. Encontra o arquivo da biblioteca física (libraylib.a ou raylib.lib) dentro da pasta lib
find_library(RAYLIB_STATIC_LIB
    NAMES raylib libraylib
    PATHS "C:/raylib-1/lib"
    REQUIRED
)

# 3. Vincula a biblioteca ao seu jogo junto com as dependências do Windows
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${RAYLIB_STATIC_LIB}
    opengl32
    gdi32
    winmm
)
# ==============================================================================