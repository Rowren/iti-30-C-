#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    int sum = 0;
    int value;

    int i = 1;
    while (i <= number)
    {
        cout << "Enter integer Value [" << i << "]: ";
        cin >> value;
        sum += value;
        i++;
    }
    cout << "\nSummation of all values: " << number;
    cout << " Values = " << sum << endl;
    return 0;
}