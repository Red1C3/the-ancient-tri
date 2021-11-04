/*
the-ancient-tri an OpenGL legacy simulator

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
#include <Renderer.h>
using namespace tat;
using namespace sf;
using namespace std;
Renderer::Renderer() {}
Renderer &Renderer::instance()
{
    static Renderer renderer;
    return renderer;
}
void Renderer::init(const char *title, int height, int width)
{
    ContextSettings ctxSettings;
    ctxSettings.antialiasingLevel = 1;
    ctxSettings.depthBits = 16;
    ctxSettings.majorVersion = 3;
    ctxSettings.minorVersion = 3;
    ctxSettings.stencilBits = 8;
    window = new Window(VideoMode(width, height), title, Style::Default, ctxSettings);
    glewInit();
    glEnable(GL_DEPTH_TEST);
}
void Renderer::render(function<void()> renderFunc)
{
    while (1)
    {
        Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                terminate();
                return;
            case Event::Resized:
                //TODO
                break;
            default:
                break;
            }
        }
        renderFunc();
        assert(glGetError() == 0);
        window->display();
    }
}
void Renderer::terminate()
{
    window->close();
}