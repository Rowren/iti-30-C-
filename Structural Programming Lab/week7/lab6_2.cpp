
#include <iostream>
#include <iomanip>
#include <string>

void grade_cal(int score, int &grade);

void  gpa_cal(float avg, float &totalGPA, int totalStudent) ;

using namespace std;
int main()
{
    cout << fixed << setprecision(1);
    cout << left << setw(15);
    cout << "John" << "Score =" << 85  <<"Grade: " << 3.0f << endl;
    cout << left << setw(15);
    cout << "Alice" << "Score =" << 75  <<"Grade: " << 2.0f << endl;
    cout << left << setw(15);
    cout << "Bob" << "Score =" << 65  <<"Grade: " << 1.0f << endl;
    cout << fixed << setprecision(2);
    cout << "Room AVG GPA: " << (3.0f + 2.0f + 1.0f) / 3.0f << endl;

  

    return 0;
}
