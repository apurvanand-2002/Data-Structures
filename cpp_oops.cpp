#include <iostream>
using namespace std;
class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle()
    { // non-parameterized constructor or default constructor
        length = breadth = 1;
    }
    rectangle(int x, int y); // parameterized-constructor
    int area();
    int perimeter();
    void set_length(int a); // function prototype
    int get_length();
    ~rectangle(); // destructor
};
rectangle::rectangle(int x, int y)
{
    length = x;
    breadth = y;
}
int rectangle::area()
{
    return length * breadth;
}
int rectangle::perimeter()
{
    return (2 * (length + breadth));
}
void rectangle::set_length(int a)
{
    length = a;
}
int rectangle::get_length()
{
    return length;
}
rectangle::~rectangle()
{
    // delete [] p;
}
int main()
{
    class rectangle r(10, 10);
    cout << "Length=" << r.get_length() << endl;
    cout << "Area=" << r.area() << " Perimeter=" << r.perimeter() << endl;
    r.set_length(20);
    cout << "Length=" << r.get_length() << endl;
    cout << "Area=" << r.area() << " Perimeter=" << r.perimeter() << endl;
}