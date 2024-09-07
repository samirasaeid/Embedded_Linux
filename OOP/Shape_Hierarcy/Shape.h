#ifndef SHAPE
#define SHAPE
#include <iostream>

inline const float PI = 2.14;

class Shape{
    protected:
        std::string name;
    public:
        Shape(std::string shapeName);
        virtual float getArea() = 0;
        virtual void printShapeInfo()=0;

};

class Circle : public Shape{
    private:
        float radius;

    public:
        Circle(float _radius);
        float getArea() override;
        void printShapeInfo() override;

};

class Rectangle : public Shape{
    private:
        float width;
        float height;

    public:
        Rectangle(float _width, float _height);
        float getArea() override;
        void printShapeInfo() override;

};

class Triangle : public Shape{
    private:
        float base;
        float height;
    public:
        Triangle(float _base, float _height);
        float getArea() override;
        void printShapeInfo() override;

};


#endif