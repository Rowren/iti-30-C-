#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Enter a Character : ";
    cin >> ch;
    cout << endl;

    if( ch >= 'a' && ch <= 'z'){
        cout << ch << " is Lower Character." << endl;
    } else if(ch >= 'A' && ch <= 'Z') {
        cout << ch << " is Upper Character." << endl;
    } else if(ch >= '0' && ch <= '9') {
        cout << ch << " is Numeric." << endl;
    } else {
        cout << ch << " is Special Character." << endl;
    }
    cout << endl;
    
    return 0;
}
