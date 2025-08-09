#include <iostream>

using namespace std;

void process1();
void process2();
void process3();
void process4();

int main()
{

    cout << "Display sqaure of numbers from 1 to 10 \n";
    cout << "========================================\n";
    cout << "\tX\tX^2\n";
    cout << "========================================\n";
    process4();
    return 0;
}

void process1()
{
    int X = 1;
    while (X <= 10)
    {
        cout << "\t" << X << "\t" << X * X << endl;
        X++;
    }
}

void process2()
{
    int X = 10;
    while (X >= 1)
    {
        cout << "\t" << X << "\t" << X * X << endl;
        X--;
    }
}

void process3()
{
    for (int X = 1; X <= 10; X++)
    {
        cout << "\t" << X << "\t" << X * X << endl;
    }
}

void process4()
{
    for (int X = 10; X >= 1; X--)
    {
        cout << "\t" << X << "\t" << X * X << endl;
    }
}