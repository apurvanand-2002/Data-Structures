#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &r = a;
    /*r is reference variable with respect to a.Any change made in 'r' will also
    be made in 'a' and vice-versa . 'r' is alias name of 'a'. 'r' and 'a' have same
    memory location.*/
    cout << r << endl;
    a++;
    cout << r << endl;
    r++;
    cout << a << endl;
}