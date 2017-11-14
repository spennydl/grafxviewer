#ifndef APP_COMPONENT_H
#define APP_COMPONENT_H

#include "component.h"
#include "drawingcontext.h"

class Button : public Component {
public:
    Button(int x_, int y_, int width_, int height_, SDL_IO::SurfacePointer sp)
        : Component(x_, y_, width_, height_, std::move(sp)), buttonText(), currentColor(0xff000000)
    {
    }
    virtual ~Button() {}

    virtual void redraw(const DrawingContext& c) override;
    virtual bool handleEvent(const SDL_IO::EventArgs& e) override;
    void cycleColor() noexcept;

private:
    std::string buttonText;
    long unsigned int currentColor;
    bool isPressed;
};

class MenuComponent : public ComponentContainer {
public:
    MenuComponent(int x_, int y_, int width_, int height_, SDL_IO::SurfacePointer sp)
        : ComponentContainer(x_, y_, width_, height_, std::move(sp))
    {
    }
    virtual ~MenuComponent() {}

    virtual void redraw(const DrawingContext& c) override;
};

#endif //APP_COMPONENT_H