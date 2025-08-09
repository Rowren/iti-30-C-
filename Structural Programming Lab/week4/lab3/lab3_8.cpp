#include <iostream>
using namespace std;
int main()
{
    int Number1, Number2, Number3;
    cout << "Enter first number : ";
    cin >> Number1;
    cout << "Enter second number : ";
    cin >> Number2;
    cout << "Enter third number : ";
    cin >> Number3;
    float Average;
    Average = static_cast<float>(Number1 + Number2 + Number3) / 3;
    cout << "\nAverage of 3 number = " << Average << endl;
    return (0);
}
