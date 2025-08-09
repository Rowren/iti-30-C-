#include<iostream>
using namespace std;
int main(){
    int i = -5;
    int flag = (i < 0)?i+6 :i-5;
    cout << "Result = " << flag << endl;
    return 0;
}