#include <iostream>
#include "Shape.h"

int main(){

    Shape * shape_pointer;

    Circle c1(10.5);
    Rectangle r1(10,20);
    Triangle t1(20,30);

    shape_pointer = &c1;
    std::cout<<shape_pointer->getArea()<<std::endl;
    shape_pointer->printShapeInfo();

    shape_pointer = &r1;
    std::cout<<shape_pointer->getArea()<<std::endl;
    shape_pointer->printShapeInfo();

    shape_pointer = &t1;
    std::cout<<shape_pointer->getArea()<<std::endl;
    shape_pointer->printShapeInfo();


    return 0;
}