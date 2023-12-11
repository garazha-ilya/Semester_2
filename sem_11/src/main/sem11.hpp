#pragma once
#include <iostream>

using namespace std;

class Shape {
 public:
  virtual void print_info() const = 0;
};

class Line : Shape {
 protected:
  double length_ = 0;

 public:
  Line() : length_(0) {}  // TODO лишнее переопределение итак 0  length

  Line(double l) : length_(l) {}

  Line(const Line& p) : length_(p.length_) {}

  double length() const;

  void print_info() const override {
    cout << "Line with length: " << this->length_ << endl;
  }
};

class PlaneShape : public Line {
 protected:
  double width_ = 0;

 public:
  PlaneShape() : Line(), width_(0) {}

  PlaneShape(int a, int b) : Line(a), width_(b) {}

  PlaneShape(const PlaneShape& p) : Line(p.length_), width_(p.width_) {}

  double square() const;

  double width() const;

  void print_info() const override {
    cout << "PlaneShape with length: " << this->length_
         << ", width: " << this->width_ << ", square: " << this->square()
         << endl;
  }
};

class VolumetricFigure : public PlaneShape {
 protected:
  double height_ = 0;

 public:
  VolumetricFigure() : PlaneShape(), height_(0) {}

  VolumetricFigure(int a, int b, int c) : PlaneShape(a, b), height_(c) {}

  VolumetricFigure(const VolumetricFigure& p)
      : PlaneShape(p.length_, p.width_), height_(p.height_) {}

  double volume() const;

  double height() const;

  void print_info() const override {
    cout << "VolumetricFigure with length: " << this->length_
         << ", width: " << this->width_ << ", height: " << this->height_
         << ", volume: " << this->volume() << endl;
  }
};

class Material {
 protected:
  char colour_;
  double density_;

 public:
  Material(char c = 'b', double d = 0) : colour_(c), density_(d) {}

  Material(const Material& p) : colour_(p.colour_), density_(p.density_) {}

  char colour() const;

  double density() const;

  void print_info() {
    cout << "Material with colour: " << this->colour_
         << ", density: " << this->density_ << endl;
  }
};

class Wire : public Line, public Material {
 protected:
  double weight_ = 0;

 public:
  Wire() : Line(), Material(), weight_(0) {}

  Wire(double l = 1, char col = 'b', double den = 7850)
      : Line(l), Material(col, den), weight_(l * den) {}

  Wire(Line& a, Material b)
      : Line(a), Material(b), weight_(a.length() * b.density()) {}

  Wire(const Wire& p)
      : Line(p.length_),
        Material(p.colour_, p.density_),
        weight_(p.length_ * p.density_) {}

  double weight();

  void print_info() const override {
    cout << "Wire with length: " << length_ << ", weight: " << weight_
         << ", density: " << density_ << ", colour: " << colour_ << endl;
  }
};

class Slate : public PlaneShape, public Material {
 protected:
  double weight_ = 0;

 public:
  Slate() : PlaneShape(), Material(), weight_(0) {}

  Slate(double a = 1, double b = 1, char col = 'b', double den = 7850)
      : PlaneShape(a, b), Material(col, den), weight_(a * b * den) {}

  Slate(PlaneShape& a, Material b)
      : PlaneShape(a),
        Material(b),
        weight_(a.length() * a.width() * b.density()) {}

  Slate(const Slate& p)
      : PlaneShape(p.length_, p.width_),
        Material(p.colour_, p.density_),
        weight_(p.length_ * p.width_ * p.density_) {}

  double weight();

  void print_info() const override {
    cout << "Slate with length: " << length_ << ", width: " << width_
         << ", square: " << square() << ", weight: " << weight_
         << ", density: " << density_ << ", colour: " << colour_ << endl;
  }
};

class Brick : public VolumetricFigure, public Material {
 protected:
  double weight_ = 0;

 public:
  Brick() : VolumetricFigure(), Material(), weight_(0) {}

  Brick(double a = 1, double b = 1, double c = 1, char col = 'b',
        double den = 7850)
      : VolumetricFigure(a, b, c),
        Material(col, den),
        weight_(a * b * c * den) {}

  Brick(VolumetricFigure a, Material b)
      : VolumetricFigure(a),
        Material(b),
        weight_(a.length() * a.width() * a.height() * b.density()) {}

  Brick(const Brick& p)
      : VolumetricFigure(p.length_, p.width_, p.height_),
        Material(p.colour_, p.density_),
        weight_(p.length_ * p.width_ * p.height_ * p.density_) {}

  double weight();

  void print_info() const override {
    cout << "VolumetricFigure with length: " << length_ << ", width: " << width_
         << ", height: " << height_ << ", volume: " << volume()
         << ", weight: " << weight_ << ", density: " << density_
         << ", colour: " << colour_ << endl;
  }
};