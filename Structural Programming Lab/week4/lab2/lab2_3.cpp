#include <iostream>
#include <string>
using namespace std;

int main() {
    string name1;
    int age;
    cout << "Enter Name1: Ex Thanatorn t;49\n";
    getline(cin, name1, ';');
    cin >> age;
    cout << "Name1 = " << name1 << endl;
    cout << "Age = " << age << endl;
    return 0;
}