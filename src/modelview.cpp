#include "modelview.h"
#include <iostream>

void ModelView::redraw(const DrawingContext& c)
{
    //draw a darkbackground
    c.setColor(0x13, 0x13, 0x13, 0xff);
    c.drawRectangle(0, 0, width, height);

    auto projectionMatrix = computeProjectionMatrix();
    auto coords = model.getCurrentCoords();
    for (auto& coord : coords)
        coord *= projectionMatrix;

    //draw our lines
    for (auto& seg : model.getLineSegments()) {
        auto& p1 = coords[seg.first - 1];
        auto& p2 = coords[seg.second - 1];

        if (p1.z < 0 && p2.z < 0) {
            c.setColor(0x74, 0x74, 0x74, 0xff);
        } else {
            c.setColor(0xD8, 0xD8, 0xD8, 0xff);
        }

        c.drawLine(p1.x, p1.y, p2.x, p2.y);
    }

    c.setColor(0xD8, 0xD8, 0xD8, 0xff);
    //draw points of our shape
    for (auto& row : coords) {
        // draw a 3x3 block around each coordinate
        int x = row.x - 1;
        int y = row.y - 1;
        c.drawRectangle(x, y, 3, 3);
    }

    c.drawComponent(*this);
}

TransformationMatrix<double> ModelView::computeProjectionMatrix()
{
    double widthTranslation = (width / 2.0) - (model.getOriginalCenter().x * unit);
    double heightTranslation = (height / 2.0) + (model.getOriginalCenter().y * unit);

    // so to get the whole thing, we do some stuff
    std::array<std::array<double, 4>, 4> m{{
        {{unit, 0, 0, 0}},
        {{0, -unit, 0, 0}},
        {{0, 0, unit, 0}},
        {{widthTranslation, heightTranslation, 0, 1}}
    }};

    return TransformationMatrix<double>(m);
}
