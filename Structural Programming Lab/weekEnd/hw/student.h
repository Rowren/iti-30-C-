#include <string>
#include <iostream>
#include <sstream> 

using namespace std;

class Student
{
private:
    string id;
    string name;
    string lastname;
    string course;
    float gpa;

public:
    Student();
    Student(string id, string name, string lname, string course, float gpa);
    void setid(string i);
    void setname(string n);
    void setlastname(string ln);
    void setcourse(string c);
    void setgpa(float g);
    string getid();
    string getname();
    string getlastname();
    string getcourse();
    float getgpa();
    string toString();
    void enterInfo();
    void displayInfo();
};

Student::Student()
{
    setid("");
    setname("");
    setlastname("");
    setcourse("");
    setgpa(0.0);
}

Student::Student(string id, string name, string lname, string course, float gpa)
{
    setid(id);
    setname(name);
    setlastname(lname);
    setcourse(course);
    setgpa(gpa);
}

void Student::setid(string i) {
     id = i; 
    }
void Student::setname(string n) { 
    name = n; 
}
void Student::setlastname(string ln) { 
    lastname = ln; 
}
void Student::setcourse(string c) {
     course = c; 
    }
void Student::setgpa(float g) {
     gpa = g; 
    }

string Student::getid() { 
    return id;
 }
string Student::getname() {
     return name; 
    }
string Student::getlastname() {
     return lastname; 
    }
string Student::getcourse() {
     return course; 
    }
float Student::getgpa() { 
    return gpa; 
}

string Student::toString()
{
    stringstream ss; // สร้างอ็อบเจกต์ stringstream
    ss << "ID: " << getid() << "\n"
       << "Name: " << getname() << " " << getlastname() << "\n"
       << "Course: " << getcourse() << "\n"
       << "GPA: " << getgpa();
    return ss.str(); // คืนค่าเป็น string
}

void Student::enterInfo()
{
    string id, name, lastname, course;
    float gpa;

    cout << "Enter ID: ";
    cin >> id;
    setid(id);

    cout << "Enter Name: ";
    cin >> name;
    setname(name);

    cout << "Enter Lastname: ";
    cin >> lastname;
    setlastname(lastname);

    cout << "Enter Course: ";
    cin >> course;
    setcourse(course);

    cout << "Enter GPA: ";
    cin >> gpa;
    setgpa(gpa);
}

void Student::displayInfo()
{
    cout << toString() << endl;
}