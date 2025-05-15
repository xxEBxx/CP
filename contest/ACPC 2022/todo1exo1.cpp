#include <iostream>
#include <cmath>

using namespace std;
class Point {
private:
    double x;double y;
public:
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}
    double distanceTo(const Point& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
    bool isSymmetrical() const {
        return (x == 0 && y == 0);
    }
    Point findMidpoint(const Point& other) const {
        double mid_x = (x + other.x) / 2;
        double mid_y = (y + other.y) / 2;
        return Point(mid_x, mid_y);
    }
    bool isInsideCircle(const Point& center, double radius) const {
        double dist_squared = (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y);
        return dist_squared <= (radius * radius);
    }
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3, 4);
    Point p2(6, 8);
    Point origin(0, 0);
     cout << "Distance between ";
    p1.display();
     cout << " and ";
    p2.display();
     cout << " is: " << p1.distanceTo(p2) <<  endl;
     cout << "Point ";
    origin.display();
     cout << " is symmetrical with respect to the origin: "
              << (origin.isSymmetrical() ? "true" : "false") <<  endl;
    Point midpoint = p1.findMidpoint(p2);
     cout << "Midpoint between ";
    p1.display();
     cout << " and ";
    p2.display();
     cout << " is: ";
    midpoint.display();
     cout <<  endl;

    Point circleCenter(5, 5);
    double radius = 5.0;
     cout << "Point ";
    p1.display();
     cout << " is inside the circle with center ";
    circleCenter.display();
     cout << " and radius " << radius << ": "
              << (p1.isInsideCircle(circleCenter, radius) ? "true" : "false") <<  endl;

    return 0;
}
