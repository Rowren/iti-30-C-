#include <string>
using namespace std;

class Employee {
        private:
                string firstName;
                string lastName;
                string day;
                string month;
                string year;
        public:
        Employee();
        Employee(string fName, string lName);
        Employee(string fName, string lName, string d, string m, string y);
        void setfirstName(string s);
        void setlastName(string s);
        void sethireDate(string d, string m, string y);
        void setDay(string d);
        void setMonth(string m);
        void setYear(string y);
        string getfirstName();
        string getlastName();
        string gethireDate();
        string getDay();
        string getMonth();
        string getYear();
        string toString();              
};

Employee::Employee(){
        setfirstName("");
        setlastName("");
        sethireDate("","","");
}

Employee::Employee(string fName, string lName){
        setfirstName(fName);
        setlastName(lName);
        sethireDate("","","");
}

Employee::Employee(string fName, string lName, string d, string m, string y){
        setfirstName(fName);
        setlastName(lName);
        sethireDate(d,m,y);
}

void Employee::setfirstName(string fName){
        firstName = fName;
}

void Employee::setlastName(string lName){
        lastName = lName;
}

void Employee::sethireDate(string d, string m, string y){
        setDay(d);
        setMonth(m);
        setYear(y);
}

void Employee::setDay(string d){
        day = d;
}

void Employee::setMonth(string m){
        month = m;
}

void Employee::setYear(string y){
        year = y;
}

string Employee::getfirstName(){
        return firstName;
}

string Employee::getlastName(){
        return lastName;
}

string Employee::gethireDate(){
        return (getDay()+"/"+getMonth()+"/"+getYear());
}

string Employee::getDay(){
        return (day);
}

string Employee::getMonth(){
        return (month);
}

string Employee::getYear(){
        return (year);
}

string Employee::toString(){
        string str = getfirstName() + " " +
                     getlastName()  + " " +
                     gethireDate();
        return str;
}