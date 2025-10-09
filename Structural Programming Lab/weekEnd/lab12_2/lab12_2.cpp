#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

using namespace std;

int main(){
    Employee E1;

    E1.setfirstName("John");
    E1.setlastName("Smith");
    E1.sethireDate("12","31","2015");
    cout << "Employee E1: " << endl;
    cout << E1.toString() << endl;
    return 0;



}