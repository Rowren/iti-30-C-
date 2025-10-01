#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int Menu();
void AddStudent(string FN);
void DisplayStudent(string FN);
string CalGrade(int Score);

int main()
{
    const string Filename = "student.dat";
    int c;
    do
    {
        system("cls"); // ล้างหน้าจอ (Windows)
        c = Menu();
        switch (c)
        {
            case 1:
                AddStudent(Filename);
                break;
            case 2:
                DisplayStudent(Filename);
                break;
        }
    } while (c != 0);

    cout << "Exit program." << endl;
    return 0;
}

int Menu()
{
    string line(25, '=');
    int Choose;
    cout << "Program Add-Display Student Data\n";
    cout << line << endl;
    cout << ": Main Menu :\n";
    cout << line << endl;
    cout << ": 0 - Exit\n";
    cout << ": 1 - Add Student\n";
    cout << ": 2 - Display Student\n";
    cout << line << endl;
    cout << "Enter choice : ";
    cin >> Choose;
    return Choose;
}

void AddStudent(string FN)
{
    ofstream OutFile(FN.c_str(), ios::app); // append mode
    if (OutFile.is_open())
    {
        string Id, Name, Surname;
        int Score;

        cout << "\nAdd Student\n";
        cout << "Enter id : ";
        cin >> Id;
        cout << "Enter name : ";
        cin >> Name;
        cout << "Enter surname : ";
        cin >> Surname;
        cout << "Enter score : ";
        cin >> Score;

        OutFile << Id << " "
                << Name << " "
                << Surname << " "
                << Score << endl;

        OutFile.close();

        char Wait;
        cin.get(Wait);
        cout << "\nSaved already, Press Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not be opened." << endl;
}

void DisplayStudent(string FN)
{
    ifstream InFile(FN.c_str());
    if (InFile.is_open())
    {
        string Id, Name, Surname, Grade;
        int Score;
        int n = 0;

        cout << "\nList Student\n";
        cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
        cout << left
             << setw(5)  << "No."
             << setw(10) << "ID"
             << setw(25) << "Name Surname"
             << setw(10) << "Score"
             << setw(6)  << "Grade"
             << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        while (true)
        {
            // พยายามอ่าน 5 ค่า
            if (InFile >> Id >> Name >> Surname >> Score >> Grade)
            {
                n++;
                cout << left
                     << setw(5)  << n
                     << setw(10) << Id
                     << setw(25) << (Name + " " + Surname)
                     << setw(10) << Score
                     << setw(6)  << Grade
                     << endl;
            }
            // ถ้าอ่านได้แค่ 4 ค่า → คำนวณเกรดเอง
            else if (InFile.clear(), InFile >> Id >> Name >> Surname >> Score)
            {
                n++;
                cout << left
                     << setw(5)  << n
                     << setw(10) << Id
                     << setw(25) << (Name + " " + Surname)
                     << setw(10) << Score
                     << setw(6)  << CalGrade(Score)
                     << endl;
            }
            else
            {
                break; // หมดไฟล์
            }
        }

        cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;

        InFile.close();

        char Wait;
        cin.ignore();
        cout << "\nPress Enter to continue...";
        cin.get(Wait);
    }
    else
        cout << "File could not be opened." << endl;
}

string CalGrade(int Score)
{
    if (Score >= 80)
        return "A";
    else if (Score >= 75)
        return "B+";
    else if (Score >= 70)
        return "B";
    else if (Score >= 65)
        return "C+";
    else if (Score >= 60)
        return "C";
    else if (Score >= 55)
        return "D+";
    else if (Score >= 50)
        return "D";
    else
        return "F";
}
