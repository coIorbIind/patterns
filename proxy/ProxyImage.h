#pragma once

#include "RealImage.h"

using namespace sf;

class ProxyImage {
private:
    RealImage *realImage;

public:
    ProxyImage(RealImage *image) {
        this->realImage = image;
    }

    void changeMoving(bool canMove) {
        this->realImage->changeMoving(canMove);
    }

    ~ProxyImage() {
        delete this->realImage;
    }

    void renderBackground(Event *event) {
        this->realImage->renderBackground(event);
    }

    void moveBackground() {
        this->realImage->moveBackground();
    }
};

