#include <iostream>
#include "sem11.hpp"

using namespace std;

double Line::length() const
{
    return this->length_;
}

double PlaneShape::square() const
{
    return this->length_ * this->width_;
}

double PlaneShape::width() const
{
    return this->width_;
}

double VolumetricFigure::volume() const
{
    return this->length_ * this->width_ * this->height_;
}

double VolumetricFigure::height() const
{
    return this->height_;
}

char Material::colour() const
{
    return this->colour_;
}

double Material::density() const
{
    return this->density_;
}

double Wire::weight()
{
    return weight_;
}

double Slate::weight()
{
    return weight_;
}

double Brick::weight()
{
    return weight_;
}