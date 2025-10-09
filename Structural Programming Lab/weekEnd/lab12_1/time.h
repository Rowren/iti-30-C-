#include <string>

using namespace std;

class Time {
public:
    int hour;
private:
    int minute;
    string grade;
public:
    void setMinute(int minute);
    int getMinute();
    void setGrade(int score);
    string getGrade();
};

void Time :: setMinute(int minute){
    Time :: minute = minute;
}

int Time :: getMinute(){
    return Time :: minute;
}

void Time :: setGrade(int score){
    if(score >= 80) {
        Time :: grade = "A";
    } else if(score >= 70) {
        Time :: grade = "B";
    } else if(score >= 60) {
        Time :: grade = "C";
    } else if(score >= 50) {
        Time :: grade = "D";
    } else {
        Time :: grade = "F";
    }
   
}

string Time :: getGrade(){
    return Time :: grade;
}