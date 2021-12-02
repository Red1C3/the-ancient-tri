/*
the-ancient-tri A low level OpenGL render engine
Copyright (C) 2021 Mohammad Issawi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once
#include<assert.h>
#include <SFML/Window.hpp>
#include<glbinding/gl33/gl.h>
#include<glbinding/glbinding.h>
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
        sf::Window* getInternalWindow();
        void terminate();
    };
}