#pragma once

#include "State.h"

class FirstState : public State{
    public:
        void onEnter(bool twoPlayer);
        void handleEvents();
        void update();
        void render();
        void exit();
        ~FirstState(){}
        bool getIsRunning();
        bool getIsChangeState();
        std::string getChangeStateKey();
    private:
        static bool restartFlag;
        static bool isRunning;
        bool isChangeState;
        std::string changeStateKey;
};