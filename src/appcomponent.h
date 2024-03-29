#ifndef APP_COMPONENT_H
#define APP_COMPONENT_H

#include "component.h"
#include "drawingcontext.h"
#include "model.h"

class Model;
class Button : public Component {
public:
    Button(int x_, int y_, int width_, int height_, SDL_IO::TexturePointer tex, std::string imgKey_)
        : Component(x_, y_, width_, height_, std::move(tex)), imgKey(imgKey_), currentImage(imgKey + "-up"), currentColor(0xff000000), isPressed(false)
    {
    }
    virtual ~Button() {}

    virtual void redraw(const DrawingContext& c) override;
    virtual bool handleEvent(const SDL_IO::EventArgs& e) override;
    void cycleColor() noexcept;

private:
    std::string imgKey;
    std::string currentImage;
    long unsigned int currentColor;
    bool isPressed;
};

class MenuComponent : public ComponentContainer {
public:
    MenuComponent(int x_, int y_, int width_, int height_, SDL_IO::TexturePointer tex)
        : ComponentContainer(x_, y_, width_, height_, std::move(tex))
    {
    }
    virtual ~MenuComponent() {}

    virtual void redraw(const DrawingContext& c) override;
};

#endif //APP_COMPONENT_H
