#ifndef MODEL_VIEW_H
#define MODEL_VIEW_H

#include "component.h"
#include "model.h"
#include "matrix.h"

class ModelView : public Component {
public:
    ModelView(int x_, int y_, int width_, int height_, Model& model_,
            SDL_IO::SurfacePointer sp)
        : Component(x_, y_, width_, height_, std::move(sp)),
        model(model_), unit(height_ / 30),
        activeTrans(), continuousTrans(), projectionMatrix(computeProjectionMatrix())
    {}

    virtual void redraw(const DrawingContext& c) override;
    virtual bool handleEvent(const SDL_IO::EventArgs& e) override { return false; }

    void applyTransformation(Matrix t);
    void applyContinuousTransformation(Matrix t);

private:
    Model& model;
    double unit;

    TransformationMatrix computeProjectionMatrix();

    TransformationMatrix activeTrans;
    TransformationMatrix continuousTrans;
    TransformationMatrix projectionMatrix;
};

#endif // MODEL_VIEW_H
