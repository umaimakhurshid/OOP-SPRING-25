#include<iostream>
#include<cmath>
using namespace std;

class Shape{
    protected:
        string position;
        string color;
        double borderThickness;

    public:
        Shape(string pos, string c, double thickness = 1.0) : position(pos), color(c), borderThickness(thickness){}
        
        virtual void draw(){
            cout << "Drawing a generic shape at " << position << endl;
        }

        virtual double calculateArea(){
		    return 0.0;  
	    }
	    
        virtual double calculatePerimeter(){
		    return 0.0;  
        }
        
		virtual ~Shape(){} 
};

class Circle : public Shape{
    double radius;

    public:
        Circle(string pos, string c, double r) : Shape(pos, c), radius(r){}

        void draw() override{
            cout << "Drawing a Circle at " << position << " with radius " << radius << endl;
        }

        double calculateArea() override{
            return 3.1415 * radius * radius;
        }

        double calculatePerimeter() override{
            return 2 * 3.1415 * radius;
        }
};

class Rectangle : public Shape{
    double width;
	double height;

    public:
        Rectangle(string pos, string c, double w, double h) : Shape(pos, c), width(w), height(h){}

        void draw() override{
            cout << "Drawing a Rectangle at " << position << " with width " << width << " and height " << height << endl;
        }

        double calculateArea() override{
            return width * height;
        }

        double calculatePerimeter() override{
            return 2 * (width + height);
        }
};

class Triangle : public Shape{
    double sideA;
	double sideB;
	double sideC;

    public:
        Triangle(string pos, string c, double a, double b, double C) : Shape(pos, c), sideA(a), sideB(b), sideC(C){}

        void draw() override{
            cout << "Drawing a Triangle at " << position << " with sides " << sideA << ", " << sideB << ", " << sideC << endl;
        } 

        double calculateArea() override{
            double s = (sideA + sideB + sideC) / 2;
            return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));            
        }

        double calculatePerimeter() override{
            return sideA + sideB + sideC;
        }
};

class Polygon : public Shape{
    double sideLength;
    int numSides;

    public:
        Polygon(string pos, string c, double length, int sides) : Shape(pos, c), sideLength(length), numSides(sides){}

        void draw() override{
            cout << "Drawing a Polygon at " << position << " with " << numSides << " sides of length " << sideLength << endl;
        } 

        double calculateArea() override{
            return (numSides * sideLength * sideLength) / (4 * tan(3.1415 / numSides));
        }

        double calculatePerimeter() override{
            return numSides * sideLength;
        }
};

int main(){
    Shape* circle = new Circle("Center (0,0)", "Red", 5);
    Shape* rectangle = new Rectangle("Top-left (2,2)", "Blue", 4, 6);
    Shape* triangle = new Triangle("Corner (1,1)", "Green", 3, 4, 5);
    Shape* polygon = new Polygon("Vertex (5,5)", "Yellow", 4, 6);  

    Shape* shapes[] = {circle, rectangle, triangle, polygon};

    for(int i = 0; i < 4; i++){
        shapes[i] -> draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
    }

    for(int i = 0; i < 4; i++){
        delete shapes[i];
    }
    return 0;
}