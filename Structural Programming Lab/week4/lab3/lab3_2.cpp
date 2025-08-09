#include <iostream>
using namespace std;    
int main() {
    float X;
    cout << "Enter Value X: ";
    cin >> X;
    float Result(0);
    Result = X * X * X + 3 * X -10;
    cout << "\nResult of  X * X * X + 3 * X -10 = " << Result << endl;
    return 0;
}