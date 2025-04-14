#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Shape {
protected:
    double x, y; // Position (x, y)
    string color; // Color of the shape
    double borderThickness; // Optional thickness of the border

public:
    // Constructor
    Shape(double x = 0, double y = 0, string color = "black", double borderThickness = 1.0)
        : x(x), y(y), color(color), borderThickness(borderThickness) {}

    // Virtual methods for drawing, area, and perimeter (to be overridden by derived classes)
    virtual void draw() = 0; // Pure virtual method to draw the shape
    virtual double calculateArea() = 0; // Pure virtual method for calculating area
    virtual double calculatePerimeter() = 0; // Pure virtual method for calculating perimeter

    // Getter for position
    void getPosition() {
        cout << "Position: (" << x << ", " << y << ")\n";
    }

    // Getter for color
    void getColor() {
        cout << "Color: " << color << endl;
    }

    // Getter for border thickness
    void getBorderThickness() {
        cout << "Border Thickness: " << borderThickness << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
    private:
        double radius;
    
    public:
        // Constructor for Circle
        Circle(double x, double y, string color, double radius, double borderThickness = 1.0)
            : Shape(x, y, color, borderThickness), radius(radius) {}
    
        // Override draw for Circle
        void draw() override {
            cout << "Drawing a circle at position (" << x << ", " << y << ") with radius " << radius << "\n";
        }
    
        // Override calculateArea for Circle
        double calculateArea() override {
            return M_PI * radius * radius; // Area of a circle: π * r^2
        }
    
        // Override calculatePerimeter for Circle
        double calculatePerimeter() override {
            return 2 * M_PI * radius; // Perimeter (circumference) of a circle: 2 * π * r
        }
};

class Rectangle : public Shape {
    private:
        double width, height;
    
    public:
        // Constructor for Rectangle
        Rectangle(double x, double y, string color, double width, double height, double borderThickness = 1.0)
            : Shape(x, y, color, borderThickness), width(width), height(height) {}
    
        // Override draw for Rectangle
        void draw() override {
            cout << "Drawing a rectangle at position (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
        }
    
        // Override calculateArea for Rectangle
        double calculateArea() override {
            return width * height; // Area of rectangle: width * height
        }
    
        // Override calculatePerimeter for Rectangle
        double calculatePerimeter() override {
            return 2 * (width + height); // Perimeter of rectangle: 2 * (width + height)
        }
};

class Triangle : public Shape {
    private:
        double base, height, side1, side2, side3;
    
    public:
        // Constructor for Triangle
        Triangle(double x, double y, string color, double base, double height, double side1, double side2, double side3, double borderThickness = 1.0)
            : Shape(x, y, color, borderThickness), base(base), height(height), side1(side1), side2(side2), side3(side3) {}
    
        // Override draw for Triangle
        void draw() override {
            cout << "Drawing a triangle at position (" << x << ", " << y << ") with base " << base << " and height " << height << "\n";
        }
    
        // Override calculateArea for Triangle
        double calculateArea() override {
            return 0.5 * base * height; // Area of triangle: 1/2 * base * height
        }
    
        // Override calculatePerimeter for Triangle
        double calculatePerimeter() override {
            return side1 + side2 + side3; // Perimeter of triangle: sum of all sides
        }
};

class Polygon : public Shape {
    private:
        vector<pair<double, double>> vertices; // List of vertices (x, y coordinates)
    
    public:
        // Constructor for Polygon (requires vertices)
        Polygon(double x, double y, string color, vector<pair<double, double>> vertices, double borderThickness = 1.0)
            : Shape(x, y, color, borderThickness), vertices(vertices) {}
    
        // Override draw for Polygon
        void draw() override {
            cout << "Drawing a polygon at position (" << x << ", " << y << ") with vertices: ";
            for (auto& vertex : vertices) {
                cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            cout << "\n";
        }
    
        // Override calculateArea for Polygon (using the shoelace formula)
        double calculateArea() override {
            double area = 0.0;
            int n = vertices.size();
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                area += vertices[i].first * vertices[j].second;
                area -= vertices[i].second * vertices[j].first;
            }
            area = fabs(area) / 2.0;
            return area;
        }
    
        // Override calculatePerimeter for Polygon
        double calculatePerimeter() override {
            double perimeter = 0.0;
            int n = vertices.size();
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                perimeter += sqrt(pow(vertices[j].first - vertices[i].first, 2) + pow(vertices[j].second - vertices[i].second, 2));
            }
            return perimeter;
        }
};

int main() {
    // Create various shapes
    Circle circle(0, 0, "red", 5);
    Rectangle rectangle(1, 1, "blue", 4, 6);
    Triangle triangle(2, 2, "green", 3, 4, 3, 4, 5);
    vector<pair<double, double>> polygonVertices = {{0, 0}, {5, 0}, {5, 5}, {0, 5}};
    Polygon polygon(3, 3, "purple", polygonVertices);

    // Draw shapes and calculate area and perimeter
    circle.draw();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << "\n";

    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << "\n";

    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << "\n";

    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << ", Perimeter: " << polygon.calculatePerimeter() << "\n";

    return 0;
}
