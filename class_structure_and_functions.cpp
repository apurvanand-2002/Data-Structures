#include <iostream>
using namespace std;
class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    void display()
    {
        cout << "Length=" << length << " Breadth=" << breadth << endl;
    }
    int area()
    {
        return length * breadth;
    }
    void change_length(int x)
    {
        length = x;
    }
};
int main()
{
    class rectangle r(10, 10);
    r.display();
    cout << "Area=" << r.area() << endl;
    r.change_length(20);
    r.display();
}