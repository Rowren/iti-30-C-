#include <iostream>
#include <string>
using namespace std;
void doprocessing1(int mark);
void doprocessing2(int mark);
int main()
{
    string name;
    int mark;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter " << "Student's  " << name << " score: ";
    cin >> mark;
    for (int i = 0; i <= 100; i++) {
        doprocessing1(i);
        doprocessing2(i);
    }
    // doprocessing1(mark);
    // doprocessing2(mark);
}

void doprocessing1(int mark)
{
    if (mark >= 50)
    {
        cout << "Score = " << mark
             << " Passed" << endl;
    }
    else
    {
        cout << "Score = " << mark
             << " Failed" << endl;
    }
}

void doprocessing2(int mark)
{
    if (mark >= 50)
    {
        cout << "Score = " << mark
             << " Passed" << endl;
    }
    if (mark < 50)
    {
        cout << "Score = " << mark
             << " Failed" << endl;
    }
}