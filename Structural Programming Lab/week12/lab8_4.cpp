#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
int Minimum(int Temp[][4], const int Students, const int Exam);
int Maximum(int Temp[][4], const int Students, const int Exam);
double Average(int Temp[], const int Exam);
double CalGrade(int Score);
double CalGPA(double Temp[], const int Exam);

int main()
{
    const int MaxStudents = 3;
    const int MaxExam = 4;
    int Score[MaxStudents][MaxExam];
    double Grade[MaxStudents][MaxExam];
    srand(time(0));

    for (int r = 0 ; r < MaxStudents; r++){
        for(int c = 0; c < MaxExam; c++){
            Score[r][c] = rand() % 30 + 50;
            Grade[r][c] = CalGrade(Score[r][c]);
        }
    }

   //Display Score
cout << "Score     ";
for(int c = 0; c < MaxExam; c++){
    cout << "[" << setw(2) << c << "]" << setw(2);
}
cout << endl;
for (int r = 0 ; r < MaxStudents; r++){
    cout << "Score[" << r << "] ";
    for (int c = 0; c < MaxExam; c++){
        cout << setw(5) << Score[r][c];
    }
    cout << endl;
}
cout << endl;

//Display Grade
cout << "Grade     ";
for(int c = 0; c < MaxExam; c++){
    cout << "[" << setw(2) << c << "]" << setw(2);
}
cout << endl;
for (int r = 0 ; r < MaxStudents; r++){
    cout << "Grade[" << r << "] ";
    for (int c = 0; c < MaxExam; c++){
        cout << setw(5) << Grade[r][c];
    }
    cout << endl;
}


    cout << "\nLowest Score : " << Minimum(Score, MaxStudents, MaxExam) << endl;
    cout << "Highest Score : " << Maximum(Score, MaxStudents, MaxExam) << endl;
    cout << endl << endl;

    for (int r = 0; r < MaxStudents; r++){
        cout << "Average of Students" << r << " is ";
        cout << fixed << setprecision(2) << Average(Score[r], MaxExam) ;
        cout << ", GPA  =  " << fixed << setprecision(2) << CalGPA(Grade[r],MaxExam);

        cout << endl ;
    }
    cout << endl;

    return 0;
}

int Minimum(int Temp[][4], const int Students, const int Exam)
{
    int LowScore = 100;
    for (int r = 0; r < Students; r++){
        for(int c = 0; c < Exam; c++){
            if( Temp[r][c] < LowScore){
                LowScore = Temp[r][c];
            }
        }
    }
    return LowScore;
}

int Maximum(int Temp[][4], const int Students, const int Exam){
    int HighScore = 0;
    for (int r = 0; r < Students; r++){
        for(int c = 0; c < Exam; c++){
            if( Temp[r][c] > HighScore){
                HighScore = Temp[r][c];
            }
        }
    }
    return HighScore;
}

double Average(int Temp[], const int Exam){
    int total = 0;
    for(int r = 0; r < Exam; r++){
        total += Temp[r];
    }
    return (double)total/Exam;
}

//CalGrade()
double CalGrade(int Score){


    if(Score >= 80){
        return 4.0;
    }else if (Score >=75)
    {
        return 3.5;
    }else if (Score >= 70)
    {
        return 3.0;
    }else if (Score >= 65){
        return 2.5;
    }else if (Score >= 60)
    {
        return 2.0;
    }else if (Score >= 55)
    {
        return 1.5;
    }else if (Score >= 50)
    {
        return 1.0;
    }else if (Score < 50)
    {
        return 0;
    }

}

//CalGPA()
double CalGPA(double Temp[], const int Exam){
    double total = 0;
    for (int i = 0; i < Exam; i++){
        total += Temp[i];
    }
    return total / Exam;
}