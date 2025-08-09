#include<iostream>

using namespace std;

int main(){
    int number;

    cout << "Enter Number: ";
    cin >> number;
    int sum = 0;
    int value;
    for(int i = 1; i <= number; i++){
        cout << "Enter integer Value [" << i << "]: ";
        cin >> value;
        sum += value;
    }

    cout << "\nSummation of all values: " << number  ;
    cout << " Values = " << sum << endl;

}