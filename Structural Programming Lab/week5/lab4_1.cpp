#include <iostream>

using namespace std;
int input(int &num);
void process(int &num, int &square);
void output(int &num, int &square);
int main()
{
    int num, square;

    num = input(num);
    process(num, square);
    output(num, square);

    return (0);
}

int input(int &num)
{
    
    // I
    cout << "Enter number : ";
    cin >> num;

    return num;
}

void process(int &num, int &square)
{
    // P
    num = num + 10;
    square = num * num;
}

void output(int &num, int &square)
{
    // O
    cout << "Square of " << num << " = " << square << endl;
}