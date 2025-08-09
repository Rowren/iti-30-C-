/*
    enter total Student: 4
    =========================
    Enter Student [1] name: John
    enter Score: 45
    student [1]  John   score: 75 grade: 3
    ==========================
    enter Student [2] name: Alice
    enter Score: 78
    student [2]  Alice   score: 78 grade: 3
    ==========================
    enter Student [3] name: Bob
    enter Score: 90
    student [3]  Bob   score: 90 grade: 4
    ==========================
    Room  AVG  GPA: 3.33
    =========================
    grade cal
    4 = 80-100
    3 = 70-79
    2 = 60-69
    1 = 50-59
    0 = 0-49
*/
#include <iostream>  // นำเข้าไลบรารี iostream เพื่อใช้ฟังก์ชันการป้อนและแสดงผลข้อมูล
#include <iomanip>  // นำเข้าไลบรารี  iomanip เพื่อจัดรูปแบบการแสดงผล
#include <string>  // นำเข้าไลบรารี string เพื่อใช้ตัวแปรแบบสตริง

void grade_cal(int score, int &grade); //Function to calculate the grade based on the score

void  gpa_cal(float avg, float &totalGPA, int totalStudent) ; // Function to calculate the average GPA of the room

using namespace std;  
int main(){  
    int totalStudent;  
    string name;
    int score;
    int grade;
    float avg;
    float totalGPA;
    

    cout << "Enter total Student: ";
    cin >> totalStudent;
    cout << "=========================" << endl;

    for (int i = 1; i <= totalStudent; i++)
    {
        cout << "Enter Student [" << i << "] name: ";
        cin >> name;
        cout << "Enter Score: ";
        cin >> score;
        grade_cal(score, grade);
        cout << "Student [" << i << "] " << left << setw(10) << name << " Score: " << score << " Grade: " << grade << endl;
        cout << "=========================" << endl;
        avg += grade;
    }
    gpa_cal(avg, totalGPA, totalStudent);
   

    return 0;
}

// Function to calculate the grade based on the score
void grade_cal(int score, int &grade)
{
    if (score >= 80)
    {
        grade = 4;
    }
    else if (score >= 70)
    {
        grade = 3;
    }
    else if (score >= 60)
    {
        grade = 2;
    }
    else if (score >= 50)
    {
        grade = 1;
    }
    else
    {
        grade = 0;
    }
}

// Function to calculate the average GPA of the room
void  gpa_cal(float avg, float &totalGPA, int totalStudent) {
    cout << "Room AVG GPA: ";
    totalGPA = avg / totalStudent;
    cout << fixed << setprecision(2);
    cout << "Room AVG GPA: " << totalGPA << endl;
    cout << "========================" << endl;
}