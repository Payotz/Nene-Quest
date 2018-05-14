#pragma once

#include <SDL2/SDL.h>

#include "State.h"

class FirstState : public State{
    public:
        void onEnter();
        void handleEvents();
        void update();
        void render();
        void exit();
        FirstState(){}
        ~FirstState(){}
        static bool isRunning;
    private:
        static bool restartFlag;
};

