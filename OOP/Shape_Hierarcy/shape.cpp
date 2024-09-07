#include "Shape.h"


Shape::Shape(std::string shapeName) : name(shapeName){

}

Circle::Circle(float _radius): radius(_radius),Shape("Circle")
{

}
float Circle::getArea(){
    return PI*radius*radius;
}

void Circle::printShapeInfo(){
    std::cout<<"Shape Name: "<<name<<std::endl;
}

Rectangle::Rectangle(float _width, float _height) : width(_width), height(_height), Shape("Rectangle")
{

}
float Rectangle::getArea(){
    return width * height;
}
void Rectangle::printShapeInfo(){
    std::cout<<"Shape Name: "<<name<<std::endl;
}


Triangle::Triangle(float _base, float _height) : base(_base), height(_height), Shape("Triangle")
{

}
float Triangle::getArea(){
    return .5 * base * height;
}
void Triangle::printShapeInfo(){
    std::cout<<"Shape Name: "<<name<<std::endl;
}

