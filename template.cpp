#include <iostream>
using namespace std;
template <class T>
class arithmetic
{
private:
    T a, b;

public:
    arithmetic(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    T add();
    T subtract();
};
template <class T>
T arithmetic<T>::add()
{
    return a + b;
}
template <class T>
T arithmetic<T>::subtract()
{
    return a - b;
}
int main()
{
    class arithmetic<int> a(1, 2);
    cout << "Sum " << a.add() << " Difference " << a.subtract() << endl;
    class arithmetic<float> b(2.3, 4.5);
    cout << "Sum " << b.add() << " Difference " << b.subtract() << endl;
}