#include "game.h"
SDL_Window* window;
SDL_GLContext context;

std::unique_ptr<State> state;

void Game::initialize(){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);

    window = SDL_CreateWindow("Hello World!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(window == NULL){
        std::cout << "Window not created! : " << SDL_GetError() << std::endl;
        return;
    }
    context = SDL_GL_CreateContext(window);
    if(!context){
        std::cout << "Context not created! : " << glGetError() << std::endl;
        return;
    }
    gl3wInit();
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

    state = std::make_unique<FirstState>();
    state->onEnter();
}

void Game::handleEvents(){
    state->handleEvents();
}

void Game::update(){
    state->update();
    isRunning = state->isRunning;

}

void Game::render(){
    glClearColor(255,255,255,255);
    state->render();
    SDL_GL_SwapWindow(window);
}

void Game::cleanup(){
    IMG_Quit();
    SDL_Quit();
}