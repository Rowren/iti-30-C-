#include <iostream>
using namespace std;
int main()
{
    int a = 2, b = 2;
    cout << "Before A = "<< a <<endl;
    cout << "A++ = " << a++ << endl; 
    cout << "After A = " << a << endl;
    cout << "---------------------------" << endl;
    cout << "Before B = " << b << endl;
    cout << "B-- = " << b-- << endl;
    cout << "After B = " << b << endl;

    return 0;
}