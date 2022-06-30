#include <iostream>
using namespace std;
int main()
{
    int *p;
    p = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter element-" << i << ":";
        cin >> (*(p + i));
    }
    printf("Entered elements are:\n");
    for (int i = 0; i < 5; i++)
    {
        cout << (*(p + i)) << endl;
    }
    delete[] p;
}