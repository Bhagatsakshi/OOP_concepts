//USING INHERITANCE

#include<iostream>
#include<cmath>
using namespace std;
class Shape {
public:
  virtual double volume() const = 0; 
};
class Cube:public Shape 
{
public:
  Cube(double side):side_(side) {}
  double volume() const override {
      return pow(side_, 3); 
  }
private:
  double side_;
};
class Cuboid:public Shape {
public:
  Cuboid(double length,double width,double height) : length_(length),width_(width),height_(height)
  {}
  double volume() const override { return length_*width_*height_; }
private:
  double length_;
  double width_;
  double height_;
};
class Cylinder:public Shape {
public:
  Cylinder(double radius, double height):radius_(radius), height_(height) {}
  double volume() const override { return 3.14 * pow(radius_, 2) * height_; }
private:
  double radius_;
  double height_;
};
int main() {
  Cube cube(3);
  Cuboid cuboid(4,5,6);
  Cylinder cylinder(2,7);
  cout<<"Volume of cube: "<<cube.volume()<<endl;
  cout<<"Volume of cuboid: "<<cuboid.volume()<<endl;
  cout<<"Volume of cylinder: "<<cylinder.volume()<<endl;
  return 0;
}

//USING EXCEPTION HANDLING

#include<iostream>
#include<cmath>
using namespace std;
double volume(double side) {
  if(side<=0) {
    throw "Side must be positive";
  }
  return pow(side,3);
}
double volume(double len,double wid,double h) {
  if(len<=0||wid<=0||h<=0) {
    throw "Dimensions must be positive";
  }
  return len*wid*h;
}
double volume(double r,double h) {
  if(r<= 0||h<=0) {
    throw "Radius and height must be positive";
  }
  return 3.14*pow(r,2)*h;
}

int main() {
  try {
    cout<<"Volume of cube: "<<volume(3)<<endl;
    cout<<"Volume of cuboid: "<<volume(4, 5, 6)<<endl;
    cout<<"Volume of cylinder: "<<volume(2, 7)<<endl;
  } 
  catch(const exception& e) 
  {
    cerr<<"Error: "<<e.what()<<endl;
  }

  return 0;
}

//USING FRIEND FUNCTION

#include<iostream>
#include<cmath>
using namespace std;
class Shape {
public:
    friend double calculateVolume(const Shape& shape);
};
class Cylinder : public Shape {
private:
    double radius;
    double height;
public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}
};
class Cube:public Shape {
private:
    double sideLength;
public:
    Cube(double sideLength) : sideLength(sideLength) {}
};
class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) : length(length), width(width), height(height) {}
};
double calculateVolume(const Shape& shape) {
    if (dynamic_cast<const Cylinder*>(&shape)) {
        const Cylinder& cylinder = dynamic_cast<const Cylinder&>(shape);
        return 3.14159 * cylinder.radius * cylinder.radius * cylinder.height;
    } else if (dynamic_cast<const Cube*>(&shape)) {
        const Cube& cube = dynamic_cast<const Cube&>(shape);
        return cube.sideLength * cube.sideLength * cube.sideLength;
    } else if (dynamic_cast<const Cuboid*>(&shape)) {
        const Cuboid& cuboid = dynamic_cast<const Cuboid&>(shape);
        return cuboid.length * cuboid.width * cuboid.height;
    } else {
        return 0;
    }
}
int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);
    cout << "Volume of cylinder: " << calculateVolume(cylinder) << endl;
    cout << "Volume of cube: " << calculateVolume(cube) << endl;
    cout << "Volume of cuboid: " << calculateVolume(cuboid) << endl;
    return 0;
}


//USING VIRTUAL FUNCTION
#include<iostream>
#include<cmath>
using namespace std;
class Shape 
{
public:
  virtual double volume() const = 0; 
};
class Cube:public Shape {
public:
  Cube(double side):side_(side) {}
  double volume() const override { return side_*side_*side_; }
private:
  double side_;
};
class Cuboid:public Shape {
public:
  Cuboid(double length,double width,double height):length_(length), width_(width), height_(height) {}
  double volume() const override { return length_ * width_ * height_; }
private:
  double length_;
  double width_;
  double height_;
};
class Cylinder : public Shape {
public:
  Cylinder(double radius, double height):radius_(radius), height_(height) {}
  double volume() const override { 
      return 3.14* pow(radius_, 2) * height_; }
private:
  double radius_;
  double height_;
};
int main() {
  Cube cube(3);
  Cuboid cuboid(4,5,6);
  Cylinder cylinder(2,7);
  cout<<"Volume of cube: "<<cube.volume()<<endl;
  cout<<"Volume of cuboid: "<<cuboid.volume()<<endl;
  cout<<"Volume of cylinder: "<<cylinder.volume()<<endl;
  return 0;
}
