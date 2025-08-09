#include<iostream>
using namespace std;

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << number << " is " << 
    ((number % 2) == 0 
        ? "even" 
        : "odd") 
    << " number." << endl;

    if((number % 2) == 0) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }
    return 0;
}