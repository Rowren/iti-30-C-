// cal grade
// enter name " noop hh"
// enter score : 45.58

// input (name, score)
// calgrade (name, score, grade) //if else if...
// calgrade2 (name, score, grade) // if only
// ouput( name ,score , grade)
/*
    A = 80-100
    b = 79-70
    c = 69-60
    d = 59-50
    f = 49-0
*/

#include <iostream>
#include <string>

using namespace std;
void input( string &name, float &score);
void calgrade(string &name, float &score, char &grade);
void calgrade2(string &name, float &score, char &grade);
void output(string &name, float &score, char grade);

int main()
{
    string name;
    float score;
    char grade;
    // input
        input(name,score);
    // loop check
    //  for (int i = 0; i <= 100; i++)
    //  {
    //      // calgrade(name, i, grade);
    //      calgrade2(name, i, grade);
    //      output(name, i, grade);
    //  }

    // process
    //      calgrade(name, score, grade);
    calgrade2(name, score, grade);

    // output
    output(name, score, grade);
}

void input( string &name, float &score)
{
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter Your Score: ";
    cin >> score;
}
void calgrade(string &name, float &score, char &grade)
{
    if (score >= 80 && score <= 100)
    {
        grade = 'A';
    }
    else if (score >= 70)
    {
        grade = 'B';
    }
    else if (score >= 60)
    {
        grade = 'C';
    }
    else if (score >= 50)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }

    // cout << "Name: " << name << ", Score: " << score << ", Grade: " << grade << endl;
}

void calgrade2(string &name, float &score, char &grade)
{
    if (score >= 80 && score <= 100)
    {
        grade = 'A';
    }
    if (score >= 70 && score < 80)
    {
        grade = 'B';
    }
    if (score >= 60 && score < 70)
    {
        grade = 'C';
    }
    if (score >= 50 && score < 60)
    {
        grade = 'D';
    }
    if (score < 50 && score >= 0)
    {
        grade = 'F';
    }

    // cout << "Name: " << name << ", Score: " << score << ", Grade: " << grade << endl;
}

void output(string &name, float &score, char grade)
{
    cout << "Name: " << name << ", Score: " << score << ", Grade: " << grade << endl;
}