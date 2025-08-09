#include <iostream>
using namespace std;

void todo1(int year, int &maxday);
void todo2(int year, int &maxday);

int main()
{
    int year, maxday;
    cout << "\nEnter Year: ";
    cin >> year;
    todo2(year, maxday);

    return 0;
}

void todo1(int year, int &maxday)
{
    if ((year % 4) == 0)
    {
        cout << "In " << year << " is leap year ";
        maxday = 29;
    }
    else
    {
        cout << "In " << year << " is not leap year ";
        maxday = 28;
    }
    cout << "\nand February has " << maxday << "day.\n";
}
void todo2(int year, int &maxday)
{
    string out;
    out = (((year % 4) == 0) ? " leap year" : " not leap year");
    maxday = (((year % 4) == 0) ? 29 : 28);
    cout << "In "<< year << out;
    cout << "\nand February has " << maxday << "day.\n";
}
