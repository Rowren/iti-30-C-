#include <iostream>
#include "Employee.h"

using namespace std;

int main(){

    Employee t1("nopphagaw", "ThonhBai");
    cout << t1.tostring() << endl;
    t1.setName("John");
    cout << t1.getName() << endl;
    cout << t1.tostring() << endl;
    
    return 0;



}