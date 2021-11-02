#pragma once
#include<assert.h>
#include <SFML/Window.hpp>
#include<GL/glew.h>
#define RENDERER Renderer::instance()
namespace tat
{
    class Renderer
    {
    private:
        Renderer();
        sf::Window *window;

    public:
        static Renderer &instance();
        void init(const char *title, int height, int width);
        void render(std::function<void()> renderFunc);
        void terminate();
    };
}