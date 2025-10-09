#include <string>
#include <iostream>

using namespace std;

class Employee
{
private:
    string firstName;
    string lastName;

public:
    Employee();
    Employee(string firstName, string lastName);
    void setName(string firstname);
    string getName();
    string tostring();
};

Employee :: Employee(){
    firstName = "n/a";
    lastName = "n/a";  
}

Employee :: Employee(string firstName, string lastName){
   Employee :: firstName = firstName;
   Employee :: lastName = lastName;  
}

string Employee :: tostring(){
    return "Name : " + firstName + " " + lastName ;
}

void Employee :: setName(string firstname){
    Employee ::  firstName = firstname;
}

string Employee :: getName(){
    return Employee :: firstName;
}
