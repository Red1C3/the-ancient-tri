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
    ctxSettings.majorVersion = 4;
    ctxSettings.minorVersion = 4;
    ctxSettings.stencilBits = 8;
    window = new Window(VideoMode(width, height), title, Style::Default, ctxSettings);
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