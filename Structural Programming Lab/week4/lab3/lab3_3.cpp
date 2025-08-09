#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 3;
    cout << "a == b ? " << (a == b) << endl;
    cout << "a != b ? " << (a != b) << endl;
    cout << "a < b ? " << (a < b) << endl;
    cout << "a <= b ? " << (a <= b) << endl;
    cout << "a > b ? " << (a > b) << endl;
    cout << "a >= b ? " << (a >= b) << endl;
    
    cout << "a && b ? " << (a && b) << endl;
    cout << "a || b ? " << (a || b) << endl;
    cout << "!a ? " << ( !a) << endl;
    cout << "!b ? " << ( !b) << endl;
    return 0;
}