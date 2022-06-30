#include <iostream>
using namespace std;
int main()
{
    cout << "Enter size of array:" << endl;
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << ":" << endl;
        cin >> A[i];
    }
    cout << "Elements entered are:\n";
    /*for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }*/
    for (int x : A)
    {
        cout << x << " ";
    }
}