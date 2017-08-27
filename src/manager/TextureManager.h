#ifndef TEXMAN__
#define TEXMAN__

#include <iostream>
#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include "../graphic/sprite.h"
#include "../graphic/shader.h"
#include "../graphic/rectangle.h"

class TextureManager{
    public:
        
        void addSprite(std::string spriteName, bool isPNG);
        Sprite* getSprite(std::string spriteName);
        void deleteSprite(std::string spriteName);

        void addShader(std::string name);
        Shader* getShader(std::string name);
        void deleteShader(std::string name);

        void addRectangle(std::string name,Rect* value);
        Rect* getRectangle(std::string name);
        void deleteRectangle(std::string name);

        static TextureManager* getInstance(){
            static TextureManager* instance = new TextureManager();
            return instance;
        }

        TextureManager(TextureManager const&) = delete;
        void operator= (TextureManager const&) = delete;

    private:
        static std::map <std::string, Sprite*> sprite_list;
        static std::map <std::string, Shader*> shader_list;
        static std::map <std::string, Rect*> rect_list;
        TextureManager() {}
        ~TextureManager() {}
};


#endif