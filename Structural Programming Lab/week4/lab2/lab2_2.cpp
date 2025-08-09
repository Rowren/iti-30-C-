#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string name1, name2;
    cout << "Enter name1: ";
    getline(cin, name1);
    cout << "Name1 = " << name1 << endl;

    cout << "Enter name2: ";
    getline(cin, name2);
    cout << "Name2 = " << name2 << endl;
    return 0;
}