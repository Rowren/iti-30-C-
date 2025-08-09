#include<iostream>
#include<string>
using namespace std;
void process1(int  number, string name) ;
void process2(int  number, string name) ;
int main() {
    int number ;
    string name;
    cout << "Enter String :";
    cin >> name;
    cout << "Enter Number :";
    cin >> number;
    process1(number, name);
    process2(number, name);
    return 0;
}


void process1(int  number, string name) {
    cout << "Process 1" << endl;
  for(int n =1 ; n <= number; n++) {
        cout << n << ":" << name << endl;
    }
}

void process2(int  number, string name) {
    cout << "Process 2" << endl;
  for(int n = number ; n >= 1; n--) {
        cout << number-n+1 << ":" << name << endl;
    }
}