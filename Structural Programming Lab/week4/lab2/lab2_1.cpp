#include<iostream>

using namespace std;

int main() {
    char ch[30], ch2[30];
    cout << "Enter char:";
    cin.get(ch, 15);
    cout << ch << endl;
    
    cin.ignore(); // Clear the newline character from the input buffer
    cout << "Enter char2:";
    cin.get(ch2, 15);
    cout << ch2 << endl;

    return 0;
}